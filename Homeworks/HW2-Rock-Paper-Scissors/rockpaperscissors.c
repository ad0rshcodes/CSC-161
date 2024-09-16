#include <stdio.h>

int main()
{
    int rounds = 0;

    while (rounds <= 0)
    {
        printf("Welcome! How many rounds do you want to play: ");
        scanf("%d", &rounds);

        if (rounds <= 0)
        {
            printf("\n Enter permissible values for rounds you want to play. The value of rounds should be greater than 0. Try again! \n \n ------------------------- \n \n");
        }
    }

    int userWins = 0;
    int computerWins = 0;

    for (int i = 0; i < rounds; i++)
    {

        int userResponse = -1;
        int computerResponse = -1;

        printf("\n \nScore Card: \n \n");
        printf("Your wins: %d \n", userWins);
        printf("Opponent's wins: %d \n \n", computerWins);

        // Input loop that considers only valid inputs.

        while (userResponse != 0 && userResponse != 1 && userResponse != 2)
        {
            printf("Make your decision for the next round. \n 0: Rock \n 1: Paper \n 2: Scissors \n");

            printf("Your choice for this round: ");
            scanf("%d", &userResponse);

            if (userResponse != 0 && userResponse != 1 && userResponse != 2)
            {
                printf("Your input value is invalid. Your input needs to one of the following numbers: 0, 1, 2. Anything apart from these will be an error!! \n Now try again. \n");
            }
        }

        // Rest of the code that will generate random number and compare the input with the random number.
    }

    return 0;
}