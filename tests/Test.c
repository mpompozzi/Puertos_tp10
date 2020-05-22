/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Test.c
 * Author: fede
 *
 * Created on May 22, 2020, 6:59 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "PortControl.h"

/*
 * Simple C Test Suite
 */
int tTotal= 0;
int passed = 0;
int fails = 0;

void test_states(int stateEsp, int func); //CHECK ESTADOS
void test_masks();

int main(void) {
    
    printf("Corriendo pruebas en PortControl.c ...");
    
    test_states(1,bitSet(0,A));
    test_states(1,bitSet(1,A));
    test_states(1,bitSet(2,A));
    test_states(1,bitSet(3,A));
    test_states(1,bitSet(4,A));
    test_states(1,bitSet(5,A));
    test_states(1,bitSet(6,A));
    test_states(1,bitSet(7,A));
    
    test_states(1,bitSet(0,B));
    test_states(1,bitSet(1,B));
    test_states(1,bitSet(2,B));
    test_states(1,bitSet(3,B));
    test_states(1,bitSet(4,B));
    test_states(1,bitSet(5,B));
    test_states(1,bitSet(6,B));
    test_states(1,bitSet(7,B));
    
    
    
    

    return 0;
}
void test_states(int stateEsp, int func){

    
    
}
