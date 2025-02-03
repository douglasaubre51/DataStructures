#include <stdio.h>
#include <windows.h>
int godown(char *adr[])
{
    
}
int main(int argc,char *argv[])
{
    argc=2;
    //argv[1] gets filename
    extern int godown(char *adr[]);
    godown(*argv);
    ShellExecute(NULL,"open",argv[1],NULL,NULL,SW_SHOW);
    return 0;
}
