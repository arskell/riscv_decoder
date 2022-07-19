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
}


struct UpImm_Instruction32 convert_to_upimm(union Instruction32 inst)
{
    struct UpImm_Instruction32 instr;
    instr.opcode = inst.opcode;
    instr.imm = inst.up_imm.imm;
    instr.rd = inst.up_imm.rd;
    
    return instr;
}


struct Store_Instruction32 convert_to_store(union Instruction32 inst)
{
    struct Store_Instruction32 instr_ret;
    instr_ret.opcode = inst.opcode;
    instr_ret.rs1 = inst.store.rs1;
    instr_ret.rs2 = inst.store.rs2;
    instr_ret.imm.imm_data = 0;
    instr_ret.imm.imm_low = inst.store.imm_4_0;
    instr_ret.imm.imm_upper = inst.store.imm_11_5;
    return instr_ret;
};

struct Branch_Instruction32 convert_to_branch(union Instruction32 inst)
{
    struct Branch_Instruction32 instr_ret;
    instr_ret.opcode = inst.opcode;
    instr_ret.rs1 = inst.branch.rs1;
    instr_ret.rs2 = inst.branch.rs2;
    instr_ret.imm.imm_data = 0;
    instr_ret.imm.imm_low = inst.branch.imm_4_1;
    instr_ret.imm.imm_mid = inst.branch.imm_10_5;
    instr_ret.imm.imm_up = inst.branch.imm_11;
    instr_ret.imm.sign = inst.branch.imm_12;
    return instr_ret;
};


struct Jump_Instruction32 convert_to_jump(union Instruction32 inst)
{
    struct Jump_Instruction32 instr_ret;
    instr_ret.opcode = inst.opcode;
    instr_ret.rd = inst.jump.rd;
    instr_ret.imm.imm_data = 0;
    instr_ret.imm.imm_low = inst.jump.imm_10_1;
    instr_ret.imm.imm_mid = inst.jump.imm_11;
    instr_ret.imm.imm_mid = inst.jump.imm_19_12;
    instr_ret.imm.sign = inst.jump.imm_20;
    return instr_ret;
};