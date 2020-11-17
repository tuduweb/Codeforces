#include <iostream>

using namespace std;

int main()
{
    int testCaseSize;
    cin >> testCaseSize;

    while(testCaseSize--)
    {
        int n,c0,c1,h;

        cin >> n >> c0 >> c1 >> h;
        string s;

        cin >> s;

        //cout << s << endl;

        int payment = 0,t1 = 0,t0;

        for(auto c : s)
        {
            if(c == '1')
                t1++;
        }

        t0 = s.length() - t1;

        //0 -> 1 
        if(c0 - c1 > h)
        {
            payment = s.length() * c1 + t0 * h; 
        }else if(c1 - c0 > h)
        {
            payment = s.length() * c0 + t1 * h;
        }else{
            payment = c1 * t1 + c0 * t0;
        }

        cout << payment << endl;

    }

    return 0;
}