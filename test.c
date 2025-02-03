#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int main(int argc,char *argv[])
{
    argc=2;
    ShellExecute(NULL,"open",argv[1],NULL,NULL,SW_SHOW);
    return 0;
}
