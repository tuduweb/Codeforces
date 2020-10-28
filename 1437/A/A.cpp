
#include <iostream>
#include <math.h>

using namespace std;

#if 0
/**
	无法完成,真的太菜了… 
**/
int main()
{
    int n = 0;
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        int l,r,flag = 0;

        cin >> l >> r;



		for(int a = r/2; a <= l*2; a++)
		{
			if((l%a)*2>=a && (l/a==r/a) )
			{
				cout << "YES" << endl;
				flag = 1;
				break;
			}
		}
		if(flag == 0)
			cout << "NO" << endl;


    }

    return 0;
}
#endif
