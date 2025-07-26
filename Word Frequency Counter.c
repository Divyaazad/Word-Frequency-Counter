#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50
#define MAX_PARAGRAPH_LENGTH 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFreq;

int main() {
    char paragraph[MAX_PARAGRAPH_LENGTH];
    WordFreq words[MAX_WORDS];
    int wordCount = 0;

    printf("Enter a paragraph:\n");
    fgets(paragraph, sizeof(paragraph), stdin);

    // Convert all characters to lowercase and tokenize
    char *token = strtok(paragraph, " ,.-\n");

    while (token != NULL) {
        // Convert token to lowercase
        for (int i = 0; token[i]; i++) {
            token[i] = tolower(token[i]);
        }

        // Check if word already exists
        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(words[i].word, token) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }

        // If not found, add as new word
        if (!found && wordCount < MAX_WORDS) {
            strcpy(words[wordCount].word, token);
            words[wordCount].count = 1;
            wordCount++;
        }

        token = strtok(NULL, " ,.-\n");
    }

    printf("\nWord Frequencies:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}
