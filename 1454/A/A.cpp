#include <iostream>
#include <vector>

using namespace std;

#define INF 10e9

int main()
{
    int testCaseSize;
    cin >> testCaseSize;

    while(testCaseSize--)
    {
        int n;

        cin >> n;

        for(int i = 2; i <= n; ++i)
            cout << i << " ";
        
        cout << "1" << endl;

    }
    return 0;
}