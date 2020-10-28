
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

/**
 * x mod a >= 1/2*a 要使左边尽可能大,右边尽可能小..
 * 参考列表:[1] https://blog.csdn.net/lmmmmmmmmmmmmmmm/article/details/109327378
 *			[2] https://www.youtube.com/watch?v=gkf63n4hMQ4
 */
int main()
{
    int n = 0;
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        int l,r,flag = 0;
        cin >> l >> r;

		if(2*l > r)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}
