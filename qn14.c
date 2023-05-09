#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(const char* plaintext, const int* key, char* ciphertext) {
    int len = strlen(plaintext);
    int key_len = strlen(key);

    for (int i = 0; i < len; i++) {
        char curr = plaintext[i];
        int shift = key[i % key_len];

        if (curr >= 'a' && curr <= 'z') {
            ciphertext[i] = 'a' + (curr - 'a' + shift) % 26;
        } else if (curr >= 'A' && curr <= 'Z') {
            ciphertext[i] = 'A' + (curr - 'A' + shift) % 26;
        } else {
            ciphertext[i] = curr;
        }
    }

    ciphertext[len] = '\0';
}

void decrypt(const char* ciphertext, const int* key, char* plaintext) {
    int len = strlen(ciphertext);
    int key_len = strlen(key);

    for (int i = 0; i < len; i++) {
        char curr = ciphertext[i];
        int shift = key[i % key_len];

        if (curr >= 'a' && curr <= 'z') {
            plaintext[i] = 'a' + (curr - 'a' - shift + 26) % 26;
        } else if (curr >= 'A' && curr <= 'Z') {
            plaintext[i] = 'A' + (curr - 'A' - shift + 26) % 26;
        } else {
            plaintext[i] = curr;
        }
    }

    plaintext[len] = '\0';
}

int main() {
    const char* plaintext = "sendmoremoney";
    const int key[] = {9, 0, 1, 7, 23, 15, 21, 14, 11, 11, 2, 8, 9};
    char ciphertext[100];
    char decrypted[100];

    encrypt(plaintext, key, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);

    decrypt(ciphertext, key, decrypted);
    printf("Decrypted: %s\n", decrypted);

    return 0;
}
