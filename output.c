#include "typeArt.h"

void output(char **out, int width) {
    for (int line = 0; line < 8; line++) {
        for (int i = 0; i < width; i++) {
            if (out[line][i] == '.') {
                printf(" ");
            } else {
                printf("%c", out[line][i]);
            }
        }
        printf("\n");
        free(out[line]);
    }
}
