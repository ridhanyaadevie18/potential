#include<stdio.h>

int main()
{
    FILE *pFile=fopen("Newfile.txt","a");

    fprintf(pFile,"\nNewly addedd Hellow");

    fclose(pFile);

    return 0;

}