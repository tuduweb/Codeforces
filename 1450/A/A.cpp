#include <iostream>
#include <string>
using namespace std;


/**
 * permutation 置换
 * 错误答案：错误应该错在英语的理解不到位上
 * can be obtained from a by deletion of several (possibly, zero or all) characters


int main()
{
    int caseSize;
    cin >> caseSize;
    while(caseSize--)
    {
        int n;//0->200
        cin >> n;
        string s;
        cin >> s;

        string::size_type pos = 0;
        while((pos = s.find("trygub", pos))  != std::string::npos)
        {
            s.replace(pos, 2, "rt");
            pos +=6;
        }
        
        cout << s << endl;
    }

    return 0;
}
 */

#include <algorithm>

int main()
{
    int caseSize;
    cin >> caseSize;

    while(caseSize--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        sort(s.begin(), s.end());

        cout << s << endl;
    }

}