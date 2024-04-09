/**
    PRACTICA #4

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


#include <xc.h>

const uint8_t PASSWORD = 0b10101111;

void setup(){
    ANSEL = 0x00;  // Configura todos los pines analógicos como pines digitales
    ANSELH = 0x00;
    TRISA = 0xFF;  // Puerto A como entradas
    TRISB = 0x00;  // Puerto B como salidas
    TRISCbits.TRISC1 = 0x00; // RC1 como salida 
}

void main(void){
    
    setup();
    PORTB = PASSWORD; // Solo asignamos a portb una sola vez pues no se debe actualizar
    
    while(1){
        // Invertimos PORTA y comparamos con PASSWORD
        PORTCbits.RC1 = (PORTA ^ 0xFF) == PASSWORD;
        __delay_ms(10);
    }
    
    return;
}
