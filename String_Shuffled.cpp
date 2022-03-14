#include <bits\stdc++.h>
using namespace std;

bool shuffled(string A, string B)
{
  int n = A.size();
  int m = B.size();

  if (n > m)
  {
    return false;
  }
  else
  {
    sort(A.begin(), A.end());

    for (int i = 0; i < m; i++)
    {

      if (i + n - 1 >= m)
        return false;

      string str = "";

      for (int j = 0; j < n; j++)
        str.push_back(B[i + j]);

      sort(str.begin(), str.end());

      if (str == A)
        return true;
    }
  }
  return NULL;
}

int main()
{

  string s1 = "har";
  string s2 = "prakhar";

  bool a = shuffled(s1, s2);
  cout << boolalpha << a << endl;

  return 0;
}
