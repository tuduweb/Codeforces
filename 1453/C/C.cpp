/**
 * https://codeforces.com/contest/1453/problem/C
 **/
#include <iostream>
#include <vector>



using namespace std;

struct point{
    int x;
    int y;
};

void solve(vector<vector<int > > v)
{
    //if the result(>0) satisfied, need two vertex.
}

void solve_line(int n, vector<struct point >* v)
{
    int result[10];
    for(int digit = 0; digit < 10; ++digit)
    {
        if(v[digit].size() < 2)
        {
            result[digit] = 0;
            continue;
        }



        //

    }
}

int main()
{
    int caseNum = 0;
    cin >> caseNum;

    while(caseNum--)
    {
        int n;
        cin >> n;
        char inputChar;

        // vector<vector<int > > v(n, vector<int >(n));

        // for(int r = 0; r < n; ++r)
        // {
            
        //     for(int c = 0; c < n;)
        //     {
        //         inputChar = getchar();
        //         if(inputChar >= '0' && inputChar <='9')
        //         {
        //             v[r][c] = inputChar - '0';
        //             cout << v[r][c] << " ";
        //             c++;
        //         }
        //     }
        //     cout << endl;
        // }

        // solve(v);

        vector<struct point > v[10];

        for(int r = 0; r < n; r++)
        {
            for(int c = 0; c < n;)
            {
                inputChar = getchar();
                if(inputChar >= '0' && inputChar <='9')
                {
                    inputChar -= '0';
                    v[inputChar].push_back({c,r});
                    c++;
                }
            }
        }

        for(int i = 0; i < 10; ++i)
        {
            cout << "[" << i << "] ";
            for(int j = 0; j < v[i].size(); ++j)
                cout << "(" << v[i][j].x << "," << v[i][j].y << ") ";
            cout << endl;
        }

        solve_line(n, v);


    }

    return 0;
}