#pragma once
#include "rft_global_c.h"

static void rftString()
{
    char str[256] = "Testing";

    printf("%s\n", str);
}

static void countWordsInString()
{
    int c, nl, nw, nc, state;
    nl = 1;
    state = OUT;
    nl = nw = nc = 0;

    while ((c = getchar()) != '.')
    {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT)
        {
            state = IN;
            ++nw;
        }
    }

    printf("\nLines: %d\nWords: %d\nChars: %d\n", nl, nw, nc);
}

static int getInputLineLength(char s[], int lim)
{
    int c, i, counter;

    for (i = 0; i < lim - 1 && (c = getchar()) != '.' && c != '\n'; i++)
    {
        s[i] = c;
    }

    if (c == '\n')
    {
        s[i] = c;
        i++;
    }

    s[i] = '\0';
    counter = i;

    return counter - 1;
}

static void copyStringFromString(char to[], char from[])
{
    int i = 0;

    while ((to[i] = from[i]) != '\0')
    {
        ++i;
    }
}

static int findLongestLineInText()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];
    max = 0;

    while ((len = getInputLineLength(line, MAXLINE)) > 0)
    {
        if (len > max)
        {
            max = len;
            copyStringFromString(longest, line);
        }
    }

    if (max > 0)
        printf("%s", longest);

    return 0;
}
