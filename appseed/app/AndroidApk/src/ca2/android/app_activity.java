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
package ca2.android.app;

import android.app.Activity;
import android.os.Bundle;
import android.content.Context;
import android.view.View;
import android.graphics.Bitmap;
import android.graphics.Canvas;


public class app_activity extends Activity
{

    // Called when the activity is first created. 

    @Override

    public void onCreate(Bundle savedInstanceState)
    {

        super.onCreate(savedInstanceState);

        setContentView(new app_view(this));

    }

    
	// load our native library 


    static
	{

        System.loadLibrary("app");

    }


}


class app_view extends View
{


    private Bitmap mBitmap;
    private long mStartTime;


    // implementend by libapp.so 
    private static native void render(Bitmap  bitmap, long time_ms);


    public app_view(Context context)
	{
    
	    super(context);

        final int W = 200;

        final int H = 200;

        mBitmap = Bitmap.createBitmap(W, H, Bitmap.Config.ARGB_8888);

        mStartTime = System.currentTimeMillis();

    }

    @Override protected void onDraw(Canvas canvas)
	{

        canvas.drawColor(0xFFCCFFCC);

        render(mBitmap, System.currentTimeMillis() - mStartTime);

        canvas.drawBitmap(mBitmap, 0, 0, null);

        // force a redraw, with a different time-based pattern.

        invalidate();

    }

}



