/**
    PRACTICA #1
    
    EQUIPO:
    CLAUDIO GAEL RODRIGUEZ VEGA #221943339
    ANGEL DE JESUS DOMINGO CABRERA #218483572
    JOSE EMANUEL GARIBALDO PADILLA #218579952
*/

#include <stdio.h>
#include <xc.h>

// Definiciones del PIC16F887
#define _XTAL_FREQ 4000000  // Frecuencia de cristal del PIC (8MHz)

// Configuración del PIC
#pragma config FOSC = HS    // Oscilador HS
#pragma config WDTE = OFF   // Watchdog Timer deshabilitado
#pragma config PWRTE = OFF  // Power-up Timer deshabilitado
#pragma config BOREN = OFF  // Brown-out Reset deshabilitado
#pragma config LVP = OFF    // Low-Voltage Programming deshabilitado
#pragma config CPD = OFF    // Data Code Protection deshabilitado
#pragma config WRT = OFF    // Write Protection deshabilitado
#pragma config CP = OFF     // Code Protection deshabilitado

// Función de inicialización
void init() {
    ANSEL = 0x00;  // Configura todos los pines analógicos como pines digitales
    TRISA = 0xFF;  // Puerto A como entradas
    TRISB = 0x00;  // Puerto B como salidas
}

// Función principal
void main(void) {
    init();  // Inicializar el PIC

    // Bucle infinito
    while (1) {
        PORTB = PORTA;
    }

    return;
}
