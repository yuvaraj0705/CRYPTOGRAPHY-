#include <stdio.h>
#include <string.h>

// Function to remove duplicate letters from a string
void removeDuplicates(char *str) {
    int len = strlen(str);
    int index = 0;

    // Loop through each character in the string
    for (int i = 0; i < len; i++) {
        // Check if the current character has already been encountered
        int j;
        for (j = 0; j < i; j++) {
            if (str[i] == str[j]) {
                break;
            }
        }
        // If the current character has not been encountered, add it to the result
        if (j == i) {
            str[index++] = str[i];
        }
    }
    // Null terminate the result string
    str[index] = '\0';
}

// Function to construct the Playfair cipher matrix from the keyword
void constructMatrix(char *key, char matrix[5][5]) {
    // Remove duplicate letters from the keyword
    removeDuplicates(key);

    int len = strlen(key);
    int index = 0;

    // Fill the matrix with the letters of the keyword
    for (int i = 0; i < len; i++) {
        if (key[i] == 'j') {
            // Replace 'j' with 'i'
            key[i] = 'i';
        }
        // Add the current letter to the matrix
        matrix[index / 5][index % 5] = key[i];
        index++;
    }

    // Fill the remaining cells of the matrix with the remaining letters of the alphabet
    for (char c = 'a'; c <= 'z'; c++) {
        if (c == 'j') {
            // Skip 'j'
            continue;
        }
        // Check if the current letter is already in the matrix
        int i, j;
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                if (matrix[i][j] == c) {
                    break;
                }
            }
            if (matrix[i][j] == c) {
                break;
            }
        }
        if (i == 5 && j == 5) {
            // The current letter is not in the matrix, add it
            matrix[index / 5][index % 5] = c;
            index++;
        }
    }
}

// Function to find the row and column of a letter in the Playfair cipher matrix
void findPosition(char matrix[5][5], char letter, int *row, int *col) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] == letter) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

// Function to encrypt a message using the Playfair cipher algorithm
void encryptMessage(char matrix[5][5], char *message, char *encrypted) {
    int len = strlen(message);

    // Remove any non-alphabetic characters from the message
    int index = 0;
    for (int i = 0; i < len; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            encrypted[index++] = message[i];
        } else if (message
