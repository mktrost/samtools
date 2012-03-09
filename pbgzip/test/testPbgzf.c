#include <assert.h>
#include "pbgzf.h"



int main(int argc, char ** argv)
{
    //////////////////////////
    // Test opening the file.
    PBGZF* filePtr = pbgzf_open("data/bamFile.bam", "rb");

    if(filePtr == NULL)
    {
        printf("ERROR opening test file.\n");
        return(-1);
    }

    ////////////////////////////////////////
    // Test Reading a buffer from the file.
    const int BUFFER_SIZE = 100;
    const int TEST_FILE_SIZE = 37;
    char testBuffer[BUFFER_SIZE];
    assert(pbgzf_read(filePtr, testBuffer, 4) == 4);
    assert(pbgzf_read(filePtr, testBuffer, 2) == 2);
    // 37 - 4 - 2 = 37 - 6 = 31 left to read
    assert(pbgzf_read(filePtr, testBuffer, BUFFER_SIZE) == 31);

    return(0);
}
