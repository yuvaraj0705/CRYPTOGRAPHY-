#include <stdio.h>
#include <string.h>

int main() {
    char message[1000], encrypted[1000], decrypted[1000];
    char key[26];
    int i, len;
    printf("Enter a message to encrypt: ");
    fgets(message, 1000, stdin);
    len = strlen(message);
    printf("Enter a key (26 letters): ");
    fgets(key, 26, stdin);
    key[strcspn(key, "\n")] = '\0'; // Remove the newline character
    if (strlen(key) != 26) {
        printf("Invalid key. The key must have exactly 26 letters.\n");
        return 1;
    }
    for (i = 0; i < len; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            encrypted[i] = key[message[i] - 'a'];
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            encrypted[i] = key[message[i] - 'A'] + 'a' - 'A';
        } else {
            encrypted[i] = message[i];
        }
    }
    encrypted[i] = '\0';
    printf("Encrypted message: %s\n", encrypted);
    for (i = 0; i < len; i++) {
        if (encrypted[i] >= 'a' && encrypted[i] <= 'z') {
            decrypted[i] = 'a' + (strchr(key, encrypted[i]) - key);
        } else if (encrypted[i] >= 'A' && encrypted[i] <= 'Z') {
            decrypted[i] = 'A' + (strchr(key, encrypted[i] - 'a' + 'A') - key);
        } else {
            decrypted[i] = encrypted[i];
        }
    }
    decrypted[i] = '\0';
    printf("Decrypted message: %s\n", decrypted);

    return 0;
}
