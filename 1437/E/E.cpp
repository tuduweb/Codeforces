#include <iostream>
#include <vector>


using namespace std;

/**
 * 贪心+二分查找找有限制条件的
 */
int FindLIS(int* array, int length)
{
    if(length == 2)
        return 0;
    vector<int > d(length);
    int bound = array[length - 1];
    int len = 0;
    d[0] = array[0];
    for(int i = 1; i < length - 1; ++i)
    {
        if(array[i] < array[0] + i)
            array[i] = 1e9;
    }

    for(int i = 1; i < length - 1; ++i)
    {
        //大于上边界,这个值可以直接忽略了
        if(array[i] >= bound)
            continue;
        
        if(array[i] > d[len])
        {
            // if(array[i] < array[i - 1] + i)
            //     continue;
            //贪心,比上一个长度大一些,进位
            d[++len] = array[i];
        }else if(array[i] == d[len]){
            continue;
        }else{
            //小,那么满足尽可能小的情况,二分查找“刚刚好”的位置
            int l = 1, r = len, pos = 0;
            while(l <= r)
            {
                int mid = (l + r) / 2;
                if(d[mid] < array[i])
                {
                    //还太大了,那么作为左边界
                    pos = mid;
                    l = mid + 1;
                }else{
                    //比较小了,那么作为右边界
                    r = mid - 1;
                }
            }
            //二分查找完毕,pos + 1为所找
            d[pos + 1] = array[i];
        }
    }

    for(int i = 0; i < length; ++i)
    {
        cout << array[i] << " ";
    }

    cout << "| lis:" << len << endl;

    

    return len;
}

int main()
{
    int n,k;

    cin >> n >> k;

    //cout << n << k;

    //需要判断k是否为0，为0则需要做一次比较

    vector<int > v(n + 2);
    vector<int > set(k + 2);

    for(int i = 0; i < n; i++)
        cin >> v[i + 1];

    v[0] = -1e9;
    v[n + 1] = 1e9;

    for(int i = 0; i < k; i++)
    {
        cin >> set[i + 1];
        set[i+1];
    }

    set[0] = 0;
    set[k + 1] = n + 1;

    // for(int i = 0; i < n; i++)
    //     cout << vn[i] << " ";

    // cout << endl;

    // for(int i = 0; i < k; i++)
    //     cout << vk[i] << " ";

    // cout << endl;

    //分割成k+2段,分别判断是否能成立 需要做几次运算
    /**
     * Input leftB,rightB,V[array]
    */
    int ok = 0;

    for(int i = 1; i < k + 1; ++i)
    {
        //限制条件
        if(v[set[i + 1]] - v[set[i]] >= set[i + 1] - set[i]) ok++;
        else break;
    }
    if(ok != k)
        cout << "-1" << endl;
    else{

        int minRep = 0;

        for(int i = 0; i < k + 1; ++i)
        {
            //cout << "[" << i << "]" ; 
            for(int j = set[i]; j < set[i + 1] + 1; ++j)
            {
                //cout << v[j] << " ";
            }
            /**
            //left set[i]
            //right set[i+1] + 1
            //array left->right
            **/
            minRep += set[i + 1] - 1 - set[i] - FindLIS(&v[set[i]], set[i + 1] + 1 - set[i]);

            //cout << " " << endl;
        }

        cout << minRep << endl;

    }





    return 0;
}