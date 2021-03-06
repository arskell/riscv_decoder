#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "decode.h"
#include "decode/instr_fmt.h"


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

    union Instruction32 instr;
    memcpy(&instr, &value, 4);

    
    char buffer[255];

    printf("As reg instruction:\r\n");
    fmt_reg(buffer, convert_to_reg(instr));
    puts(buffer);

    printf("\r\nAs imm instruction:\r\n");
    fmt_imm(buffer, convert_to_imm(instr));
    puts(buffer);

    printf("\r\nAs upper imm instruction:\r\n");
    fmt_up_imm(buffer, convert_to_upimm(instr));
    puts(buffer);

    printf("\r\nAs store instruction:\r\n");
    fmt_store(buffer, convert_to_store(instr));
    puts(buffer);


    printf("\r\nAs branch instruction:\r\n");
    fmt_branch(buffer, convert_to_branch(instr));
    puts(buffer);

    printf("\r\nAs jump instruction:\r\n");
    fmt_jump(buffer, convert_to_jump(instr));
    puts(buffer);

}


void print_help(){
    printf("Utility for converting given value into riscv instruction\n");
    printf("Usage riscv_decoder [val]\n");
    printf("Val - is riscv instruction\n");

}