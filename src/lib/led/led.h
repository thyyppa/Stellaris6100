
#define LED_PORT GPIO_PORTF_BASE
#define LED_PERIPHERAL SYSCTL_PERIPH_GPIOF
#define LED_RED GPIO_PIN_1
#define LED_BLUE GPIO_PIN_2
#define LED_GREEN GPIO_PIN_3


/**
 * Blink an LED
 *
 * @param  led   LED to blink
 * @param  rate  Rate to blink
 */
void led_blink( int led, int rate );


/**
 * Turn on an LED
 *
 * @param  led
 */
void led_on( int led );


/**
 * Turn off an LED
 *
 * @param  led
 */
void led_off( int led );


/**
 * Enable LED ports and pins
 */
void enable_led();
