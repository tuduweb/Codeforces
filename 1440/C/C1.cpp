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

#define P1 x+1,y+1
#define P2 x+2,y+1
#define P3 x+1,y+2
#define P4 x+2,y+2

#define CS(a,b,c,d) (a*8 + b*4 + c*2 +d)

struct P{
    int num1X,num1Y,num2X,num2Y,num3X,num3Y;
};
vector<P > p;

void DirectSolution(int n, int m, vector<string >& v)
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
                    // if(A) PA;
                    // if(B) PB;
                    // if(C) PC;
                    // if(D) PD;
                    if(!A)
                        p.push_back({P2,P3,P4});
                    else if(!B)
                        p.push_back({P1,P3,P4});
                    else if(!C)
                        p.push_back({P1,P2,P4});
                    else if(!D)
                        p.push_back({P1,P2,P3});

                    // ENDL;
                    sum += 3;
                    break;
                case CS(1,1,1,1):
                    p.push_back({P1,P2,P3});
                    p.push_back({P2,P3,P4});
                    p.push_back({P1,P3,P4});
                    p.push_back({P1,P2,P4});
                    // PA;PB;PC;ENDL;//1
                    // PB;PC;PD;ENDL;//2
                    // PA;PC;PD;ENDL;//3
                    // PA;PB;PD;ENDL;//0
                    sum += 4;
                    break;
                case CS(1,1,0,0):
                    p.push_back({P1,P3,P4});
                    p.push_back({P2,P3,P4});
                    // PA;PC;PD;ENDL;//0,1,1,1
                    // PB;PC;PD;ENDL;
                    sum += 2;
                    break;
                case CS(1,0,1,0):
                    p.push_back({P1,P2,P4});
                    p.push_back({P2,P3,P4});
                    // PA;PB;PD;ENDL;//0,1,1,1
                    // PB;PC;PD;ENDL;
                    sum += 2;
                    break;
                case CS(1,0,0,1):
                    p.push_back({P1,P2,P3});
                    p.push_back({P2,P3,P4});
                    // PA;PB;PC;ENDL;
                    // PB;PC;PD;ENDL;
                    sum += 2;
                    break;
                case CS(0,1,1,0):
                    p.push_back({P1,P2,P4});
                    p.push_back({P1,P3,P4});
                    // PA;PB;PD;ENDL;
                    // PA;PC;PD;ENDL;
                    sum += 2;
                    break;
                case CS(0,1,0,1):
                    p.push_back({P1,P2,P3});
                    p.push_back({P1,P3,P4});
                    // PA;PB;PC;ENDL;
                    // PA;PC;PD;ENDL;
                    sum += 2;
                    break;
                case CS(0,0,1,1):
                    p.push_back({P1,P2,P3});
                    p.push_back({P1,P2,P4});
                    // PA;PB;PC;ENDL;
                    // PA;PB;PD;ENDL;
                    sum += 2;
                    break;
                case CS(1,0,0,0):
                    p.push_back({P1,P2,P3});
                    p.push_back({P1,P2,P4});
                    p.push_back({P1,P3,P4});
                    // PA;PB;PC;ENDL;
                    // PA;PB;PD;ENDL;
                    // PA;PC;PD;ENDL;
                    sum += 3;
                    break;
                case CS(0,1,0,0):
                    p.push_back({P1,P2,P3});
                    p.push_back({P1,P2,P4});
                    p.push_back({P2,P3,P4});
                    // PA;PB;PC;ENDL;
                    // PA;PB;PD;ENDL;//0,1,1,1
                    // PB;PC;PD;ENDL;
                    sum += 3;
                    break;
                case CS(0,0,1,0):
                    p.push_back({P1,P2,P3});
                    p.push_back({P1,P3,P4});
                    p.push_back({P2,P3,P4});
                    // PA;PB;PC;ENDL;
                    // PA;PC;PD;ENDL;//0,1,1,1
                    // PB;PC;PD;ENDL;
                    sum += 3;
                    break;
                case CS(0,0,0,1):
                    p.push_back({P2,P3,P4});
                    p.push_back({P1,P2,P4});
                    p.push_back({P1,P3,P4});
                    // PB;PC;PD;ENDL;
                    // PA;PB;PD;ENDL;
                    // PA;PC;PD;ENDL;
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
    vector<string > vex(5000);
    vector<P > v;
    int testCaseSize;
    cin >> testCaseSize;

    while(testCaseSize--)
    {
        int n, m;
        cin >> n >> m;
        
        for(int row = 0; row < n; ++row)
        {
            cin >> vex[row];
        }

        // for(int i = 0; i < n; ++i)
        // {
        //     cout << vex[i] << endl;
        // }

        DirectSolution(n, m, vex);

        cout << p.size() << endl;

        for(int i = 0; i < p.size(); ++i)
        {
            cout << p[i].num1X << " " << p[i].num1Y << " " << p[i].num2X << " " << p[i].num2Y << " " << p[i].num3X << " " << p[i].num3Y << endl;
        }

        p.clear();
        // for(int i = 0; i < n; ++i)
        //     cout << vex[i] << endl;
    }

    return 0;
}