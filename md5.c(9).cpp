#include <stdio.h>
#include <string.h>

// Function to compute the MD5 hash
void compute_md5(const char *str, unsigned char digest[MD5_DIGEST_LENGTH]) {
    MD5_CTX ctx;
    MD5_Init(&ctx);
    MD5_Update(&ctx, str, strlen(str));
    MD5_Final(digest, &ctx);
}

// Function to print the MD5 hash in hexadecimal format
void print_md5(unsigned char digest[MD5_DIGEST_LENGTH]) {
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");
}

int main() {
    const char *str = "Hello, world!";
    unsigned char digest[MD5_DIGEST_LENGTH];

    // Compute and print the MD5 hash
    compute_md5(str, digest);
    
    printf("MD5 hash of '%s': ", str);
    print_md5(digest);

    return 0;
}

