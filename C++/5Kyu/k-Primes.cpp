
#include <vector>
#include <math.h>

using namespace std;

bool isPrime(long long num)
{
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (long long i = 3; i <= sqrt(num); i += 2)
    {
      if (num % i == 0)
        return false;
    }
    return true;
}

vector<long long> factors(long long number)
{
    if (isPrime(number))
        return {number};

    for(long long i = 2; i < number; i++)
    {
        if (number % i == 0)
        {
            vector<long long> v = factors(number / i);
            v.push_back(i);
            return v;
        }
    }
    return {};
}

class KPrimes
{
public:
    static std::vector<long long> countKprimes(int k, long long start, long long end);
    static int puzzle(int s);
};

std::vector<long long> KPrimes::countKprimes(int k, long long start, long long end)
{
    vector <long long> kprimes,factor;
    for (int n = start; n <= end; ++n)
    {
        factor = factors(n);
        if (factor.size() == k)
            kprimes.push_back(n);
    }
    return kprimes;
};

int KPrimes::puzzle(int s)
{
   vector<vector<long long>> sol {KPrimes::countKprimes(1, 0,s),
                                  KPrimes::countKprimes(3, 0,s),
                                  KPrimes::countKprimes(7, 0,s),
                                  };
  int solutions = 0;
  
  for (auto i = sol.at(0).begin();i != sol.at(0).end();i++)
    for (auto j = sol.at(1).begin();j != sol.at(1).end();j++)
      for (auto k = sol.at(2).begin();k != sol.at(2).end();k++)
        if ((*i) + (*j) + (*k) == s)
          solutions++;
          
  return solutions;                    
}

/*

A natural number is thus prime if and only if it is 1-prime.

Examples:
k = 2 -> 4, 6, 9, 10, 14, 15, 21, 22, …
k = 3 -> 8, 12, 18, 20, 27, 28, 30, …
k = 5 -> 32, 48, 72, 80, 108, 112, …

#Task:

    Write function count_Kprimes (or countKprimes or count-K-primes or kPrimes in C) which given parameters k, start, end (or nd) returns an array (or a list in C) of the k-primes between start (inclusive) and end (inclusive).

#Example:

countKprimes(5, 500, 600) --> [500, 520, 552, 567, 588, 592, 594]

...............................................................................

    for all languages except Bashshell

Given positive integers s and a, b, c where a is 1-prime, b 3-prime, c 7-prime find the number of solutions of a + b + c = s. Call this function puzzle(s).

Examples:

puzzle(138) --> 1 ([2 + 8 + 128] is solution)
puzzle(143) --> 2 ([3 + 12 + 128, 7 + 8 + 128] are solutions)

...............................................................................

*/

