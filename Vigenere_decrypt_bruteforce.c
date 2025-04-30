#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT 20
#define MAX_KEYLEN 5


char decrypt_char(char c, char k) {
    if (isupper(c))
        return (c - 'A' - (toupper(k) - 'A') + 26) % 26 + 'A';
    else if (islower(c))
        return (c - 'a' - (tolower(k) - 'a') + 26) % 26 + 'a';
    else
        return c;
}


void vigenere_decrypt(const char *ciphertext, const char *key, char *output) {
    int key_len = strlen(key);
    int j = 0;
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            output[i] = decrypt_char(ciphertext[i], key[j % key_len]);
            j++;
        } else {
            output[i] = ciphertext[i];
        }
    }
    output[strlen(ciphertext)] = '\0';
}

void generate_keys(int len, char *prefix, const char *ciphertext) {
    if (len == 0) {
        char decrypted[MAX_TEXT];
        vigenere_decrypt(ciphertext, prefix, decrypted);
        printf("Key: %-5s => Decrypted: %s\n", prefix, decrypted);
        return;
    }

    for (char c = 'a'; c <= 'z'; c++) {
        char new_prefix[MAX_KEYLEN + 1];
        snprintf(new_prefix, sizeof(new_prefix), "%s%c", prefix, c);
        generate_keys(len - 1, new_prefix, ciphertext);
    }
}

int main() {
    char ciphertext[MAX_TEXT];

    printf("Enter ciphertext (max 10 characters): ");
    fgets(ciphertext, sizeof(ciphertext), stdin);
    ciphertext[strcspn(ciphertext, "\n")] = 0;

    printf("\nBrute-forcing keys (length 1 to %d)...\n", MAX_KEYLEN);

    for (int keylen = 1; keylen <= MAX_KEYLEN; keylen++) {
        printf("\nTrying key length: %d\n", keylen);
        generate_keys(keylen, "", ciphertext);
    }

    return 0;
}