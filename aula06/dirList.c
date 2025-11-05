#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

void listDir(char dirname[])
{
    DIR *dp; 
    struct dirent *dent;
    char path[1024];
    struct stat st;

    dp = opendir(dirname); 
    if (dp == NULL)
    {
        perror("Error opening directory");
        return;
    }

    while ((dent = readdir(dp)) != NULL) 
    {
        if (dent->d_name[0] == '.')
            continue;

        snprintf(path, sizeof(path), "%s/%s", dirname, dent->d_name);

        if (stat(path, &st) == -1)
        {
            perror("Error reading file info");
            continue;
        }

        if (S_ISDIR(st.st_mode))
        {
            printf("d %s\n", path);

            listDir(path); // recursive
        }
        else
        {
            printf("  %s\n", path);
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s base_directory\n", argv[0]);
        return EXIT_FAILURE;
    }

    listDir(argv[1]);
    
    return EXIT_SUCCESS;
}
