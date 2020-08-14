package com.revo.aesrsa;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import com.revo.aesrsa.resrsa.AES;
import com.revo.aesrsa.resrsa.AesUtils;
import com.revo.aesrsa.resrsa.RSA;

public class MainActivity extends AppCompatActivity {
    Button button,enbtn,debtn;
    TextView tv;
    private JniUtil jniUtil;
    private String ming = "woshiyigemingwen";
    private String encrypmi,decrypmi;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        button = findViewById(R.id.button);
        enbtn = findViewById(R.id.button_encrpty);
        debtn = findViewById(R.id.button_decrpty);
        tv = findViewById(R.id.tv);



        jniUtil = new JniUtil();
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                tv.setText("获取key："+ jniUtil.getKeyValue());
            }
        });

        enbtn.setOnClickListener(new View.OnClickListener(){

            @Override
            public void onClick(View v) {
                encrypmi = jniUtil.encrypt(ming);
                Log.e("fuckdemo","JNI加密AES256--base64后："+ encrypmi);
                tv.setText("加密后："+ encrypmi);
            }
        });

        debtn.setOnClickListener(new View.OnClickListener(){

            @Override
            public void onClick(View v) {
                decrypmi = jniUtil.decrypt(encrypmi);
                Log.e("fuckdemo","JNI解密AES256--base64后："+ decrypmi);
                tv.setText("解密后："+ decrypmi);
            }
        });


        tv.setText("\n加密前：" + ming );

        //java加解密

        String encyptdateStr = AES.encryptToBase64(ming, jniUtil.getKeyValue().substring(0,16), jniUtil.getIv());

        Log.e("fuckdemo","java加密AES128--base64后："+ encyptdateStr);

        String decyptdateStr = AES.decryptFromBase64(encyptdateStr, jniUtil.getKeyValue().substring(0,16), jniUtil.getIv());
        Log.e("fuckdemo","java解密AES128--base64后："+ decyptdateStr);




        String javaEncrypt= AesUtils.aesEncrypt(ming, jniUtil.getKeyValue(), jniUtil.getIv());
        Log.e("fuckdemo","java解密AES256--base64后："+ javaEncrypt);
        String javaDecrypt = AesUtils.aesDecrypt(javaEncrypt, jniUtil.getKeyValue(), jniUtil.getIv());
        Log.e("fuckdemo","java解密AES256--base64后："+ javaDecrypt);
        String ncrypt_AESKey = RSA.encrypt(jniUtil.getKeyValue(),RSA.serverPublicKey);
        RSA.decrypt(ncrypt_AESKey,RSA.serverPrivateKey);
    }
}
