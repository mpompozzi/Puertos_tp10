
/*        Tabla de valores
 
Para A y B:
 [128] [64] [32] [16] [8] [4] [2] [1]
   b7   b6   b5   b4   b3  b2  b1  b0

Para D:
[32768] [16384] [8192] [4096] [2048] [1024] [512] [256] [128] [64] [32] [16] [8] [4] [2] [1]
  b15     b14     b13    b12    b11    b10    b9    b8    b7   b6   b5   b4   b3  b2  b1  b0

*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "PortControl.h"

#define ON  1
#define OFF 0

int tTotal= 0;
int passed = 0;
int fails = 0;

void test_out(int esperado, int actual);

int main(void) {
    
    printf("Corriendo pruebas en PortControl.c ...\n");

//***********************************************************************************
//Testeo todos los bits con funciones bitSet y bitCLr encendiendo y apagando los bits
//***********************************************************************************

    test_out(1,bitSet(0,'A'));
    test_out(0,bitClr(0,'A'));

    test_out(4,bitSet(2,'A'));
    test_out(0,bitClr(2,'A'));

    test_out(16,bitSet(4,'A'));
    test_out(0,bitClr(4,'A'));

    test_out(64,bitSet(6,'A'));
    test_out(0,bitClr(6,'A'));

    test_out(2,bitSet(1,'B'));
    test_out(0,bitClr(1,'B'));

    test_out(8,bitSet(3,'B'));
    test_out(0,bitClr(3,'B'));

    test_out(32,bitSet(5,'B'));
    test_out(0,bitClr(5,'B'));

    test_out(128,bitSet(7,'B'));
    test_out(0,bitClr(7,'B'));

    test_out(512,bitSet(9,'D'));
    test_out(0,bitClr(9,'D'));

    test_out(2048,bitSet(11,'D'));
    test_out(0,bitClr(11,'D'));

    test_out(8192,bitSet(13,'D'));
    test_out(0,bitClr(13,'D'));

    test_out(32768,bitSet(15,'D'));
    test_out(0,bitClr(15,'D'));

    printf("Prueba de funciones bitSet y bitClr completa con %i errores\n",fails);

//***********************************************************************************
//Testeo estados con la funcion bitGet asignando valores con la funcion bitSet 
//***********************************************************************************

    bitSet(0,'A');
    test_out(ON,bitGet(0,'A'));
    bitSet(2,'A');
    test_out(ON,bitGet(2,'A')); 
    bitSet(4,'A');
    test_out(ON,bitGet(4,'A')); 
    bitSet(6,'A');
    test_out(ON,bitGet(6,'A')); 

    bitSet(1,'B');
    test_out(ON,bitGet(1,'B')); 
    bitSet(3,'B');
    test_out(ON,bitGet(3,'B')); 
    bitSet(5,'B');
    test_out(ON,bitGet(5,'B')); 
    bitSet(7,'B');
    test_out(ON,bitGet(7,'B')); 

    bitSet(9,'D');
    test_out(ON,bitGet(9,'D')); 
    bitSet(11,'D');
    test_out(ON,bitGet(11,'D')); 
    bitSet(13,'D');
    test_out(ON,bitGet(13,'D')); 
    bitSet(15,'D');
    test_out(ON,bitGet(15,'D')); 

    printf("Prueba de funcion bitGet completa con %i errores\n",fails);

    for(int i = 0;i <=7; i++){  //Pongo todos los bits en 0

        bitClr(i,'A');
        bitClr(i,'B');
    }

//***********************************************************************************
//Testeo funcion bitToggle 
//***********************************************************************************
    for(int i = 0;i <=7; i++){  //Pongo todos los bits en 1

        bitSet(i,'A');
        bitSet(i,'B');
    }

    test_out(254, bitToggle(0,'A'));    //254= 255-2^x (x=0)
    test_out(255, bitToggle(0,'A'));    //Devuelvo el valor a 0
    test_out(251, bitToggle(2,'A'));    //251= 255-2^x (x=2)
    test_out(255, bitToggle(2,'A'));    //Devuelvo el valor a 0
    test_out(239, bitToggle(4,'A'));    //239= 255-2^x (x=4)
    test_out(255, bitToggle(4,'A'));    //Devuelvo el valor a 0
    test_out(191, bitToggle(6,'A'));    //191= 255-2^x (x=6)
    test_out(255, bitToggle(6,'A'));    //Devuelvo el valor a 0

    test_out(253, bitToggle(1,'B'));
    test_out(255, bitToggle(1,'B'));
    test_out(247, bitToggle(3,'B'));
    test_out(255, bitToggle(3,'B'));
    test_out(223, bitToggle(5,'B'));
    test_out(255, bitToggle(5,'B'));
    test_out(127, bitToggle(7,'B'));
    test_out(255, bitToggle(7,'B'));

    test_out(65023, bitToggle(9,'D'));  //65023= ((2^16)-1)-2^x  (x=9)
    test_out(65535, bitToggle(9,'D'));  //Devuelvo el valor a 0
    test_out(63487, bitToggle(11,'D')); //63487= ((2^16)-1)-2^x  (x=11)
    test_out(65535, bitToggle(11,'D')); //Devuelvo el valor a 0
    test_out(57343, bitToggle(13,'D')); //57343= ((2^16)-1)-2^x  (x=13)
    test_out(65535, bitToggle(13,'D')); //Devuelvo el valor a 0
    test_out(32767, bitToggle(15,'D')); //32767= ((2^16)-1)-2^x  (x=15)
    test_out(65535, bitToggle(15,'D')); //Devuelvo el valor a 0

    printf("Prueba de funcion bitToggle completa con %i errores\n",fails);

    for(int i = 0;i <=7; i++){  //Pongo todos los bits en 0

        bitClr(i,'A');
        bitClr(i,'B');
    }

//***********************************************************************************
//Testeo funcion maskOn y maskOff usando mascaras 0x55, 0xAA y 0xFEDE
//***********************************************************************************

    test_out(0x55,maskOn(0x55,'A'));
    test_out(0,maskOff(0x55,'A'));
    test_out(0xAA,maskOn(0xAA,'A'));
    test_out(0,maskOff(0xAA,'A'));

    test_out(0x55,maskOn(0x55,'B'));
    test_out(0,maskOff(0x55,'B'));
    test_out(0xAA,maskOn(0xAA,'B'));
    test_out(0,maskOff(0xAA,'B'));

    test_out(0xFEDE,maskOn(0xFEDE,'D'));
    test_out(0,maskOff(0xFEDE,'D'));
    test_out(0xAA,maskOn(0xAA,'D'));
    test_out(0,maskOff(0xAA,'D'));
    
    printf("Prueba de funcion maskOn y maskOff completa con %i errores\n",fails);

//***********************************************************************************
//Testeo funcion maskToggle usando mascaras 0x55, 0xAA , 0xFEDE, 0x5FE2 y 0xA13C
//***********************************************************************************

    test_out(0x55,maskToggle(0x55,'A'));
    test_out(0XFF,maskToggle(0xAA,'A'));
    test_out(0,maskToggle(0xFF,'A'));

    test_out(0x55,maskToggle(0x55,'B'));
    test_out(0XFF,maskToggle(0xAA,'B'));
    test_out(0,maskToggle(0xFF,'B'));

    test_out(0xFEDE,maskToggle(0xFEDE,'D'));
    test_out(0XA13C,maskToggle(0x5FE2,'D'));
    test_out(0,maskToggle(0xA13C,'D'));

    printf("Prueba de funcion maskToggle completa con %i errores\n",fails);

    printf("Pruebas:%i, Correctas:%i, Incorrectas:%i\n",tTotal,passed,fails);

    return 0;
}

void test_out(int esperado, int actual){

        tTotal++;

        if(esperado==actual){

            passed++;
        }

        else{

            fails++;
            printf("ERROR! Esperado:%i, Actual: %i\n",esperado,actual);

        }
}
