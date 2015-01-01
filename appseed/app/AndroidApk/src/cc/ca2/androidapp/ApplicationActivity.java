/*
 * Copyright (C) 2010 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package cc.ca2.androidapp;

import android.app.Activity;
import android.os.Bundle;
import android.content.Context;
import android.view.View;
import android.graphics.Bitmap;
import android.graphics.Canvas;


public class ApplicationActivity extends Activity
{

    ApplicationView m_view;

    @Override protected void onCreate(Bundle bundle)
	{
        
		super.onCreate(bundle);

        m_view = new ApplicationView(this);

		setContentView(m_view);

    }


	static
	{
       
	   System.loadLibrary("app");

    }

}




class ApplicationView extends View
{


    private Bitmap	m_bitmap;
    private long	m_lStartTime;
	private int		m_iW;
	private int		m_iH;


	private static native void applicationViewUpdateBitmap(Bitmap  bitmap, long time_ms);

	private static native void applicationViewStart();
	private static native void applicationViewStop();

    public ApplicationView(Context context)
	{

        super(context);

		applicationViewStart();

        m_lStartTime = System.currentTimeMillis();

    }



 /*
    This onSizeChanged() method gets called automatically
    BEFORE the view gets layed out or drawn for the first time.
    It alse gets called when the view's orientation changes
    or gets resized etc. This is the method that does the trick.
    In this method, you get your view's updated dimensions.
    Then you should store these dimension values into
    the global int variables that are declared above.
    Later, you can call these global variables to read what
    is the new width or height of the object
    --------- thanks to kgiannakakis May 25 '10 at 9:18
    --------- http://ow.ly/44hzw  
    */
    @Override
    protected void onSizeChanged(int wNew, int hNew, int wOld, int hOld)
	{

		super.onSizeChanged(wNew, hNew, wOld, hOld);

		m_iW = wNew;

		m_iH = hNew;

		createGraphicsResources();

    }
 

    @Override protected void onDraw(Canvas canvas)
	{


		if(m_bitmap != null)
		{

			applicationViewUpdateBitmap(m_bitmap, System.currentTimeMillis() - m_lStartTime);

			canvas.drawBitmap(m_bitmap, 0, 0, null);

		}

		invalidate();

    }

	void createGraphicsResources()
	{

		int iW = 200;

		int iH = 200;

		if(m_iW > 0)
		{
		
			iW = m_iW;

		}
	
		if(m_iH > 0)
		{
		
			iH = m_iH;

		}
	
		m_bitmap = Bitmap.createBitmap(iW, iH, Bitmap.Config.ARGB_8888);	

	}


}


