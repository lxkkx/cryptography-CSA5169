#include <stdio.h>
#define SIZE 2 
void hillCipher(char message[], int keyMatrix[SIZE][SIZE]) {
    int messageVector[SIZE], cipherMatrix[SIZE];
    for (int i = 0; i < SIZE; i++)
        messageVector[i] = message[i] - 'A';
    for (int i = 0; i < SIZE; i++) {
        cipherMatrix[i] = 0;
        for (int j = 0; j < SIZE; j++)
            cipherMatrix[i] += keyMatrix[i][j] * messageVector[j];
        cipherMatrix[i] %= 26; 
    }
    printf("Encrypted text: ");
    for (int i = 0; i < SIZE; i++)
        printf("%c", cipherMatrix[i] + 'A');
    printf("\n");
}
int main() {
    char message[] = "HI"; 
    int keyMatrix[SIZE][SIZE] = { { 3, 3 }, { 2, 5 } };
    hillCipher(message, keyMatrix);
    return 0;
}
