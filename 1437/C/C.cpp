#include <iostream>
#include "math.h"
#include <algorithm>
#include<iomanip>

using namespace std;

#define DEBUG_MODE 0

/**
 * dp i j
 * i = 0,2n the most bad , pick j1 on time N(N minutes)
 * j = 0->n max n N object
 * n = [1,200]
 * dp[i][j] = max{ dp[i - 1][j], dp[i - 1][j - 1] + Abs(t[j] - i) }
**/
#define MAX_N 200
int dp[MAX_N * 2 + 1][MAX_N + 1];
int t[MAX_N];

#if DEBUG_MODE == 1
#define INF 1e3
#else
#define INF 1e9
#endif

//#define ABS(a) (a > 0 ? a : -a)
int ABS(int a)
{
    if(a > 0)
        return a;
    else
        return -a;
}


int main()
{
    int n;


    for(int i = 0; i < MAX_N*2+1; ++i)
        dp[i][0] = 0;

    //j > i INF
    for(int j = 1; j < MAX_N + 1; ++j)
    {
        for(int i = 0; i < j; ++i)
        {
            dp[i][j] = INF;
        }
    }

#if DEBUG_MODE == 1
    for(int j = 0; j < 10; ++j)
    {
        for(int i = 0; i < 10; ++i)
        {
            cout << dp[i][j] << "\t";
        }
        cout << endl;
    }
#endif

    cin >> n;

    while(n--)
    {
        int dishLen;
        cin >> dishLen;
        for(int i = 0; i < dishLen; ++i)
        {
            cin >> t[i];
        }

        sort(t, t+dishLen);

#if DEBUG_MODE == 1
        for(int i = 0; i < dishLen; ++i)
        {
            cout << t[i] << " ";
        }
        cout << endl;
#endif

        for(int i = 1; i < dishLen * 2 + 1; ++i)
        {
            for(int j = 1; j < dishLen + 1; ++j)
            {
                if(dp[i][j] == INF) continue;
                dp[i][j] = min<int >(dp[i - 1][j], dp[i - 1][j - 1] + ABS(i - t[j - 1]));
#if DEBUG_MODE == 1
                cout << "dp" << i << ","  << j << ":  " << dp[i - 1][j] << "|"  << ABS(i - t[j - 1])<<endl;
#endif
            }
        }

        

#if DEBUG_MODE == 1
        for(int j = 0; j < dishLen+1; ++j)
        {
            for(int i = 0; i < 2*dishLen+1; ++i)
            {
                cout << setw(5)<<dp[i][j];
            }
            cout << endl;
        }
#else
        cout << dp[dishLen*2][dishLen] << endl;
#endif
    }


    return 0;
}