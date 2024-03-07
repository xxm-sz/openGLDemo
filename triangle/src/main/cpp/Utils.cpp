//
// Created by zhangws on 2024/3/7.
//
#include <android/log.h>


//加载着色器
GLuint LoadShader(GLenum type,const char * shaderSrc){
    GLuint shader;
    GLint compiled;
    shader=glCreateShader(type);
    if(shader==0){
        return 0;
    }
    glShaderSource(shader,1,&shaderSrc,NULL);
    glCompileShader(shader);
    glGetShaderiv(shader,GL_COMPILE_STATUS,&compiled);
    if(!compiled)
    {
        GLint infoLen=0;
        glGetShaderiv(shader,GL_INFO_LOG_LENGTH,&infoLen);
        if(infoLen>0)
        {
            char * infoLog=(char*) malloc(sizeof(char)*infoLen);
            glGetShaderInfoLog(shader,infoLen,NULL,infoLog);
            LOGE("Error compiling shader:[%s]",infoLog);
            free(infoLog);
        }
        glDeleteShader(shader);
        return 0;
    }
    return shader;
}