package com.app;

import android.app.Activity;
import android.os.Bundle;
import android.content.Context;
import android.view.View;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.view.Display;
import android.graphics.Point;

public class app extends Activity
{

	view			m_view;
    
    @Override
    public void onCreate(Bundle savedInstanceState)
    {

        super.onCreate(savedInstanceState);

		Display display = getWindowManager().getDefaultDisplay();

		Point size = new Point();
		
		display.getSize(size);

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

    private static native void renderPlasma(Bitmap  bitmap, long time_ms, int iScreenW, int iScreenH);

    public view(Context context, Point size)
	{

        super(context);

        m_iScreenW = size.x;

        m_iScreenH = size.y;

        m_bitmap = Bitmap.createBitmap(m_iScreenW, m_iScreenH - 66, Bitmap.Config.RGBA_8888);

        m_lStartTime = System.currentTimeMillis();

    }

    @Override
	protected void onDraw(Canvas canvas)
	{
        
		renderPlasma(m_bitmap, System.currentTimeMillis() - m_lStartTime, m_iScreenW, m_iScreenH);

        canvas.drawBitmap(m_bitmap, 0, 0, null);

        invalidate();

    }

}



