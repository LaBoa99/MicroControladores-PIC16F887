/**
    PRACTICA #8

    EQUIPO:
    CLAUDIO GAEL RODRIGUEZ VEGA #221943339
    ANGEL DE JESUS DOMINGO CABRERA #218483572
    JOSE EMANUEL GARIBALDO PADILLA #218579952
*/

// Definiciones del PIC16F887
#define _XTAL_FREQ 4000000  // Frecuencia de cristal del PIC (4MHz)

// Configuración del PIC
#pragma config FOSC = INTRC_NOCLKOUT  // Oscilador HS
#pragma config WDTE = OFF             // Watchdog Timer deshabilitado
#pragma config PWRTE = OFF            // Power-up Timer deshabilitado
#pragma config BOREN = OFF            // Brown-out Reset deshabilitado
#pragma config LVP = OFF              // Low-Voltage Programming deshabilitado
#pragma config CPD = OFF              // Data Code Protection deshabilitado
#pragma config WRT = OFF              // Write Protection deshabilitado
#pragma config CP = OFF               // Code Protection deshabilitado


// Pins to use
#include <xc.h>
#include <stdbool.h>

#define PIN_SWITCH PORTAbits.RA0

void setup(){
    ANSEL = 0x00;  // Configura todos los pines analógicos como pines digitales
    ANSELH = 0x00;
    
    TRISAbits.TRISA0 = 1;  // Puerto A como entradas
    TRISB = 0x00;
}

void main(void){
    
    setup();
    uint8_t snake = 0x01;
    bool isBack = false;
    while(1){
        if(PIN_SWITCH){
            PORTB = 0x00;
            continue;
        }
        
        PORTB = snake;
        snake = isBack ? snake >> 1 : snake << 1;
        isBack = (snake == 0x01) ? false : (snake == 0x40) ? true : isBack;
        
        __delay_ms(500);

    }
    
    return;
}
