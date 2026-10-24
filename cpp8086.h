#ifndef CPP8086_H
#define CPP8086_H
#include <cstdint>

// https://en.wikipedia.org/wiki/Intel_8086
// https://www.geeksforgeeks.org/electronics-engineering/types-of-registers-in-8086-microprocessor/
// https://en.wikipedia.org/wiki/FLAGS_register


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

    // Segment Registers
    uint16_t ES = 0; // Extra Segment
    uint16_t CS = 0; // Code Segment
    uint16_t SS = 0; // Stack Segment
    uint16_t DS = 0; // Data Segment

    // Status Register
    uint16_t Flags = 0b1111000000101010; // Flag Register

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

        void updateCF(bool CF);
        void updateAF(bool AF);
        void updatePF(bool PF);
        void updateZF(bool ZF);
        void updateSF(bool SF);
        void updateOF(bool OF);

        void updateTF(bool TF);
        void updateIF(bool IF);
        void updateDF(bool DF);
};

#endif