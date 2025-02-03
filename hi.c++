#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "enter a no :-\n";
    cin >> n;
    if (n > 0)
        cout << "The no is positive";
    else if (n < 0)
        cout << "The no is negative";
    else
        cout << "The no is neither negative or positive, it's zero!";
    return 0;
}
