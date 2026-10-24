#ifndef MEMFILE_H
#define MEMFILE_H

#include <iostream>
#include <cstdint>

// There's probably a better way to do this but this is simple enough for this application. We can easily spare about a megabyte's worth of memory in PC applications like this.

class MEMfile{
    private:
        // The 8086 has a 20-bit address space so we have 1048576 bytes that we can access. 
        char RAMFile[1048576] = {};
    public:
        void writeToMem(uint32_t Rs, char data);
        char fetchMem(uint32_t Rs);
};

#endif