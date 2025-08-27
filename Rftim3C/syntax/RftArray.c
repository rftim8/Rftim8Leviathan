#include "RftArray.h"

static int initializeDynamicArray();

void printRftArrayMain()
{
}

static int initializeDynamicArray()
{
    size_t len = 4;
    int *buf = malloc(len * sizeof *buf);

    if (buf == NULL)
    {
        printf("Not enough memory to allocate.\n");
        return 1;
    }

    size_t i = 0;
    int *temp;

    while (scanf("%d", buf + i) == 1)
    {
        i++;
        if (i == len)
        {
            temp = buf;
            len *= 2;
            buf = realloc(buf, len * sizeof *buf);
            if (buf == NULL)
            {
                printf("Not enough memory to reallocate.\n");
                buf = temp;
                break;
            }
        }
    }

    if (i == 0)
    {
        printf("No input read\n");
        return 1;
    }

    for (size_t j = 0; j < i; j++)
    {
        printf("%d ", buf[j]);
    }

    free(buf);
    buf = NULL;
}
