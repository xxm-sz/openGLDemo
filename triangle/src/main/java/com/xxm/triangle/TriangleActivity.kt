package com.xxm.triangle

import android.opengl.GLSurfaceView
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.LayoutInflater
import androidx.databinding.ViewDataBindingKtx
import com.xxm.triangle.databinding.ActivityTriagnleBinding

class TriangleActivity : AppCompatActivity() {
    private lateinit var nativeRender:NativeLib
    private lateinit var binding:ActivityTriagnleBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding=ActivityTriagnleBinding.inflate(LayoutInflater.from(this))
        setContentView(binding.root)
        nativeRender= NativeLib()
        binding.triangle.setEGLContextClientVersion(3)
        binding.triangle.setRenderer(nativeRender)
        binding.triangle.renderMode=GLSurfaceView.RENDERMODE_WHEN_DIRTY
    }

    override fun onResume() {
        super.onResume()
        binding.triangle.onResume()
    }

    override fun onPause() {
        super.onPause()
        binding.triangle.onPause()
    }
}