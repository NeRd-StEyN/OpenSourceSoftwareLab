#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char paragraph[MAX];
    char words[MAX][MAX];
    int frequency[MAX];
    int wordCount = 0;

    // Read a paragraph from the user
    printf("Enter a paragraph: ");
    fgets(paragraph, MAX, stdin);

    // Tokenize the input paragraph into words
    char *token = strtok(paragraph, " ,.-!\n\t");

    while (token != NULL) {
        int found = 0;

        // Check if the word already exists
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(words[i], token) == 0) {
                frequency[i]++;  // Increment frequency if word is found
                found = 1;
                break;
            }
        }

        // If word not found, add it to the list
        if (!found) {
            strcpy(words[wordCount], token);
            frequency[wordCount] = 1;
            wordCount++;
        }

        token = strtok(NULL, " ,.-!\n\t");  // Get the next word
    }

    // Print the frequency of each word
    printf("\nWord Frequency:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", words[i], frequency[i]);
    }

    return 0;
}
