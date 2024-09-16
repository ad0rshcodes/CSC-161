# [Homework 2: Rock, Paper, Scissors](https://eikmeier.sites.grinnell.edu/csc-161-fall-2024/hw/02-rock-paper-scissors/)

## Requirements

Your program should implement the following behaviors:

1. Ask the user how many rounds of Rock, Paper, Scissors they’d like to play
2. At the beginning of each round, print the current number of wins for each player, and prompt the user for Rock, Paper, or Scissors for the current round.
3. Use integers to stand in for each of the options, and be sure to communicate to the user what options they have for input.
4. If an invalid option is selected by the user, do not count this as one of the rounds, allow the user to choose again. Conversely, if the result of the round is a tie (both players choose the same option), this is a valid round.
5. After each round, print a summary of what was chosen by each player and who won that round. Please print “Rock” rather than the number 1, for example. After all rounds are completed, print who is the overall winner.

6. Throughout, make use of spacing and new line characters to make the terminal output easy to follow.

## Handling Inputs

When you present users with a choice of several options, print them with numbers and ask them to type the number corresponding to the option they want. We will explore alternative ways to collect input from users later in the semester.

Your program must check the validity of all inputs; a number of rounds that is 0 or negative should be rejected, as should any attempt to select an option that does not exist. When a user provides an invalid input, print a message to report that the input was invalid (include an explanation of why) and ask them to try again. We haven’t yet looked at how we can read non-numeric data, so you may assume users will always type a number when you ask them to. Just don’t assume the number will be acceptable without checking it first.

## What to Submit

You will submit your work for this homework assignment on gradescope. Please upload your implementation in a file named rockpaperscissors.c, along with a testing transcript. You can create a testing transcript by running:

`script tests.txt`

The command above will record the commands you run and any outputs to a file named tests.txt. Run the program as many times as you need to thoroughly test your implementation, then run exit to end the transcript. Include tests.txt with your implementation when you submit your work to gradescope.

You should make sure your testing covers at least the following cases:

Valid inputs for number of rounds and user selections (there are quite a few combinations of valid inputs, therefore there should be several tests within this category)

Invalid inputs for number of rounds (negative numbers, zero)
Invalid inputs for user selections (you determine these based on your program design)

It is in your interest to be thorough with your testing. Your tests must cover these cases to receive credit for the testing portion of your grade, but testing your code will help you find bugs that might otherwise have hurt your score in other parts of the assignment.
