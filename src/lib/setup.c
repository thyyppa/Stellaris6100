#include <inc/hw_gpio.h>
#include <inc/hw_memmap.h>
#include <inc/hw_sysctl.h>
#include <inc/hw_types.h>
#include <driverlib/gpio.h>
#include <driverlib/rom.h>
#include <driverlib/sysctl.h>
#include "led/led.c"
#include "lcd/lcd.c"

/**
 * Set up the system
 */
void setup()
{
    ROM_SysCtlClockSet(
        SYSCTL_SYSDIV_2_5
        | SYSCTL_USE_PLL
        | SYSCTL_XTAL_16MHZ
        | SYSCTL_OSC_MAIN
    );

    lcd_init();
}
