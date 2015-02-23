#include <xc.h>
#define _XTAL_FREQ 32000000                  // Fosc  frequency for _delay()  library
//
// PIC16F1829 Configuration Bit Settings
//

// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable (PWRT enabled)
#pragma config MCLRE = OFF      // MCLR Pin Function Select (MCLR/VPP pin function is digital input)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Memory Code Protection (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable (Brown-out Reset disabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = ON        // Internal/External Switchover (Internal/External Switchover mode is enabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is disabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config PLLEN = ON       // PLL Enable (4x PLL enabled)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LVP = ON         // Low-Voltage Programming Enable (Low-voltage programming enabled)


#include <stdint.h>
#include <stdlib.h>


//
//
//          +-------V------+
//      +5 1|VDD        VSS|20 GND
//    Led0 2|RA5    DAT/RA0|19 Led3
//     Pot 3|RA4    CLK/RA1|18 Led4
//  Button 4|MCLR/RA3   RA2|17 Led5
//    Led1 5|RC5        RC0|16 Led6
//    Led2 6|RC4        RC1|15 Led7
//   Led14 7|RC3        RC2|14 Led8
//   Led15 8|RC6        RB4|13 Led9
//   Led12 9|RC7        RB5|12 Led10
//  Led13 10|RB7        RB6|11 Led11
//          +--------------+
//            PIC16F1829
//


// LED0  LED1  LED2  LED3       A5 C5 C4 A0
// LED4  LED5  LED6  LED7       A1 A2 C0 C1
// LED8  LED9  LED10 LED11      C2 B4 B5 B6
// LED12 LED13 LED14 LED15      C7 B7 C3 C6





void main(void) {
    int dly;
    uint8_t led;

    TRISA=0x00;
    TRISB=0x00;
    TRISC=0x00;

    LATA=0x00;
    LATB=0x00;
    LATC=0x00;

    OSCCON=0b11110000;  // PLL ENABLE, 8/32 MHZ, OSC BY CONFIG-1



    for (;;) {
        for (led=0; led<16; led++) {
            LATA=0x00;
            LATB=0x00;
            LATC=0x00;
            for (dly=0; dly<1; dly++) __delay_ms(10);

            switch (rand()&0x0F) {
                case  0: LATAbits.LATA5=1; break;
                case  1: LATCbits.LATC5=1; break;
                case  2: LATCbits.LATC4=1; break;
                case  3: LATAbits.LATA0=1; break;
                case  4: LATAbits.LATA1=1; break;
                case  5: LATAbits.LATA2=1; break;
                case  6: LATCbits.LATC0=1; break;
                case  7: LATCbits.LATC1=1; break;
                case  8: LATCbits.LATC2=1; break;
                case  9: LATBbits.LATB4=1; break;
                case 10: LATBbits.LATB5=1; break;
                case 11: LATBbits.LATB6=1; break;
                case 12: LATCbits.LATC7=1; break;
                case 13: LATBbits.LATB7=1; break;
                case 14: LATCbits.LATC3=1; break;
                case 15: LATCbits.LATC6=1; break;
            }
//            __delay_ms(1);
            __delay_us(1);
        }
    }
//    LATAbits.LATA0=1;   // LED3
//    LATAbits.LATA1=1;   // LED4
//    LATAbits.LATA2=1;   // LED5
//    LATAbits.LATA5=1;   // LED0

//    LATBbits.LATB4=1;   // LED9
//    LATBbits.LATB5=1;   // LED10
//    LATBbits.LATB6=1;   // LED11
//    LATBbits.LATB7=1;   // LED13

//    LATCbits.LATC0=1;   // LED6
//    LATCbits.LATC1=1;   // LED7
//    LATCbits.LATC2=1;   // LED8
//    LATCbits.LATC3=1;   // LED14
//    LATCbits.LATC4=1;   // LED2 (affects A0/LED3)
//    LATCbits.LATC5=1;   // LED1
//    LATCbits.LATC6=1;   // LED15
//    LATCbits.LATC7=1;   // LED12

    for (;;);
}

