#include <cstdio>
#include <cstdlib>
#include <ctime>

int main() {
    printf("Welcome to Number Guesser!\n");
    //  initialise random number generator with current time
    srand(time(NULL));

    //  keep playing until user wants to quit
    bool exit = false;
    while(!exit) {
        //  the minimum and maximum numbers to guess between
        int maxGuess = 100, minGuess = 1;
        int curGuess, tries = 0;
        //  generate random number
        int num = rand() % (maxGuess - 1) + minGuess;

        //  greet user and prompt for first guess
        printf("A number between %d and %d has been generated.\n", minGuess, maxGuess);
        printf("Enter your guess (%d - %d): ", minGuess, maxGuess);
        //  keep asking for numbers if user doesn't enter one
        while(scanf("%d", &curGuess) != 1 || curGuess > maxGuess || curGuess < minGuess) {
            printf("Please enter a valid number between %d and %d: ", minGuess, maxGuess);
        }
        
        //  count first guess
        tries++;

        //  not correct, inform user then prompt for next number
        while(curGuess != num) {
            //  update guess range
            if(curGuess > num) {
                printf("Your guess was too high\n");
                maxGuess = curGuess - 1;
            } else if(curGuess < num) {
                printf("Your guess was too low\n");
                minGuess = curGuess + 1;
            }

            //  prompt for next guess
            printf("Enter your guess (%d - %d): ", minGuess, maxGuess);
            while(scanf("%d", &curGuess) != 1 || curGuess > maxGuess || curGuess < minGuess) {
                printf("Please enter a valid number between %d and %d: ", minGuess, maxGuess);
            }
            
            //  count guess
            tries++;
        }

        //  done, print number and attempt count
        printf("Congrats! The number was %d and you guessed it in %d tries.\n", num, tries);

        //  ask to play again
        printf("Would you like to play again (Y/N)? ");
        char answer;
        //  read twice to skip the newline character at the end of the input stream
        scanf("%c %c", &answer, &answer);
        while(answer != 'Y' && answer != 'N' && answer != 'y' && answer != 'n') {
            printf("Please enter Y or N: ");
            //  read twice to skip the newline character at the end of the input stream
            scanf("%c %c", &answer, &answer);
        }

        if(answer == 'n' || answer == 'N') exit = true;
    }
    printf("Thanks for playing!\n");
    return 0;
}
