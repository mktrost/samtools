#include <assert.h>
#include "pbgzf.h"



int main(int argc, char ** argv)
{
    //////////////////////////
    // Test opening the file.
    PBGZF* pbgzfHandle = pbgzf_open("data/bamFile.bam", "rb");

    if(pbgzfHandle == NULL)
    {
        printf("ERROR opening test file.\n");
        return(-1);
    }

    ////////////////////////////////////////
    // Test Reading a buffer from the file.
    const int BUFFER_SIZE = 100;
    const int TEST_FILE_SIZE = 37;
    char testBuffer[BUFFER_SIZE];
    assert(pbgzf_tell(pbgzfHandle) == 0);
    assert(pbgzf_read(pbgzfHandle, testBuffer, 4) == 4);
    assert(pbgzf_read(pbgzfHandle, testBuffer, 2) == 2);
    // 37 - 4 - 2 = 37 - 6 = 31 left to read
    assert(pbgzf_read(pbgzfHandle, testBuffer, BUFFER_SIZE) == 31);

    // Read again after at the end of the file.
    assert(pbgzf_read(pbgzfHandle, testBuffer, 2) == 0);

    // Rewind the file.
    assert(pbgzf_seek(pbgzfHandle, 0, SEEK_SET) == 0);
    assert(pbgzf_tell(pbgzfHandle) == 0);
    assert(pbgzf_read(pbgzfHandle, testBuffer, 4) == 4);

    assert(pbgzf_read(pbgzfHandle, testBuffer, BUFFER_SIZE) == 33);
    // Read again after at the end of the file.
    assert(pbgzf_read(pbgzfHandle, testBuffer, 2) == 0);

    pbgzf_close(pbgzfHandle);

     ////////////////////////////
    // Test again.
    pbgzfHandle = pbgzf_open("data/bamFile.bam", "rb");

    assert(pbgzf_tell(pbgzfHandle) == 0);
    assert(pbgzf_read(pbgzfHandle, testBuffer, 4) == 4);
    assert(pbgzf_read(pbgzfHandle, testBuffer, 2) == 2);
    // 37 - 4 - 2 = 37 - 6 = 31 left to read
    assert(pbgzf_read(pbgzfHandle, testBuffer, BUFFER_SIZE) == 31);

    // Read again after at the end of the file.
    assert(pbgzf_read(pbgzfHandle, testBuffer, 2) == 0);

    // Rewind the file.
    assert(pbgzf_seek(pbgzfHandle, 0, SEEK_SET) == 0);
    assert(pbgzf_tell(pbgzfHandle) == 0);
    assert(pbgzf_read(pbgzfHandle, testBuffer, 4) == 4);

    assert(pbgzf_read(pbgzfHandle, testBuffer, BUFFER_SIZE) == 33);
    // Read again after at the end of the file.
    assert(pbgzf_read(pbgzfHandle, testBuffer, 2) == 0);

    pbgzf_close(pbgzfHandle);

   
    ////////////////////////////
    // Test again.
    pbgzfHandle = pbgzf_open("data/bamFile.bam", "rb");

    assert(pbgzf_tell(pbgzfHandle) == 0);
    assert(pbgzf_read(pbgzfHandle, testBuffer, BUFFER_SIZE) == TEST_FILE_SIZE);
    pbgzf_tell(pbgzfHandle);
    assert(pbgzf_read(pbgzfHandle, testBuffer, BUFFER_SIZE) == 0);
    assert(pbgzf_read(pbgzfHandle, testBuffer, BUFFER_SIZE) == 0);
    // Rewind the file.
    assert(pbgzf_seek(pbgzfHandle, 0, SEEK_SET) == 0);
    assert(pbgzf_tell(pbgzfHandle) == 0);
    assert(pbgzf_read(pbgzfHandle, testBuffer, 4) == 4);

    pbgzf_close(pbgzfHandle);


    return(0);
}
