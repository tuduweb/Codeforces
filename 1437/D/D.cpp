#include <iostream>
#include <vector>

using namespace std;

//int v[200000];//时间上无差别

int main()
{
    int n;
    cin >> n;

    while(n--)
    {
        
        int setSize;
        cin >> setSize;

        vector<int> v(setSize);

        for(int i = 0; i < setSize; ++i)
            cin >> v[i];

        //第一层,有两个格子
        int level = 1;
        int currentSize = 1;
		int nextSize = 0;
        for(int i = 1; i < setSize; ++i)
        {
			if(v[i] > v[i - 1])
			{
				//顺序增加一个节点
				nextSize++;
			}else{
                currentSize--;
                if(currentSize > 0)
                    nextSize++;
                else{
                    level++;
                    currentSize = nextSize;
                    nextSize = 1;
                }
			}
        }

        cout << level << endl;

        //build Tree?


    }

    return 0;
}

/**
 * 第一次优化：  删除在setSize设立的边界
 *              327ms -> 312ms
 */