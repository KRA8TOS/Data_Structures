/*So we will learn the best approach for finding all the prime no small then any input using seive of Eratosthenes algo.So lets start.

  Lets first learn about this algorithm.
    The sieve of Eratosthenes is one of the most efficient ways to find all primes smaller than n when n is smaller than 10 million or so.
    This algorithm works as we define a array of boolean numbers with a size n and declare all the value as true.After we use a nested loop so that we can make all
    the composite no(multipple of prime no) as a value of false and after it we print all the indexes which have true value.In this algo we leave the index 0 & 1 as
    this are neither prime no nor composite no.Its time complexity will me O(nlog(logn)) and its auxiliary space will ne O(n).

  Lets write the code in C++:
*/

#include <iostream>
#include <cstring>
using namespace std;

void seive(int num)
{
  bool prime[n+1];
  memset(prime,true,n+1); //memset is a function used in string operation for copying the values in an array or string to a input no of times.
  for(int i=2; i*i <=n;i++)
  {
    if(prime[i])
    {
      for(int j=i*i;j <=n ;j++)
      {
        prime[j]=false;
      }
    }
  }
  for(int i=2 ;i<=n;i++)
  {
      if(prime[i])
          cout<<i<<endl;
  }
}
