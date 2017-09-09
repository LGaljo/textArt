#include "typeArt.h"

int getWord(char *word) {
    char buffer;
    int stevilo = 0;

    for (int i = 0; scanf("%c", &buffer) != EOF; i++) {
        if (buffer == '\n') break;
        word = realloc(word, (i + 1)*sizeof(char));
        word[i] = buffer;
        stevilo++;
    }

    if (DEBUG) {
        printf("%d\n", stevilo);
        for (int i = 0; i < stevilo; i++) {
            printf("%c", word[i]);
        }
        printf("\n");
    }

    return stevilo;
}
