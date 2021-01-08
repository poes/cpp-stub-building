#include <stdio.h>
#include <windows.h>

#define STUB_NAME "stub.exe"


int main()
{
    char data[256]; // initialize data char array
    char Filename_New[32] = "build.exe"; // build stub name

    printf("Enter data: ");
    fflush(stdin);
    scanf("%s", data); // write data to char array

    FILE *Copy = fopen(STUB_NAME, "rb"); // open stub
    FILE *Paste = fopen(Filename_New, "wb"); // open new build

    if(!Copy || !Paste)
    {
        printf("\nError occured reading stub or writing new file\n");
        fflush(stdin);
        getchar();
        return 0;
    }

    int c;
    while((c = fgetc(Copy)) != EOF) // copy og stub to new file
        fprintf(Paste, "%c", c);

    fclose(Copy);
    fclose(Paste);

    FILE *Write = fopen(Filename_New, "a+b"); // reopen new build
    if(!Write)
    {
        printf("\nError occured opening stub\n");
        fflush(stdin);
        getchar();
        return 0;
    }

    fwrite(&data, sizeof(data), sizeof(char), Write); // write data to end of file
    fclose(Write);

    printf("\nSuccessfully written data to stub\n");
    fflush(stdin);
    getchar();
    return 0;
}
