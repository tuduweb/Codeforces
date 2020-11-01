//#include <iostream>
#include "bits/stdc++.h"


using namespace std;
#define INF 1e9
//int a[1000];
//int b[1000];



int main()
{
    int caseNum;
    cin >> caseNum;
    string emptyLine =  "";
    while(caseNum--)
    {
        int n,x;
        cin >> n >> x;
        vector<int > a(n);
        vector<int > b(n);

        for(int i = 0; i < n; ++i)
        {
            cin >> a[i];
            //cout << a[i] << "/";
        }
        //cout << endl;
        b[0] = 1e9;
        for(int i = 0; i < n; ++i)
        {
            cin >> b[i];
            b[i] -= x;
            //cout << b[i] << "/";
        }
        //cout << endl;

        getline(std::cin, emptyLine);
        

        if((a[0] + b[n] > 0) || (a[n - 1] + b[1] > 0))
            cout << "NO" << endl;
        else if(a[n - 1] + b[n] <= 0)
            cout << "YES" << endl;
        else
        {
            int p = 0,q = n - 1;
            while(q)
            {
                if(a[p] == INF)
                {
                    q--;
                    continue;
                }

                if(a[p] + b[q] <= 0)
                {
                    //找到最临界的
                    p++;
                }else{//>0
                    a[p] = INF;
                    p--;//P太大,需要减小
                }
            }
            if(p == n - 1)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }

        //cout << emptyLine;
    }

    return 0;
}