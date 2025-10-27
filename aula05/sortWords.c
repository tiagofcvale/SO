#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int compareAsc(const void *a, const void *b) {
    const char *s1 = *(const char **)a;
    const char *s2 = *(const char **)b;
    return strcasecmp(s1, s2); // Ignore case
}

int compareDesc(const void *a, const void *b) {
    const char *s1 = *(const char **)a;
    const char *s2 = *(const char **)b;
    return strcasecmp(s2, s1);
}

int main(int argc, char *argv[]) {
    const char *sortOrder = getenv("SORTORDER");
    if (sortOrder == NULL) {
        printf("SORTORDER Undefined, using default value.\n");
        sortOrder = "asc"; 
    }

    int (*compareFunc)(const void *, const void *) = compareAsc;
    if (strcasecmp(sortOrder, "desc") == 0) {
        compareFunc = compareDesc;
    }

    // Filter alpha starting words
    char *validWords[argc - 1];
    int count = 0;

    for (int i = 1; i < argc; i++) {
        if (isalpha((unsigned char)argv[i][0])) {
            validWords[count++] = argv[i];
        }
    }

    // No valid words
    if (count == 0) {
        printf("No valid words to sort.\n");
        return EXIT_SUCCESS;
    }

    // Sort words
    qsort(validWords, count, sizeof(char *), compareFunc);

    // Print sorted words
    printf("Palavras ordenadas:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", validWords[i]);
    }

    return EXIT_SUCCESS;
}
