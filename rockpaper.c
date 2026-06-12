#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <string.h>


int rand_num(){
    int num;
    num = (rand() % 3) + 1; //generates in range 0-2, +1 will makes it 1-3
    return num;
}

int rock(){
    int ui , score_ui = 0, score_co = 0;
    char rps[3][10] = {"Rock", "Paper", "Scissor"};
    char uirps[3][10] = {"Rock", "Paper", "Scissor"};
    
    while (1){
        printf("\nEnter your choice \n 1: Rock \n 2: Paper \n 3: Scissor\n 4: Show Score\n");
        printf("Press 0 to exit\n");
        scanf("%d", &ui);
        int co = rand_num();
        
        if (ui == co){
            printf("Tie");
            printf("\nComputer chose: %s, you chose: %s", rps[co-1], uirps[ui-1]);
        }
        
        else if ((ui == 1 && co == 2) || (ui == 2 && co == 3) || (ui == 3 && co == 1)){
            printf("Computer won!");
            printf("\nYou entered %s, computer chose %s", uirps[ui-1], rps[co-1]);
            score_co = score_co + 1;
        }
        
        else if (ui == 0){
            break;
        }
        
        else if (ui == 4){
            printf("\nShowing scores: ");
            printf("\nYou: %d", score_ui);
            printf("\nYou: %d", score_co);
        }
        
        else{
            printf("You won!");
            printf("\nYou entered %s, computer chose %s", uirps[ui-1], rps[co-1]);
            score_ui = score_ui + 1;
        }
}
    return 0;
}

int main(){
    int ui;
    srand(time(NULL));
    printf("----Rock paper scissor----");
    printf("\nEnter 1 if you want to play: ");
    scanf("%d", &ui);
    if (ui == 1){
        rock();
    }
    else if (ui == 2){
        //numguess();
    }
    else {
        printf("Invalid choice!");
    }
    
    return 0;
}