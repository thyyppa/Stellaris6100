#include "lcd.h"
#include "../spi/spi.c"

/**
 * Enable Port and set GPIO to output
 */
void enable_lcd()
{
    ROM_SysCtlPeripheralEnable( LCD_PERIPHERAL );
    ROM_GPIOPinTypeGPIOOutput( LCD_PORT, LCD_CS | LCD_SCL | LCD_SI | LCD_RST );
}


/**
 * Fill the lcd with white
 */
void lcd_clear()
{
    lcd_box( 0, 0, 131, 131, 0xff );
}


/**
 * Initialize the lcd
 */
void lcd_init()
{
    enable_lcd();

    setPin( LCD_PORT, LCD_RST, 0 );
    setPin( LCD_PORT, LCD_RST, 1 );
    ROM_SysCtlDelay( 500 );

    spi_command( SLEEPOUT );
    spi_command( BSTRON );
    spi_command( COLMOD );

    spi_command( MADCTL );
    spi_data( 0xC0 );

    spi_command( SETCON );
    spi_data( 0x40 );
    spi_command( DISPON );
    setPin( LCD_PORT, LCD_CS, 0 );

    lcd_clear();
}


/**
 * Fill a box on the lcd
 *
 * @param  sx     Start X
 * @param  sy     Start Y
 * @param  ex     End X
 * @param  ey     End Y
 * @param  color  Color
 */
void lcd_box( char sx, char sy, char ex, char ey, char color )
{
    spi_command( CASET );
    spi_data( sx );
    spi_data( ex );

    spi_command( PASET );
    spi_data( sy );
    spi_data( ey );

    spi_command( RAMWR );
    int len = ( ( ex - sx ) * ( ey - sy ) ) * 2;

    for ( int i = 0; i < len; i++ )
    {
        spi_data( color );
    }
}
