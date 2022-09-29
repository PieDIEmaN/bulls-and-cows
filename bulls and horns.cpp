#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char code[5];
    char guess[5];
    int bulls, hits;
    int i, j;
    
    srand(time(NULL));
    for (i = 0; i < 4; i++) {
        code[i] = rand() % 9 + '0';
        for (j = 0; j < i; j++) {
            if (code[j] == code[i]) {
                i--;
            }
        }
    }
    
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5; j++) {
            if (code[i] == code[j])
                break;
        }
    }
    for (i = 0; i < 4; i++) {
        printf("%c", code[i]);
    }
    putchar('\n');

    do {
        bulls = 0;
        hits = 0;
        scanf("%s", guess);
        for (i = 0; i < 4; i++) {
            for (j = i + 1; j < 4; j++) {
                if (guess[i] == guess[j]) {
                    printf("Invalid entry. The digits have to differ\n");
                    break;
                }
            }
        }

        for (i = 0; i < 4; i++) {
            for (j = 0; j < 5; j++) {
                if (code[i] == guess[j]) {
                    if (i == j) {
                        bulls++;
                    }
                    else {
                        hits++;
                    }
                }
            }
        }

        printf("%d bulls %d hits\n", bulls, hits);
    } while (bulls != 4);
    printf("nice");

    return 0;
}