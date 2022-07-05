#include <stdio.h>

#include "decode.h"
#include "stdlib.h"


void print_help();

int main(int argc, char** argv){
    
    if(argc == 1){
        print_help();
        return 0;
    }

    long int value = strtoll(argv[1], NULL, 0);

    if(value == 0){
        print_help();
        return 0;
    }


    printf("%ld\n", value);
}


void print_help(){
    printf("Utility for converting given value into riscv instruction\n");
    printf("Usage riscv_decoder [val]\n");
    printf("Where val - is riscv instruction\n");

}