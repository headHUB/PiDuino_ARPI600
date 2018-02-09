#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include "bcm2835_registers.h"

#define NOT_A_PIN 0
#define NOT_A_PORT 0
#define NOT_AN_INTERRUPT -1

#define EXTERNAL_NUM_INTERRUPTS     32
#define NUM_DIGITAL_PINS            32
#define NUM_ANALOG_INPUTS           10

#define analogInputToDigitalPin(p)  (-1)
#define analogInPinToBit(p)         (p)

#define digitalPinToPort(p)         (((p)<32)?0:1)
#define digitalPinToBitMask(p)      (1 << p)
#define portOutputRegister(p)       ((volatile uint32_t *)((p)?&GPSET1:&GPSET0))
#define portModeRegister(p)         ((volatile uint32_t *)((p)?&GPSET1:&GPSET0))

#define digitalPinHasPWM(p)         ((p) == 12 || (p) == 13 || (p) == 18 || (p) == 19)
#define digitalPinToInterrupt(p)    (p)
#define digitalPinToTimer(p)        ((p==12||p==18)?0:(p==13||p==19)?1:-1)

//*portModeRegister(digitalPinToPort(ETHERNET_SHIELD_SPI_CS)) |= digitalPinToBitMask(ETHERNET_SHIELD_SPI_CS);

// A/B - 17 GPIO | A+/B+/2/Zero - 28 GPIO
//                                    RX, TX, D2, D3, D4, D5, D6, D7, D8, D9, D10, D11, D12, D13, A0, A1, A2, A3, A4, A5, SDA, SCL, SCK, MISO, MOSI, RST
//const uint8_t piToArduinoB[26] =  { 15, 14, 4,  18, 7,  22, 23, 24, 25, 17, 8,   10,  9,   11,  28, 29, 30, 31, 2,  3,  2,   3,   11,  9,    10,   27  };
//const uint8_t piToArduinoBP[26] = { 15, 14, 4,  18, 7,  22, 23, 24, 25, 17, 8,   12,  16,  13,  5,  19, 20, 21, 6,  26, 2,   3,   11,  9,    10,   27  };
					//		BCM#   PIN#		2ND Function  WiringPi
static const uint8_t ID_SD = 19; //pin 27 	SDA.1			30
static const uint8_t ID_SC = 18; //pin 28   SDA.1			31
static const uint8_t SDA   =  2; //pin 3	SDA.0			8
static const uint8_t SCL   =  3; //pin 5    SCL.0           9
static const uint8_t D0	   = 14; //pin 10	RxD3			16
static const uint8_t D1	   = 13; //pin 8	TxD3			15
static const uint8_t D2	   =  1; //pin 11	RxD2			0
static const uint8_t D3    =110; //pin 12	GPIO.1			1
static const uint8_t D4    =  0; //pin 13	TxD2			2
static const uint8_t D5    =  3; //pin 15 	CTS2   			3
static const uint8_t D6    = 68; //pin 16 	GPIO.4			4
static const uint8_t D7    = 71; //pin 18	GPIO.5			5		
static const uint8_t D8    =  2; //pin 22	RTS2			6
static const uint8_t D9    =  6; //pin 7	GPIO.7			7
static const uint8_t SS1   = 21; //pin 26 	GPIO.11 		11
static const uint8_t SS    = 67; //pin 24	SPI_CE0_N		8
static const uint8_t D10   = 67; //pin 24	SPI_CE0_N		8
static const uint8_t D11   = 64; //pin 19   MOSI            12
static const uint8_t MOSI  = 64; //pin 19   MOSI			12
static const uint8_t D12   = 65; //pin 21   MISO			13
static const uint8_t MISO  = 65; //pin 21	MISO			13
static const uint8_t D13   = 66; //pin 23	SCLK			14
static const uint8_t SCK   = 66; //pin 23   SCLK			14	
static const uint8_t PWM00 =200; //pin 32   RTS1			26
static const uint8_t PWM01 =  9; //pin 33 	GPIO.23			23
static const uint8_t TX    = 13; //pin 8	TxD3			15
static const uint8_t RX    = 14; //pin 10	RxD3			14
//static const uint8_t D16 = 16 ;//pin 36 //B+
//static const uint8_t D17 = 17;//pin 11
static const uint8_t PWM10 = 18;//pin 12        //PCM_CLK
static const uint8_t PWM11 = 19;//pin 35 //B+   //PCM_FS
//static const uint8_t D20 = 20;//pin 38 //B+   //PCM_DIN
//static const uint8_t D21 = 21;//pin 40 //B+   //PCM_DOUT
//static const uint8_t D22 = 22;//pin 15
//static const uint8_t D23 = 23;//pin 16
//static const uint8_t D24 = 24;//pin 18
//static const uint8_t D25 = 25;//pin 22
//static const uint8_t D26 = 26;//pin 37 //B+
//static const uint8_t D27 = 27;//pin 13
//static const uint8_t D28 = 28;//pin  //A/B    //PCM_CLK  //ID_SD
//static const uint8_t D29 = 29;//pin  //A/B    //PCM_FS   //ID_SC
//static const uint8_t D30 = 30;//pin  //A/B    //PCM_DIN
//static const uint8_t D31 = 31;//pin  //A/B    //PCM_DOUT

#define SERIAL_PORT_USBVIRTUAL  Console
#define SERIAL_PORT_MONITOR     Console
#define SERIAL_PORT_HARDWARE    Serial

#endif
