#include <stdio.h>
#include <math.h>

typedef unsigned long long ull;

ull mod_exp(ull base, ull exp, ull mod) {
    ull result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    // RSA parameters
    ull p = 61; // Example prime number
    ull q = 53; // Example prime number
    ull n = p * q; // Modulus
    ull phi = (p - 1) * (q - 1); // Euler's totient function
    ull e = 17; // Public exponent (should be coprime with phi)
    ull d = 2753; // Private exponent (modular inverse of e mod phi)
    
    // Example message
    ull msg = 65; // Example plaintext (must be < n)
    
    // Encryption
    ull enc = mod_exp(msg, e, n);
    printf("Encrypted message: %llu\n", enc);
    
    // Decryption
    ull dec = mod_exp(enc, d, n);
    printf("Decrypted message: %llu\n", dec);
    
    return 0;
}

