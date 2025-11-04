#include <jni.h>
#include "MyTestJNI.h"

#include <iostream>
#include <string>


JNIEXPORT jstring JNICALL Java_MyTestJNI_CppMethod
    (JNIEnv *env, jobject jObj, jstring jMsg )
{

    std::string message = std::string(env->GetStringUTFChars(jMsg,NULL));
    std::cout << message << " <-- Output from CppMethod() " <<std::endl;

    std::cout << message << " <-- Output from CppMethod() second time " <<std::endl;


    std::string rtn = " Return Message From CppMethod() ";
    return env->NewStringUTF(rtn.c_str());


}

