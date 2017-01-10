#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_ARRAY_SIZE 6000
#define MAX_NAME_LENGTH 32

unsigned long long int getNameScores(char* filePath)
{
    // Declare array of name strings
    char* nameArray[NAME_ARRAY_SIZE];

    FILE* namesFile = fopen(filePath, "r");

    char buffer[MAX_NAME_LENGTH];
    int i = 0;

    // Loop through all names in file
    while (fscanf(namesFile, "\"%s\"", buffer) != EOF) {
        nameArray[i] = (char*)malloc(sizeof(char[MAX_NAME_LENGTH]));
        strcpy(nameArray[i], buffer);
        i++;
    }

    return 0;
}
