#include <pic.h>

__CONFIG (INTOSC & WDTDIS & MCLRDIS);

#define LEDX0 GP0
#define LEDX1 GP1
#define LEDX2 GP2

#define LEDY0 GP5
#define LEDY1 GP4

#define DT 80

void delay(unsigned t)
{
  unsigned i;
  for (i=0; i<t; i++)
  {
    TMR0=0;
    //PSA: 0
    //PS0, PS1, PS2: 1
    OPTION=0xC5;
    while(TMR0 != 100);
  }
}

void main(void)
{
  TRIS=0xff;
  delay(20);
  TRIS=0x00;


  ADCON0=0;
  CM1CON0=0;

/*
GPIO:
  7 -
  6 -
  5 - upper
  4 - lower
  3 - button
  2 - x1
  1 - x2
  0 - x3
*/

  while(1)
  {
    TRIS=0b11011011;
    GPIO=0b00100000;
    delay(DT); //1

    TRIS=0b11011011;
    GPIO=0b00000100;
    delay(DT); //2

    TRIS=0b11101011;
    GPIO=0b00010000;
    delay(DT); //7

    TRIS=0b11101011;
    GPIO=0b00000100;
    delay(DT); //8

    TRIS=0b11011110;
    GPIO=0b00000001;
    delay(DT); //6
    
    TRIS=0b11011110;
    GPIO=0b00100000;
    delay(DT); //5

    TRIS=0b11101110;
    GPIO=0b00000001;
    delay(DT); //12

    TRIS=0b11101110;
    GPIO=0b00010000;
    delay(DT); //11


//    TRIS=0b11011101;
//    GPIO=0b00100000;
//    delay(DT); //3
//
//    TRIS=0b11011101;
//    GPIO=0b00000010;
//    delay(DT); //4
//
//    TRIS=0b11101101;
//    GPIO=0b00010000;
//    delay(DT); //9
//
//    TRIS=0b11101101;
//    GPIO=0b00000010;
//    delay(DT); //10

  }

}
