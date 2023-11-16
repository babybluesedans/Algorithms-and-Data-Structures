#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define max_len 120000

#define hashsize(n) ((unsigned long)1 << (n))
#define hashmask(n) (hashsize(n) - 1)

unsigned long oaat(char* key, unsigned long len, unsigned long bits);
char* readLine(int size);
void checkNodes(char* word);
char* words[131072];


typedef struct node
{
    struct node* next;
    char* word;
    int wordFound;
}
node;

node* hashTable[131072] = {NULL};
node* foundWords[131072] = {NULL};

int main(void)
{
    char* word;
    int wordCount = 0;
    int foundWordCount = 0;

    
    word = readLine(16);
    while (*word)
    {
        words[wordCount] = word;
        int wordCode = oaat(word, strlen(word), 17);
        node* n = calloc(sizeof(node), 0);
        n->word = words[wordCount];
        n->next = hashTable[wordCode];
        hashTable[wordCode] = n;
        word = readLine(16);
        wordCount++;

    }
    
    int i;


    for (i = 0; i < wordCount; i++)
    {
        checkNodes(words[i]);
    }

}

unsigned long oaat(char* key, unsigned long len, unsigned long bits)
{
    unsigned long hash = 0;
    unsigned long i;
    
    for (i = 0; i < len; i++)
    {
        hash += key[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    } 
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    hash = (hash & hashmask(bits));
    return hash;
}

char* readLine(int size)
{
    char* str;
    int ch;
    int len = 0;
    str = malloc(size);
    if (str == NULL)
    {
        printf("Malloc err\n");
        exit(1);
    }
    while ((ch = getchar()) != EOF && (ch != '\n'))
    {
        str[len++] = ch;
        if (len == size)
        {
            size *= 2;
        }
        str = realloc(str, size);
        if (str == NULL)
        {
            printf("realloc err\n");
            exit(1);
        }
    }
    str[len] = '\0';
    return str;
}

void checkNodes(char* word)
{
    int j;
    int k;

    int word1InList;
    int word2InLIst;
    
    int initWordCode = oaat(word, strlen(word), 17);
    int word1Code;
    int word2Code;

    int size1 = 16;
    int size2 = 16;

    node* tmpmain = hashTable[initWordCode];

    while (strcmp(word, tmpmain->word) != 0)
    {
        tmpmain = tmpmain->next;
    }

    int wordLength = strlen(word);
    int i;
    for (i = 0; i < wordLength; i++)
    {   
        char* word1 = malloc(size1);
        char* word2 = malloc(size2);

        for (j = 0; j <= i; j++)
        {
            word1[j] = word[j];
            if (j == size1)
            {
                size1 = size1 * 2;
                word1 = realloc(word1, size1);
            }
        }

        word1[j] = '\0';
        word1Code = oaat(word1, strlen(word1), 17);
        if (hashTable[word1Code] != NULL)
        {
            node* tmp = hashTable[word1Code];
            while (tmp != NULL)
            {
                if (strcmp(word1, tmp->word) == 0)
                {
                    for (k = i + 1; k < wordLength; k++)
                    {
                        word2[(k - i - 1)] = word[k];
                        if ((k - i - 1) == size2)
                        {
                            size2 *= 2;
                            word2 = realloc(word2, size2);
                        }
                    } 

                    word2[k - i - 1] = '\0';
                    word2Code = oaat(word2, strlen(word2), 17);
                    if (hashTable[word2Code] != NULL)
                    {
                        node* tmp2 = hashTable[word2Code];
                        while (tmp2 != NULL)
                        {
                            if (strcmp(word2, tmp2->word) == 0 && !(tmpmain->wordFound))
                            {
                                printf("%s\n", word);
                                hashTable[initWordCode]->wordFound = 1;
                                break;
                            }
                            tmp2 = tmp2->next;
                        }
                    }

                }
                tmp = tmp->next;
            }
        }
        free(word1);
        free(word2);

    }
}