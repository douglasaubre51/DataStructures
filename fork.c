//this works in linux
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void search_file(char *filename, char *path) 
{
    DIR *dir;
    struct dirent *ent;
    char new_path[256];
    dir = opendir(path);
    if (dir == NULL) 
    {
        printf("No such file");
        return;
    }
    while ((ent = readdir(dir)) != NULL) 
    {
        if (strcmp(ent->d_name, filename) == 0) 
        {
            printf("File found: %s/%s\n", path, filename);
            char command[30]="nautilus ";
            strcat(command,path);
           	system(command);
        } else if (ent->d_type == DT_DIR && strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) 
        {
            sprintf(new_path, "%s/%s", path, ent->d_name);
            search_file(filename, new_path);
        }
    }
    
    closedir(dir);
}
int main() 
{
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);
    search_file(filename, ".");
    return 0;
}
