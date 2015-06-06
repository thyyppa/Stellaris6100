#define spi_command(i) spi_push( i, 0 )
#define spi_data(i) spi_push( i, 1 )

/**
 * Set a pin on a port to a value
 *
 * @param  port
 * @param  pin
 * @param  value
 */
void setPin( int port, int pin, char value );


/**
 * Tick the spi clock
 */
void spi_clock();


/**
 * Output data tp spi
 *
 * @param  data  Byte to output
 * @param  type  Type of data (0 = command, 1 = data)
 */
void spi_push( char data, char type );
