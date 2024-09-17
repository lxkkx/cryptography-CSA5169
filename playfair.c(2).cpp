#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

void generateKeyMatrix(char key[], char keyMatrix[SIZE][SIZE]) {
    int map[26] = {0};
    int i, j, k = 0;

    for (i = 0; i < strlen(key); i++) {
        if (key[i] != 'j') {
            if (map[key[i] - 'a'] == 0) {
                keyMatrix[k / SIZE][k % SIZE] = key[i];
                map[key[i] - 'a'] = 1;
                k++;
            }
        }
    }

    // Fill remaining letters
    for (i = 0; i < 26; i++) {
        if (i == 'j' - 'a') continue; // Skip 'j'
        if (map[i] == 0) {
            keyMatrix[k / SIZE][k % SIZE] = i + 'a';
            k++;
        }
    }
}

void formatText(char text[], char formattedText[]) {
    int i, j = 0;
    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            formattedText[j++] = tolower(text[i] == 'j' ? 'i' : text[i]);
        }
    }
    formattedText[j] = '\0';

    for (i = 0; i < j; i += 2) {
        if (formattedText[i] == formattedText[i + 1]) {
            for (j = strlen(formattedText) + 1; j > i + 1; j--) {
                formattedText[j] = formattedText[j - 1];
            }
            formattedText[i + 1] = 'x';
        }
    }

    if (strlen(formattedText) % 2 != 0) {
        formattedText[strlen(formattedText)] = 'x';
        formattedText[strlen(formattedText) + 1] = '\0';
    }
}

void findPosition(char keyMatrix[SIZE][SIZE], char ch, int *row, int *col) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (keyMatrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void encrypt(char text[], char keyMatrix[SIZE][SIZE], char encryptedText[]) {
    int i, row1, col1, row2, col2;

    for (i = 0; i < strlen(text); i += 2) {
        findPosition(keyMatrix, text[i], &row1, &col1);
        findPosition(keyMatrix, text[i + 1], &row2, &col2);

        if (row1 == row2) {
            encryptedText[i] = keyMatrix[row1][(col1 + 1) % SIZE];
            encryptedText[i + 1] = keyMatrix[row2][(col2 + 1) % SIZE];
        } else if (col1 == col2) {
            encryptedText[i] = keyMatrix[(row1 + 1) % SIZE][col1];
            encryptedText[i + 1] = keyMatrix[(row2 + 1) % SIZE][col2];
        } else {
            encryptedText[i] = keyMatrix[row1][col2];
            encryptedText[i + 1] = keyMatrix[row2][col1];
        }
    }
    encryptedText[i] = '\0';
}

int main() {
    char key[] = "playfairexample";
    char text[] = "hide the gold in the tree stump";
    char keyMatrix[SIZE][SIZE];
    char formattedText[100];
    char encryptedText[100];

    // Step 1: Generate Key Matrix
    generateKeyMatrix(key, keyMatrix);

    // Step 2: Format the input text
    formatText(text, formattedText);

    // Step 3: Encrypt the formatted text
    encrypt(formattedText, keyMatrix, encryptedText);

    printf("Plaintext: %s\n", text);
    printf("Formatted Text: %s\n", formattedText);
    printf("Encrypted Text: %s\n", encryptedText);

    return 0;
}

