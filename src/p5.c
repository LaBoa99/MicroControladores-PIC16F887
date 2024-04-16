/**
    PRACTICA #4

    EQUIPO:
    CLAUDIO GAEL RODRIGUEZ VEGA #221943339
    ANGEL DE JESUS DOMINGO CABRERA #218483572
    JOSE EMANUEL GARIBALDO PADILLA #218579952
*/

// Definiciones del PIC16F887
#define _XTAL_FREQ 4000000  // Frecuencia de cristal del PIC (4MHz)

// Configuraciï¿½n del PIC
#pragma config FOSC = INTRC_NOCLKOUT  // Oscilador HS
#pragma config WDTE = OFF             // Watchdog Timer deshabilitado
#pragma config PWRTE = OFF            // Power-up Timer deshabilitado
#pragma config BOREN = OFF            // Brown-out Reset deshabilitado
#pragma config LVP = OFF              // Low-Voltage Programming deshabilitado
#pragma config CPD = OFF              // Data Code Protection deshabilitado
#pragma config WRT = OFF              // Write Protection deshabilitado
#pragma config CP = OFF               // Code Protection deshabilitado

#include <xc.h>

void setup() {
    ANSEL = 0x00;  // Configura todos los pines analï¿½gicos como pines digitales
    ANSELH = 0x00;
    TRISA = 0xFF;  // Puerto A como entradas
    TRISB = 0x00;  // Puerto B como salidas
}

typedef enum  {
    ZERO = 0x00,
    ONE = 0x1,
    TWO = 0x2,
    THREE = 0x3,
    FOUR = 0x4,
    FIVE = 0x5,
    SIX = 0x6,
    SEVEN = 0x7,
    EIGHT = 0x8,
    NINE = 0x9,
    A = 0xA,
    B = 0xB,
    C = 0xC,
    D = 0xD,
    E = 0xE,
    F = 0xF,
} BIN_KEYS;

typedef enum  {
    DISPLAY_ZERO = 0x3F,
    DISPLAY_ONE = 0x6,
    DISPLAY_TWO = 0x5B,
    DISPLAY_THREE = 0x4F,
    DISPLAY_FOUR = 0x66,
    DISPLAY_FIVE = 0x6D,
    DISPLAY_SIX = 0x7D,
    DISPLAY_SEVEN = 0x7,
    DISPLAY_EIGHT = 0x7F,
    DISPLAY_NINE = 0x6F,
    DISPLAY_A = 0x77,
    DISPLAY_B = 0x7C,
    DISPLAY_C = 0x39,
    DISPLAY_D = 0x5E,
    DISPLAY_E = 0x79,
    DISPLAY_F = 0x71,
    DISPLAY_DEFAULT = 0x76,
} DISPLAY_VALUES;

void main(void) {
    setup();

    BIN_KEYS bits;
    DISPLAY_VALUES display = DISPLAY_DEFAULT;

    while (1) {
        bits = (BIN_KEYS)(PORTA ^ 0x0F) & 0x0F;
        switch (bits) {
            case ZERO:
                display = DISPLAY_ZERO;
                break;
            case ONE:
                display = DISPLAY_ONE;
                break;
            case TWO:
                display = DISPLAY_TWO;
                break;
            case THREE:
                display = DISPLAY_THREE;
                break;
            case FOUR:
                display = DISPLAY_FOUR;
                break;
            case FIVE:
                display = DISPLAY_FIVE;
                break;
            case SIX:
                display = DISPLAY_SIX;
                break;
            case SEVEN:
                display = DISPLAY_SEVEN;
                break;
            case EIGHT:
                display = DISPLAY_EIGHT;
                break;
            case NINE:
                display = DISPLAY_NINE;
                break;
            case A:
                display = DISPLAY_A;
                break;
            case B:
                display = DISPLAY_B;
                break;
            case C:
                display = DISPLAY_C;
                break;
            case D:
                display = DISPLAY_D;
                break;
            case E:
                display = DISPLAY_E;
                break;
            case F:
                display = DISPLAY_F;
                break;
            default:
                display = DISPLAY_DEFAULT;
                break;
        }
        PORTB = display;
        __delay_ms(10);
    }
    return;
}
