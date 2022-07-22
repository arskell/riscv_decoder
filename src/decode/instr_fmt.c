#include "instr_fmt.h"

#include <stdio.h>

void fmt_reg(char* str, struct Reg_Instruction32 instr){
    
    sprintf(str, "opcode: %d | rd: %d | funct3: %d | rs1: %d | rs2: %d | funct3: %d",
    instr.opcode, instr.rd, instr.funct3, instr.rs1, instr.rs2, instr.funct7);
}

void fmt_imm(char* str, struct Imm_Instruction32 instr){
    
    sprintf(str, "opcode: %d | rd: %d | funct3: %d | rs1: %d | imm: %d",
    instr.opcode, instr.rd, instr.funct3, instr.rs1, instr.imm);
}


void fmt_up_imm(char* str, struct UpImm_Instruction32 instr){
    
    sprintf(str, "opcode: %d | rd: %d | imm: %d (%d)",
    instr.opcode, instr.rd, instr.imm, instr.imm << 12);
}



void fmt_store(char* str, struct Store_Instruction32 instr){
    
    sprintf(str, "opcode: %d | funct3: %d | rs1: %d | rs2: %d | imm: %d",
    instr.opcode, instr.funct3, instr.rs1, instr.rs2, instr.imm.imm_data);
}


void fmt_branch(char* str, struct Branch_Instruction32 instr){
    
    sprintf(str, "opcode: %d | funct3: %d | rs1: %d | rs2: %d | imm: %d",
    instr.opcode, instr.funct3, instr.rs1, instr.rs2, instr.imm.imm_data);
}


void fmt_jump(char* str, struct Jump_Instruction32 instr){
    
    sprintf(str, "opcode: %d | rd: %d | imm: %d",
    instr.opcode, instr.rd, instr.imm.imm_data);
}
