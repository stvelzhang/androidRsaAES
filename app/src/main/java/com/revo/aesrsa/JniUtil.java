package com.revo.aesrsa;

public class JniUtil {

    static {
        System.loadLibrary("JniUtil");
    }

    //定义一个方法，该方法在C中实现
    public native String getString();  //native关键字指示以原生形式实现的方法.向编译器告知实现在原生库中

    public native int add(int i, int j);
    public native String encrypt(String plainText);
    public native String decrypt(String cipherText);

    public native String getKeyValue();
    public native String getIv();













}
