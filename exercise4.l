%{
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <cstring>

bool areAllDifferent(char *str) {
    // Split the string at the space character and get substring after it
    char *characters = strchr(str, ' ') + 1;

    // Check if all characters after the split are different
    for (int i = 0; characters[i] != '\0'; i++) {
        for (int j = i + 1; characters[j] != '\0'; j++) {
            if (characters[i] == characters[j]) {
                return false; // Not all characters are different
            }
        }
    }
      return true; // All characters are different
}
%}

%%
^point[[:space:]][A-Z] {
    printf("point, ok!\n");
}

^line[[:space:]][A-Z]{2}$ {
    if (areAllDifferent(yytext)) printf("line, ok!\n");
    else printf("invalid line definition\n");
}

^triangle[[:space:]][A-Z]{3}$ {
    if (areAllDifferent(yytext)) printf("triangle, ok!\n");
    else printf("invalid triangle definition\n");
}

^square[[:space:]][A-Z]{4}$ {
    if (areAllDifferent(yytext)) printf("square, ok!\n");
    else printf("invalid square definition\n");
}

^pentagon[[:space:]][A-Z]{5}$ {
    if (areAllDifferent(yytext)) printf("pentagon, ok!\n");
    else printf("invalid pentagon definition\n");
}

^hexagon[[:space:]][A-Z]{6}$ {
    if (areAllDifferent(yytext)) printf("hexagon, ok!\n");
    else printf("invalid hexagon definition\n");
}

^heptagon[[:space:]][A-Z]{7}$ {
    if (areAllDifferent(yytext)) printf("heptagon, ok!\n");
    else printf("invalid heptagon definition\n");
}

^octagon[[:space:]][A-Z]{8}$ {
    if (areAllDifferent(yytext)) printf("octagon, ok!\n");
    else printf("invalid octagon definition\n");
}

.* {
    printf("%s : invalid shape\n", yytext);
}

%%

int yywrap(){}


int main() {
    yylex();
    return 0;
}