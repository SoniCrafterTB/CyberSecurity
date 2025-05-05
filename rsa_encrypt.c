#include <stdio.h>
#include <stdlib.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#define BufferSize 256
#define KEY_FILE "public.pem"

RSA *load_public_key(const char *filename)
{
    FILE* fp = fopen(filename,"rb");
    RSA* rsa = PEM_read_RSAPublicKey(fp,NULL,NULL,NULL);
    fclose(fp);
    return rsa;
}

int encrypt_message(RSA* rsa, const unsigned char* plaintext,const unsigned char* cipher)
{
        int length = strlen(plaintext)+1;
        int result = RSA_public_encrypt(length,plaintext,cipher,rsa,
            RSA_PKCS1_OAEP_PADDING);
            return result;
} 

int main ()
{
            unsigned char plaintext[BufferSize];
            scanf("%s", plaintext);
            unsigned char cipher[BufferSize];
            RSA* rsa = load_public_key(KEY_FILE);
            int encrypted_len = encrypt_message(rsa,plaintext,cipher);
            for (int i = 0; i < encrypted_len; i++)
            {
              printf("%02x", plaintext[i]);
            }
            printf("\n");
            return EXIT_SUCCESS;
}