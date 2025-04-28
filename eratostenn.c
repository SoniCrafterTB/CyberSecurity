#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>



void sieve_of_eratosten(int n)
{
        
    FILE *fout = fopen("prime.txt", "w");

 bool is_prime[n+1];
 for (int i = 0; i < n; i++)
  is_prime[i] = true;
  is_prime[0]=false;
  is_prime[1]= false;

  for ( int p = 2; p * p < n; p++)
  {
    if(is_prime[p])
    {
            for ( int i = p*p; i < n; i+=p)
            {
                is_prime[i]= false;
            }
        }
    }
  
    for ( int i = 2; i < n; i++)
    {
        if(is_prime[i])
    {
        
        fprintf(fout,"%d ",i);
      
    }
    }
   

}


int main()
{
    
        int limit;
        printf("Find prime numbers up to: ");
        scanf ("%d", &limit);
        sieve_of_eratosten(limit);

 }