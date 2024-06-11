#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAGE_SIZE 100

int getPithy(int buffSize, char *outPithy)
{
    const char filename[] = "pithy.txt";
    FILE *fp;
    char buffer[buffSize];
    char *r;
    char *entry;
    int items;
    int saying;
    char **listBase;
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Unable to open file %s\n", filename);
        return EXIT_FAILURE;
    }
    items = 0;
    listBase = (char **)malloc(sizeof(char *) * PAGE_SIZE);
    while (!feof(fp))
    {
        r = fgets(buffer, buffSize, fp);
        if (r == NULL)
        {
            break;
        }

        entry = (char *)malloc(sizeof(char) * strlen(buffer) + 1);
        if (entry == NULL)
        {
            fprintf(stderr, "Unable to allocate memory\n");
            return EXIT_FAILURE;
        }
        strcpy(entry, buffer);
        *(listBase + items) = entry;
        items++;
        if (items % 100 == 0)
        {
            listBase = (char **)realloc(listBase, sizeof(char *) * (items + PAGE_SIZE));
            if (listBase == NULL)
            {
                fprintf(stderr, "Unable to allocate memory\n");
                return EXIT_FAILURE;
            }
        }
    }
    srand((unsigned)time(NULL));
    saying = rand() % (items - 1);
    strcpy(outPithy, *(listBase + saying));
    fclose(fp);
    free(listBase);
    return EXIT_SUCCESS;
}