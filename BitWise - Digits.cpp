//To check if the string contain 0-9 digts
#include <iostream>
using namespace std;

int main() {
    char str[1000001];
    cin >> str;

    int digit = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] >= '0' && str[i] <= '9')
            digit |= (1 << (str[i] - '0'));
    }

    if (digit == (1 << 10) - 1)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}