#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


char* encrypt(const char* text, int s) {
    int length = strlen(text);
    char* result = (char*)malloc(length + 1);
    result[length] = '\0';

    for (int i = 0; i < length; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            result[i] = (char)(((text[i] + s - 'A') % 26) + 'A');
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            result[i] = (char)(((text[i] + s - 'a') % 26) + 'a');
        } else {
            result[i] = text[i]; 
        }
    }

    return result;
}

int main() 
{
    //const char* text = "PRAGMAONCE";
    char str = "Pope";
    scanf("%s" ,str);
    int s = 4;
    printf("Text : %s", str);
    printf("\nShift: %d", s);
    char* cipher = encrypt(str, s);
    printf("\nCipher: %s", cipher);
    free(cipher);
    return 0;
}

