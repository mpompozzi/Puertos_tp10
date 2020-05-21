/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void bitSet (int bit, puertos_t *);
void bitClr (int bit, puertos_t *);
void bitGet (int bit, puertos_t *);
void bitToggle (int bit, puertos_t *);
void maskOn (int bit, puertos_t *);
void maskOff (int bit, puertos_t *);
void maskToggle (int bit, puertos_t *);

typedef union
{
    uint16_t portD;
    struct
    {
        uint8_t portA;
        uint8_t partB;
    }
    uint16_t portD;
    
}puertos_t;


void bitSet (int bit,char puerto, puertos_t *)
{
    if ((puerto== 'd') && (bit>=0) && (bit<=15))
    {
        uint16_t mask 0x0001; //??
        mask <<= bit;
        puertos_t.portD |= mask;
    }
    else if ((bit>=0) && (bit<=7) && ((puero=='a')||(puerto=='b')))
    {
        uint8_t mask 0x01;
        mask<<= bit;
        if (puerto=='a')
        {
            puertos_t.portA |= mask;
        }
        else
        {
            puertos_t.portB |= mask;
        }
    }
    else
    {
        printf("Datos mal ingresados\n");
    }
}

void bitClr (int bit, puertos_t *)
{
    uint16_t mask 0x0001; //??
    mask <<= bit;
    mask ~= mask;
    puertos_t.portD &= mask;
}

void bitGet (int bit, puertos_t *)
{
    uint16_t mask 0x0001; //??
    mask <<= bit;
    mask ~= mask;
    puertos_t.portD &= mask;
}
void bitToggle (int bit, puertos_t *);
void maskOn (int bit, puertos_t *);
void maskOff (int bit, puertos_t *);
void maskToggle (int bit, puertos_t *);