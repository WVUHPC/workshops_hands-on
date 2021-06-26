#include <inttypes.h>
#include <limits>
#include <cmath>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
 
template <typename ForwardIterator>
size_t SieveOfEratosthenes(ForwardIterator start, ForwardIterator end)
{
  if (start == end) return 0;
  // Filling the entire vector with zeros
  std::fill(start, end, 0);
  // mark composites with 1
  for (ForwardIterator prime_it = start + 1; prime_it != end; ++prime_it)
    {
      if (*prime_it == 1) continue;
      // The variable stride contains the actual prime number that we use to skip across 
      size_t stride = (prime_it - start) + 1;
      // Jumping with stride all elements staring on the current index are marked as non-primes
      ForwardIterator mark_it = prime_it;
      while ((end - mark_it) > stride)
        {
	  std::advance(mark_it, stride);
	  // Here is where the non-prime is marked
	  *mark_it = 1;
        }
    }
  // copy marked primes into container
  ForwardIterator out_it = start;
  for (ForwardIterator it = start + 1; it != end; ++it)
    {
      if (*it == 0)
        {
	  *out_it = (it - start) + 1;
	  ++out_it;
        }
    }
  return out_it - start;
}
 
int main(int argc, const char* argv[])
{
  using namespace std;

  int n=100, counter=0;

  if (argc == 2) {
    stringstream ss(argv[--argc]);
    ss >> n;
 
    if (n < 1 or ss.fail()) {
      cerr << "USAGE:\n  SieveOfEratosthenes N\n\nwhere N in the range [1, " 
	   << numeric_limits<int>::max() << ")" << endl;
      return 2;
    }
  }

  std::vector<int> primes(n);

  printf(" Prime numbers up to %d\n", n);
  size_t nprimes = SieveOfEratosthenes(primes.begin(), primes.end());

  if (n <= 10000){
    for (size_t i = 0; i < nprimes; ++i)
      {
	std::cout << std::setw(8) << primes[i] << " ";
	counter++;
	if (counter==10){
	  counter = 0;
	  std::cout << std::endl;
	}
      }
    std::cout << std::endl;
  }

  std::cout << " Total number of primes found: "<< nprimes<< std::endl;

  return 0;
}
