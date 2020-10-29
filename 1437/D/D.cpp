#include <iostream>
#include <vector>

using namespace std;

#define INF 1e9

int main()
{
    int n;
    cin >> n;

    while(n--)
    {
        
        int setSize;
        cin >> setSize;

        vector<int> v(setSize + 1);
		v[setSize] = INF;

        for(int i = 0; i < setSize; ++i)
            cin >> v[i];

        //第一层,有两个格子
        int level = 1;
        int currentSize = 1;
		int nextSize = 0;
        for(int i = 1; i <= setSize; ++i)
        {

            //cout << "[" << level <<  "] c:" << currentSize << " n:" << nextSize << " - "  << v[i-1] << "," << v[i] << endl;


			if(v[i] > v[i - 1])
			{
				//顺序增加一个节点
				nextSize++;
			}else{
			{
                currentSize--;
                if(currentSize > 0)
                    nextSize++;
                else{
                    //本层消耗殆尽
                    if(currentSize == 0 && i < setSize)
                    {
                        level++;
                        currentSize = nextSize;
                        nextSize = 1;
                    }
                }
            }




			}


        }

        cout << level << endl;

        //build Tree?


    }

    return 0;
}