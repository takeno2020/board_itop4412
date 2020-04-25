package mobile.android.leds.hal.service;

public class AiLedHalService
{
    private static AiLedHalService aiLedHalService;

    public static AiLedHalService getInstance()
    {
        if (aiLedHalService == null)
            return new AiLedHalService();
        else
            return aiLedHalService;
    }

    private AiLedHalService()
    {
        init();
    }

    public boolean init()
    {
        return _init();
    }

    public boolean setOn(int led)
    {
        return _ai_set_on(led);
    }

    public boolean setOff(int led)
    {
        return _ai_set_off(led);
    }

    private native boolean _init();
    private native boolean _ai_set_on(int led);
    private native boolean _ai_set_off(int led);

    static
    {
        System.load("/system/lib/ai_led_hal_jni.so");
    }
}
