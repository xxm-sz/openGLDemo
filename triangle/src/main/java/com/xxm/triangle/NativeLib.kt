package com.xxm.triangle

class NativeLib {

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
}