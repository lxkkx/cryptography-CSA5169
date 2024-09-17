#include <stdio.h>

// Function to perform modular exponentiation
unsigned long long mod_exp(unsigned long long base, unsigned long long exp, unsigned long long mod) {
    unsigned long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    // Public parameters
    unsigned long long p = 23; // A prime number
    unsigned long long g = 5;  // A primitive root modulo p

    // Alice's private key
    unsigned long long a = 6;  // Example private key for Alice

    // Bob's private key
    unsigned long long b = 15; // Example private key for Bob

    // Alice's public key
    unsigned long long A = mod_exp(g, a, p);
    printf("Alice's public key: %llu\n", A);

    // Bob's public key
    unsigned long long B = mod_exp(g, b, p);
    printf("Bob's public key: %llu\n", B);

    // Shared secret computed by Alice
    unsigned long long shared_secret_A = mod_exp(B, a, p);
    printf("Shared secret computed by Alice: %llu\n", shared_secret_A);

    // Shared secret computed by Bob
    unsigned long long shared_secret_B = mod_exp(A, b, p);
    printf("Shared secret computed by Bob: %llu\n", shared_secret_B);

    return 0;
}

