#include <math.h>
#include <pic16f887.h>
#include <stdio.h>
#include <stdlib.h>
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
        // Operacio XOR sobre puerto A
        PORTB = PORTA ^ 0xFF;
    }

    return;
}