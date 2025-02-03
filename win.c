#include <windows.h>
#include <stdio.h>
#include <string.h>
void search_file(char *filename, char *path) 
{
    WIN32_FIND_DATA find_data;
    HANDLE h_find;
    char new_path[MAX_PATH];
    sprintf(new_path, "%s\\*.*", path);
    h_find = FindFirstFile(new_path, &find_data);
    if (h_find == INVALID_HANDLE_VALUE) 
    {
        return;
    }
    do 
    {
        if (strcmp(find_data.cFileName, filename) == 0) 
        {
            printf("File found: %s\\%s\n", path, filename);
        } else if (find_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) 
        {
            sprintf(new_path, "%s\\%s", path, find_data.cFileName);
            search_file(filename, new_path);
        }
    } while (FindNextFile(h_find, &find_data));
    FindClose(h_find);
}
int main() 
{
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);
    search_file(filename, ".");
    return 0;
}
