#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000002
int longestPrefix(char s1[], char s2[], int len);
int longestSuffix(char s1[], char s2[], int len);

int main(void)
{
    static char s1[MAX + 2], s2[MAX + 2];
    fgets(&s1[0], MAX, stdin);
    fgets(&s2[0], MAX, stdin);

    int s1Len = strlen(s1);
    int s2Len = strlen(s2);

    int longestPref = longestPrefix(s1, s2, s2Len); //below this bound + 1
    int longestSuff = longestSuffix(s1, s2, s1Len); //above this bound

    int total = (longestPref + 1) - (longestSuff );
    if (total <= 0)
    {
        total = 0;
    }
    if (s1Len > MAX || s2Len > MAX)
    {
        total = 0;
    }

    
    
    printf("%u\n", total);

    if (total != 0)
    {
        for (int i = 0; i < total; i++)
        {
            printf("%u ", longestSuff + 1 + i);
        }
        printf("\n");
    }


}

int longestPrefix(char s1[], char s2[], int len)
{
    int i = 0;
    while (s1[i] == s2[i] && i < MAX  && i < len - 1)
    {
        i++;
    }

    return i;
}

int longestSuffix(char s1[], char s2[], int len)
{
    int i = len - 2;

    while(i > 0 && s1[i] == s2[i - 1] && i < MAX)
    {
        i--;
    }

    return i;
}