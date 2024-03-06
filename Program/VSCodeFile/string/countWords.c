#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define wordLength 11
#define contextLength 100001

char *input(int length) {
    char *word = malloc(length * sizeof(char));
    if (word == NULL) {
        perror("Malloc failed");
        exit(EXIT_FAILURE);
    }

    int i = 0, ch;

    while (i < length - 1 && (ch = getchar()) != '\n' && ch != EOF) {
        word[i++] = (char) ch;
    }
    word[i] = '\0';
    return word;
}

void toLower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char *word = input(wordLength);
    char *context = input(contextLength);

    toLower(word);
    toLower(context);

    int count = 0, firstPos = -1, currentPos = 0;
    char *token = strtok(context, " ");
    while (token != NULL) {
        if (strcmp(token, word) == 0) {
            count++;
            if (firstPos == -1) {
                firstPos = currentPos;
            }
        }
        currentPos += strlen(token) + 1; // +1 for the space
        token = strtok(NULL, " ");
    }

    if (count > 0) {
        printf("%d %d\n", count, firstPos);
    } else {
        printf("-1\n");
    }

    free(word);
    free(context);

    return 0;
}
