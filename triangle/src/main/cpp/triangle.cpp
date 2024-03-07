#include <jni.h>
#include <string>
#include <GLES3/gls.h>

#include "Utils.h"

extern "C" JNIEXPORT void JNICALL
Java_com_xxm_triangle_NativeLib_glesResize(JNIEnv
*env,
jobject thiz, jint
width,
jint height
) {

}
extern "C" JNIEXPORT void JNICALL
Java_com_xxm_triangle_NativeLib_glesRender(JNIEnv
*env,
jobject thiz
) {

}
extern "C" JNIEXPORT void JNICALL
Java_com_xxm_triangle_NativeLib_glesInit(JNIEnv
*env,
jobject thiz
) {
char vShaderStr[] = "#version 300 es                          \n"
                    "layout(location = 0) in vec4 vPosition;  \n"
                    "void main()                              \n"
                    "{                                        \n"
                    "   gl_Position = vPosition;              \n"
                    "}                                        \n";

char fShaderStr[] = "#version 300 es                              \n"
                    "precision mediump float;                     \n"
                    "out vec4 fragColor;                          \n"
                    "void main()                                  \n"
                    "{                                            \n"
                    "   fragColor = vec4 ( 1.0, 0.0, 0.0, 1.0 );  \n"
                    "}                                            \n";

GLuint vertexShader;
GLuint fragmentShader;
GLuint programObject;
GLuint linked;

vertexShader = LoadShader(GL_VERTEX_SHADER, vShaderStr);
fragmentShader = LoadShader(GL_FRAGMENT_SHADER, fShaderStr);
}