/*

Given two numbers: 'left' and 'right' (1 <= 'left' <= 'right' <= 1 000 000 000) return sum of all '1' occurencies in binary representations of numbers between 'left' and 'right' (including both)

Example:
countOnes 4 7 should return 8, because:
4(dec) = 100(bin), which adds 1 to the result.
5(dec) = 101(bin), which adds 2 to the result.
6(dec) = 110(bin), which adds 2 to the result.
7(dec) = 111(bin), which adds 3 to the result.
So finally result equals 8.

WARNING: Segment may contain billion elements, to pass this kata, your solution cannot iterate through all numbers in the segment!

*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main(int argc, char const *argv[])
{
	cout << (8 >> 1) << endl;
}