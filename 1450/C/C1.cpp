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

    vector<vector<pair<int ,int > > > vInCol(n);
    vector<vector<pair<int ,int > > > vInRow(n);

    for(int col = 0; col < n; ++col)
    {
        int k = 0;
        for(int row = 0; row < n; ++row)
        {
            if(v[row][col] == 'X')
                k++;
            else{
                if(k > 2)
                {
                    //当前为空 从上一个 到 上一个 - k
                    vInCol[col].push_back({row - k, row});
                }
                k = 0;
            }
        }
        //退出时
        if(k > 2)
        {
            //当前为空 从上一个 到 上一个 - k
            vInCol[col].push_back({n - k, n});
        }
    }

    for(int row = 0; row < n; ++row)
    {
        int k = 0;
        for(int col = 0; col < n; ++col)
        {
            if(v[row][col] == 'X')
            {
                k++;
            }else{
                if(k > 2)
                {
                    vInRow[row].push_back({col - k, col});
                }
                k = 0;
            }
        }
        if(k > 2)
        {
            vInRow[row].push_back({n - k , n});
        }
    }


    for(int i = 0; i < vInCol.size(); ++i)
    {
        for(int j = 0; j < vInCol[i].size(); ++j)
        {
            cout << "[" << vInCol[i][j].first << "," << vInCol[i][j].second << "]  ";
        }
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