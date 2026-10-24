#include "cpp8086.h"
#include "memFile.cpp"
#include <iostream>
#include <cstdint>
#include <string>

// Defining Write & Fetch Commands for the Main Registers
uint16_t CPUregisters::fetchAX(){
    return ((uint16_t)AXbytes.AH << 8) | AXbytes.AL;
}

uint8_t CPUregisters::fetchAH(){
    return AXbytes.AH;
}

uint8_t CPUregisters::fetchAL(){
    return AXbytes.AL;
}

void CPUregisters::writeAX(uint16_t Rs){
    AXbytes.AH = ((uint16_t)Rs >> 8) & 0xFF;
    AXbytes.AL = ((uint16_t)Rs >> 0) & 0xFF;
}

void CPUregisters::writeAH(uint8_t Rs){
    AXbytes.AH = Rs;
}

void CPUregisters::writeAL(uint8_t Rs){
    AXbytes.AL = Rs;
}

uint16_t CPUregisters::fetchCX(){
    return ((uint16_t)CXbytes.CH << 8) | CXbytes.CL;
}

uint8_t CPUregisters::fetchCH(){
    return CXbytes.CH;
}

uint8_t CPUregisters::fetchCL(){
    return CXbytes.CL;
}

void CPUregisters::writeCX(uint16_t Rs){
    CXbytes.CH = ((uint16_t)Rs >> 8) & 0xFF;
    CXbytes.CL = ((uint16_t)Rs >> 0) & 0xFF;
}

void CPUregisters::writeCH(uint8_t Rs){
    CXbytes.CH = Rs;
}

void CPUregisters::writeCL(uint8_t Rs){
    CXbytes.CL = Rs;
}

uint16_t CPUregisters::fetchDX(){
    return ((uint16_t)DXbytes.DH << 8) | DXbytes.DL;
}

uint8_t CPUregisters::fetchDH(){
    return DXbytes.DH;
}

uint8_t CPUregisters::fetchDL(){
    return DXbytes.DL;
}

void CPUregisters::writeDX(uint16_t Rs){
    DXbytes.DH = ((uint16_t)Rs >> 8) & 0xFF;
    DXbytes.DL = ((uint16_t)Rs >> 0) & 0xFF;
}

void CPUregisters::writeDH(uint8_t Rs){
    DXbytes.DH = Rs;
}

void CPUregisters::writeDL(uint8_t Rs){
    DXbytes.DL = Rs;
}

uint16_t CPUregisters::fetchBX(){
    return ((uint16_t)BXbytes.BH << 8) | BXbytes.BL;
}

uint8_t CPUregisters::fetchBH(){
    return BXbytes.BH;
}

uint8_t CPUregisters::fetchBL(){
    return BXbytes.BL;
}

void CPUregisters::writeBX(uint16_t Rs){
    BXbytes.BH = ((uint16_t)Rs >> 8) & 0xFF;
    BXbytes.BL = ((uint16_t)Rs >> 0) & 0xFF;
}

void CPUregisters::writeBH(uint8_t Rs){
    BXbytes.BH = Rs;
}

void CPUregisters::writeBL(uint8_t Rs){
    BXbytes.BL = Rs;
}

// Defining Write & Fetch Commands for Index, Program, and Segment Registers
void CPUregisters::updateSP(uint16_t Rs){
    SP = Rs;
}
uint16_t CPUregisters::fetchSP(){
    return SP;
}

void CPUregisters::updateBP(uint16_t Rs){
    BP = Rs;
}
uint16_t CPUregisters::fetchBP(){
    return BP;
}

void CPUregisters::updateSI(uint16_t Rs){
    SI = Rs;
}
uint16_t CPUregisters::fetchSI(){
    return SI;
}

void CPUregisters::updateDI(uint16_t Rs){
    DI = Rs;
}
uint16_t CPUregisters::fetchDI(){
    return DI;
}

void CPUregisters::updateIP(uint16_t Rs){
    IP = Rs;
}
uint16_t CPUregisters::fetchIP(){
    return IP;
}

void CPUregisters::updateES(uint16_t Rs){
    ES = Rs;
}
uint16_t CPUregisters::fetchES(){
    return ES;
}

void CPUregisters::updateCS(uint16_t Rs){
    CS = Rs;
}
uint16_t CPUregisters::fetchCS(){
    return CS;
}

void CPUregisters::updateSS(uint16_t Rs){
    SS = Rs;
}
uint16_t CPUregisters::fetchSS(){
    return SS;
}

void CPUregisters::updateDS(uint16_t Rs){
    DS = Rs;
}
uint16_t CPUregisters::fetchDS(){
    return DS;
}

// Updating & Fetching Flags
void CPUregisters::updateCF(bool CF){
    if (CF) {
        Flags = Flags | 0b0000000000000001;
    }
    else {
        Flags = Flags & ~0b0000000000000001;
    }

}

bool CPUregisters::fetchCF(){
    if ((Flags & 0b0000000000000001) == 0b0000000000000001){
        return true;
    }
    return false;
}

void CPUregisters::updateAF(bool AF){
    if (AF) {
        Flags = Flags | 0b0000000000010000;
    }
    else {
        Flags = Flags & ~0b0000000000010000;
    }

}

bool CPUregisters::fetchAF(){
    if ((Flags & 0b0000000000010000) == 0b0000000000010000){
        return true;
    }
    return false;
}

void CPUregisters::updatePF(bool PF){
    if (PF) {
        Flags = Flags | 0b0000000000000100;
    }
    else {
        Flags = Flags & ~0b0000000000000100;
    }

}

bool CPUregisters::fetchPF(){
    if ((Flags & 0b0000000000000100) == 0b0000000000000100){
        return true;
    }
    return false;
}

void CPUregisters::updateZF(bool ZF){
    if (ZF) {
        Flags = Flags | 0b0000000001000000;
    }
    else {
        Flags = Flags & ~0b0000000001000000;
    }

}

bool CPUregisters::fetchZF(){
    if ((Flags & 0b0000000001000000) == 0b0000000001000000){
        return true;
    }
    return false;
}

void CPUregisters::updateSF(bool SF){
    if (SF) {
        Flags = Flags | 0b0000000010000000;
    }
    else {
        Flags = Flags & ~0b0000000010000000;
    }

}

bool CPUregisters::fetchSF(){
    if ((Flags & 0b0000000010000000) == 0b0000000010000000){
        return true;
    }
    return false;
}

void CPUregisters::updateOF(bool OF){
    if (OF) {
        Flags = Flags | 0b0000100000000000;
    }
    else {
        Flags = Flags & ~0b0000100000000000;
    }

}

bool CPUregisters::fetchOF(){
    if ((Flags & 0b0000100000000000) == 0b0000100000000000){
        return true;
    }
    return false;
}

void CPUregisters::updateTF(bool TF){
    if (TF) {
        Flags = Flags | 0b0000000100000000;
    }
    else {
        Flags = Flags & ~0b0000000100000000;
    }

}

bool CPUregisters::fetchTF(){
    if ((Flags & 0b0000000100000000) == 0b0000000100000000){
        return true;
    }
    return false;
}

void CPUregisters::updateIF(bool IF){
    if (IF) {
        Flags = Flags | 0b0000001000000000;
    }
    else {
        Flags = Flags & ~0b0000001000000000;
    }

}

bool CPUregisters::fetchIF(){
    if ((Flags & 0b0000001000000000) == 0b0000001000000000){
        return true;
    }
    return false;
}

void CPUregisters::updateDF(bool DF){
    if (DF) {
        Flags = Flags | 0b0000010000000000;
    }
    else {
        Flags = Flags & ~0b0000010000000000;
    }

}

bool CPUregisters::fetchDF(){
    if ((Flags & 0b0000010000000000) == 0b0000010000000000){
        return true;
    }
    return false;
}


int main() {
    MEMfile bankA;
    CPUregisters CPUA;

    std::cout<<"Testing A"<<std::endl;
    std::cout<<CPUA.fetchCF()<<std::endl;
    CPUA.updateCF(true);
    std::cout<<CPUA.fetchCF()<<std::endl;
    CPUA.updateAF(true);
    std::cout<<CPUA.fetchAF()<<std::endl;
    CPUA.updateCF(false);
    std::cout<<CPUA.fetchCF()<<std::endl;


    return 0;
}

