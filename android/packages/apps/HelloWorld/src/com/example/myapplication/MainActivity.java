package com.example.myapplication;

import android.app.Activity;
import android.os.ServiceManager;
import android.os.IHelloWorldService;
import android.os.IBinder;
import android.os.Bundle;
import android.os.RemoteException;
import android.util.Log;

public class MainActivity extends Activity {

public IHelloWorldService mService;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Log.d("ZSH", "start App");
        try {
          IBinder binder = ServiceManager.getService("helloworld");
          IHelloWorldService helloWorldService = IHelloWorldService.Stub.asInterface(binder);
          int result = helloWorldService.addVal(4,9);
          Log.d("ZSH", "ZSH testHal addVal result is " + result);
       } catch (RemoteException e) {
       	e.printStackTrace();
       }
    }
}
