#include <iostream>
#include <vector>


using namespace std;


int main()
{
    int n,k;

    cin >> n >> k;

    //cout << n << k;

    //需要判断k是否为0，为0则需要做一次比较

    vector<int > v(n);
    vector<int > set(k + 2);

    for(int i = 0; i < n; i++)
        cin >> v[i];

    for(int i = 0; i < k; i++)
    {
        cin >> set[i + 1];
        set[i+1]--;
    }

    set[0] = 0;
    set[k + 1] = n;

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
    
    for(int i = 0; i < k + 1; ++i)
    {
        if(v[set[i + 1]] - v[set[i]] >= set[i + 1] - set[i]) ok++;

        cout << "[" << i << "]" ; 
        for(int j = set[i]; j < set[i + 1]; ++j)
        {
            cout << v[j] << " ";
        }
        cout << " " << endl;
    }

    cout << "OK:" << ok << endl;

    if(ok != k)
        cout << "NO" << endl;


    return 0;
}