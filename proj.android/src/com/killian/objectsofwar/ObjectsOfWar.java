package com.killian.objectsofwar;

import android.app.Activity;
import android.os.Bundle;

public class ObjectsOfWar extends Activity
{
	protected void onCreate(Bundle savedInstanceState){
		super.onCreate(savedInstanceState);
	}
	
    static {
         System.loadLibrary("objectsofwar");
    }
}
