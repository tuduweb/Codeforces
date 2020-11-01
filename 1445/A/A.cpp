//#include <iostream>
#include "bits/stdc++.h"


using namespace std;
//#define INF 1e9
int a[1000];
int b[1000];



int main()
{
    int caseNum;
    cin >> caseNum;
    string emptyLine =  "";
    while(caseNum--)
    {
        int n,x;
        cin >> n >> x;
        //vector<int > a(n);
        //vector<int > b(n);

        for(int i = 0; i < n; ++i)
        {
            cin >> a[i];
            //cout << a[i] << "/";
        }
        //cout << endl;

        for(int i = 0; i < n; ++i)
        {
            cin >> b[i];
            //cout << b[i] << "/";
        }
        //cout << endl;
        
        if(caseNum > 0)
            getline(std::cin, emptyLine);
        

        if((a[0] + b[n - 1] > x) || (a[n - 1] + b[0] > x))
            cout << "No" << endl;
        else if(a[n - 1] + b[n - 1] <= 0)
            cout << "Yes" << endl;
        else
        {

            int i = 1;
            for(; i < n - 1; ++i)
            {
                if(a[i] + b[ n - 1 - i] > x)
                {
                    cout << "No" << endl;
                    i = 0;
                    break;
                }
            }

            if(i > 0)
                cout << "Yes" << endl;

        }

        //cout << emptyLine;
    }

    return 0;
}