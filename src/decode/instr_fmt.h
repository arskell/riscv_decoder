#ifndef INSTR_FMT_H
#define INSTR_FMT_H

#include "data_types.h"

void fmt_reg(char* str, struct Reg_Instruction32 instr);
void fmt_imm(char* str, struct Imm_Instruction32 instr);
void fmt_up_imm(char* str, struct UpImm_Instruction32 instr);
void fmt_store(char* str, struct Store_Instruction32 instr);
void fmt_branch(char* str, struct Branch_Instruction32 instr);
void fmt_jump(char* str, struct Jump_Instruction32 instr);

#endif