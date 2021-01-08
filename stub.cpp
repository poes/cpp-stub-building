#include <stdio.h>
#include <windows.h>
#include <iosfwd>
#include <fstream>

#define STUB_EOF 85504 // this depends on your compiler. build this first, look at the size, replace this and build again

int main()
{
    char Filename_Current[256];

    GetModuleFileName(NULL, Filename_Current, 256);

    FILE *Read = fopen(Filename_Current, "rb");
    if(!Read)
    {
        printf("\nError occured reading current file\n");
        getchar();
        return 0;
    }



    char* rawData; // going to hold data

    int size = MAX_PATH; // max file length
    char *filename = new char[size]; // going to store filename

    GetModuleFileNameA(NULL, filename, STUB_EOF); // get filename, store in filename

    std::ifstream file(filename, std::ios::binary);	// get file handle

    if (!file.is_open())
    {
        return -1;
    }

    file.seekg(0, file.end); // go to end of file
    long outputsize = static_cast<long>(file.tellg());	// get size

    long realsize = outputsize - STUB_EOF; // get data size
    rawData = new char[realsize]; // alloc memory for data

    file.seekg(STUB_EOF); // go to end of stub
    file.read(rawData, realsize); // read data, write to rawData
    file.close();


    printf("data: %s\n", rawData);

    getchar();
    return 0;
}
