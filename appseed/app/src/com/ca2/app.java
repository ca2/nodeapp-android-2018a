package com.ca2;

import android.app.Activity;
import android.os.Bundle;
import android.content.Context;
import android.view.View;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.view.Display;
import android.view.MotionEvent;
import android.view.KeyEvent;
import android.view.inputmethod.BaseInputConnection;
import android.view.inputmethod.InputConnection;
import android.view.inputmethod.InputMethodManager;
import android.text.InputType;
import android.view.inputmethod.EditorInfo;
import android.graphics.Point;
import android.view.MotionEvent.PointerProperties;
import android.content.pm.PackageManager;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager.NameNotFoundException;
import android.net.Uri;
import android.content.Intent;


public class app extends Activity
{

	view			m_view;

	private static native void configureApp(String strCommandLine, String strCacheDir, int iScreenW, int iScreenH);
    
    @Override
    public void onCreate(Bundle savedInstanceState)
    {

        super.onCreate(savedInstanceState);

		Display display = getWindowManager().getDefaultDisplay();

		Point size = new Point();
		
		display.getSize(size);

		//configureApp("app : app=app-core/hellomultiverse no_hello_edit client_only", getApplicationContext().getCacheDir().getAbsolutePath(), size.x, size.y);

		String prjname = "";

		String cmdline = "";

		String libname = "";

		try
		{

			ApplicationInfo ai = getPackageManager().getApplicationInfo(getPackageName(), PackageManager.GET_META_DATA);
    
			Bundle bundle = ai.metaData;
		
			prjname = bundle.getString("project_name");

			cmdline = bundle.getString("command_line");

			libname = bundle.getString("library_name");

		}
		catch (NameNotFoundException e)
		{
			
		}
		catch (NullPointerException e)
		{
			
		}



		if(prjname.substring(0, 5).equals("nord_"))
		{

			prjname = prjname.substring(5);

		}

        System.loadLibrary("activity");

		//System.loadLibrary("axis");

		//System.loadLibrary("core");

		//System.loadLibrary("axispixman");

		//System.loadLibrary("axiscairo");

		if(libname.length() > 0)
		{
			
			String[] parts = libname.split(",");

			for(int i = 0; i < parts.length; i++)
			{
				
				String lib = parts[i];

				if(lib.length() > 0)
				{

					System.loadLibrary(lib);

				}

			}

		}

		System.loadLibrary("axis_image_jpeg");

		System.loadLibrary("draw2d_cairo");

		boolean bLoaded = false;

		if(!bLoaded)
		{


			try
			{

				System.loadLibrary(prjname);

				bLoaded = true;

			}
			catch (UnsatisfiedLinkError e)
			{

			}
		
		}

		if(!bLoaded)
		{

			if(prjname.substring(0, 4).equals("app_"))
			{

				prjname = prjname.substring(4);

			}
			else
			{

				throw new UnsatisfiedLinkError(prjname);

			}
		
			//try
			{

				System.loadLibrary(prjname);

				bLoaded = true;

			}
			//catch (UnsatisfiedLinkError e)
			{

			}

		}

		System.loadLibrary("launcher");


		configureApp(cmdline, getApplicationContext().getCacheDir().getAbsolutePath(), size.x, size.y);

		m_view = new view(this, size);
		
        setContentView(m_view);

    }




}


class TakeInfoResult
{

   boolean	m_bShowKeyboard;
   boolean	m_bHideKeyboard;
   String	m_strOpenUrl;
   
}


class view extends View
{

    private Bitmap m_bitmap;

    private long m_lStartTime;

	private int m_iScreenW;

	private int m_iScreenH;

	private TakeInfoResult m_result;

    private static native void renderImpact(Bitmap  bitmap, long time_ms, TakeInfoResult result);

	private static native void lButtonDown(float x, float y);

	private static native void mouseMove(float x, float y);

	private static native void lButtonUp(float x, float y);

	private static native void keyDown(int keycode);

	private static native void keyUp(int keycode);

	private static native void keyPreImeDown(int keycode, int iUni);

	private static native void keyPreImeUp(int keycode, int iUni);

	private static native void onReceivedShowKeyboard();

	private static native void onReceivedHideKeyboard();


    public view(Context context, Point size)
	{

        super(context);

		m_result = new TakeInfoResult();

		//m_result.m_strOpenUrl = new String();

		setFocusableInTouchMode(true);

		setOnKeyListener(new OnKeyListener()
			{

				public boolean onKey(View v, int keyCode, KeyEvent event)
				{

	                if (event.getAction() == KeyEvent.ACTION_DOWN)
					{

						keyDown(keyCode);

	                    return true;

		            }
	                else if (event.getAction() == KeyEvent.ACTION_UP)
					{

						keyUp(keyCode);

	                    return true;

		            }

		            return false;
	
				}

            });

        m_iScreenW = size.x;

        m_iScreenH = size.y;

        m_bitmap = Bitmap.createBitmap(m_iScreenW, m_iScreenH - 66, Bitmap.Config.ARGB_8888);

        m_lStartTime = System.currentTimeMillis();

    }

    @Override
	protected void onDraw(Canvas canvas)
	{
        
		renderImpact(m_bitmap, System.currentTimeMillis() - m_lStartTime, m_result);

        canvas.drawBitmap(m_bitmap, 0, 0, null);

        invalidate();

		if(m_result.m_bShowKeyboard)
		{

			m_result.m_bShowKeyboard = false;

			onReceivedShowKeyboard();

			InputMethodManager imm = (InputMethodManager) getContext().getSystemService(Context.INPUT_METHOD_SERVICE);
				
			imm.showSoftInput(this, InputMethodManager.SHOW_FORCED);

		}


		if(m_result.m_bHideKeyboard)
		{

			m_result.m_bHideKeyboard = false;

			onReceivedHideKeyboard();

			InputMethodManager imm = (InputMethodManager) getContext().getSystemService(Context.INPUT_METHOD_SERVICE);
				
			imm.showSoftInput(this, InputMethodManager.HIDE_IMPLICIT_ONLY);

		}


		if(m_result.m_strOpenUrl != null && m_result.m_strOpenUrl.length() > 0)
		{

			openUrl(m_result.m_strOpenUrl);
		}

    }


   @Override
   public InputConnection onCreateInputConnection(EditorInfo outAttrs)
   {
        //BaseInputConnection fic = new BaseInputConnection(this, true); // avoid send raw events (avoid sending key up key down)
		BaseInputConnection fic = new BaseInputConnection(this, false); // send raw events (key up key down)
        outAttrs.actionLabel = null;
//        outAttrs.inputType = InputType.TYPE_CLASS_TEXT; // if is rich editable (offer suggestions?)
        outAttrs.inputType = InputType.TYPE_NULL; // send raw events
        //outAttrs.imeOptions = EditorInfo.IME_ACTION_NEXT;
		outAttrs.imeOptions = EditorInfo.IME_ACTION_DONE;
        return fic;
    }

    @Override
    public boolean onCheckIsTextEditor() 
	{
        return true;
    }

	public boolean onTouchEvent (final MotionEvent ev)
	{
        // my Code
        //boolean b = super.onTouchEvent(ev);

		if(ev.getAction() == MotionEvent.ACTION_DOWN)
		{

			lButtonDown(ev.getX(), ev.getY());
		
		}
		else if(ev.getAction() == MotionEvent.ACTION_MOVE)
		{

			mouseMove(ev.getX(), ev.getY());
		
		}
		else if(ev.getAction() == MotionEvent.ACTION_UP)
		{

			lButtonUp(ev.getX(), ev.getY());
		
		}

		//return b;
		return true;
    }


	public boolean onKeyPreIme(int keyCode, KeyEvent ev)
	{

		if(ev.getAction() == KeyEvent.ACTION_DOWN)
		{

			keyPreImeDown(keyCode, ev.getUnicodeChar());
		
		}
		else if(ev.getAction() == KeyEvent.ACTION_UP)
		{

			keyPreImeUp(keyCode, ev.getUnicodeChar());
		
		}
		
		return true;

	}



    private void openUrl( String url )
    {
        Uri uriUrl = Uri.parse( url );
        Intent intent = new Intent(Intent.ACTION_VIEW, uriUrl);
        intent.setFlags( Intent.FLAG_ACTIVITY_NEW_TASK );
        getContext().startActivity( intent );
    } 
}



