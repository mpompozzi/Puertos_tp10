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
#include "PortControl.h"

/*
 * 
 */
int main(void) 
{
    bitSet(2,'a');
    bitClr(2,'a');
    bitSet(4,'a');
    bitSet(2,'b');
    bitSet(2,'d');
    return (0);
}


