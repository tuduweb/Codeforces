#include <iostream>
#include <vector>


using namespace std;


void solve(vector<pair<int , int> > v, int k)
{
    vector<vector<int > > result;

    //遍历情况
    for(int i = 0; i < v.size(); ++i)
    {
        for(int j = i + 1; j < v.size(); ++j)
        {
            result[i].push_back(v[j].first);
        }
    }
}

int main()
{
    int testCase;

    cin >> testCase;

    while(testCase--)
    {
        int n,k;

        cin >> n >> k;

        vector<pair<int , int> > v(n);

        for(int i = 0; i < n; ++n)
        {
            cin >> v[i].first >> v[i].second;   
        }
        
        solve(v, k);


    }

    return 0;
}