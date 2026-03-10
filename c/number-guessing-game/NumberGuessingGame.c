 #include <stdio.h>
 #include <stdlib.h>
 #include <ctype.h>
 #include <time.h>

 int main(){
	srand(time(NULL));
    while(1){
        int difficulty, max, hint=0, num, usr_guess, max_guess;
        char hint_choice, replay;

        printf("WELCOME TO NUMBER GUESSING GAME.\n\n");
        
        while(1){
            printf("Select difficulty:\n1)Easy -> 7 Guesses.\n2)Medium -> 5 Guesses.\n3)Hard -> 3 Guesses.\n");
            scanf("%d",&difficulty);

            switch(difficulty){
                case 1:
                    max_guess = 7;
                    break;
                case 2:
                    max_guess = 5;
                    break;
                case 3:
                    max_guess = 3;
                    break;
                default:
                    printf("Wrong input!\n");
                    continue;
            }break;
        }

        printf("Do you want to turn on the hint? (y/n) :");
        scanf(" %c",&hint_choice);
        if(tolower(hint_choice) == 'y'){
            hint = 1;
        }

        while(1){
            printf("Enter the maximum number for the guessing game: ");
            scanf("%d", &max);

            if(max <= 0){
                printf("The maximum number must be greater than 0.\n");
                continue;
            }
            else{
                break;
            }
        }

        num = rand() % max +1;

        for(int i=1; i<=max_guess; i++){
            printf("Guess the number in %d guesses.\n",max_guess + 1 - i);
            scanf("%d",&usr_guess);

            if(usr_guess == num){
                printf("\nCongratulations.\nYou got it in guess %d\n",i);
                break;
            }
            else if(hint && usr_guess < num){
                printf("Its higher!\n");
            }
            else if(hint && usr_guess > num){
                printf("Its lower!\n");
            }
            else{
                printf("Wrong guess!\n\n");
            }
        }
        printf("The number was %d.\n\n",num);

        printf("Do you want to play again? (y/n) :");
        scanf(" %c",&replay);

        if(tolower(replay) != 'y'){
            break;
        }
    }
 }
