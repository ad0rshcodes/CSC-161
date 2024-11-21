/**
 * Author: Adarsh Sharma
 * Resources Used: Class Textbook, labs and readings
 * Date: Nov 20, 2024
 */

#include <stdio.h>
#include <string.h>

#define MAX_WORD_LEN 100

// definiting structure to store position
typedef struct
{
    int row;
    int col;
    char direction; // 'H' for horizontal, 'V' for vertical
} Position;

typedef struct
{
    char word[MAX_WORD_LEN];
    Position pos;
    int found;
} WordEntry;

// Function prototypes for good practice
void read_dimensions(FILE *file, int *rows, int *cols);
void read_grid(FILE *file, int rows, int cols, char grid[rows][cols]);
void read_word(FILE *file, char *word);
int check_horizontal_word(int rows, int cols, char grid[rows][cols], const char *word, int row, int col);
int check_vertical_word(int rows, int cols, char grid[rows][cols], const char *word, int row, int col);
void search_horizontal(int rows, int cols, char grid[rows][cols], WordEntry *word_entry);
void search_vertical(int rows, int cols, char grid[rows][cols], WordEntry *word_entry);
void print_solution(const WordEntry *word_entry);
void mark_word_in_visual(int rows, int cols, char visual[rows][cols], const WordEntry *word_entry);
void init_visual(int rows, int cols, char visual[rows][cols]);
void print_visual(int rows, int cols, char visual[rows][cols]);

int main(int argc, char *argv[])
{
    // Opening the puzzle file.

    FILE *file = fopen(argv[1], "r");

    if (!file)
    {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    // Read dimensions
    int rows, cols;
    read_dimensions(file, &rows, &cols);

    // Create VLAs
    char grid[rows][cols];
    char visual[rows][cols];

    // Read the puzzle grid
    read_grid(file, rows, cols, grid);

    // Initialize the final output grid
    init_visual(rows, cols, visual);

    // Process words
    WordEntry current_word;
    char temp;
    fscanf(file, "%c", &temp); // Consume newline

    // Main loop to process each word from the input file
    while (fscanf(file, "%s", current_word.word) == 1)
    {
        current_word.found = 0;

        search_horizontal(rows, cols, grid, &current_word);
        if (!current_word.found)
        {
            search_vertical(rows, cols, grid, &current_word);
        }

        if (current_word.found)
        {
            print_solution(&current_word);
            mark_word_in_visual(rows, cols, visual, &current_word);
        }
    }

    printf("\n");
    print_visual(rows, cols, visual);

    fclose(file);
    return 0;
}

// Function to read the dimensions of the puzzle grid from the file
void read_dimensions(FILE *file, int *rows, int *cols)
{
    fscanf(file, "%d %d", rows, cols);
}

// Function to read the puzzle grid from the file into a 2D array
void read_grid(FILE *file, int rows, int cols, char grid[rows][cols])
{
    char temp;
    fscanf(file, "%c", &temp); // Consume newline
    // Loop through each row of the grid
    for (int i = 0; i < rows; i++)
    {
        // Loop through each column in the current row
        for (int j = 0; j < cols; j++)
        {
            fscanf(file, " %c", &grid[i][j]);
        }
    }
}

// Function to check if a word exists horizontally at a given position
// Returns: 1 if word found, 0 if not found
int check_horizontal_word(int rows, int cols, char grid[rows][cols], const char *word, int row, int col)
{
    int len = strlen(word);
    if (col + len > cols)
        return 0;

    // Check each character of the word against the grid
    for (int k = 0; k < len; k++)
    {
        if (grid[row][col + k] != word[k])
        {
            return 0;
        }
    }
    return 1;
}

// Function to search for a word horizontally in the entire grid
void search_horizontal(int rows, int cols, char grid[rows][cols], WordEntry *word_entry)
{
    // Loop through each row
    for (int i = 0; i < rows && !word_entry->found; i++)
    {
        // Loop through each possible starting position in the row
        for (int j = 0; j < cols; j++)
        {
            if (check_horizontal_word(rows, cols, grid, word_entry->word, i, j))
            {
                word_entry->found = 1;
                word_entry->pos.row = i;
                word_entry->pos.col = j;
                word_entry->pos.direction = 'H';
                break;
            }
        }
    }
}

// Function to check if a word exists vertically at a given position
// Returns: 1 if word found, 0 if not found
int check_vertical_word(int rows, int cols, char grid[rows][cols], const char *word, int row, int col)
{
    int len = strlen(word);
    if (row + len > rows)
        return 0;

    // Check each character of the word against the grid
    for (int k = 0; k < len; k++)
    {
        if (grid[row + k][col] != word[k])
        {
            return 0;
        }
    }
    return 1;
}

// Function to search for a word vertically in the entire grid
void search_vertical(int rows, int cols, char grid[rows][cols], WordEntry *word_entry)
{
    // Loop through each column
    for (int j = 0; j < cols && !word_entry->found; j++)
    {
        // Loop through each possible starting position in the column
        for (int i = 0; i < rows; i++)
        {
            if (check_vertical_word(rows, cols, grid, word_entry->word, i, j))
            {
                word_entry->found = 1;
                word_entry->pos.row = i;
                word_entry->pos.col = j;
                word_entry->pos.direction = 'V';
                break;
            }
        }
    }
}

// Function to print the solution for a found word
void print_solution(const WordEntry *word_entry)
{
    printf("%s (%d, %d) %s\n",
           word_entry->word,
           word_entry->pos.row,
           word_entry->pos.col,
           word_entry->pos.direction == 'H' ? "horizontal" : "vertical");
}

// Function to initialize the visual grid with spaces
void init_visual(int rows, int cols, char visual[rows][cols])
{
    // Loop through each row
    for (int i = 0; i < rows; i++)
    {
        // Loop through each column
        for (int j = 0; j < cols; j++)
        {
            visual[i][j] = ' ';
        }
    }
}

// Function to mark a found word in the visual grid
void mark_word_in_visual(int rows, int cols, char visual[rows][cols], const WordEntry *word_entry)
{
    int len = strlen(word_entry->word);
    if (word_entry->pos.direction == 'H')
    {
        // Loop to mark horizontal word
        for (int j = 0; j < len; j++)
        {
            visual[word_entry->pos.row][word_entry->pos.col + j] = word_entry->word[j];
        }
    }
    else
    {
        // Loop to mark vertical word
        for (int i = 0; i < len; i++)
        {
            visual[word_entry->pos.row + i][word_entry->pos.col] = word_entry->word[i];
        }
    }
}

// Function to print the visual grid showing found words
void print_visual(int rows, int cols, char visual[rows][cols])
{
    // Loop through each row
    for (int i = 0; i < rows; i++)
    {
        // Loop through each column
        for (int j = 0; j < cols; j++)
        {
            printf("%c ", visual[i][j]);
        }
        printf("\n");
    }
}