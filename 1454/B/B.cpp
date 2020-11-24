#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

#define INF 1e9

int main()
{
    int testCaseSize;
    vector<int > v;
    int a[200000];
    int b[200000];
    cin >> testCaseSize;

    while(testCaseSize--)
    {
        int n;
        cin >> n;// number of participants
        
        for(int i = 0; i < n; ++i)
        {
            cin >> a[i];
            b[i] = a[i];
        }


        sort(a, a + n);
        a[n] = INF;

        int num = -1;
        int first = -999;
        int flag = -1;

        for(int i = 0; i < n; ++i)
        {
            if(a[i] != a[i+1])
            {

                if(flag == -1)
                {
                    num = a[i];
                    break;
                }else{
                    flag = -1;
                }

            }else{
                flag++;
            }
            
        }
        

        if(num == -1)
            cout << "-1";
        else{
            for(int i = 0; i < n; ++i)
            {
                if(b[i] == num)
                    cout << i + 1;
            }
        }

        cout << endl;



    }

    return 0;//-1 no winner
}