#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int arr[n];

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  int sum = 0;
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (arr[j] > arr[i])
      {
        int tim = arr[i];
        arr[i] = arr[j];
        arr[j] = tim;
        sum = j - i + 1;
      }
    }
  }
  cout << sum << endl;

  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}