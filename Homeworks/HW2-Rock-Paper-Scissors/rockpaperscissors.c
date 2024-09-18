/**
 * Homework 2: Rock, Paper, Scissors
 * Author: Adarsh Sharma
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    srand((unsigned)time(NULL));

    int rounds = 0;

    // Taking valid round input from user. Error generated if negative or 0 value is given
    while (rounds <= 0)
    {
        printf("Welcome! How many rounds do you want to play: ");
        scanf("%d", &rounds);

        if (rounds <= 0)
        {
            printf("\n Enter permissible values for rounds you want to play. The value of rounds should be greater than 0. Try again! \n \n ------------------------- \n \n");
        }
    }

    // Win counts
    int userWins = 0;
    int computerWins = 0;

    // Looping through each round.
    for (int i = 0; i < rounds; i++)
    {
        // Computer and user responses.
        int userResponse = -1;
        int computerResponse = -1;

        printf("\n \nScore Card: \n \n");
        printf("Your wins: %d \n", userWins);
        printf("Opponent's wins: %d \n \n", computerWins);

        // Input loop that considers only valid inputs.

        while (userResponse != 0 && userResponse != 1 && userResponse != 2)
        {
            printf("Make your decision for the next round. You can choose amongst 3 integers: 0, 1, 2. Each integer corresponds to the following values. \n 0: Rock \n 1: Paper \n 2: Scissors \n \n");

            printf("Your choice for this round: ");
            scanf("%d", &userResponse);

            if (userResponse != 0 && userResponse != 1 && userResponse != 2)
            {
                printf("\n\nYour input value is invalid. Your input needs to one of the following numbers: 0, 1, 2. Anything apart from these will be an error!! \n Now try again. \n \n");
            }
        }

        // Generating random number between 0 to 2.
        computerResponse = rand() % 3;

        // test cases for each round
        /*
            0: rock
            1: paper
            2: scissors
        */

        // Posibilities check
        if (userResponse == 0 && computerResponse == 0)
        {
            printf("Tie!! Both players choose rock.");
            userWins++;
            computerWins++;
        }
        else if (userResponse == 1 && computerResponse == 1)
        {
            printf("Tie!! Both players choose paper.");
            userWins++;
            computerWins++;
        }
        else if (userResponse == 2 && computerResponse == 2)
        {
            printf("Tie!! Both players choose scissors.");
            userWins++;
            computerWins++;
        }
        else if (userResponse == 0 && computerResponse == 1)
        {
            printf("Other player won!! You chose Rock and the other player chose Paper.");
            computerWins++;
        }
        else if (userResponse == 0 && computerResponse == 2)
        {
            printf("You won!! You chose Rock and the other player chose Scissors.");
            userWins++;
        }
        else if (userResponse == 1 && computerResponse == 0)
        {
            printf("You won!! You chose Paper and the other player chose Rock.");
            userWins++;
        }
        else if (userResponse == 1 && computerResponse == 2)
        {
            printf("Other player won!! You chose Paper and the other player chose Scissors.");
            computerWins++;
        }
        else if (userResponse == 2 && computerResponse == 0)
        {
            printf("Other player won!! You chose Scissors and the other player chose Rock.");
            computerWins++;
        }
        else if (userResponse == 2 && computerResponse == 1)
        {
            printf("You won!! You chose Scissors and the other player chose Paper.");
            userWins++;
        }
        else
        {
            printf("Something is not working as intended!!");
        }
    }

    printf("\n\nAll the rounds are completed!!\n\n");

    // Determining and printing who won

    if (userWins > computerWins)
    {
        printf("You WON!!");
    }
    else if (computerWins > userWins)
    {
        printf("You LOST!!");
    }
    else
    {
        printf("It's a TIE!!");
    }

    printf("\n Final Scores:\n");

    printf("Your Wins: %d \n", userWins);
    printf("Other player Wins: %d \n \n", computerWins);

    printf("Thanks for Playing :)\n");

    return 0;
}