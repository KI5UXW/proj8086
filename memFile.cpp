#include "memFile.h"
#include <iostream>
#include <cstdint>

void MEMfile::writeToMem(uint32_t Rs, char data){
    Rs = Rs << 12;
    Rs = Rs >> 12;
    RAMFile[Rs] = data;
}

char MEMfile::fetchMem(uint32_t Rs){
    Rs = Rs << 12;
    Rs = Rs >> 12;
    return RAMFile[Rs];
}
/*
int main(){
    MEMfile bankA;
    uint32_t Rs = 0x1;
    char data = 23;
    bankA.writeToMem(Rs, data);
    std::cout<<int(bankA.fetchMem(Rs))<<std::endl;
    return 0;
}
*/