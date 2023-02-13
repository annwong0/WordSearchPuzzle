/**
 * ENGG1110 Problem Solving by Programming
 *
 * Course Project
 *
 * I declare that the project here submitted is original
 * except for source material explicitly acknowledged,
 * and that the same or closely related material has not been
 * previously submitted for another course.
 * I also acknowledge that I am aware of University policy and
 * regulations on honesty in academic work, and of the disciplinary
 * guidelines and procedures applicable to breaches of such
 * policy and regulations, as contained in the website.
 *
 * University Guideline on Academic Honesty:
 *   https://www.cuhk.edu.hk/policy/academichonesty/
 *
 * Student Name  : <your name>
 * Student ID    : <your student ID>
 * Class/Section : <your class/section>
 * Date          : <date>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Macros */
#define MAX_GRID 10
#define MAX_WORDLIST 8
#define MAX_WORD 11
#define MAX_FILENAME 260


/* NO global variables are allowed */


/* Read the letter grid from console into the 2D array parameter letterGird
   Return the size of the letter grid */
int readLetterGridFromConsole(char letterGrid[MAX_GRID][MAX_GRID]) {
    int row, col;
    int gridSize;

    printf("Enter the size of the letter grid:\n");
    scanf("%d", &gridSize);
    printf("Enter the letter grid:\n");

    for(row = 0; row < gridSize; row++) {
        for(col = 0; col < gridSize; col++) {
            /* In scanf(), use " %c" instead of "%c" to read the first non-whitespace character,
               so that the newline character at the end of the previous line can be ignored */
            scanf(" %c", &letterGrid[row][col]);
        }
    }

    return gridSize;
}


/* Read the word list from console into the 2D array parameter wordList
   Return the number of words */
int readWordListFromConsole(char wordList[MAX_WORDLIST][MAX_WORD]) {
    int i;
    int listSize;

    printf("Enter the size of the word list:\n");
    scanf("%d", &listSize);
    printf("Enter the word list:\n");
    for(i = 0; i < listSize; i++) {
        /* no & before wordList[i] since wordList[i] already represents the memory address */
        scanf("%s", wordList[i]);
    }

    return listSize;
}


/* Read the letter grid from file into the 2D array parameter letterGird
   Return
        the size of the letter grid if successful
        -1 if there is any file reading error */
int readLetterGridFromFile(char letterGrid[MAX_GRID][MAX_GRID]) {


/* TODO: Complete the function, you can refer to readLetterGridFromConsole() for reference */


}


/* Read the word list from file into the 2D array parameter wordList
   Return
         the number of words if successful
         -1 if there is any file reading error */
int readWordListFromFile(char wordList[MAX_WORDLIST][MAX_WORD]) {


/* TODO: Complete the function, you can refer to readWordListFromConsole() for reference */


}


/* Display the letter grid, assume gridSize <= 10 */
void printLetterGrid(char letterGrid[MAX_GRID][MAX_GRID], int gridSize) {
    int row, col;

    /* For debugging */
    if(gridSize < 2 || gridSize > MAX_GRID) {
        printf("DEBUG: gridSize is %d but not between 2 and %d\n", gridSize, MAX_GRID);
        printf("Program terminates.\n");
        exit(1);
    }

    printf("### %d x %d Letter Grid ###\n", gridSize, gridSize);


/* TODO: Print the letter grid */


}


/* Display the word list stored in wordList of size listSize with the matching status for each word */
void printWordList(char wordList[MAX_WORDLIST][MAX_WORD], int listSize, int matchingStatus[MAX_WORDLIST]) {
    int i;

    /* For debugging */
    if(listSize < 1 || listSize > MAX_WORDLIST) {
        printf("DEBUG: listSize is %d but not between 1 and %d\n", listSize, MAX_WORDLIST);
        printf("Program terminates.\n");
        exit(1);
    }

    printf("### Word List of Size %d ###\n", listSize);


/* TODO: Print the word list with matching status */


}


/* Check whether the input word is in the word list and whether it is matched before
   Return
        the index of the input word in the word list (i.e., a value between 0 and listSize - 1) if the input word is in the word list and has not been matched before
        listSize if the input word is in the word list but has been matched already
        -1 if the input word is not in the word list */
int checkWordList(char wordList[MAX_WORDLIST][MAX_WORD], int listSize, int matchingStatus[MAX_WORDLIST], char inputWord[MAX_WORD]) {


/* TODO: Complete the function */


}


/* Check whether the input word is in the letter grid in the specified row, column, and direction
   Return
        1 if the input word is in the letter grid in the specified row, column, and direction
        0 if the input word cannot be found in the letter grid in the specified row, column, and direction
        -1 if the search of the input word exceeds the boundary of the letter grid
   This function should not print anything, except debugging messages (if any) */
int checkLetterGrid(char letterGrid[MAX_GRID][MAX_GRID], int gridSize, char inputWord[MAX_WORD], int matchRow, int matchCol, int matchDirection) {


/* TODO: Complete the function */


}


/* Display the secret table */
void printSecretTable(/* put your parameter list here */) {


/* TODO: Complete the function */


}

/* The main() function */
int main()
{
    int gridSize;
    char letterGrid[MAX_GRID][MAX_GRID];
    int listSize;
    char wordList[MAX_WORDLIST][MAX_WORD];
    int matchingStatus[MAX_WORDLIST];     /* Each element should be either 0 (not matched) or 1 (matched) */


/* TODO: Complete the main() function by invoking the functions declared above */


    /* Ask the user whether to read the data from file */


    /* Read the letter grid and the word list from file or console */


    /* Initialize all elements in the matchingStatus array to 0 */


    /* FOR TESTING: Uncomment the following two statements to print the letter grid and the word list
       You can move them elsewhere after testing
       Please make sure the five arguments are initialized properly */
    //printLetterGrid(letterGrid, gridSize);
    //printWordList(wordList, listSize, matchingStatus);


    /* Read the user input repeatedly until the puzzle finishes */


    return 0;
}
