#include <iostream>
#include <vector>
#include "math.h"
#include "string.h"

#define DEBUG 0

using namespace std;

#define INF 1e9
typedef long long ll;

struct factor_pair{
    ll factor;
    int cnt;
};

vector<struct factor_pair > factors;
vector<int > result;

int cnt[100000];

void solve2(ll number)
{
    int factor_limit = ceil(sqrtl(number));
    //memset(cnt, 0, sizeof(cnt));
    cnt[0] = cnt[1] = cnt[2] = 0;
#if DEBUG == 1
    cout << "=====================================" << endl;
#endif

    // find factors
    ll num_temp = number;
    int factor = 2;
    for(; factor <= factor_limit; )
    {
        if(num_temp % factor == 0)
        {
            result.push_back(factor);
            num_temp /= factor;
            cnt[factor]++;
        }else{
            cnt[factor + 1] = 0;
            factor++;
            if(num_temp < factor_limit)
                break;
        }
    }
    //处理边界
    //if(num_temp > factor_limit)

    
#if DEBUG == 1
    cout << "FACTORS:" << endl;
#endif
    int max_cnt = 1;
    for(int i = 2; i <= factor; ++i)
    {
        if(cnt[i] == 0)
            continue;

        if(cnt[i] > max_cnt)
            max_cnt = cnt[i];
        //把统计数据加入到factors数据结构向量中
        factors.push_back({i, cnt[i]});
    }

    if(factors.size() && num_temp > factors.back().factor || factors.size() == 0)
        factors.push_back({num_temp, 1});

#if DEBUG == 1
    for(int i = 0; i < factors.size(); ++i)
    {
        cout << "[" << factors[i].factor << "] " << factors[i].cnt << endl;
    }
#endif

    //输出结果
    cout << max_cnt << endl;

    for(int output_pos = 0; output_pos < max_cnt; ++output_pos)
    {
        ll output = 1;
        //cout << "[o " << output_pos << "] ";
        for(int fact_pos = 0; fact_pos < factors.size(); ++fact_pos)
        {
            if(factors[fact_pos].cnt + output_pos >= max_cnt)
            {
                //cout << factors[fact_pos].factor << " ";
                output *= factors[fact_pos].factor;
            }
        }
        cout << output << " ";
    }
    cout << endl;
    //cout << endl << endl << endl;
    factors.clear();
    result.clear();
}


int main()
{
    int testCaseSize;

    cin >> testCaseSize;

    while(testCaseSize--)
    {
        ll n;
        cin >> n;
        solve2(n);
    }

    return 0;
}

/**
 * 错误的测试数据

1
9876543210

没有考虑 factor2 = 1的情况
没有考虑 剩余的数字大于sqrt的情况
*/