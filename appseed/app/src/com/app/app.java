package com.app;

import android.app.Activity;
import android.os.Bundle;
import android.content.Context;
import android.view.View;
import android.graphics.Bitmap;
import android.graphics.Canvas;

public class app extends Activity
{
    
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(new view(this));
    }

    static
	{

		System.loadLibrary("launcher");
        System.loadLibrary("activity");

    }

}


class view extends View
{
    private Bitmap m_bitmap;
    private long m_lStartTime;

    private static native void renderPlasma(Bitmap  bitmap, long time_ms);
	private static native void start();

    public view(Context context)
	{
        super(context);

        final int W = 200;
        final int H = 200;

        m_bitmap = Bitmap.createBitmap(W, H, Bitmap.Config.RGB_565);
        m_lStartTime = System.currentTimeMillis();
		start();
    }

    @Override
	protected void onDraw(Canvas canvas)
	{
        renderPlasma(m_bitmap, System.currentTimeMillis() - m_lStartTime);
        canvas.drawBitmap(m_bitmap, 0, 0, null);
        invalidate();
    }

}