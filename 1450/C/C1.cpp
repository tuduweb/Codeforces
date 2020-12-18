#include <iostream>
#include <vector>

using namespace std;


void offical_solve(int n, vector<vector<char> > & v)
{
    int cnt[3] = { 0, 0, 0};

    //分类
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(v[i][j] == 'X')
                cnt[(i+j)%3]++;
        }
    }

    int minCntPos = 0;
    if(cnt[0] <= cnt[1] && cnt[0] <= cnt[2])
        minCntPos = 0;
    else if(cnt[1] <= cnt[0] && cnt[1] <= cnt[2])
        minCntPos = 1;
    else
        minCntPos = 2;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if((i+j)%3 == minCntPos && v[i][j] == 'X')
                v[i][j] = 'O';
        }
    }

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cout << v[i][j];
        }
        cout << endl;
    }


}


void solve(int n, vector<vector<char > >& v)
{
    for(int col = 0; col < n; ++col)
    {
        int k = 0;
        for(int row = 0; row < n; ++row)
        {
            if(v[row][col] == 'X')
            {
                k++;
                if(k == 3)
                {
                    v[row][col] = 'O';
                    k = 0;
                }
            }else{
                k = 0;
            }
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
                if(k == 3)
                {
                    v[row][col] = 'O';
                    k = 0;
                }
            }else{
                k = 0;
            }
        }
    }

    //cout << endl << endl;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
            cout << v[i][j];
        cout << endl;
    }

    // vector<vector<pair<int ,int > > > vInCol(n);
    // vector<vector<pair<int ,int > > > vInRow(n);

    // for(int col = 0; col < n; ++col)
    // {
    //     int k = 0;
    //     for(int row = 0; row < n; ++row)
    //     {
    //         if(v[row][col] == 'X')
    //             k++;
    //         else{
    //             if(k > 2)
    //             {
    //                 //当前为空 从上一个 到 上一个 - k
    //                 vInCol[col].push_back({row - k, k});
    //             }
    //             k = 0;
    //         }
    //     }
    //     //退出时
    //     if(k > 2)
    //     {
    //         //当前为空 从上一个 到 上一个 - k
    //         vInCol[col].push_back({n - k, k});
    //     }
    // }

    // for(int row = 0; row < n; ++row)
    // {
    //     int k = 0;
    //     for(int col = 0; col < n; ++col)
    //     {
    //         if(v[row][col] == 'X')
    //         {
    //             k++;
    //         }else{
    //             if(k > 2)
    //             {
    //                 vInRow[row].push_back({col - k, k});
    //             }
    //             k = 0;
    //         }
    //     }
    //     if(k > 2)
    //     {
    //         vInRow[row].push_back({n - k , k});
    //     }
    // }


    // for(int i = 0; i < vInCol.size(); ++i)
    // {
    //     for(int j = 0; j < vInCol[i].size(); ++j)
    //     {
    //         cout << "[" << vInCol[i][j].first << "," << vInCol[i][j].second << "]  ";
    //     }
    //     cout << endl;
    // }

    // for(int i = 0; i < vInRow.size(); ++i)
    // {
    //     for(int j = 0; j < vInRow[i].size(); ++j)
    //     {
    //         cout << "[" << vInRow[i][j].first << "," << vInRow[i][j].second << "]  ";
    //     }
    //     cout << endl;
    // }

    // //找交点
    // for(int i = 0; i < vInCol.size(); ++i)
    // {
    //     for(int j = 0; j < vInCol[i].size(); ++j)
    //     {
    //         //最少决策点数量 3,4,5 -> 1 6,7,8 -> 2 ..
    //         //k/3
    //     }
    //     cout << endl;
    // }

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



        offical_solve(n, v);

    }

    return 0;
}