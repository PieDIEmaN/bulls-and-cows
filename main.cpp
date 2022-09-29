#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int code[5];    
    short bulls, hits;
    short i, j;
    short robogues[4];

    srand(time(NULL));    

    printf("your code:\n");
    for (i = 0; i < 4; i++){
        scanf("%d", &code[i]);
    }//создание  массива   
  
    
    do {//делать
        bulls = 0;
        hits = 0;

        
        for (i = 0; i < 4; i++) {
            robogues[i] = rand() % 9 ;           
        }      
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 5; j++) {
                if (code[i] == robogues[j]) {
                    if (i == j) {
                        bulls++;
                    }
                    else {
                        hits++;
                    }
                }
            }
        }//если цифра кода ровна цифре из другого массива и стоит на том месте то плюс корова если не стоит то плюс рога 

        printf("%d bulls %d hits\n", bulls, hits);
    } while (bulls != 4); //пока быки не будут равны 4    
    printf("i won!\nMy answer: %d%d%d%d", robogues[0], robogues[1], robogues[2], robogues[3]);
    printf("\n");
    system("pause");
    return 0;
}