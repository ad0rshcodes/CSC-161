#include <stdio.h>

#define MAX_LEN 100

// Function to display all encoding or decoding
void display_shifts(char message[], int length, int is_decode)
{
    // for loop to over all the possibilities of n and give multiple encoded strings.
    for (int n = 0; n < 26; n++)
    {
        printf("n=%d: ", n);
        // for loop to go over each character in the string and encode or decode that character
        for (int i = 0; i < length; i++)
        {
            char ch = message[i];

            // encoding and decoding each character
            if (is_decode)
            {
                // shift left by n positions
                ch = ((ch - 'a' - n + 26) % 26) + 'a';
            }
            else
            {
                // shift right by n positions
                ch = ((ch - 'a' + n) % 26) + 'a';
            }
            printf("%c", ch);
        }
        printf("\n");
    }
}

// Function to validate if the input contains only lowercase letters
int validate_input(char message[], int length)
{
    for (int i = 0; i < length; i++)
    {
        if (message[i] < 'a' || message[i] > 'z')
        {
            return 0; // Invalid input found
        }
    }
    return 1; // Valid input
}

int main()
{
    char option;
    char message[MAX_LEN];
    int length = 0;

    // Description
    printf("This program encrypts and decrypts messages using the Caesar Cipher.\n");
    printf("Type 'e' to encode or 'd' to decode a message: ");

    option = getchar();
    getchar(); // this getchar() will take '\n' after we press enter.

    // Check if the user wants to encode or decode
    if (option != 'e' && option != 'd')
    {
        printf("Invalid option! Please enter 'e' to encode or 'd' to decode.\n");
        return 1; // return 1 is usually used when we our program didn't run completely and encountered an error.
    }

    // Prompt for the message
    printf("Enter the string to ");
    if (option == 'e')
    {
        printf("encode: ");
    }
    else
    {
        printf("decode: ");
    }

    // Real message input until newline or max length is reached
    char ch;
    while ((ch = getchar()) != '\n' && length < MAX_LEN)
    {
        message[length] = ch;
        length++;
    }

    // Validate the input (lowercase letters only)
    if (!validate_input(message, length))
    {
        printf("Invalid input! Please enter lowercase letters only.\n");
        return 1;
    }

    // Display all shifts for encoding or decoding
    if (option == 'd')
    {
        display_shifts(message, length, 1);
    }
    else
    {
        display_shifts(message, length, 0);
    }

    return 0;
}
