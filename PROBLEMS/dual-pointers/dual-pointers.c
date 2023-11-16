#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000000
unsigned int longestPrefix(char s1[], char s2[]);
unsigned int longestSuffix(char s1[], char s2[], unsigned int len);

int main(void)
{
    static char s1[MAX + 2], s2[MAX + 2];
    fgets(&s1[0], MAX, stdin);
    fgets(&s2[0], MAX, stdin);

    stringLen = strlen(s1)

    unsigned int longestPref = longestPrefix(s1, s2); //below this bound + 1
    unsigned int longestSuff = longestSuffix(s1, s2, stringLen); //above this bound

    for (int i = longestSuff + 1; i < longestPref + 2; i++);
    {
        
        int j;
        int k;
        for (j = 0; j < i; j++)//create new prefix
        {

        }
    }


}

unsigned int longestPrefix(char s1[], char s2[])
{
    unsigned int i = 1;
    while (s1[i] == s2[i] && i < MAX + 2)
    {
        i++;
    }
    return i;
}

unsigned int longestSuffix(char s1[], char s2[], unsigned int len)
{
    unsigned int i = len;
    printf("%u\n", len);

    while(s1[i] == s2[i - 1] && i > 2)
    {
        i--;
    }

    return i;
}