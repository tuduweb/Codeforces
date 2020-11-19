#include <iostream>
using namespace std;
#include <vector>

/**
 * 暴力法
 * 在2*2的区块里面,从全1到全0需要转换4次
 * 1 1      0 0     0 1     1 1     0 0
 * 1 1      0 1     1 0     0 1     0 0
 * [4]      [1]     [2]     [3]     [0]
 * 
 * 策略 暴力左边扫到右边
 * 
 *      A B C D
 * CASE 0 0 0 0
 * 0    0 0 0 0
 * 1    0 0 0 1
 * 2    0 0 1 0
 * 3    0 0 1 1
 */
#define A (v[x][y] - '0')
#define B (v[x+1][y] - '0')
#define C (v[x][y+1] - '0')
#define D (v[x+1][y+1] - '0')

#define PA  cout << x+1 << " " << y+1 << " "
#define PB  cout << x+2 << " " << y+1 << " "
#define PC  cout << x+1 << " " << y+2 << " "
#define PD  cout << x+2 << " " << y+2 << " "
#define ENDL cout << endl
#define RESET v[x][y] = '0';v[x+1][y] = '0';v[x][y+1]='0';v[x+1][y+1]='0'

#define CS(a,b,c,d) (a*8 + b*4 + c*2 +d)

void DirectSolution(int n, int m, vector<string > v)
{
    //行
    int cs = 0;
    int sum = 0;

    for(int x = 0; x < n; )
    {
        //列
        for(int y = 0; y < m; )
        {
            // 2*x,2*y 2*x+1,2*y 2*x,y+1
            // cout << "(" << x << "," << y << ") = " << v[x][y];
            // cout << "(" << x+1 << "," << y << ") = " << v[x+1][y];
            // cout << "(" << x << "," << y+1 << ") = " << v[x][y+1];
            // cout << "(" << x+1 << "," << y+1 << ") = " << v[x+1][y+1];

            cs = A * 8 +B * 4 +C * 2 + D;

            // cout << "   cs=" << cs;
            // cout << endl;

            while(1)
            {
                switch (cs)
                {
                case CS(1,1,1,0):
                case CS(1,1,0,1):
                case CS(1,0,1,1):
                case CS(0,1,1,1):
                    sum += 1;
                    break;
                case CS(1,1,1,1):
                    sum += 4;
                    break;
                case CS(1,1,0,0):
                    sum += 2;
                    break;
                case CS(1,0,1,0):
                    sum += 2;
                    break;
                case CS(1,0,0,1):
                    sum += 2;
                    break;
                case CS(0,1,1,0):
                    sum += 2;
                    break;
                case CS(0,1,0,1):
                    sum += 2;
                    break;
                case CS(0,0,1,1):
                    sum += 2;
                    break;
                case CS(1,0,0,0):
                    sum += 3;
                    break;
                case CS(0,1,0,0):
                    sum += 3;
                    break;
                case CS(0,0,1,0):
                    sum += 3;
                    break;
                case CS(0,0,0,1):
                    sum += 3;
                    break;
                case CS(0,0,0,0):
                    break;
                default:
                    break;
                }

                break;
                if(cs = CS(0,0,0,0))
                    break;
            }
        
            y+=2;
            if(y == m - 1)
            {
                //特殊处理边沿位置
                y-=1;
            }
                    
        }

        x+=2;
        if(x == n - 1)
        {
            x-=1;
        }
    }

    cout << sum << endl;

    for(int x = 0; x < n; )
    {
        //列
        for(int y = 0; y < m; )
        {
            // 2*x,2*y 2*x+1,2*y 2*x,y+1
            // cout << "(" << x << "," << y << ") = " << v[x][y];
            // cout << "(" << x+1 << "," << y << ") = " << v[x+1][y];
            // cout << "(" << x << "," << y+1 << ") = " << v[x][y+1];
            // cout << "(" << x+1 << "," << y+1 << ") = " << v[x+1][y+1];

            cs = A * 8 +B * 4 +C * 2 + D;

            // cout << "   cs=" << cs;
            // cout << endl;

            while(1)
            {
                switch (cs)
                {
                case CS(1,1,1,0):
                case CS(1,1,0,1):
                case CS(1,0,1,1):
                case CS(0,1,1,1):
                    if(A) PA;
                    if(B) PB;
                    if(C) PC;
                    if(D) PD;
                    ENDL;
                    sum += 3;
                    break;
                case CS(1,1,1,1):
                    PA;PB;PC;ENDL;//1
                    PB;PC;PD;ENDL;//2
                    PA;PC;PD;ENDL;//3
                    PA;PB;PD;ENDL;//0
                    sum += 4;
                    break;
                case CS(1,1,0,0):
                    PA;PC;PD;ENDL;//0,1,1,1
                    PB;PC;PD;ENDL;
                    sum += 2;
                    break;
                case CS(1,0,1,0):
                    PA;PB;PD;ENDL;//0,1,1,1
                    PB;PC;PD;ENDL;
                    sum += 2;
                    break;
                case CS(1,0,0,1):
                    PA;PB;PC;ENDL;
                    PB;PC;PD;ENDL;
                    sum += 2;
                    break;
                case CS(0,1,1,0):
                    PA;PB;PD;ENDL;
                    PA;PC;PD;ENDL;
                    sum += 2;
                    break;
                case CS(0,1,0,1):
                    PA;PB;PC;ENDL;
                    PA;PC;PD;ENDL;
                    sum += 2;
                    break;
                case CS(0,0,1,1):
                    PA;PB;PC;ENDL;
                    PA;PB;PD;ENDL;
                    sum += 2;
                    break;
                case CS(1,0,0,0):
                    PA;PB;PC;ENDL;
                    PA;PB;PD;ENDL;
                    PA;PC;PD;ENDL;
                    sum += 3;
                    break;
                case CS(0,1,0,0):
                    PA;PB;PC;ENDL;
                    PA;PB;PD;ENDL;//0,1,1,1
                    PB;PC;PD;ENDL;
                    sum += 3;
                    break;
                case CS(0,0,1,0):
                    PA;PB;PC;ENDL;
                    PA;PC;PD;ENDL;//0,1,1,1
                    PB;PC;PD;ENDL;
                    sum += 3;
                    break;
                case CS(0,0,0,1):
                    PB;PC;PD;ENDL;
                    PA;PB;PD;ENDL;
                    PA;PC;PD;ENDL;
                    sum += 3;
                    break;
                case CS(0,0,0,0):
                    break;
                default:
                    break;
                }
                RESET;

                break;
                if(cs = CS(0,0,0,0))
                    break;
            }
        
            y+=2;
            if(y == m - 1)
            {
                //特殊处理边沿位置
                y-=1;
            }
                    
        }

        x+=2;
        if(x == n - 1)
        {
            x-=1;
        }
    }

}

int main()
{
    int testCaseSize;
    cin >> testCaseSize;

    while(testCaseSize--)
    {
        int n, m;
        cin >> n >> m;
        vector<string > vex(n);
        for(int row = 0; row < n; ++row)
        {
            cin >> vex[row];
        }

        // for(int i = 0; i < n; ++i)
        // {
        //     cout << vex[i] << endl;
        // }

        DirectSolution(n, m, vex);
    }

    return 0;
}