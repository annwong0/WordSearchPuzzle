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
 * Student Name  : Wong Pui Yee
 * Student ID    : 1155127529
 * Class/Section : ENGG1110/E
 * Date          : 28/11/2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
    FILE *fptr;
    char file_name[MAX_FILENAME];
    int gridSize;
    int row, col;

    printf("Enter filename of the letter grid:\n");
    scanf("%s", file_name);

    fptr = fopen(file_name, "r");
    if (fptr == NULL){
        printf("Error in reading the letter grid file. Program terminates.\n");
        exit(-1);
    }

    fscanf(fptr, "%d", &gridSize);

    for(row = 0; row < gridSize; row++) {
        for(col = 0; col < gridSize; col++) {
        /* In scanf(), use " %c" instead of "%c" to read the first non-whitespace character,
            so that the newline character at the end of the previous line can be ignored */
            fscanf(fptr, " %c", &letterGrid[row][col]);
            }
        }

    fclose(fptr);
    return gridSize;

}


/* Read the word list from file into the 2D array parameter wordList
   Return
         the number of words if successful
         -1 if there is any file reading error */
int readWordListFromFile(char wordList[MAX_WORDLIST][MAX_WORD]) {


/* TODO: Complete the function, you can refer to readWordListFromConsole() for reference */
    FILE *fptr;
    char file_name[MAX_FILENAME];
    int listSize;
    int i;

    printf("Enter filename of the word list:\n");
    scanf("%s", file_name);

    fptr = fopen(file_name, "r");
    if (fptr == NULL){
        printf("Error in reading the word list file. Program terminates.\n");
        exit(-1);
    }

    fscanf(fptr, "%d", &listSize);

    for(i = 0; i < listSize; i++) {
        /* no & before wordList[i] since wordList[i] already represents the memory address */
        fscanf(fptr, "%s", wordList[i]);
    }

    fclose(fptr);
    return listSize;

}


/* Display the letter grid, assume gridSize <= 10 */
void printLetterGrid(char letterGrid[MAX_GRID][MAX_GRID], int gridSize) {
    int row, col;
    int i = 0, j = 0;

    /* For debugging */
    if(gridSize < 2 || gridSize > MAX_GRID) {
        printf("DEBUG: gridSize is %d but not between 2 and %d\n", gridSize, MAX_GRID);
        printf("Program terminates.\n");
        exit(1);
    }

    printf("### %d x %d Letter Grid ###\n", gridSize, gridSize);


/* TODO: Print the letter grid */
     for (row = 0; row < gridSize + 2; row++){
        for (col = 0; col < gridSize + 2; col++){
            if (row == 0 && col == 0)
                printf("  ");
            else
            if (row == 1 || col == 1)
                printf("+ ");
            else
            if (row == 0 && col >= 2){
                printf("%d ", i);
                i++;
            }
            else
            if (row >= 2 && col == 0){
                printf("%d ", j);
                j++;
            }else
            if (row >= 2 && col >= 2)
                printf("%c ", letterGrid[row-2][col-2]);
        }
        printf(" \n");
    }


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
    for (i = 0; i < listSize; i++){
        if (matchingStatus[i] == 0)
            printf("[ ] %s\n", wordList[i]);
        else
        if (matchingStatus[i] == 1)
            printf("[X] %s\n", wordList[i]);
    }



/* TODO: Print the word list with matching status */


}


/* Check whether the input word is in the word list and whether it is matched before
   Return
        the index of the input word in the word list (i.e., a value between 0 and listSize - 1) if the input word is in the word list and has not been matched before
        listSize if the input word is in the word list but has been matched already
        -1 if the input word is not in the word list */
int checkWordList(char wordList[MAX_WORDLIST][MAX_WORD], int listSize, int matchingStatus[MAX_WORDLIST], char inputWord[MAX_WORD]) {


/* TODO: Complete the function */
    int check;
    int i, j = 0;

    for (i = 0; i < listSize; i++){
        check = strcmp(inputWord, wordList[i]);
        if (check == 0){
            if (matchingStatus[i] == 0){
                return i;
            }else
            if (matchingStatus[i] != 0){
                printf("The input word has already been matched before. \n");
                return listSize;
            }
        }else
        if (check != 0){
            j++;
            if (j == listSize){
                printf("The input word is not in the word list. \n");
                return -1;
            }
        }
    }
    return 0;
}


/* Check whether the input word is in the letter grid in the specified row, column, and direction
   Return
        1 if the input word is in the letter grid in the specified row, column, and direction
        0 if the input word cannot be found in the letter grid in the specified row, column, and direction
        -1 if the search of the input word exceeds the boundary of the letter grid
   This function should not print anything, except debugging messages (if any) */
int checkLetterGrid(char letterGrid[MAX_GRID][MAX_GRID], int gridSize, char inputWord[MAX_WORD], int matchRow, int matchCol, int matchDirection) {


/* TODO: Complete the function */
    int i, len, k = 0;

    len = (int)strlen(inputWord);

    for (i = 0; i < len; i++){
        if (matchDirection == 1){
            if (inputWord[i] != letterGrid[matchRow][matchCol] && isupper(letterGrid[matchRow][matchCol])) {
                return 0;
            }else
            if (inputWord[i] != letterGrid[matchRow][matchCol] && !(isupper(letterGrid[matchRow][matchCol]))){
                return -1;
            }else
            if (inputWord[i] == letterGrid[matchRow][matchCol]){
                matchRow++;
                matchCol--;
                k++;
                if (k == len){
                    return 1;
                }
            }
        }else
        if (matchDirection == 2){
        if (inputWord[i] != letterGrid[matchRow][matchCol] && isupper(letterGrid[matchRow][matchCol])) {
                return 0;
            }else
            if (inputWord[i] != letterGrid[matchRow][matchCol] && !(isupper(letterGrid[matchRow][matchCol]))){
                return -1;
            }else
            if (inputWord[i] == letterGrid[matchRow][matchCol]){
                matchRow++;
                k++;
                if (k == len){
                    return 1;
                }
            }
        }else
        if (matchDirection == 3){
            if (inputWord[i] != letterGrid[matchRow][matchCol] && isupper(letterGrid[matchRow][matchCol])) {
                return 0;
            }else
            if (inputWord[i] != letterGrid[matchRow][matchCol] && !(isupper(letterGrid[matchRow][matchCol]))){
                return -1;
            }else
            if (inputWord[i] == letterGrid[matchRow][matchCol]){
                matchRow++;
                matchCol++;
                k++;
                if (k == len){
                    return 1;
                }
            }
        }else
        if (matchDirection == 4){
            if (inputWord[i] != letterGrid[matchRow][matchCol] && isupper(letterGrid[matchRow][matchCol])) {
                return 0;
            }else
            if (inputWord[i] != letterGrid[matchRow][matchCol] && !(isupper(letterGrid[matchRow][matchCol]))){
                return -1;
            }else
            if (inputWord[i] == letterGrid[matchRow][matchCol]){
                matchCol--;
                k++;
                if (k == len){
                    return 1;
                }
            }
        }else
        if (matchDirection == 6){
            if (inputWord[i] != letterGrid[matchRow][matchCol] && isupper(letterGrid[matchRow][matchCol])) {
                return 0;
            }else
            if (inputWord[i] != letterGrid[matchRow][matchCol] && !(isupper(letterGrid[matchRow][matchCol]))){
                return -1;
            }else
            if (inputWord[i] == letterGrid[matchRow][matchCol]){
                matchCol++;
                k++;
                if (k == len){
                    return 1;
                }
            }
        }else
        if (matchDirection == 7){
            if (inputWord[i] != letterGrid[matchRow][matchCol] && isupper(letterGrid[matchRow][matchCol])) {
                return 0;
            }else
            if (inputWord[i] != letterGrid[matchRow][matchCol] && !(isupper(letterGrid[matchRow][matchCol]))){
                return -1;
            }else
            if (inputWord[i] == letterGrid[matchRow][matchCol]){
                matchRow--;
                matchCol--;
                k++;
                if (k == len){
                    return 1;
                }
            }
        }else
        if (matchDirection == 8){
            if (inputWord[i] != letterGrid[matchRow][matchCol] && isupper(letterGrid[matchRow][matchCol])) {
                return 0;
            }else
            if (inputWord[i] != letterGrid[matchRow][matchCol] && !(isupper(letterGrid[matchRow][matchCol]))){
                return -1;
            }else
            if (inputWord[i] == letterGrid[matchRow][matchCol]){
                matchRow--;
                k++;
                if (k == len){
                    return 1;
                }
            }
        }else
        if (matchDirection == 9){
            if (inputWord[i] != letterGrid[matchRow][matchCol] && isupper(letterGrid[matchRow][matchCol])) {
                return 0;
            }else
            if (inputWord[i] != letterGrid[matchRow][matchCol] && !(isupper(letterGrid[matchRow][matchCol]))){
                return -1;
            }else
            if (inputWord[i] == letterGrid[matchRow][matchCol]){
                matchRow--;
                matchCol++;
                k++;
                if (k == len){
                    return 1;
                }
            }
        }
    }
    return 0;

}


/* Display the secret table */
void printSecretTable(char wordList[MAX_WORDLIST][MAX_WORD], int *row, int *column, int *direction) {


/* TODO: Complete the function */
    int i;

    printf("### Secret Table ###\n");
    printf("%s: R%d C%d D%d", wordList[i], *row, *column, *direction);

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

    char read_data;
    int i, count;
    char inputWord[MAX_WORD];
    int matchRow, matchCol, matchDirection;
    int elementStatus = 0, statusValue = 0;
    int win[MAX_WORDLIST];
    int *row, *column, *direction;


    /* Ask the user whether to read the data from file */
    printf("Read data from file [Y/N]?\n");
    scanf("%c", &read_data);

    /* Read the letter grid and the word list from file or console */
    if (read_data == 'N'){
        gridSize = readLetterGridFromConsole(letterGrid);
        listSize = readWordListFromConsole(wordList);
    }

    /* Initialize all elements in the matchingStatus array to 0 */
    if (read_data == 'Y'){
        gridSize = readLetterGridFromFile(letterGrid);
        listSize = readWordListFromFile(wordList);
    }

    for (i=0; i< listSize; i++){
        matchingStatus[i] = 0;
    }

    for (i = 0; i < listSize; i++){
        win[i] = 1;
    }

    /* FOR TESTING: Uncomment the following two statements to print the letter grid and the word list
       You can move them elsewhere after testing
       Please make sure the five arguments are initialized properly */

    /* Read the user input repeatedly until the puzzle finishes */
        while (1){
            count = 0;

            for (i = 0; i < listSize; i++){
                if (matchingStatus[i] != win[i])
                    break;
                count++;
            }
            if (count == listSize){
                printWordList(wordList, listSize, matchingStatus);
                printf("You have finished the puzzle.\n");
                printf("Congratulations!\n");
                break;
            }

            printLetterGrid(letterGrid, gridSize);
            printWordList(wordList, listSize, matchingStatus);

            printf("Enter the word:\n");
            scanf("%s", inputWord);
            if (inputWord == "SECTBL"){

                //for (i = 0;i < listSize; i++){
                    //for (*direction = 0 ;*direction < 9; *direction++){
                        //for (*row = 0; *row < gridSize; *row++){
                            //for (*column = 0; *column < gridSize; *column++){
                                //if (checkLetterGrid(letterGrid, gridSize, inputWord, &row, &column, &direction) == 0)
                                    //printSecretTable(wordList, &row, &column, &direction);
                            //}
                        //}
                    //}
                //}
            }
            if (inputWord != "SECTBL"){
            elementStatus = checkWordList(wordList, listSize, matchingStatus, inputWord);
            if (elementStatus != -1 && elementStatus != listSize){
                printf("Enter the row number, the column number, and the direction (1-4 or 6-9):\n");
                scanf("%d%d%d", &matchRow, &matchCol, &matchDirection);
                statusValue = checkLetterGrid(letterGrid, gridSize, inputWord, matchRow, matchCol, matchDirection);
                if (statusValue == 1){
                    matchingStatus[elementStatus] = 1;
                    printf("The word is found!\n");
                }else
                if (statusValue == 0){
                    matchingStatus[elementStatus] = 0;
                    printf("The input word cannot be found in the given location.\n");
                }else
                if (statusValue == -1){
                    matchingStatus[elementStatus] = 0;
                    printf("The search exceeds the boundary of the letter grid.\n");
                }
            }
            }
        }

    return 0;
}
