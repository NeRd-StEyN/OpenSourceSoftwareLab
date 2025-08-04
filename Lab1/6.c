// word_frequency.c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordFreq;

int main() {
    char paragraph[1000];
    WordFreq words[MAX_WORDS];
    int wordCount = 0;

    printf("Enter a paragraph:\n");
    fgets(paragraph, sizeof(paragraph), stdin);

    char *token = strtok(paragraph, " ,.-\n");

    while (token != NULL) {
        // convert to lowercase
        for (int i = 0; token[i]; i++)
            token[i] = tolower(token[i]);

        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(words[i].word, token) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(words[wordCount].word, token);
            words[wordCount].count = 1;
            wordCount++;
        }

        token = strtok(NULL, " ,.-\n");
    }

    printf("Word Frequencies:\n");
    for (int i = 0; i < wordCount; i++)
        printf("%s: %d\n", words[i].word, words[i].count);

    return 0;
}

