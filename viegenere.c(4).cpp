#include <stdio.h>
#include <string.h>
void vigenereEncrypt(char plaintext[], char key[]) {
    int n = strlen(plaintext);
    int keyLength = strlen(key);
    char ciphertext[n + 1];
    for (int i = 0; i < n; i++) {
        char p = plaintext[i];
        char k = key[i % keyLength]; 
        ciphertext[i] = ((p - 'A') + (k - 'A')) % 26 + 'A'; 
    }
    ciphertext[n] = '\0'; 
    printf("Encrypted Text: %s\n", ciphertext);
}
int main() {
    char plaintext[] = "HELLO"; 
    char key[] = "KEY";         
    vigenereEncrypt(plaintext, key);
    return 0;
}
