#include <iostream>
#include <vector>
using namespace std;
void ShowVec(const vector<int> &valList)
{
  for (vector<int>::const_iterator iter = valList.cbegin(); iter != valList.cend(); iter++)
  {
    cout << (*iter) << endl;
  }
}
int main(int argc, char *argv[])
{
  vector<int> valList = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  ShowVec(valList);
  return 0;
}