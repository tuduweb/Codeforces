#include <iostream>
#include <vector>
#include "math.h"

using namespace std;


typedef long long ll;

inline ll MyAbs(ll num)
{
    if(num < 0)
        return -num;
    return num;
}

void solve(vector<int >& v)
{
    //i->n increase 1, or decrease 1
    //you have the option of changing one of the integers in the array to any other integer



    //output minimum
}


int main()
{
    int caseNum;
    cin >> caseNum;

    while(caseNum--)
    {
        int n;

        cin >> n;
        
        vector<ll > v(n);

        ll sum = 0, minSum = 1e19;

        for(int i = 0; i < n; ++i)
        {
            cin >> v[i];
        }

        for(int i = 0; i < n - 1; ++i)
        {
            v[i] -= v[i+1];
        }

        for(int i = 0; i < n - 1; ++i)
        {
            //cout << v[i] << " ";
            sum += MyAbs(v[i]);
        }

        //cout << endl;

        // 0 -> n-2 (n - 1 items)
        //change one item will change left and right item(or only one(left or right))
        for(int i = 0; i < n - 1; ++i)
        {
            ll temp = sum;
            //set v[i] -> 0
            if(i != 0)
            {
                temp -= MyAbs(v[i]);
                //no left
            }
            ll tempNum = v[i + 1];
            if(i != n - 2)
            {
                // -5 -> 0 equal sub 5
                // 0 -> -5 equal add 5
                // -1 -> 5 equal add 4
                //no right
                temp = temp - MyAbs(v[i+1]) + MyAbs(tempNum + v[i]);
            }

            if(temp < minSum) minSum = temp;
        }
        cout << minSum;
        cout << endl << endl;
        //solve(v);
    }
    return 0;
}
