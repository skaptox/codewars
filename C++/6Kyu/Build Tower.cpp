/*
Build Tower by the following given argument:
number of floors (integer and always greater than 0).

Tower block is represented as *

Have fun!

for example, a tower of 3 floors looks like below

[
  '  *  ', 
  ' *** ', 
  '*****'
]

and a tower of 6 floors looks like below

[
  '     *     ', 
  '    ***    ', 
  '   *****   ', 
  '  *******  ', 
  ' ********* ', 
  '***********'
]
*/

class Kata
{
public:
    std::vector<std::string> towerBuilder(int nFloors)
    {
        std::vector<std::string> tower;
        int x = (2 * nFloors) - 1,n = 1;
        std::string level;
        for (int i = 1; i <= nFloors; i++)
        {
          level.clear();
          level.insert(0,(x-n)/2, ' ');
          level.insert(level.end(),n,'*');
          level.insert(level.end(),(x-n)/2, ' ');
          n += 2;
          tower.push_back(level);
        }
        return tower;
    }
};