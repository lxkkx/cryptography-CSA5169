#include <stdio.h>
#include <ctype.h>

// Function to encrypt the text using Caesar Cipher
void caesarCipher(char *text, int shift) {
    char ch;
    int i = 0;
    
    while (text[i] != '\0') {
        ch = text[i];

        // For uppercase letters
        if (isupper(ch)) {
            text[i] = ((ch - 'A' + shift) % 26) + 'A';
        }
        // For lowercase letters
        else if (islower(ch)) {
            text[i] = ((ch - 'a' + shift) % 26) + 'a';
        }
        
        i++;
    }
}

int main() {
    char text[100];
    int shift;

    // Input string and shift value
    printf("Enter a string: ");
    fgets(text, sizeof(text), stdin);
    
    printf("Enter shift value: ");
    scanf("%d", &shift);

    // Encrypt the string
    caesarCipher(text, shift);

    // Output the encrypted string
    printf("Encrypted text: %s", text);

    return 0;
}

