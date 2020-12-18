/**
 * https://codeforces.com/contest/1450/problem/D
 */
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

void solve(int n, vector<int > & v)
{
    vector<int > v_copy = v;
    
    sort(v_copy.begin(), v_copy.end());
    //找连续的 不连续了就最大这么多

    //继续搜
}

int main()
{
    int caseSize;
    cin >> caseSize;

    while(caseSize--)
    {
        int n; 
        cin >> n;

        vector<int> v(n);

        for(int i  = 0; i < n; ++i)
        {
            cin >> v[i];
        }


        solve(n, v);

    }

    return 0;
}