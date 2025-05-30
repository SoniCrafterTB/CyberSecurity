#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAXN 1000
#define ALPHA_LENGTH 26
#define COMMON_COUNT 10

char* cezar_decipher(char* cipher,int key)
{
 int length=strlen(cipher);
 char * text = (char*)malloc(sizeof(char) * (length+1));
 for(int i = 0;i<length;i++)
 {
    if(cipher[i] >= 'a' && cipher[i] <= 'z')
    {
        text[i]=((cipher[i]-'a')-key+26)%26 + 'a';
    }
    else if(cipher[i]>= 'A' && cipher[i] <= 'Z')
    {
        text[i]=((cipher[i]-'A')-key+26)%26 + 'A';
    }
    else if(cipher[i]>= '0' && cipher[i] <= '9')
    {
        text[i]=((cipher[i]-'0')-key+10)%10 + '0';
    }
    else
    {
        text[i]=cipher[i];
    }
    
 }
 return text;
}


int* count_frequencies(char* cipher)
{
    int* frequency = (int*) malloc(sizeof(int) * ALPHA_LENGTH);
    memset(frequency, 0, sizeof(int) * ALPHA_LENGTH);
    int length = strlen(cipher);
    for(int i = 0; i < length; i++)
    {
        int position = tolower(cipher[i]) - 'a';
        frequency[position]++;
    }

    return frequency;
}

int get_max_index(int* frequencies)
{
    int max_index = 0;
    for(int i = 0; i < ALPHA_LENGTH; i++)
    {
        if(frequencies[i] > frequencies[max_index])
        {
            max_index = i;
        }
    }
    return max_index;
}

int main()
{

    char cipher[MAXN];
    fgets(cipher,MAXN,stdin);
    char max_letter = get_max_index(count_frequencies(cipher)) + 'a';
    char common_letters[COMMON_COUNT] = 
        {'e', 't', 'a', 'o', 'i', 'n', 's', 'r', 'h', 'l'};
    for(int i = 0; i < COMMON_COUNT; i++)
    {
        int key = abs(max_letter - common_letters[i]);
        char* text = cezar_decipher(cipher, key);
        printf("Key = %d, result: %s\n", key, text);
        free(text);
    }
    return EXIT_SUCCESS;
}
