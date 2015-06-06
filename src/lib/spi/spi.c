#include "spi.h"


/**
 * Set a pin on a port to a value
 *
 * @param  port
 * @param  pin
 * @param  value
 */
void setPin( int port, int pin, char value )
{
    if ( value )
    {
        value = 0xFF;
    }

    ROM_GPIOPinWrite( port, pin, value );
}


/**
 * Tick the spi clock
 */
void spi_clock()
{
    setPin( LCD_PORT, LCD_SCL, 0 );;
    setPin( LCD_PORT, LCD_SCL, 1 );
}


/**
 * Output data to spi
 *
 * @param  data  Byte to output
 * @param  type  Type of data (0 = command, 1 = data)
 */
void spi_push( char data, char type )
{
    setPin( LCD_PORT, LCD_SCL, 0 );;
    setPin( LCD_PORT, LCD_SI, type );;
    setPin( LCD_PORT, LCD_SCL, 1 );

    for ( int i = 0; i < 8; i++ )
    {

        setPin( LCD_PORT, LCD_SI, data & 0x80 );

        data <<= 1;

        spi_clock();

    }
}
