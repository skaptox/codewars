/*

Description:

Given two strings s1 and s2, we want to visualize how different the two strings are. We will only
take into account the lowercase letters (a to z). First let us count the frequency of each lowercase
letters in s1 and s2.

s1 = "A aaaa bb c"

s2 = "& aaa bbb c d"

s1 has 4 'a', 2 'b', 1 'c'

s2 has 3 'a', 3 'b', 1 'c', 1 'd'

So the maximum for 'a' in s1 and s2 is 4 from s1; the maximum for 'b' is 3 from s2. In the following
we will not consider letters when the maximum of their occurrences is less than or equal to 1.

We can resume the differences between s1 and s2 in the following string: "1:aaaa/2:bbb" where 1 in
1:aaaa stands for string s1 and aaaa because the maximum for a is 4. In the same manner 2:bbb stands
for string s2 and bbb because the maximum for b is 3.

The task is to produce a string in which each lowercase letters of s1 or s2 appears as many times as
its maximum if this maximum is strictly greater than 1; these letters will be prefixed by the number
of the string where they appear with their maximum value and :. If the maximum is in s1 as well as
in s2 the prefix is =:.

In the result, substrings (a substring is for example 2:nnnnn or 1:hhh; it contains the prefix) will
be in decreasing order of their length and when they have the same length sorted in ascending
lexicographic order (letters and digits - more precisely sorted by codepoint); the different groups
will be separated by '/'. See examples and "Example Tests".

Examples below

*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <utility> // pair

class Mix
{
public:
  static std::string mix(const std::string &s1, const std::string &s2);
};

std::string Mix::mix (const std::string &s1, const std::string &s2)
{
   std::vector<std::pair<char,int>> v1,v2;
   int count;

   /*Count ocurrence*/

   for (char i = 'a'; i <= 'z'; ++i)
   {
      v1.push_back(std::make_pair (i,std::count(s1.begin(),s1.end(),i))); //<letter,occurrence>
      v2.push_back(std::make_pair (i,std::count(s2.begin(),s2.end(),i)));
   }

   std::vector<std::pair<std::string,std::pair<char,int>>> v;
   int greater;
   std::string prefix;

   /*Adding element selecte to new vector*/

   for (int i = 0; i < v1.size(); ++i)
   { 
      prefix = v1[i].second > v2[i].second ? "1:" : "2:";
      if (v1[i].second == v2[i].second)
         prefix = "=:";

      greater = std::max(v1[i].second,v2[i].second);
      if (greater > 1)
         v.push_back(std::make_pair(prefix,std::make_pair(v1[i].first,greater))); // <prefix,<letter,ocurrence>>
   }

   /*Sort the vector*/

   std::sort(v.begin(),v.end(),[](auto &left, auto &right)
   {
      if (left.second.second != right.second.second)   //Order by secuence
         return left.second.second > right.second.second;  
      return left.first + left.second.first < right.first + right.second.first; //Order by prefix and alphabatical character
      
   });

   /*Make the final solution*/

   std::string solution;
   for (auto & item : v)
   {
      solution += item.first + std::string(item.second.second,item.second.first) + '/'; //Repeat each letter
   };
   solution.pop_back(); //Delete last '/'
   return solution;
};

int main()
{
   std::string s1 = "my&friend&Paul has heavy hats! &";
   std::string s2 = "my friend John has many many friends &";
   std::string s3 = "2:nnnnn/1:aaaa/1:hhh/2:mmm/2:yyy/2:dd/2:ff/2:ii/2:rr/=:ee/=:ss";

   std::cout << (Mix::mix(s1, s2) == s3)<< std::endl;

   s1 = "mmmmm m nnnnn y&friend&Paul has heavy hats! &";
   s2 = "my frie n d Joh n has ma n y ma n y frie n ds n&";
   s3 = "1:mmmmmm/=:nnnnnn/1:aaaa/1:hhh/2:yyy/2:dd/2:ff/2:ii/2:rr/=:ee/=:ss";

   std::cout << (Mix::mix(s1, s2) == s3)<< std::endl;

   s1 = "Are the kids at home? aaaaa fffff";
   s2 = "Yes they are here! aaaaa fffff";
   s3 = "=:aaaaaa/2:eeeee/=:fffff/1:tt/2:rr/=:hh";

   std::cout << (Mix::mix(s1, s2) == s3)<< std::endl;

   return 0;
}