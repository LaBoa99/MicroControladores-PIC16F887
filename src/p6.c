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


// Pins to use
#include <xc.h>
#include <stdbool.h>

#define PIN_SWITCH  PORTAbits.RA0

void setup(){
    ANSEL = 0x00;  // Configura todos los pines analógicos como pines digitales
    ANSELH = 0x00;
    
    TRISAbits.TRISA0 = 1;  // Puerto A como entradas
    TRISCbits.TRISC0 = 0; // RC0 como salida
    TRISCbits.TRISC1 = 0; // RC1 como salida 
}

void main(void){
    
    setup();
    uint8_t leds = 0x01;
    while(1){
        // Si el switch está activo, apagamos ambos LEDs.
        if (PIN_SWITCH) {
            PORTC = 0x00;
            continue;
        }
        
        PORTC = leds = leds == 0x01 ? 0x02: 0x01;
        __delay_ms(500);

    }
    
    return;
}
