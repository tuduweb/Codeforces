#include <iostream>
#include <vector>
#include "math.h"
#include "string.h"

#define DEBUG 1

using namespace std;

#define INF 1e9
typedef long long ll;

struct factor_pair{
    int factor;
    int cnt;
};

vector<struct factor_pair > factors;
vector<int > result;

int cnt[100000];

int solve(ll n)
{
    ll num = n;
    int sqrtn = ceil(sqrtl(n));

#if DEBUG == 1
    cout << "=========================================" << endl;
#endif
    memset(cnt, 0, sizeof(cnt));
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
#endif

    for(int i = 1; i < sqrtn; ++i)
    {
        if(cnt[i] == 0)
            continue;
#if DEBUG == 1
        cout << i << ":" << cnt[i] << endl;
#endif
        factors.push_back({ i, cnt[i]});
    }

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

#if DEBUG == 1

    cout << "1 ";
    for(int i = 0; i < result.size(); ++i)
        cout << result[i] << " ";

    cout << endl;

    cout << "@@@@@@@@@@@@@@@@" << endl;
    cout <<"first:" << first << " min?:" << cnt[pos] << " num:" << pos << "rst.sz=" << result.size() << "fct.sz=" << factors.size() << endl;

#endif

    if(factors.size() > 1 || (factors.size() == 1 && factors[0].cnt > 1))
    {
        cout << factors[0].cnt << endl;
        // for(int i = 0; i < result.size(); ++i)
        //     cout << result[i] << " ";

        ll multi = 1;
        for(int i = 0; i < factors[0].cnt - 1; ++i)
        {
            multi = 1;
#if DEBUG == 1
            cout << " |- ";
#endif
            for(int j = 0; factors[j].factor <= pos && j < factors.size(); ++j)
            {
                if(factors[j].cnt + i >= factors[0].cnt)
                {
                    multi *= factors[j].factor; 
                    //cout << factors[j].factor << " ";
                }
            }
            cout << multi << " ";
        }

#if DEBUG == 1
        cout << " |- ";
#endif
        //特殊处理最后一个,把剩下的都给整上
        multi = 1;

        for(int j = 0; j < factors.size(); ++j)
        {

            multi *= factors[j].factor;
            //cout << factors[j].factor << " ";
            if(factors[j].cnt > factors[0].cnt)
            {
                //继续输出
                for(int k = factors[0].cnt; k < factors[j].cnt; ++k)
                {
                    multi *= factors[j].factor;

                    //cout << factors[j].factor << " ";
                }
            }

            // for(int k = factors[0].cnt - 1; k < factors[j].cnt; ++k)
            // {
            //     cout << factors[j].factor << " ";
            // }
        }
        cout << multi << endl;

    }else{
        cout << 1 << endl << n << endl;
    }

#if DEBUG == 1
    cout << endl << endl << endl;
#endif

    factors.clear();
    result.clear();
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

/**
 * 错误的测试数据

1
9876543210

没有考虑 factor2 = 1的情况
*/