#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <vector>
#include <utility>
#include <tuple>

using namespace std;

class Mix
{
public:
  static std::string mix(const std::string &s1, const std::string &s2);
};

std::string Mix::mix (const std::string &s1, const std::string &s2)
{
	std::vector<std::pair<char,int>> v1,v2;
	int count;
	for (char i = 'a'; i <= 'z'; ++i)
	{
		v1.push_back(std::make_pair (i,std::count(s1.begin(),s1.end(),i))); 
		v2.push_back(std::make_pair (i,std::count(s2.begin(),s2.end(),i)));
	}

	std::vector<std::pair<string,std::pair<char,int>>> v;

	int greater;
	std::string prefix;

	for (int i = 0; i < v1.size(); ++i)
	{ 
		prefix = v1[i].second > v2[i].second ? "1:" : "2:";
		if (v1[i].second == v2[i].second)
			prefix = "=:";

		greater = std::max(v1[i].second,v2[i].second);
		if (greater > 1)
			v.push_back(make_pair(prefix,make_pair(v1[i].first,greater)));
	}

	std::sort(v.begin(),v.end(),[](auto &left, auto &right)
	{
		if (left.second.second != right.second.second)
			return left.second.second > right.second.second;
		
		if (left.first == "=:") 
			return false; 

		if (right.first == "=:")
			return true;

		return left.second.second > right.second.second;
	});

	std::string solution;
	for (auto & item : v)
	{
		solution += item.first + std::string(item.second.second,item.second.first) + '/';
	};
	solution.pop_back();
	return solution;
};

int main()
{
   std::string s1;
   std::string s2;
   std::string s3;

	s1 = "my&friend&Paul has heavy hats! &";
	s2 = "my friend John has many many friends &";
	s3 = "2:nnnnn/1:aaaa/1:hhh/2:mmm/2:yyy/2:dd/2:ff/2:ii/2:rr/=:ee/=:ss";
	cout << (Mix::mix(s1, s2) == s3) << endl;
	cout << Mix::mix(s1, s2)<<endl;

	s1 = "mmmmm m nnnnn y&friend&Paul has heavy hats! &";
	s2 = "my frie n d Joh n has ma n y ma n y frie n ds n&";
	s3 = "1:mmmmmm/=:nnnnnn/1:aaaa/1:hhh/2:yyy/2:dd/2:ff/2:ii/2:rr/=:ee/=:ss";

	cout << Mix::mix(s1, s2)<<endl;
	cout << (Mix::mix(s1, s2) == s3)<<endl;

	s1 = "Are the kids at home? aaaaa fffff";
	s2 = "Yes they are here! aaaaa fffff";
	s3 = "=:aaaaaa/2:eeeee/=:fffff/1:tt/2:rr/=:hh";

	cout << Mix::mix(s1, s2)<<endl;

	cout << (Mix::mix(s1, s2) == s3)<<endl;

   return 0;
}