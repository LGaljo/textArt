#include "typeArt.h"

int main() {
    char *word = malloc(sizeof(char *));
    char **out = malloc(7*sizeof(char *));

    // Preberem zahtevane crke v array
    int len = getWord(word);
    int offset = 0;

    offset = includeFont(word, len, out);

    if (DEBUG) printf("Koncni offset: %d\n", offset);

    output(out, offset);
    free(word);

    //system("pause");
    return 0;
}

int includeFont(char *word, int len, char **out) {

    FILE *fp = NULL;
    int height = 0;
    int width = 0;
    int comWidth = 0;
    char buffer;

    for (int crka = 0; crka < len; crka++) {
        // Preveri za napacne vnose
        if (isAlphabetic(word[crka])) {

            fp = openFile(fp, word[crka]);

            // Visina in sirina crke
            fscanf(fp, "%d %d\n", &height, &width);

            if (DEBUG) printf("Oblika crke: %dx%d\n", height, width);
            if (DEBUG) printf("Pisem z offsetom: %d\n", comWidth);

            // Berem crko vrstico po vrstici
            for (int line = 0; line < 8; line++) {
                // Alociram pomnilnik za vrstico v črki
                if (crka == 0) {
                    // Za prvic
                    out[line] = (char *) malloc((width + comWidth) * (sizeof(char)));
                } else {
                    // Naslednjic pa realociram
                    out[line] = (char *) realloc(out[line], (width + comWidth) * (sizeof(char)));
                }

                if (out[line] == NULL) {
                    printf("Pomnilnik ni bil alociran :/");
                    // To se zgodi, ce ima beseda vec kot 8 crk
                    exit(1);
                }

                // Preberem vrstico
                for (int i = comWidth; i < width + comWidth; i++) {
                    fscanf(fp, "%c", &buffer);
                    if (buffer == '\n') {
                        out[line][i] = '.';
                    } else {
                        out[line][i] = buffer;
                    }
                }
            }
            fclose(fp);
        }
        comWidth += width;
    }
    return comWidth;
}

