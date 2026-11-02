#ifndef CPP8086_H
#define CPP8086_H
#include <cstdint>

// https://en.wikipedia.org/wiki/Intel_8086
// https://www.geeksforgeeks.org/electronics-engineering/types-of-registers-in-8086-microprocessor/
// https://en.wikipedia.org/wiki/FLAGS_register
// https://www.philadelphia.edu.jo/academics/qhamarsheh/uploads/emu8086.pdf
// https://edge.edx.org/c4x/BITSPilani/EEE231/asset/8086_family_Users_Manual_1_.pdf


// Defining our functions so we can define them out of order.
class CPUregisters{
    
    private:

    // Accumulator
    union {
        uint16_t AX;
        struct {
            uint8_t AH;
            uint8_t AL;
        } AXbytes;
    };


    // Counter
    union {
        uint16_t CX;
        struct {
            uint8_t CH;
            uint8_t CL;
        } CXbytes;
    };

    // Extended ACC
    union {
        uint16_t DX;
        struct {
            uint8_t DH;
            uint8_t DL;
        } DXbytes;
    };

    // Base
    union {
        uint16_t BX;
        struct {
            uint8_t BH;
            uint8_t BL;
        } BXbytes;
    };


    // Index Registers
    uint16_t SP = 0; // Stack Pointer
    uint16_t BP = 0; // Base Pointer
    uint16_t SI = 0; // Source Index
    uint16_t DI = 0; // Destination Index

    // Program Counter
    uint16_t IP = 0; // Instruction Pointer/Program Counter
    // Stores the next addr. to be fetched by the BIU during normal operation.
    // When IP is saved on the stack, it's automatically adjusted to point to the next instruction to be executed.

    // Segment Registers
    uint16_t ES = 0; // Extra Segment
    uint16_t CS = 0; // Code Segment
    uint16_t SS = 0; // Stack Segment
    uint16_t DS = 0; // Data Segment

    // Flags/Status Register
    uint16_t Flags = 0b1111000000101010; // Flag Register: CF (Carry), PF (Parity), AF (Auxiliary Carry), ZF (Zero), SF (Sign), OF (Overflow), TF (Trap), IF (Interrupt Enable), DF (Direction)
    // Refer to the documentation starting on Page 22.


    // Instruction Stream Queue
    uint8_t ISQ[6] = {};

    // Bus Cycle Status Signals
    uint8_t busStatus = 0b10100000;

    // Instruction Fetch & Execution 
    uint8_t statusEU = 0; // 0 = NOP, 1 = Execute.
    uint8_t statusBIU = 0; // 0 = Fetch, 1 = Read, 2 = Write.
    //uint8_t statusBUS = 1; // 0 = Not Busy, 1 = Busy.
    // Documentation Starting on Page 19.
    // BIU for the 8086 usually gets two instructions per fetch.
    // If fetching from an odd address, the BIU reads one byte and then goes back to even addresses.
    // Usually, the EU doesn't have to wait for fetches as long as it has one byte. 
    // If the EU transfers control, the BIU requests the queue and passes the first address immediately to the EU and then resumes filling the queue.
    // The BIU will stop fetching if the EU requests memory or I/O or wait until an existing fetch is completed before the EU's bus request.


    public:
        // Fetching Register Values
        uint16_t fetchAX();
        uint8_t fetchAH();
        uint8_t fetchAL();

        uint16_t fetchCX();
        uint8_t fetchCH();
        uint8_t fetchCL();

        uint16_t fetchDX();
        uint8_t fetchDH();
        uint8_t fetchDL();

        uint16_t fetchBX();
        uint8_t fetchBH();
        uint8_t fetchBL();

        uint16_t fetchSP();
        uint16_t fetchBP();
        uint16_t fetchSI();
        uint16_t fetchDI();
        uint16_t fetchIP();
        uint16_t fetchES();
        uint16_t fetchCS();
        uint16_t fetchSS();
        uint16_t fetchDS();
        uint16_t fetchFlags();

        bool fetchCF();
        bool fetchAF();
        bool fetchPF();
        bool fetchZF();
        bool fetchSF();
        bool fetchOF();

        bool fetchTF();
        bool fetchIF();
        bool fetchDF();

        // Updating Register Values
        void writeAX(uint16_t Rs);
        void writeAH(uint8_t Rs);
        void writeAL(uint8_t Rs);

        void writeCX(uint16_t Rs);
        void writeCH(uint8_t Rs);
        void writeCL(uint8_t Rs);

        void writeDX(uint16_t Rs);
        void writeDH(uint8_t Rs);
        void writeDL(uint8_t Rs);

        void writeBX(uint16_t Rs);
        void writeBH(uint8_t Rs);
        void writeBL(uint8_t Rs);

        void updateSP(uint16_t Rs);
        void updateBP(uint16_t Rs);
        void updateSI(uint16_t Rs);
        void updateDI(uint16_t Rs);
        void updateIP(uint16_t Rs);
        void updateES(uint16_t Rs);
        void updateCS(uint16_t Rs);
        void updateSS(uint16_t Rs);
        void updateDS(uint16_t Rs);

        // Updating Flags
        void updateCF(bool CF);
        void updateAF(bool AF);
        void updatePF(bool PF);
        void updateZF(bool ZF);
        void updateSF(bool SF);
        void updateOF(bool OF);

        void updateTF(bool TF);
        void updateIF(bool IF);
        void updateDF(bool DF);

        // Implementing RESET
        void RESET();

        //
        uint8_t updateEU(uint8_t state); // 0 = NOP, 1 = Execute.
        uint8_t updateBIU(uint8_t state); // 0 = Fetch, 1 = Read, 2 = Write.

        // Implementing 8086 ISA Instructions
        void AAA();
        void AAD();
        void AAM();

};

#endif