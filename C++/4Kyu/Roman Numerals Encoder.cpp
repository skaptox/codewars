// Copyright (c) 2017 Richard Games. All rights reserved.


/*

Create a function taking a positive integer as its parameter and
returning a string containing the Roman Numeral representation of that
integer.

Modern Roman numerals are written by expressing each digit separately
starting with the left most digit and skipping any digit with a value
of zero. In Roman numerals 1990 is rendered: 1000=M] = 900=CM] = 90=XC;
resulting in MCMXC. 2008 is written as 2000=MM] = 8=VIII; or MMVIII.
1666 uses each Roman symbol in descending order: MDCLXVI.

Symbol    Value
I          1
V          5
X          10
L          50
C          100
D          500
M          1] = 000

*/

#include <assert.h>
#include <iostream>
#include <map>
#include <string>
#include <utility>

using std::cout;
using std::endl;

std::string solution(int number) {
  using std::string;
  // convert the number to a roman numeral
  static const std::map<int, string> dic{
    {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},{100, "C"},
    {90, "XC"}, {50, "L"}, {40, "XL"},{10, "X"},
    {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
  };

  string sol;
  for (auto it = dic.crbegin(); it != dic.crend() && number > 0; ++it) {
    while(number > 0) {
      if (number >= it -> first) {
        number -= it->first;
        sol +=  it->second;
      } else {
        break;
      }
    }
  }
  return sol;
}

int main(int argc, char const *argv[]) {
  assert(solution(182) == "CLXXXII");
  assert(solution(1990) == "MCMXC");
  assert(solution(1875) == "MDCCCLXXV");
  cout << "Everything is ok!" << endl;
  return 0;
}