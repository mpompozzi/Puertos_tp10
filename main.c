/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: maga
 *
 * Created on May 20, 2020, 12:22 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*
 * 
 */
int main(void) 
{

typedef union
{
    uint16_t portD;
    struct
    {
        uint8_t portA;
        uint8_t partB;
    }
    puerto16_t port_d;
    
}puertos_t;

puertos_t puerto16;


    return 0;
}


