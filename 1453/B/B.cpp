#include <iostream>
#include <vector>
using namespace std;




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
        
        vector<int > v(n);
        for(int i = 0; i < n; ++i)
        {
            cin >> v[i];
        }

        solve(v);
    }
    return 0;
}
