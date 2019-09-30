/*
 * File:   serialOut.c
 * Author: curtaeletronica
 *
 * Created on 30 de Setembro de 2019, 17:42
 * 
 * Objetivo: 
 *      Camada de Abstração de Hardware:
 *          Interface com o CI 74595 (Shift Register).
 * 
 * Pinos    |nº     |Conexão
 * RE0      |8      | SHLD : Shift / Load
 * RE1      |9      | CLK : Clock
 * RE2      |10     | OUT
 */

//***************** Bibliotecas
#include <xc.h>
#include "config.h"


//***************** Interface com PORTs/Pinos
#define SERIALIO_ADDRS 0x009       // PORTE

//***************** Structs
typedef union
{
    struct
    {
        unsigned char SHLD:1;
        unsigned char CLK :1;
        unsigned char OUT :1;
    };
} SERIALIObits_t;

volatile SERIALIObits_t SERIALIO __at(SERIALIO_ADDRS);



/****************** Procedimento initSerialOut
 * Entrada: -
 * Retorno: -
 * Objetivo: Inicializar a interface com o CI 74595
 */
void initSerialOut( void )
{
//***************** Serial IO Shift/Load
    PORTEbits.RE0 = 0;
    ANSELbits.ANS5 = 0;
    TRISEbits.TRISE0 = 0;

// **************** Serial IO Clock
    PORTEbits.RE1 = 0;
    ANSELbits.ANS6 = 0;
    TRISEbits.TRISE1 = 0;

// **************** Serial IO Output
    PORTEbits.RE2 = 0;
    ANSELbits.ANS7 = 0;
    TRISEbits.TRISE2 = 0;

    SERIALIO.CLK = 0;
    SERIALIO.OUT = 0;
    SERIALIO.SHLD = 1;
    
}


/****************** Procedimento serialOut
 * Entrada: Dado a ser transmitido
 * Retorno: -
 * Objetivo: Enviar um dado d de forma serial via o registrador de 
 *          deslocamento 74595, que o converte em paralelo. 
 */
void serialOut( unsigned char d )
{
    unsigned char i = 0x80;

    SERIALIO.SHLD = 1;
    while( i )
    {
        SERIALIO.CLK = 0;
        if(d & i)
            SERIALIO.OUT = 1;
        else
            SERIALIO.OUT = 0;
        SERIALIO.CLK = 1;
        i >>= 1;
    }
    SERIALIO.SHLD = 0;
    SERIALIO.CLK = 0;
    SERIALIO.SHLD = 1;
}

