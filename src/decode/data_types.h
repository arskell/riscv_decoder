#ifndef DATA_TYPES_H
#define DATA_TYPES_H


//todo
//big/little endian?
struct Reg_Instruction32_raw{
    unsigned int opcode: 7;
    unsigned int rd :    5;
    unsigned int funct3: 3;
    unsigned int rs1: 5;
    unsigned int rs2: 5;
    unsigned int funct7: 7;
};
struct Imm_Instruction32_raw{
    unsigned int opcode: 7;
    unsigned int rd : 5;
    unsigned int funct3: 3;
    unsigned int rs1: 5;
    int imm: 12;
};

struct UpImm_Instruction32_raw{
    unsigned int opcode: 7;
    unsigned int rd : 5;
    int imm: 20;
};

struct Store_Instruction32_raw{
    
    unsigned int opcode: 7;
    unsigned int imm_4_0: 5;
    unsigned int funct3: 3;
    unsigned int rs1:5;
    unsigned int rs2:5;
    unsigned int imm_11_5: 7;
    
};
struct Branch_Instruction32_raw{

    unsigned int opcode: 7;
    unsigned int imm_11: 1;
    unsigned int imm_4_1: 4;
    unsigned int funct3: 3;
    unsigned int rs1:5;
    unsigned int rs2:5;
    unsigned int imm_10_5: 6;
    unsigned int imm_12: 1;

};
struct Jump_Instruction32_raw{
    
    unsigned int opcode: 7;
    unsigned int rd : 5;
    unsigned int imm_19_12: 8;
    unsigned int imm_11:1;
    unsigned int imm_10_1 :10;
    unsigned int imm_20: 1;
};




struct Reg_Instruction32{
    unsigned int funct7: 7;
    unsigned int rs2: 5;
    unsigned int rs1: 5;
    unsigned int funct3: 3;
    unsigned int rd :    5;
    unsigned int opcode: 7;
};
struct Imm_Instruction32{
    int imm: 12;
    unsigned int rs1: 5;
    unsigned int funct3: 3;
    unsigned int rd : 5;
    unsigned int opcode: 7;
};
struct UpImm_Instruction32{
    int imm: 20;
    unsigned int rd : 5;
    unsigned int opcode: 7;
};
struct Store_Instruction32{

    union {
        struct {
            unsigned int imm_low: 5;
            int imm_upper: 7;
        };
        int  imm_data: 12;
    } imm;

    unsigned int rs2:   5;
    unsigned int rs1:   5;
    unsigned int funct3: 3;
    unsigned int opcode: 7;
};
struct Branch_Instruction32{

    union {
        struct {
            unsigned int :1;
            unsigned int imm_low: 4;
            unsigned int imm_mid: 6;
            unsigned int imm_up: 1;
            unsigned int sign:1;
        };
        int  imm_data: 13;
    } imm;

    unsigned int rs2:5;
    unsigned int rs1:5;
    unsigned int funct3: 3;
    unsigned int opcode: 7;
};
struct Jump_Instruction32{

    union {
        struct {
            unsigned int :1;
            unsigned int imm_low: 10;
            unsigned int imm_mid: 1;
            unsigned int imm_up: 8;
            unsigned int sign:1;
        };
        int  imm_data: 20;
    } imm;

    unsigned int rd : 5;
    unsigned int opcode: 7;
};


union Instruction16
{
    //todo 16 bit csr 
    /* data */
};


union Instruction32
{
    struct Reg_Instruction32_raw reg;
    struct Imm_Instruction32_raw imm;
    struct UpImm_Instruction32_raw up_imm;
    struct Store_Instruction32_raw store;
    struct Branch_Instruction32_raw branch;
    struct Jump_Instruction32_raw jump;
    
    unsigned int opcode: 7;
};





#endif