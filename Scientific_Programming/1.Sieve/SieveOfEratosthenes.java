// Java version of Sieve of Eratosthenes
 
class SieveOfEratosthenes
{
    void sieveOfEratosthenes(int n)
    {
        // Create a boolean array, we will avoid all even numbers
	// so the element i on the array stores true or false if 
	// the number 2*i+1 is actually prime
	int imax, neff, counter=1, nprimes=0;
	boolean prime[];
	if (n%2==0)
	    imax=n/2;
	else
	    imax=(n+1)/2;
	neff= 2*(imax-1)+1;
	prime = new boolean[imax];

	// Lets assume that all odd numbers are primes
        for(int i=0;i<imax;i++)
            prime[i] = true;

	System.out.format(" Dimension of array: %d\n", imax);
	System.out.format(" Array with indices between 0 to %d\n", imax-1);
	System.out.format(" Stores primality of odd numbers in range [1, %d]\n\n", neff);
        
	// The loop runs over all odd numbers starting at 3
        for(int p = 3; p <n/2+1; p+=2)
	    {
		// If prime[p] is true, then it is a prime
		if(prime[(p-1)/2] == true)
		    {
			// Update all multiples of p
			for(int i = p*2; i <= neff; i += p)
			    {
			    if (i%2!=0) prime[(i-1)/2] = false;
			    }
		    }
	    }	

        // Print all prime numbers if the number is small otherwise just count the number of primes found
	if (imax < 10000) {
	    System.out.format("%8d ", 2);
	    // Starting with index 1 instead of zero because (2*0)+1 = 1 is not prime
	    for(int i = 1; i < imax; i++){
		if(prime[i] == true){
		    System.out.format("%8d ", 2*i+1);
		    counter++;
		}
		if (counter == 15){
		    System.out.format("\n");
		    counter=0;
		}
	    }
	    System.out.format("\n");
	}
	else {
	    for(int i = 1; i < imax; i++){
		if(prime[i] == true)
		    nprimes ++;
	    }
	    System.out.format(" Total number of primes found: %d\n", nprimes+1);
	}
    }
    
    // Main program, reads command line to get upper limit for Sieve
    public static void main(String args[])
    {
        int n=1;
	if (args.length > 0) {
	    try {
		n = Integer.parseInt(args[0]);
	    } catch (NumberFormatException e) {
		System.err.println("Argument" + args[0] + " must be an integer.");
		System.exit(1);
	    }
	}
	else
	    n = 100;
	
	System.out.format("\n");
	System.out.format(" Prime numbers up to %d\n", n);
        SieveOfEratosthenes g = new SieveOfEratosthenes();
        g.sieveOfEratosthenes(n);
    }
}
