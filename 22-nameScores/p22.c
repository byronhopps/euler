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

    FILE* namesFile = fopen(filePath, "r");

    char buffer[MAX_NAME_LENGTH];
    int nameCount = 0;

    // Loop through all names in file
    while (fscanf(namesFile, "\"%s\"", buffer) != EOF) {

        // Add pointer to string to nameArray, and copy string to memory
        nameArray[nameCount] = (char*)malloc(sizeof(char[MAX_NAME_LENGTH]));
        strcpy(nameArray[nameCount], buffer);

        // Increment number of names imported
        nameCount++;
    }

    // Sort nameArray in alphabetic order
    qsort(nameArray, nameCount, sizeof(char*), compareNames);

    // TODO: free all the malloc-ed memory before returning

    return 0;
}

int compareNames(const void *a, const void* b)
{
    return strcmp(a, b);
}
