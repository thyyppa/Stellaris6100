
#define LCD_PORT GPIO_PORTA_BASE
#define LCD_PERIPHERAL SYSCTL_PERIPH_GPIOA

#define LCD_CS GPIO_PIN_2
#define LCD_SCL GPIO_PIN_3
#define LCD_SI GPIO_PIN_4
#define LCD_RST GPIO_PIN_5

#define NOP       0x00 /* No operation; Data: none */
#define SWRESET   0x01 /* Software reset ; Data: none */
#define BSTROFF   0x02 /* Booster voltage off; Data: none */
#define BSTRON    0x03 /* Booster voltage on; Data: none */
#define RDDIDIF   0x04 /* Read display identification; Data: none */
#define RDDST     0x09 /* Read display status; Data: none */
#define SLEEPIN   0x10 /* Sleep_IN; Data: none */
#define SLEEPOUT  0x11 /* Sleep_OUT; Data: none */
#define PTLON     0x12 /* Partial mode on; Data: none */
#define NORON     0x13 /* Normal Display mode on; Data: none */
#define INVOFF    0x20 /* Display inversion off; Data: none */
#define INVON     0x21 /* Display inversion on; Data: none */
#define DALO      0x22 /* All pixel off; Data: none */
#define DAL       0x23 /* All pixel on; Data: none */
#define SETCON    0x25 /* Set contrast; Data: (1) contrast */
#define DISPOFF   0x28 /* Display off; Data: none */
#define DISPON    0x29 /* Display on; Data: none */
#define CASET     0x2a /* Column address set; Data: (1) X start (2) X end  */
#define PASET     0x2b /* Page address set Data: (1) Y start (2) Y end */
#define RAMWR     0x2c /* Memory write; Data: (1) write data */
#define RGBSET    0x2d /* Colour set; Data: (1-8) red tones, (9-16) green tones, (17-20) blue tones */
#define PTLAR     0x30 /* Partial area; Data: (1) start address (2) end address */
#define VSCRDEF   0x33 /* Vertical scroll definition; Data: (1) top fixed, (2) scrol area, (3) bottom fixed */
#define TEOFF     0x34 /* Tearing line off; Data: none */
#define TEON      0x35 /* Tearing line on;  Data: (1) don't care */
#define MADCTL    0x36 /* Memory data access control; Data: (1) access control settings */
#define SEP       0x37 /* Set Scroll Entry Point; Data: (1) scroll entry point */
#define IDMOFF    0x38 /* Idle mode off; Data: none */
#define IDMON     0x39 /* Idle mode on; Data: none */
#define COLMOD    0x3a /* Interface pixel format; Data: (1) color interface format */
#define SETVOP    0xb0 /* Set VOP; Data: (1) VOP5-8 (2) VOP0-4 */
#define BRS       0xb4 /* Bottom Row Swap; Data: none */
#define TRS       0xb6 /* Top Row Swap; Data: none */
#define FINV      0xb9 /* Super Frame INVersion; Data: none */
#define DOR       0xba /* Data ORder; Data: none */
#define TCDFE     0xbd /* Enable/disable DF temp comp; Data: none */
#define TCVOPE    0xbf /* Enable or disable VOP temp comp; Data: none */
#define EC        0xc0 /* Internal or external oscillator; Data: none */
#define SETMUL    0xc2 /* Set multiplication factor; Data: (1) Multiplication factor */
#define TCVOPAB   0xc3 /* Set TCVOP slopes A and B; Data: (1) SLB and SLA */
#define TCVOPCD   0xc4 /* Set TCVOP slopes C and D; Data: (1) SLD and SLC */
#define TCDF      0xc5 /* Set divider frequency; Data: Divider factor in region (1) A (2) B (3) C (4) D */
#define DF8COLOR  0xc6 /* Set divider frequency 8-colour mode; Data: (1) DF80-6 */
#define SETBS     0xc7 /* Set bias system; Data: (1) Bias systems */
#define RDTEMP    0xc8 /* Temperature read back; Data: none */
#define NLI       0xc9 /* N-Line Inversion; Data: (1) NLI time slots invervsion */
#define RDID1     0xda /* Read ID1; Data: none */
#define RDID2     0xdb /* Read ID2; Data: none */
#define RDID3     0xdc /* Read ID3; Data: none */
#define SFD       0xef /* Select factory defaults; Data: none */
#define ECM       0xf0 /* Enter Calibration mode; Data: (1) Calibration control settings */
#define OTPSHTIN  0xf1 /* Shift data in OTP shift registers; Data: Any number of bytes */

/**
 * Set up ports and pins
 */
void enable_lcd();


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
 * Output data to spi
 *
 * @param  data  Byte to output
 * @param  type  Type of data (0 = command, 1 = data)
 */
void spi_push( char data, char type );


/**
 * Initialize LCD
 */
void lcd_init();


/**
 * Fill LCD with white
 */
void lcd_clear();


/**
 * Draw a filled box on the lcd
 *
 * @param  sx     Start X
 * @param  sy     Start Y
 * @param  ex     End X
 * @param  ey     End Y
 * @param  color  Color
 */
void lcd_box( char sx, char sy, char ex, char ey, char color );
