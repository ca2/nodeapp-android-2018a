package com.app;

import android.app.Activity;
import android.os.Bundle;
import android.content.Context;
import android.view.View;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.view.Display;
import android.view.MotionEvent;
import android.graphics.Point;
import android.view.MotionEvent.PointerProperties;

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

		configureApp("app : app=app-core/hellomultiverse no_hello_edit client_only", getApplicationContext().getCacheDir().getAbsolutePath(), size.x, size.y);

		m_view = new view(this, size);
		
        setContentView(m_view);

    }



    static
	{

        System.loadLibrary("activity");

		//System.loadLibrary("axis");

		//System.loadLibrary("core");

		//System.loadLibrary("axispixman");

		//System.loadLibrary("axiscairo");

		System.loadLibrary("draw2d_cairo");

		System.loadLibrary("app_core_hellomultiverse");

		System.loadLibrary("launcher");

    }

}


class view extends View
{
    private Bitmap m_bitmap;
    private long m_lStartTime;

	private int m_iScreenW;
	private int m_iScreenH;

    private static native void renderPlasma(Bitmap  bitmap, long time_ms);
	private static native void lButtonDown(float x, float y);
	private static native void mouseMove(float x, float y);
	private static native void lButtonUp(float x, float y);

    public view(Context context, Point size)
	{

        super(context);

        m_iScreenW = size.x;

        m_iScreenH = size.y;

        m_bitmap = Bitmap.createBitmap(m_iScreenW, m_iScreenH - 66, Bitmap.Config.ARGB_8888);

        m_lStartTime = System.currentTimeMillis();

    }

    @Override
	protected void onDraw(Canvas canvas)
	{
        
		renderPlasma(m_bitmap, System.currentTimeMillis() - m_lStartTime);

        canvas.drawBitmap(m_bitmap, 0, 0, null);

        invalidate();

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

}



