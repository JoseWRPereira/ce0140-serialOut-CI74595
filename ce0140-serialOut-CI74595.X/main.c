/*
 * File:   main.c
 * Author: curtaeletronica
 *
 * Created on 30 de Setembro de 2019, 17:39
 * 
 * IDE:         MPLAB X IDE v3.15
 * Compiler:    XC8 v1.45
 * OS:          Deepin 15.11 X86_64
 * Kernel:      4.15.0-30deepin-generic
 * 
 * Objetivo: 
 *      Apresentar mensagens em display LCD atrav�s de barramento de 8 vias.
 * 
 * Pinos    |n�     |Conex�o
 *  VDD     |11,32  | Alimenta��o (Vcc/+5V)
 *  VSS     |12,31  | Alimenta��o (GND/0V)
 * 
*/

//***************** Bibliotecas
#include <xc.h>
#include "config.h"
#include "serialOut.h"

//***************** Programa Principal
void main(void)
{
    initSerialOut();
    while( 1 )                      // La�o de repeti��o infinita.
    {
    }
    return;
}
//***************** Fim do Programa Principal
