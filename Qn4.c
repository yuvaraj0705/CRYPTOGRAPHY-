#include <stdio.h>
#include <string.h>

int main() {
    char message[1000], encrypted[1000], decrypted[1000];
    char key[1000];
    int i, j, k, len;
    printf("Enter a message to encrypt: ");
    fgets(message, 1000, stdin);
    len = strlen(message);
    printf("Enter a key: ");
    fgets(key, 1000, stdin);
    k = strlen(key) - 1; // Remove the newline character
    for (i = 0; i < len; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            encrypted[i] = (message[i] - 'a' + key[i % k] - 'a') % 26 + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            encrypted[i] = (message[i] - 'A' + key[i % k] - 'a') % 26 + 'A';
        } else {
            encrypted[i] = message[i];
        }
    }
    encrypted[i] = '\0';
    printf("Encrypted message: %s\n", encrypted);
    for (i = 0; i < len; i++) {
        if (encrypted[i] >= 'a' && encrypted[i] <= 'z') {
            decrypted[i] = (encrypted[i] - 'a' - key[i % k] + 'a' + 26) % 26 + 'a';
        } else if (encrypted[i] >= 'A' && encrypted[i] <= 'Z') {
            decrypted[i] = (encrypted[i] - 'A' - key[i % k] + 'a' + 26) % 26 + 'A';
        } else {
            decrypted[i] = encrypted[i];
        }
    }
    decrypted[i] = '\0';
    printf("Decrypted message: %s\n", decrypted);

    return 0;
}
