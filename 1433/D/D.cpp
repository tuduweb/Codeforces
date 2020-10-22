#include <iostream>
#include <vector>

using namespace std;


int main()
{
    int n = 0;
    cin >> n;

    for(;n > 0; --n)
    {
        int caseSize = 0;
        cin >> caseSize;

        vector<pair<int ,int > > v;

        int* oneSet = new int[caseSize];

        int i = 0;
        for(; i < caseSize; ++i)
        {
            cin >> oneSet[i];
        }

        //跳过开头相同的元素
        for(i = 1; i < caseSize; ++i)
        {
            if(oneSet[i] != oneSet[0])
                break;
        }

        //第i个与之前不同,那么表明有结果
        for(; i < caseSize; ++i)
        {
            if(oneSet[i] != oneSet[0])
                v.push_back(make_pair(0, i));
            else
                v.push_back( make_pair( v.front().second, i ) );
        }

        if(v.size() == 0)
        {
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
            for(int i = 0; i < v.size(); ++i)
                cout << v[i].first + 1 << " " << v[i].second + 1 << endl;
            //补全头部跳过的
            for(int i = v.front().second - 1; i > 0; --i)
                cout << i + 1 << " " << v.front().second + 1 << endl;
        }

        delete []oneSet;

    }

    return 0;
}