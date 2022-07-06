#include "string.h"

#include "decode/data_types.h"


struct Reg_Instruction32 convert_to_reg(union Instruction32 inst){

    struct Reg_Instruction32 reg;
    reg.opcode = inst.opcode;
    reg.rs1 = inst.reg.rs1;
    reg.rs2 = inst.reg.rs2;
    reg.funct3 = inst.reg.funct3;
    reg.funct7 = inst.reg.funct7;
    reg.rd = inst.reg.rd;
    return reg;
}

struct Imm_Instruction32 convert_to_imm(union Instruction32 inst)
{
    struct Imm_Instruction32 imm;
    imm.opcode = inst.opcode;
    imm.funct3 = inst.imm.funct3;
    imm.rd = inst.imm.rd;
    imm.rs1 = inst.imm.rs1;
    imm.imm = inst.imm.imm;
    return imm;
};
