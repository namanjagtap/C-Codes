#include <iostream>

using namespace std;

int modPower(long long input1, unsigned int input2, int input3)
{

    int res = 1;
    input1 = input1 % input3;

    if (input1 == 0)
        return 0;

    while (input3 > 0)

    {
        if (input3 & 1)

            res = (res * input1) % input3;

        input3 = input3 >> 1;

        input1 = (input1 * input1) % input3;
    }

    return res;
}

int main()
{

    int input1;
    cin >> input1;

    int input2;
    cin >> input2;

    int input3;
    cin >> input3;

    cout << "Power is " << modPower(input1, input3, input3);
    return 0;
}