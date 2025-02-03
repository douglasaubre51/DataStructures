#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[]){
    FILE *reader,*writer;
    reader=fopen(argv[1],"r");
    writer=fopen(argv[2],"a");
    int bytes;
    char buffer[60];
    int trueSize=60;
    do{
	bytes=fread(buffer,1,trueSize,reader);
	fwrite(buffer,1,bytes,writer);
    }while(bytes>0);
    printf("printing complete!open %s",argv[2]);
    fclose(reader);
    fclose(writer);
}
