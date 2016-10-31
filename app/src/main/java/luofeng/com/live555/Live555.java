package luofeng.com.live555;

/**
 * Created by luofe on 2016/10/31.
 */
public class Live555 {

    static{
        System.loadLibrary("live555");
    }

    public native void startLive555Serve();

}
