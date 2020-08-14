//
// Created by Administrator on 2020/8/3.
//

#include <jni.h>
#include <com_revo_aesrsa_JniUtil.h>
#include <stdio.h>
#include <string.h>
#include<android/log.h>
#include <stdlib.h>
#include "base64.h"
#include <aes256.h>


#define LOG    "fuckDemo-jni" // 这个是自定义的LOG的标识
#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG,__VA_ARGS__) // 定义LOGD类型
#define LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG,__VA_ARGS__) // 定义LOGI类型
#define LOGW(...)  __android_log_print(ANDROID_LOG_WARN,LOG,__VA_ARGS__) // 定义LOGW类型
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG,__VA_ARGS__) // 定义LOGE类型
#define LOGF(...)  __android_log_print(ANDROID_LOG_FATAL,LOG,__VA_ARGS__) // 定义LOGF类型


const char keyValue[] = {
        21, 25, 21, 45, 25, 98, 55, 45, 10, 35, 45, 35,
        26, 5, 25, 65, 78, 99, 85, 45, 5, 10, 0, 11,
        35, 48, 98, 65, 32, 14, 67, 25, 36, 56, 45, 5,
        12, 15, 35, 15, 25, 14, 62, 25, 33, 45, 55, 12, 8
};

const char iv[] =  {    //16 bit
        33, 32, 25, 25, 35, 27, 55, 12, 15,32,
        23, 45, 26, 32, 5,16
};

const uint8_t AesKey[32] = {
        0x77,0x6f,0x6a,0x69,
        0x75,0x62,0x75,0x67,
        0x61,0x6f,0x73,0x75,
        0x6e,0x69,0x6d,0x65,
        0x6e,0x67,0x6c,0x61,
        0x6c,0x69,0x73,0x61,
        0x64,0x65,0x79,0x61,
        0x6e,0x6c,0x65,0x69
};

const uint8_t AesIv[16] = {
        0x6e,0x67,0x6c,0x61,
        0x6c,0x69,0x73,0x61,
        0x64,0x65,0x79,0x61,
        0x6e,0x6c,0x65,0x69
};





#define LEN 512
/*
 * Class:     com_revo_aesrsa_JniUtil
 * Method:    getString
 * Signature: ()Ljava/lang/String;
 */
extern "C" {
JNIEXPORT jstring JNICALL Java_com_revo_aesrsa_JniUtil_getString
        (JNIEnv *env, jobject obj){
    const char keyvalue[8] = {'s','t','v','e','l','z','s','x'};
    return  env->NewStringUTF(keyvalue);
//    return env->NewStringUTF("hello,TEE-CA--stvelzhang from C++");
}
}


/*
 * Class:     com_revo_aesrsa_JniUtil
 * Method:    add
 * Signature: (II)I
 */
extern "C" {
JNIEXPORT jint JNICALL Java_com_revo_aesrsa_JniUtil_add
        (JNIEnv *env, jobject obj, jint k, jint j){
    int i;

    const unsigned char master_key[16] = {
            '1', '2', '3', '4', '5', '6', '7', '8',
            '9', '0', 'a', 'b', 'c', 'd', 'e', 'f',
    };
    const unsigned char text[16] = {
            '1', '2', '3', '4', '5', '6', '7', '8',
            '9', '0', 'a', 'b', 'c', 'd', 'e', 'f',
    };

    const unsigned char iv[16] = {
            '9', '0', 'a', 'b', 'c', 'd', 'e', 'f',
            '1', '2', '3', '4', '5', '6', '7', '8',
    };

    unsigned char ivc[16];

    unsigned char encrypted[16], decrypted[16];
    memset(encrypted, 0, 16*sizeof(char));
    memset(decrypted, 0, 16*sizeof(char));

    return k + j;
}
}



/*
 * Class:     com_revo_aesrsa_JniUtil
 * Method:    getKeyValue
 * Signature: ()Ljava/lang/String;
 */
extern "C" {
JNIEXPORT jstring JNICALL Java_com_revo_aesrsa_JniUtil_getKeyValue
        (JNIEnv *env, jobject obj){

    jbyteArray KeyArray = env->NewByteArray(sizeof(AesKey));
    jbyte *bytes = env->GetByteArrayElements(KeyArray, 0);

    int i;

    for (i = 0; i < sizeof(AesKey); i++){


        //__android_log_print(ANDROID_LOG_ERROR,LOG,"AesIv的是%d",AesKey[i]);
        bytes[i] = (jbyte) (AesKey[i]);
        //__android_log_print(ANDROID_LOG_ERROR,LOG,"bytes[i] %d",bytes[i]);
    }

    env->SetByteArrayRegion(KeyArray, 0, sizeof(iv), bytes);
    env->ReleaseByteArrayElements(KeyArray,bytes,0);

    jclass strClass = env->FindClass("java/lang/String");
    jmethodID ctorID = env->GetMethodID(strClass, "<init>", "([BLjava/lang/String;)V");

    jstring encoding = env->NewStringUTF("utf-8");

    return (jstring)env->NewObject(strClass, ctorID, KeyArray, encoding);

}
}


/*
 * Class:     com_revo_aesrsa_JniUtil
 * Method:    getIv
 * Signature: ()Ljava/lang/String;
 */
extern "C" {
JNIEXPORT jstring JNICALL Java_com_revo_aesrsa_JniUtil_getIv
    (JNIEnv *env, jobject obj){


    jbyteArray ivArray = env->NewByteArray(sizeof(AesIv));
    jbyte *bytes = env->GetByteArrayElements(ivArray, 0);

    int i;

    for (i = 0; i < sizeof(AesIv); i++){


       // __android_log_print(ANDROID_LOG_ERROR,LOG,"AesIv的是%d",AesIv[i]);
        bytes[i] = (jbyte) (AesIv[i]);
       // __android_log_print(ANDROID_LOG_ERROR,LOG,"bytes[i] %d",bytes[i]);
    }

    env->SetByteArrayRegion(ivArray, 0, sizeof(iv), bytes);
    env->ReleaseByteArrayElements(ivArray,bytes,0);

    jclass strClass = env->FindClass("java/lang/String");
    jmethodID ctorID = env->GetMethodID(strClass, "<init>", "([BLjava/lang/String;)V");

    jstring encoding = env->NewStringUTF("utf-8");

    return (jstring)env->NewObject(strClass, ctorID, ivArray, encoding);
}

}











