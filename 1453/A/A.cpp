#include <iostream>
#include <vector>

using namespace std;

int bottoms[100+1],lefts[100+1];

vector<int > result;

void solve(int n,int m, int* a, int* b)
{
    int res = 0;
    //两个中的元素相等就相撞
    a[n] = 0; b[m] = 0;
    int i = 0, j = 0;

    while(a[i] && b[j])
    {
        if(a[i] == b[j])
        {
            res++;i++;j++;
        }else if(a[i] < b[j])
            i++;
        else
            j++;
    }
    //cout << res << endl;

    result.push_back(res);
}

int main()
{
    int caseNum;
    cin >> caseNum;

    while(caseNum--)
    {
        int n,m;
        cin >> n >> m;
        for(int i = 0; i < n; ++i)
        {
            cin >> bottoms[i];
        }

        for(int j = 0; j < m; ++j)
        {
            cin >> lefts[j];
        }
        
        solve(n, m, bottoms, lefts);
    }

    for (auto item : result)
    {
        cout << item << endl;
    }

    return 0;
}