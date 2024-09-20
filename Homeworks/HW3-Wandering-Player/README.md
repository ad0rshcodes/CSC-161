# [Homework 3: Wandering Player](https://eikmeier.sites.grinnell.edu/csc-161-fall-2024/hw/03-wandering-player/)

## Overview

In many video games there are non-playing-characters (NPC) who wander around a map, potentially triggering an interaction with the player if the player and the NPC happen to occupy the same space at the same time. In this assignment we will implement a simple wandering player on a 2D grid.

## Requirements

In your game, you will use a 2D array of characters to keep track of the NPC’s location. Use a 10-by-10 array, and initialize every cell to contain a period character (‘.’). The game will progress in the following manner:

1. Choose a random location on the grid for the NPC to start, and change the character in that cell to ‘A’.
2. Make the player move in a random direction (left, right, up, or down), and fill that cell in with the next letter, ‘B’.
3. Continue on in the same way, moving through the grid and placing the next letter of the alphabet.
4. There are a few rules for the movement of the NPC: the NPC cannot move into a space that has previously been occupied, and the NPC cannot move “off” of the grid. When you choose one of the four random directions to move, you must make sure it’s a valid move based on these rules. If it’s not valid, choose a random direction again.
5. After each letter is placed, the program should print the 10-by-10 array showing the placement of the letters (along with the periods).
6. The program should end when one of the two conditions is met: either the NPC has no more valid moves, or we have reached the letter ‘Z’.

## What to Submit

You will submit your work for this homework assignment on gradescope. Please upload your implementation in a file named wanderingplayer.c, along with a testing transcript. You can create a testing transcript by running:

`script tests.txt`

The command above will record the commands you run and any outputs to a file named tests.txt. Run the program as many times as you need to thoroughly test your implementation, then run exit to end the transcript. Include tests.txt with your implementation when you submit your work to gradescope.

In this assignment, there is no user input or variables that will change on different runs. The changes will come from the random-ness of the movements of the NPC. Therefore, you should run your program enough times that you are (fairly) confident it runs as you expect. You should be sure to see your program can make it to the letter ‘Z’ successfully, as well as multiple cases where it ends earlier due to lack of valid moves. You should be confident that your NPC can move in any of the four directions.

It is in your interest to be thorough with your testing, testing your code will help you find bugs that might otherwise have hurt your score in other parts of the assignment.
