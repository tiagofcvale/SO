#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>


int hasExtension(const char *filename, const char *ext) {
    const char *dot = strrchr(filename, '.');
    if (!dot || dot == filename)
        return 0; 
    return strcmp(dot + 1, ext) == 0;
}

void listDir(const char *dirname, int showFiles, int showDirs, int filterExt, const char *ext) {
    DIR *dp;
    struct dirent *entry;
    struct stat st;
    char path[1024];

    dp = opendir(dirname);
    if (dp == NULL) {
        perror(dirname);
        return;
    }

    printf("\n[%s]\n", dirname);
    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_name[0] == '.')
            continue;

        snprintf(path, sizeof(path), "%s/%s", dirname, entry->d_name);
        if (stat(path, &st) == -1)
            continue;

        if (S_ISDIR(st.st_mode)) {
            if (showFiles && !showDirs)
                continue;
            if (!showFiles && !showDirs)
                printf("d %s\n", entry->d_name);
            else if (showDirs)
                printf("d %s\n", entry->d_name);
        } else if (S_ISREG(st.st_mode)) {
            if (showDirs && !showFiles)
                continue;
            if (filterExt && !hasExtension(entry->d_name, ext))
                continue;
            printf("  %s\n", entry->d_name);
        }
    }

    closedir(dp);
}


int main(int argc, char *argv[]) {
    
    int opt, filterExt;

    char ext[32] = "";
    int showFiles = 0;
    int showDirs = 0;

    while ((opt = getopt(argc, argv, "fde:")) != -1) {
        switch (opt)
        {
        case 'f':
            showFiles = 1;
            break;
        
        case 'd':
            showDirs = 1;
            break;
        case 'e':
            filterExt = 1;
            strncpy(ext, optarg, sizeof(ext) - 1);
            break;
        default:
            fprintf(stderr, "Uso: %s [-f] [-d] [-e ext] [dir...]\n", argv[0]);
            exit(EXIT_FAILURE);
        }
    }

    if (optind == argc)
        listDir(".", showFiles, showDirs, filterExt, ext);
    else {
        for (int i = optind; i < argc; i++) {
            listDir(argv[i], showFiles, showDirs, filterExt, ext);
        }
    }

    return EXIT_SUCCESS;

}