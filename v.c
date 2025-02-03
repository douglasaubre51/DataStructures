#include<windows.h>
#include<stdio.h>
int main()
{
    int c;
    char buffer[1000];
    FILE *filename;
    fopen("CLIPS.txt","w+");
    fprintf(filename,"danzo");
    if(filename==NULL)
    {
        printf("error");
    }
    c=ftell(filename);
    fscanf(filename,"%s",buffer);
    printf("%s",buffer);
    fclose(filename);
    printf("%d",c);
    return 0;
}