package com.android.server;

import android.content.Context;
import android.os.IHelloWorldService;
import android.util.Slog;
import android.content.Context;

public class HelloWorldService extends IHelloWorldService.Stub {

    private Context mContext;

    HelloWorldService(Context context) {
        mContext=context;
        init();
        Slog.v("HelloWorldService", "init result= " + addVal(3, 5));
    }

    public int addVal(int a, int b) {
        Slog.v("HelloWorldService", "addVAl result= " + addValue(a, b));
        return addValue(a, b);
    }

    private static native boolean init();

    private static native int addValue(int a, int b);

}


