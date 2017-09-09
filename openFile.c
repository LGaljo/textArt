#include "typeArt.h"

FILE *openFile(FILE *fp, char crka) {
    // Konstruiraj ime datoteke
    if (crka == ' ') {
        fp = fopen("font/space.txt", "r");
        if (DEBUG) printf("Space\n");
    } else if (crka == '/') {
        // TODO: Nova vrstica
    } else if (crka == '!') {
        fp = fopen("font/exclamation.txt", "r");
        if (DEBUG) printf("Exclamation\n");
    } else {
        char imeDat[11] = {'f', 'o', 'n', 't', '/', tolower(crka), '.', 't', 'x', 't', '\0'};
        if (DEBUG) printf("Datoteka: %s\n", imeDat);
        fp = fopen(imeDat, "r");
    }

    // Preveri, ce je datoteka odprta
    if (fp == NULL) {
        printf("Napaka pri odpiranju datoteke");
        exit(1);
    } else {
        if (DEBUG) printf("Datoteka odprta!\n");
    }

    return fp;
}

int isAlphabetic(char c) {
    switch (toupper(c)) {
        case 'A' :
            return 1;
        case 'B' :
            return 1;
        case 'C':
            return 1;
        case 'D' :
            return 1;
        case 'E':
            return 1;
        case 'F' :
            return 1;
        case 'G':
            return 1;
        case 'H' :
            return 1;
        case 'I':
            return 1;
        case 'J' :
            return 1;
        case 'K':
            return 1;
        case 'L' :
            return 1;
        case 'M':
            return 1;
        case 'N' :
            return 1;
        case 'O' :
            return 1;
        case 'P':
            return 1;
        case 'Q' :
            return 1;
        case 'R':
            return 1;
        case 'S':
            return 1;
        case 'T' :
            return 1;
        case 'U' :
            return 1;
        case 'V':
            return 1;
        case 'X' :
            return 1;
        case 'Y':
            return 1;
        case 'W' :
            return 1;
        case 'Z':
            return 1;
        case ' ' :
            return 1;
        case '/' :
            // TODO: Nova vrstica
            return 1;
        case '!' :
            return 1;
        default:
            return 0;
    }
}
