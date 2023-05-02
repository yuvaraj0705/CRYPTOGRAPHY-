#include <stdio.h>
#include <string.h>

int main() {
    char message[1000], encrypted[1000], decrypted[1000];
    int i, j, k, len;
    printf("Enter a message to encrypt: ");
    fgets(message, 1000, stdin);
    len = strlen(message);
    printf("Enter a key (1-25): ");
    scanf("%d", &k);   
    if (k < 1 || k > 25) {
        printf("Invalid key. The key must be between 1 and 25.\n");
        return 1;
    }   
    for (i = 0; i < len; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            encrypted[i] = (message[i] - 'a' + k) % 26 + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            encrypted[i] = (message[i] - 'A' + k) % 26 + 'A';
        } else {
            encrypted[i] = message[i];
        }
    }
    encrypted[i] = '\0';

   
    printf("Encrypted message: %s\n", encrypted);

    
    for (i = 0; i < len; i++) {
        if (encrypted[i] >= 'a' && encrypted[i] <= 'z') {
            decrypted[i] = (encrypted[i] - 'a' + 26 - k) % 26 + 'a';
        } else if (encrypted[i] >= 'A' && encrypted[i] <= 'Z') {
            decrypted[i] = (encrypted[i] - 'A' + 26 - k) % 26 + 'A';
        } else {
            decrypted[i] = encrypted[i];
        }
    }
    decrypted[i] = '\0';

 
   
