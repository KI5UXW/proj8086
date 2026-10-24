#ifndef MEMFILE_H
#define MEMFILE_H

#include <iostream>
#include <cstdint>

class MEMfile{
    private:
        // The 8086 has a 20-bit address space so we have 1048576 bytes that we can access. 
        char RAMFile[1048576] = {};
    public:
        void writeToMem(char Rs);
        char fetchMem(char Rs);
};

#endif