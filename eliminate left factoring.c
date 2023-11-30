#include <stdio.h>
#include <string.h>
void eliminateLeftFactoring(char nonTerminal, char production[][100], int numProductions) {
    int i, j;
    printf("Common prefix for left factoring in %c:\n", nonTerminal);
    int commonPrefixLength = 0;
    while (production[0][commonPrefixLength] == production[1][commonPrefixLength]) {
        commonPrefixLength++;
    }
    for (i = 0; i < commonPrefixLength; i++) {
        printf("%c", production[0][i]);
    }
    printf("\n");
    printf("\nAfter eliminating left factoring:\n");
    printf("%c->%.*s%c'\n", nonTerminal, commonPrefixLength, production[0], nonTerminal);
    for (i = 0; i < numProductions; i++) {
        if (production[i][0] != nonTerminal) {
            printf("%c'->%s\n", nonTerminal, production[i] + commonPrefixLength);
        }
    }
    printf("%c'->epsilon\n", nonTerminal);
}
int main() {
    char nonTerminal = 'A';
    char production[][100] = {"A->abxyz", "A->abcw", "B->ba", "B->bcd"};

    int numProductions = sizeof(production) / sizeof(production[0]);

    eliminateLeftFactoring(nonTerminal, production, numProductions);

    return 0;
}
