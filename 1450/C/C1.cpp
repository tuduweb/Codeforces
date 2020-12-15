#include <iostream>
#include <vector>

using namespace std;



void solve(int n, vector<vector<char > >& v)
{
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
            cout << v[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int testCase;

    cin >> testCase;

    while(testCase--)
    {
        int n;

        cin >> n;

        vector<vector<char > > v(n, vector<char >(n));

        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
                cin >> v[i][j];
        }



        solve(n, v);

    }

    return 0;
}