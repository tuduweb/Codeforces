#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int FindLIS_1116(int* array, int length)
{
    if(length == 2)
        return 0;
    int* d = new int[length];
    int bound = array[length - 1];

    int len = 0;
    d[0] = array[0];

    for(int i = 1; i < length - 1; ++i)
    {
        if(array[i] < array[0] || array[i] > bound)
            continue;

        if(array[i] >= d[len])
        {
            d[++len] = array[i];
        }else{
            //查找更新位置
            int j = upper_bound(d, d+len+1,array[i]) - d;
            d[j] = array[i];
        }

    }

    // for(int i = len; i >= 0; --i)
    // {
    //     if(d[i] <= bound)
    //     {
    //         delete[] d;
    //         return i;
    //     }
    // }



    delete[] d;

    return len;

}


int main()
{
    int n,k;

    cin >> n >> k;

    vector<int > v(n + 2);
    vector<int > set(k + 2);

    for(int i = 0; i < n; i++)
    {
        cin >> v[i + 1];
    }

    v[0] = -1e9;
    v[n + 1] = 1e9;

    for(int i = 0; i < k; i++)
    {
        cin >> set[i + 1];
    }

    set[0] = 0;
    set[k + 1] = n + 1;

    //分割成k+1段,分别判断是否能成立 需要做几次运算
    /**
     * Input leftB,rightB,V[array]
    */
    int ok = 0;
    
    //洗键入的数据,转换问题
    for(int i = 1; i < n + 1; i++)
    {
        v[i] -= i;
    }
    
    for(int i = 1; i <= k + 1; ++i)
    {
        //限制条件
        if(v[set[i]] >= v[set[i-1]]) ok++;
        else break;
    }
    if(ok != k+1)
        cout << "-1" << endl;
    else{

        int minRep = 0;

        for(int i = 0; i < k + 1; ++i)
        {
            // cout << "[" << i << "]" ; 
            // for(int j = set[i]; j < set[i + 1] + 1; ++j)
            // {
            //     cout << v[j] << " ";
            // }
            // cout << " " << endl;

            //每一段
            minRep += (set[i + 1] - 1 - set[i]) - FindLIS_1116(&v[set[i]], set[i + 1] + 1 - set[i]);

        }

        cout << minRep << endl;

    }





    return 0;
}

/** err
 *
100 0
4 20 52 2 7 36 8 73 9 99 13 19 14 89 32 2 6 2 16 21 47 22 66 23 25 95 28 4 29 64 30 31 7 48 32 51 35 37 77 57 40 42 56 40 43 44 46 13 47 12 48 49 24 51 69 53 54 98 21 57 59 61 62 52 63 30 68 32 69 39 8 67 71 59 72 81 76 77 11 82 85 14 83 33 86 89 89 90 43 96 91 31 93 69 58 94 45 96 2 99
*/