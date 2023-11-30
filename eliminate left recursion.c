#include <stdio.h>
#include <string.h>
void eliminateLeftRecursion(char nonTerminal, char production[][100], int numProductions) {
    int i, j;
    printf("Productions with left recursion for %c:\n", nonTerminal);
    for (i = 0; i < numProductions; i++) {
        if (production[i][0] == nonTerminal) {
            printf("%s\n", production[i]);
        }
    }
    printf("\nAfter eliminating left recursion:\n");
    for (i = 0; i < numProductions; i++) {
        if (production[i][0] != nonTerminal) {
            printf("%s\n", production[i]);
        }
    }
    for (i = 0; i < numProductions; i++) {
        if (production[i][0] == nonTerminal) {

            for (j = 0; j < numProductions; j++) {
                if (production[j][0] != nonTerminal) {
                    printf("%c->%s%c'\n", nonTerminal, production[j], nonTerminal);
                }
            }
            printf("%c'->%s%c' | epsilon\n", nonTerminal, production[i] + 1, nonTerminal);
        }
    }
}

int main() {
    // Example grammar
    char nonTerminal = 'A';
    char production[][100] = {"A->Aa", "A->Ab", "A->c", "B->Ba", "B->Bb", "B->d", "C->Cg", "C->f", "C->e"};

    int numProductions = sizeof(production) / sizeof(production[0]);

    eliminateLeftRecursion(nonTerminal, production, numProductions);

    return 0;
}
