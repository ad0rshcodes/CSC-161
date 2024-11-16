/**
 * Author: Adarsh Sharma
 * Submission 02
 * Date: Nov 15, 2024
 */

#include <stdio.h>
#define MAX_LEN 100

// Validate if the input contains only lowercase letters
int validate_input(char message[], int length)
{
    // Check if any character is capital letter or other symbols.
    for (int i = 0; i < length; i++)
    {
        if (message[i] < 'a' || message[i] > 'z')
        {
            return 0; // Invalid input found
        }
    }
    return 1; // Valid input
}

// Display all encoding or decoding shifts
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

// Function to get the user's choice for encoding or decoding
char get_option()
{
    char option;
    printf("This program encrypts and decrypts messages using the Caesar Cipher.\n");
    printf("Type 'e' to encode or 'd' to decode a message: ");
    option = getchar();
    getchar(); // Consume newline character

    // Check if user inputs a wrong character and display the error message.
    if (option != 'e' && option != 'd')
    {
        printf("Invalid option! Please enter 'e' to encode or 'd' to decode.\n");
        // returning null character to make sure that the invalid input doesn't get used by other functions and lead to unpredictable behavior.
        return '\0'; // Return null character on invalid input
    }
    return option;
}

// Function to get the input message from the user
int get_message(char message[])
{
    printf("Enter the string to process (lowercase letters only): ");
    int length = 0;
    char ch;

    // Get input from the user and initialise the message array with input
    while ((ch = getchar()) != '\n' && length < MAX_LEN)
    {
        message[length] = ch;
        length++;
    }
    message[length] = '\0'; // Null-terminate the string
    return length;
}

// Function to process user input and display encoding/decoding shifts
void process_shifts(char option, char message[], int length)
{
    if (!validate_input(message, length))
    {
        printf("Invalid input! Please enter lowercase letters only.\n");
        return;
    }
    if (option == 'd')
    {
        display_shifts(message, length, 1);
    }
    else
    {
        display_shifts(message, length, 0);
    }
}

int main()
{
    char message[MAX_LEN];
    char option = get_option();

    // check on what get_option() returned and whether its a valid input or not.
    if (option == '\0')
    {
        return 1; // Exit on invalid option
    }

    int length = get_message(message);
    process_shifts(option, message, length);
    return 0;
}
