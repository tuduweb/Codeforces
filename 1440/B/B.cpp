#include <iostream>
#include <vector>

using namespace std;

/**
 * 不是普通的题目
 * 是需要找到maximum的值
 * 
 * 需要找到最大值,那么medians以下的值应该是
 * 
 * 贪心策略 那么从最大值开始填坑,可以找到通项公式
 * n*k - (n - medians) * p = i (p = 1,2,……,k)
 */
int main()
{
    int testCaseSize;
    cin >> testCaseSize;

    while(testCaseSize--)
    {
        int n,k;
        cin >> n >> k;
        
        //vector<int > v(1000);//non-decreasing
        __int64 temp = 0,sum = 0;
        int medians = (n + 1) / 2 - 1;

        for(int i = 0; i < k*n; ++i)
        {

            cin >> temp;
            if(((n*k - i) % (n - medians)== 0) && i >= (n*k - k*(n - medians)))
            {
                sum += temp;
                //cout << temp << " ";
            }
        }
        //cout << endl;

        //cout << "medians: " << medians << "  sum: " << sum << endl;
        cout << sum << endl;
    }

    return 0;
}