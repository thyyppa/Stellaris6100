#include "led.h"


/**
 * Enable port and set gpio to output
 */
void enable_led()
{
    ROM_SysCtlPeripheralEnable( LED_PERIPHERAL );
    ROM_GPIOPinTypeGPIOOutput( LED_PORT, LED_RED | LED_BLUE | LED_GREEN );
}


/**
 * Blink an LED at a given rate
 *
 * @param  led   LED to blink
 * @param  rate  Rate to blink
 */
void led_blink( int led, int rate )
{
    led_on( led );
    ROM_SysCtlDelay( rate * 1000 );

    led_off( led );
    ROM_SysCtlDelay( rate * 1000 );
}


/**
 * Turn on an LED
 *
 * @param  led  LED to turn on
 */
void led_on( int led )
{
    setPin( LED_PORT, led, 1 );
}


/**
 * Turn off an LED
 *
 * @param  led  LED to turn of
 */
void led_off( int led )
{
    setPin( LED_PORT, led, 0 );
}
