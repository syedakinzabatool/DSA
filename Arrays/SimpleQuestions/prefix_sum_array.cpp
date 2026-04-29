#include <iostream>
using namespace std;

int main()
{
    int n = 4;
    int A[n] = {1, 2, 3, 4};
    int pre[n + 1];
    pre[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + A[i - 1];
    }

    for (int i = 0; i <= n; i++)
    {
        cout << pre[i] << " ";
        cout << endl;
    }
    // To get the sum of the required index.
    int i = 2;
    int j = 3;
    cout << "The sum of the required part is: " << pre[j + 1] - pre[i] << endl;

    return 0;
}
