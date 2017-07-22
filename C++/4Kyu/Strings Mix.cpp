#include <iostream>
#include <algorithm>
#include <ctype.h>

using namespace std;

class Mix
{
public:
  static std::string mix(const std::string &s1, const std::string &s2);
};

template <typename T>
bool lowel(T & lowel)
{
	return true;
}

std::string Mix::mix (const std::string &s1, const std::string &s2)
{
	std::string st1 = s1;
	auto it = std::remove_if(st1.begin(),st1.end(),[](char i){return !(islower(i) or isdigit(i));}); //Copy only lower and digits
	st1.resize(std::distance(st1.begin(),it));

	sort(st1.begin(),st1.end());

	it = std::unique(st1.begin(),st1.end());
	st1.resize(std::distance(st1.begin(),it));

	

	cout << st1 << endl;


	return "";
}

int main()
{
    std::string s1 = "my&friend&Paul has heavy hats! &";
    std::string s2 = "my friend John has many many friends &";
    std::string s3 = "2:nnnnn/1:aaaa/1:hhh/2:mmm/2:yyy/2:dd/2:ff/2:ii/2:rr/=:ee/=:ss";

	Mix::mix(s1,s2);

    return 0;
}