#include <iostream>
#include <string>

#include <jni.h>
#include"MyTestJNI.h"

/*
 * # define JNI_FALSE 0
 * # define JNI_TRUE 1
 */


JNIEXPORT jstring JNICALL Java_MyTestJNI_CppMethod
    (JNIEnv *env,jobject jObj,jstring jMsg)
{
    std::string message = std::string(env->GetStringUTFChars(jMsg, JNI_FALSE));
    std::cout << message << " <- CppMethod() " << std::endl;

    jclass thisClass = env->GetObjectClass(jObj);
    jmethodID mid = env->GetMethodID(thisClass, "setValue" ,"(Ljava/lang/String;)V");
    jstring msg = env->NewStringUTF("Hello From CppMethod()");
    env->CallVoidMethod(jObj,mid,msg);
   
    jfieldID fid = env->GetFieldID(thisClass,"value","Ljava/lang/String;");
    jstring val = (jstring)env->GetObjectField(jObj,fid);
    std::cout << std::string(env->GetStringUTFChars(val,JNI_FALSE)) << " <- CppMethod()" <<std::endl;

    std::string rtn = "Return From CppMethod";
    return env->NewStringUTF(rtn.c_str());

}


