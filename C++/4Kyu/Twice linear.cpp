/*

Consider a sequence u where u is defined as follows:

    The number u(0) = 1 is the first one in u.
    For each x in u, then y = 2 * x + 1 and z = 3 * x + 1 must be in u too.
    There are no other numbers in u.

Ex: u = [1, 3, 4, 7, 9, 10, 13, 15, 19, 21, 22, 27, ...]

1 gives 3 and 4, then 3 gives 7 and 10, 4 gives 9 and 13, then 7 gives 15 and 22 and so on...

#Task: Given parameter n the function dbl_linear (or dblLinear...) returns the element u(n) of the ordered (with <) sequence u.

#Example: dbl_linear(10) should return 22

#Note: Focus attention on efficiency

*/

#include <iostream>
#include <queue>  
#include <algorithm>
#include <math.h>
#include <vector>
#include <set>

class DoubleLinear
{
public: static int dblLinear(int n);
};


int DoubleLinear::dblLinear(int n)
{
  std::vector<unsigned long long> mySet{1};
  std::queue<unsigned long long> myQue;
  
  unsigned long long x = 1,y,z;
  
  unsigned long long t1,t2,t3;

  int h = log2(n+1)-1;
  int l = pow(2,(h+1))-1;
  
  while(mySet.size() < l)
  {
    y = 2 * x + 1;
    z = 3 * x + 1;
    
    mySet.push_back(y);
    mySet.push_back(z);
    
    myQue.push(y);
    myQue.push(z);
  
    x = myQue.front();
    myQue.pop();
  };

  std::sort(mySet.begin(),mySet.end());
  mySet.erase(std::unique(mySet.begin(),mySet.end()),mySet.end());

  

  int p = 0;
	for (auto item:mySet)
		std::cout<< p++ <<"- "<<item<<std::endl;
  
  return mySet[n];
}

int main()
{
    std::cout << (DoubleLinear::dblLinear(20) == 57) << std::endl;
    std::cout << (DoubleLinear::dblLinear(30) == 91) << std::endl;
    std::cout << (DoubleLinear::dblLinear(50) == 175) << std::endl;
}