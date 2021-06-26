#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sieveOfEratosthenes(unsigned int n);

int main(int argc, char *argv[])
{

  unsigned int n=1, nprimes;
  if (argc > 1) n = atoi(argv[1]);
  else n = 100;
  
  printf(" Prime numbers up to %d\n", n);
  nprimes=sieveOfEratosthenes(n);
  printf(" Total number of primes found: %d\n\n", nprimes);
}

int sieveOfEratosthenes(unsigned int n)
{
  unsigned int imax, neff, counter=1, nprimes=0;
  char *prime;
  
  if (n%2==0)
    imax=n/2;
  else
    imax=(n+1)/2;
  neff= 2*(imax-1)+1;
  prime = (char *)malloc(imax * sizeof(char));

  for(unsigned int i=0; i<imax; i++){
    prime[i]=1;
  }

  printf(" Dimension of array: %d\n", imax);
  printf(" Array with indices between 0 to %d\n", imax-1);
  printf(" Stores primality of odd numbers in range [1, %d]\n\n", neff);

  // The loop runs over all odd numbers starting at 3
  for(unsigned int p = 3; p <n/2+1; p+=2)
    {
      // If prime[p] is true, then it is a prime
      if(prime[(p-1)/2] == 1)
	{
	  // Update all multiples of p
	  for(unsigned int i = p*2; i <= neff; i += p)
	    {
	      if (i%2!=0) prime[(i-1)/2] = 0;
	    }
	}
    }

  // Print all prime numbers if the number is small otherwise just count the number of primes found
  if (imax < 10000) {
    printf("%10d ", 2);
    // Starting with index 1 instead of zero because (2*0)+1 = 1 is not prime
    for(unsigned int i = 1; i < imax; i++){
      if(prime[i] == 1){
	printf("%10d ", 2*i+1);
	counter++;
      }
      if (counter == 15){
	printf("\n");
	counter=0;
      }
    }
    printf("\n");
  }
  for(unsigned int i = 1; i < imax; i++){
    if(prime[i] == true)
      nprimes ++;
  }
  // Adding one extra due to 2 that is not counted on the list
  return nprimes+1;
}
