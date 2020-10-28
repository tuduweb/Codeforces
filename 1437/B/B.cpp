#include <iostream>

using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        while(n--)
        {
            int sLen;
            cin >> sLen;

            string s;
            cin >> s;

            //cout << s << endl;

            int cnt = 0;

            //查找0's,1's相连个数…
            for(int i = 0; i < s.length() - 1;  i++)
            {
                if(s[i] == s[i+1])
                    cnt++;
            }

            cout << (cnt + 1)/2 << endl;

        }
    }
    return 0;
}