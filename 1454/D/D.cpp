#include <iostream>
#include <vector>
#include "math.h"
#include "string.h"

#define DEBUG 1

using namespace std;

#define INF 1e9
typedef long long ll;

int solve(ll n)
{
    ll num = n;
    int sqrtn = ceil(sqrtl(n));
    vector<int > result;
    int cnt[100000];

    cout << "=========================================" << endl;

    for(int i = 2; i <= sqrtn; )
    {
        //整除
        if(num % i == 0)
        {
            result.push_back(i);
            num = num / i;
            cnt[i]++;
        }else{
            i++;
        }
    }

    cnt[0] = sqrtn;

#if DEBUG == 1
    cout << "FACTOR:" << endl;

    for(int i = 1; i < sqrtn; ++i)
    {
        if(cnt[i] == 0)
            continue;
        cout << i << ":" << cnt[i] << endl;
    }
#endif

    //查找凹点
    int pos = 0;
    ll first = 0;
    int numCnt = 0;

    for(int i = 1; i < result.size(); ++i)
    {
        if(cnt[i] == 0)
            continue;
        else
        {
            if(first == 0)
                first = pos;
            if(pos == 0)
                pos = i;
            if((cnt[i] <= cnt[pos]))
                pos = i;
            else
                break;
        }
    }

    if(first == 0)
        first = n;

    cout <<"first:" << first << " min?:" << cnt[pos] << " num:" << pos << endl;

#if DEBUG == 1
    cout << "1 ";
    for(int i = 0; i < result.size(); ++i)
        cout << result[i] << " ";
#endif
    cout << endl;

    cout << "RESULT!" << endl;

    if(first <= pos)
    {
        cout << result.size() << endl;
        for(int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
    }else{
        cout << 1 << endl << n << endl;
    }

    cout << endl << endl << endl;

    return 0;
}


int main()
{
    int testCaseSize;

    cin >> testCaseSize;

    while(testCaseSize--)
    {
        ll n;
        cin >> n;
        solve(n);
    }

    return 0;
}