#include <iostream>
#include <vector>
#include "math.h"
#include "string.h"

using namespace std;

#define INF 1e9
typedef long long ll;

int solve(ll n)
{
    ll num = n;
    int sqrtn = ceil(sqrtl(n));
    vector<int > result;
    int cnt[100000];

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


    for(int i = 0; i < result.size(); ++i)
    {
        cout << i << ":" << cnt[i] << endl;
    }

    //查找凹点
    int pos = 0;
    cnt[0] = sqrtn;
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

    for(int i = 0; i < result.size(); ++i)
        cout << result[i] << " ";

    cout << endl;

    cout << "RESULT!" << endl;

    if(first <= pos)
    {
        cout << 
    }else{
        cout << 1 << endl << n << endl;
    }


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