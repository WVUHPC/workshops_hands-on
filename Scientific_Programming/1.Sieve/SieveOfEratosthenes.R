#!/usr/bin/env Rscript

SieveOfEratosthenes <- function(n) {
  if (n < 2) return(NULL)
  primes <- rep(T, n)
  sprintf(" Dimension of array %d", length(primes))
  
  # 1 is not prime
  primes[1] <- F
  for(i in seq(n)) {
    if (primes[i]) {
      j <- i * i
      if (j > n){ 
      	 if (sum(primes, na.rm=TRUE)<=10000) {
	    # Select just the indices of True values
	    print(which(primes))
	 }  
	 return(sum(primes, na.rm=TRUE))
	 }	 
      primes[seq(j, n, by=i)] <- F
    }
  }
  return()
}

# Collecting arguments from the command 
args = commandArgs(trailingOnly=TRUE)

# Default number is n=100
if (length(args)==0) {
  n = 100
} else {
  n = strtoi(args[1])
}

sprintf(" Prime numbers up to %d", n)
nprimes<-SieveOfEratosthenes(n)
sprintf(" Total number of primes found: %d", nprimes)
