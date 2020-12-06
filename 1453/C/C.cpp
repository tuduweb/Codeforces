/**
 * https://codeforces.com/contest/1453/problem/C
 * 想破头也想不出来,只能想到最拉跨的方法..但写起来一定特别麻烦
 * 视频: https://www.youtube.com/watch?v=TZhy-BIIO-Q (印度人…)
 **/
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

struct point{
    int c;
    int r;
};

void solve(vector<vector<int > > v)
{
    //if the result(>0) satisfied, need two vertex.
}

void solve_line(int n, vector<struct point >* v)
{
    vector<int > ans(10, 0);
    for(int digit = 0; digit < 10; ++digit)
    {
        if(v[digit].size() < 2)
        {
            ans[digit] = 0;
            continue;
        }

        //关键点,最最最靠近四个边的点
        struct point    minC = {n, n},
                        maxC = {-1, -1},
                        minR = {n, n},
                        maxR = {-1, -1};
        #define P v[digit][i]
        for(int i = 0; i < v[digit].size(); ++i)
        {
            if(P.c < minC.c) minC = P;
            if(P.c > maxC.c) maxC = P;
            if(P.r < minR.r) minR = P;
            if(P.r > maxR.r) maxR = P;
        }
        // cout << "minC(" << minC.c <<  "," << minC.r << ")" << endl;
        // cout << "maxC(" << maxC.c <<  "," << maxC.r << ")" << endl;
        // cout << "minR(" << minC.c <<  "," << minR.r << ")" << endl;
        // cout << "maxR(" << maxR.c <<  "," << maxR.r << ")" << endl;
        //所有位置的遍历,取出最大面积ans
        for(int i = 0; i < v[digit].size(); ++i)
        {
            ans[digit] = max(ans[digit], max(P.c - minC.c, maxC.c - P.c) * max(P.r, n - 1 - P.r));
            ans[digit] = max(ans[digit], max(P.r - minR.r, maxR.r - P.r) * max(P.c, n - 1 - P.c));
        }
        //
    }

    for(int i = 0; i < 10; ++i)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main()
{
    int caseNum = 0;
    cin >> caseNum;

    while(caseNum--)
    {
        int n;
        cin >> n;
        char inputChar;

        // vector<vector<int > > v(n, vector<int >(n));

        // for(int r = 0; r < n; ++r)
        // {
            
        //     for(int c = 0; c < n;)
        //     {
        //         inputChar = getchar();
        //         if(inputChar >= '0' && inputChar <='9')
        //         {
        //             v[r][c] = inputChar - '0';
        //             cout << v[r][c] << " ";
        //             c++;
        //         }
        //     }
        //     cout << endl;
        // }

        // solve(v);

        vector<struct point > v[10];

        for(int r = 0; r < n; r++)
        {
            for(int c = 0; c < n;)
            {
                inputChar = getchar();
                if(inputChar >= '0' && inputChar <='9')
                {
                    inputChar -= '0';
                    v[inputChar].push_back({r,c});
                    c++;
                }
            }
        }

        // for(int i = 0; i < 10; ++i)
        // {
        //     cout << "[" << i << "] ";
        //     for(int j = 0; j < v[i].size(); ++j)
        //         cout << "(" << v[i][j].c << "," << v[i][j].r << ") ";
        //     cout << endl;
        // }

        solve_line(n, v);


    }

    return 0;
}