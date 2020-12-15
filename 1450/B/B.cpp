#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


void solve(vector<pair<int , int> > v, int k)
{
    vector<vector<int > > result(v.size());

    //遍历情况
    for(int i = 0; i < v.size(); ++i)
    {
        for(int j = i + 1; j < v.size(); ++j)
        {
            result[i].push_back( (abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second) <= k) );
            //cout << (abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second) <= k) << " ";
        }
    }

    //输出调试
#if 0
    for(int i = 0; i < v.size(); ++i)
    {
        for(int j = 0; j < i + 1; ++j)
        {
            cout << "# ";
        }

        for(int j = 0; j < v.size() - i - 1; ++j)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
#endif
    //查找符合要求的值
    int pass = 0;
    int mk = 0;
    for(; mk < v.size(); ++mk)
    {
        pass = 0;
        for(int i = 0; i < mk; ++i)
        {
            if(result[i][mk - 1 - i])
                pass++;
        }

        for(int j = 0; j < v.size() - mk - 1; ++j)
        {
            if(result[mk][j])
                pass++;
        }

        if(pass == v.size() - 1)
        {
            break;
        }
    }
    
    //cout << "case : K = " << mk << "  pass = " << pass << endl;

    if(pass == v.size() - 1)
        cout << "1" << endl;
    else
        cout << "-1" << endl;
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

        for(int i = 0; i < n; ++i)
        {
            cin >> v[i].first >> v[i].second;
        }
        
        solve(v, k);


    }

    return 0;
}