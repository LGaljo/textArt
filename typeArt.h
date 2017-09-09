#ifndef TYPEART_H
#define TYPEART_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static int DEBUG = 0;

int includeFont(char *word, int len, char **out);
int getWord(char *word);
void output(char **out, int width);
int isAlphabetic(char c);
FILE *openFile(FILE *fp, char crka);

#endif //TYPEART_H
