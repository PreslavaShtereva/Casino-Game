#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getBettingAmount(int totalCash) {
    int betAmount;
    do {
        printf("Enter the amount to bet: $");
        scanf("%d", &betAmount);
        if (betAmount > totalCash) {
            printf("You don't have enough money to bet that amount!\n");
        }
    } while (betAmount > totalCash);
    return betAmount;
}

int getPlayerGuess() {
    int guess;
    do {
        printf("Guess a number between 1 and 10: ");
        scanf("%d", &guess);
        if (guess < 1 || guess > 10) {
            printf("Invalid choice! Please choose a number between 1 and 10.\n");
        }
    } while (guess < 1 || guess > 10);
    return guess;
}

int main() {
    int totalCash = 1000;  // Starting amount of money for the player
    int betAmount, playerGuess, randomNumber;
    char playAgain;

    srand(time(0));

    printf("Welcome to the Casino Game!\n");
    printf("You have $1000 to start with.\n");

    do {
        if (totalCash <= 0) {
            printf("You're out of money! Game over.\n");
            break;
        }

        betAmount = getBettingAmount(totalCash);

        playerGuess = getPlayerGuess();

        randomNumber = rand() % 10 + 1;

        if (playerGuess == randomNumber) {
            printf("Congratulations! You guessed the correct number %d!\n", randomNumber);
            printf("You win $%d!\n", betAmount * 10);
            totalCash += betAmount * 10;
        } else {
            printf("Sorry, the correct number was %d. You lose $%d.\n", randomNumber, betAmount);
            totalCash -= betAmount;
        }

        printf("You now have $%d.\n", totalCash);

        if (totalCash > 0) {
            printf("Do you want to play again? (y/n): ");
            scanf(" %c", &playAgain);  // Space before %c to ignore any newline character in the buffer
        }

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("Thank you for playing! You leave with $%d.\n", totalCash);
    return 0;
}
