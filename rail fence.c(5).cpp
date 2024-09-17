#include <stdio.h>
#include <string.h>
void railFenceEncrypt(char *plaintext, int key) {
    int n = strlen(plaintext);
    char rail[key][n];
    for (int i = 0; i < key; i++)
        for (int j = 0; j < n; j++)
            rail[i][j] = '\n';
    int row = 0, dir_down = 0;
    for (int i = 0; i < n; i++) {
        rail[row][i] = plaintext[i];

        if (row == 0 || row == key - 1)
            dir_down = !dir_down;

        row += dir_down ? 1 : -1;
    }
    char ciphertext[n + 1];
    int idx = 0;
    for (int i = 0; i < key; i++)
        for (int j = 0; j < n; j++)
            if (rail[i][j] != '\n')
                ciphertext[idx++] = rail[i][j];
    ciphertext[idx] = '\0'; 
    printf("Encrypted Text: %s\n", ciphertext);
}
int main() {
    char plaintext[] = "HELLOPROGRAM";
    int key = 3;                   
    railFenceEncrypt(plaintext, key);
    return 0;
}
