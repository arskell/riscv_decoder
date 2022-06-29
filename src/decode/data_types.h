
//todo
//big/little endian?
struct Reg_Instruction_payload{};
struct Imm_Instruction_payload{};
struct UpImm_Instruction_payload{};
struct Store_Instruction_payload{};
struct Branch_Instruction_payload{};
struct Jump_Instruction_payload{};

union Instruction
{
    struct Reg_Instruction_payload reg;
    struct Imm_Instruction_payload imm;
    struct UpImm_Instruction_payload up_imm;
    struct Store_Instruction_payload store;
    struct Branch_Instruction_payload branch;
    struct Jump_Instruction_payload jump;
    
    unsigned int opcode: 7;
};





