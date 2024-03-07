package com.xxm.triangle

import android.opengl.GLSurfaceView
import android.util.Log
import javax.microedition.khronos.egl.EGLConfig
import javax.microedition.khronos.opengles.GL10

class NativeLib:GLSurfaceView.Renderer {
    private  val TAG = "NativeLib"
    /**
     * A native method that is implemented by the 'triangle' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String

    companion object {
        // Used to load the 'triangle' library on application startup.
        init {
            System.loadLibrary("triangle")
        }
    }


    external fun glesInit()

    external fun glesRender()

    external fun glesResize(width: Int,height:Int)

    override fun onSurfaceCreated(gl: GL10?, config: EGLConfig?) {
        Log.i(TAG,"onSurfaceCreated")
        glesInit()
    }

    override fun onSurfaceChanged(gl: GL10?, width: Int, height: Int) {
        Log.i(TAG,"onSurfaceChanged:${width},${height}")
        glesResize(width,height)
    }

    override fun onDrawFrame(gl: GL10?) {
        Log.i(TAG,"onDrawFrame")
        glesRender()
    }
}