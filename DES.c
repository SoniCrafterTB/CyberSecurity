#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/des.h>
#define key_size 8
#define MAXN 100

int main()
{
    unsigned char key[key_size] = "Banichka";
    unsigned char input[MAXN];

    fgets((char*)input,MAXN,stdin);
    input[strcspn(input,"\n")]='\0';
    unsigned int length = strlen(input);
    unsigned int padded_length = ((length +7)/8)*8;
    unsigned char padded_input[padded_length];
    unsigned char output[padded_length];

    memcpy(padded_input,input,length);
    memset(padded_input+length,padded_length-length,padded_length-length);

    DES_key_schedule key_schedule;
    DES_set_key( (DES_cblock*) key, &key_schedule);

    for (int i = 0; i < padded_length; i++)
    {
        DES_ecb_encrypt((DES_cblock*) input, (DES_cblock*) output, &key_schedule, 
    DES_ENCRYPT);
    }
    
    for(int i = 0; i < length; i++)
    {
        printf("%02x", output[i]);
    }

    return EXIT_SUCCESS;
}

    


