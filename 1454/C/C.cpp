/**
 * 在比赛过程中没有注意细节 自行设计的测试数据没有考虑到等于n的情况 导致没有AC
 * 这种事情是需要踩坑 然后总结的 希望下次不要出现这种离谱的情况
 * 2020年11月25日 小王 于N504
 */
#include <iostream>
#include <vector>
#include "string.h"
#include <algorithm>
using namespace std;

#define INF 1e9

int main()
{
    int testCaseSize;
    int a[200010];
    int occ[200010];

    cin >> testCaseSize;

    while(testCaseSize--)
    {
        int n;
        cin >> n;
        int diffNum = 0;

        memset(occ, 0, sizeof(occ));

        for(int i = 0 ; i < n; ++i)
        {
            cin >> a[i];
            if(occ[a[i]] == 0)
                diffNum++;

            if(i > 0 && a[i] == a[i - 1])
            {
                //不要统计相邻是一样的的..
                continue;
            }

            occ[a[i]]++;
        }

        occ[a[0]]--;
        occ[a[n-1]]--;

        if(occ[a[0]] <= 0)
            occ[a[0]] = -1;
        if(occ[a[n-1]] <= 0)
            occ[a[n-1]] = -1;


        int minElement = INF;
        int minElementPos = -1;

        for(int i = 1; i <= n; ++i)
        {
            if(occ[i] == 0)
                continue;
            
            if(occ[i] < minElement)
            {
                minElement = occ[i];
                minElementPos = i;
            }
        }

#if 0
        cout << "OCC" << endl;
        for(int i = 0; i < n; ++i)
        {
            cout << i << ": " << occ[i] << endl;
        }

        cout << "diff " << diffNum << endl;
        cout << endl;

#endif


        if(diffNum == 1)
        {
            cout << 0 << endl;
        }else if(minElement != -1)
        {
            cout << minElement + 1 << endl;
        }else{
            cout << 1 << endl;
        }
        
        

    }

    return 0;
}

