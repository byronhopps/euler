#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "p22.h"

#define NAME_ARRAY_SIZE 6000
#define MAX_NAME_LENGTH 32

unsigned long long int getNameScores(char* filePath)
{
    // Declare array of name strings
    char* nameArray[NAME_ARRAY_SIZE];

    // Variable declaration for file looping
    FILE* namesFile = fopen(filePath, "r");
    
    // Verify file was opened properly
    if (namesFile == NULL) {
        fprintf(stderr, "Failed to open file\n");
        exit(-1);
    }

    char* newStringPtr = NULL; int nameCount = 0;

    // Loop through all names in file
    while (fscanf(namesFile, "\"%m[^\"]\"", &newStringPtr) != EOF) {

        // Check for NULL return value
        if (newStringPtr == NULL) {
            fprintf(stderr, "Failed to allocate memory for name %d\n", nameCount);
            exit(-1);
        }

        // Assign pointer in array as pointer to new string
        nameArray[nameCount] = newStringPtr;

        // Increment number of names imported
        nameCount++;
    }

    fclose(namesFile);

    // Sort nameArray in alphabetic order
    qsort(nameArray, nameCount, sizeof(char*), compareNames);

    // TODO: free all the malloc-ed memory before returning

    return 0;
}

int compareNames(const void *a, const void* b)
{
    char* s1 = *(char**)a;
    char* s2 = *(char**)b;
    return strcmp(s1, s2);
}
