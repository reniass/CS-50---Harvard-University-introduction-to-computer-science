// Implements a dictionary's functionality

#include <stdbool.h>
#include <string.h>
#include "dictionary.h"
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <ctype.h>


typedef struct node
{
    char wordInNode[46];
    struct node *next;
}node;

// the longest english word contains 45 character suppose that every single letter have value from 0 to 25 (a = 0, b = 1, ..., z = 25)
//  so every english word will have value from 0 to 1125(25 * 45) and word with such a value will be assign to array at position value
node *addresses[1126];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    unsigned int wordValue = 0;
    int i = 0;
    while (i < strlen(word))
    {
        if (islower(word[i]))
        {
            wordValue = wordValue + (word[i] - 97);
            i++;
        }
        else if (word[i] == '\'')
        {
            i++;
        }
        else
        {
            wordValue = wordValue + ((word[i] + 32) - 97);
            i++;
        }
        //i++;
    }
    if (wordValue > 1125)
    {
        return false;
    }
    else if (addresses[wordValue] == NULL)
    {
        return false;
    }
    else
    {
        node *nodePointer = addresses[wordValue];
        while (nodePointer != NULL)
        {
            if (strcasecmp(word, nodePointer->wordInNode) == 0)
            {
                return true;
            }
            else
            {
                nodePointer = nodePointer->next;
            }
        }
    }
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *fPtr;
    fPtr = fopen(dictionary, "r");
    if (fPtr == NULL)
    {
        printf("No memory.");
        return 1;
    }

    int i = 0;
    while (i < 1126)
    {
        addresses[i] = NULL;
        i++;
    }

    char word[46];
    int wordValue = 0;
    // assigning next word from dictionary to variable word
    while (fgets(word, 47, fPtr) != NULL)
    {
        if (word[strlen(word) - 1] == '\n')
        {
            word[strlen(word) - 1] = '\0';
        }
        else
        {
            word[strlen(word)] = '\0';
        }

        int j = 0;
        while (j < strlen(word))
        {
            if (word[j] == '\'')
            {
                j++;
            }
            else
            {
            // calculate value of word
                wordValue = wordValue + (word[j] - 97);
                j++;
            }

        }

        // we check if address in which our word will be included have NULL pointer
        if (addresses[wordValue] == NULL)
        {
            node *nodePointer = (node*) malloc(sizeof(node));
            // checking whether exists enough memory to allocate nodePointer
            if(nodePointer == NULL)
            {
                printf("No memory.");
                return false;
            }
            else
            {
                addresses[wordValue] = nodePointer;
                strcpy(nodePointer->wordInNode, word);
                nodePointer->next = NULL;
            }
        }
        else
        {
            node *nodePointer = (node*) malloc(sizeof(node));
            // checking whether exists enough memory to allocate nodePointer
            if (nodePointer == NULL)
            {
                printf("No memory.");
                return false;
            }
            else
            {
                node *temporaryPointer = addresses[wordValue];
                addresses[wordValue] = nodePointer;
                strcpy(nodePointer->wordInNode, word);
                nodePointer->next = temporaryPointer;
            }
        }
        wordValue = 0;
    }
    // close the file fPtr
    fclose(fPtr);

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // we create variable that will store number of words loaded from dictionary into memory
    unsigned int wordCount = 0;
    int i = 0;
    node *nodePointer;
    while (i < 1126)
    {
        nodePointer = addresses[i];
        while (nodePointer != NULL)
        {
            wordCount += 1;
            nodePointer = nodePointer->next;
        }
        i++;
    }
    return wordCount;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    int i = 0;
    while (i < 1126)
    {
        node *nodePointer = addresses[i];
        while (nodePointer != NULL)
        {
            node *freeNode = nodePointer;
            nodePointer = nodePointer->next;
            free(freeNode);
        }
        i++;
    }
    return true;
}
