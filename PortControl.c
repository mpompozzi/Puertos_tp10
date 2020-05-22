/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>



typedef union
{
    uint16_t D;
    struct
    {
        uint8_t B;
        uint8_t A;
    };
    
    
}puerto_t;

static puerto_t port;


void bitSet (int bit,char puerto)
{
    if (((puerto== 'd')||(puerto=='D')) && (bit>=0) && (bit<=15))
    {
        uint16_t mask= 0x0001; 
        mask <<= bit;
        port.D |= mask;
    }
    else if ((bit>=0) && (bit<=7) && ((puerto=='b')||(puerto=='B')))
    {
        uint8_t mask= 0x01;
        mask<<= bit;
        port.B |= mask;
        
    }
    else if((bit>=0) && (bit<=7) && ((puerto=='a')||(puerto=='A')))
    {
        uint8_t mask= 0x01;
        mask<<= bit;
        port.A |= mask;
    }
    else
    {
        printf("Datos mal ingresados\n");
    }
}

void bitClr (int bit, char puerto)
{
    if (((puerto== 'd')||(puerto=='D')) && (bit>=0) && (bit<=15))
    {
        uint16_t mask= 0x0001; 
        mask <<= bit;
        port.D &= ~mask;
    }
    else if ((bit>=0) && (bit<=7) && ((puerto=='b')||(puerto=='B')))
    {
        uint8_t mask= 0x01;
        mask<<= bit;
        port.B &= ~mask;
        
    }
    else if((bit>=0) && (bit<=7) && ((puerto=='a')||(puerto=='A')))
    {
        uint8_t mask= 0x01;
        mask<<= bit;
        port.A &= ~mask;
    }
    else
    {
        printf("Datos mal ingresados\n");
    }
}

int bitGet (int bit, char puerto)
{
    
}

void bitToggle (int bit, char puerto)
{
    
}
void maskOn (int bit, char puerto)
{
    
}
void maskOff (int bit, char puerto)
{
    
}
void maskToggle (int bit, char puerto)
{
    
}