#include <iostream>
#include <vector>

using namespace std;

/**
 * 不是普通的题目
 * 是需要找到maximum的值
 * 
 * 需要找到最大值,那么medians以下的值应该是
 */
int main()
{
    int testCaseSize;
    cin >> testCaseSize;

    while(testCaseSize--)
    {
        int n,k;
        cin >> n >> k;
        
        vector<int > v(1000);//non-decreasing
        int temp;
        int sum = 0, medians = (n + 1) / 2 - 1;

        for(int i = 0; i < k; ++i)
        {

            for(int j = 0; j < n; ++j)
            {
                cin >> temp;
                if(j == medians)
                {
                    sum += temp;
                }
            }
        }

        cout << "medians: " << medians << "  sum: " << sum << endl;

    }

    return 0;
}