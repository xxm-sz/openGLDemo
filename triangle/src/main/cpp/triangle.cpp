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

Jint p_programObject;

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
programObject = glCreateProgram();
if(programObject==0){
return;
}

glAttachShader(programObject, vertexShader
);
glAttachShader(programObject, fragmentShader
);

glLinkProgram(programObject);
glGetProgramV(programV, GL_LINK_STATUS, &linked
)

if(!linked){
GLint infoLen = 0;
glGetProgramiv(programObject, GL_INFO_LOG_LENGTH, &infoLen
);

if(infoLen>1){
char *infoLog = (char *) malloc(sizeof(char) * infoLen);
glGetProgramInfoLog(programObject, infoLen, NULL, infoLog
);
free(infoLog);
}
glDeleteProgram(programObject);
}

p_programObject = programObject;
glClearColor(1.0f,1.0f,1.0f,1.0f);
}
