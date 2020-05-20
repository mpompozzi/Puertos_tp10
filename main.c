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
    typedef struct
    {
        uint8_t b0   :1;
        uint8_t b1   :1;
        uint8_t b2   :1;
        uint8_t b3   :1;
        uint8_t b4   :1;
        uint8_t b5   :1;
        uint8_t b6   :1;
        uint8_t b7   :1;         
    }port_t;
    
    typedef struct
    {   
        uint16_t b0   :1;
        uint16_t b1   :1;
        uint16_t b2   :1;
        uint16_t b3   :1;
        uint16_t b4   :1;
        uint16_t b5   :1;
        uint16_t b6   :1;
        uint16_t b7   :1;
        uint16_t b8   :1;
        uint16_t b9   :1;
        uint16_t b10  :1;
        uint16_t b11  :1;
        uint16_t b12  :1;
        uint16_t b13  :1;
        uint16_t b14  :1;
        uint16_t b15  :1;
    }puerto16_t;

typedef union
{
    struct
    {
        port_t port_a;
        port_t port_b;
    }
    puerto16_t port_d;
}puertos_t;

    return 0;
}

