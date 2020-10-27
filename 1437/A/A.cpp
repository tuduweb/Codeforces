
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        int l,r;

        cin >> l >> r;
        
        float al = r*1.0/2,ar = l*1.0/3*2;



		if( (ar > al && floor(al) != floor(ar)) || ( 2 * l - r > 1) )
			cout << "YES" <<endl;
		else
			cout << "NO" << endl;




    }

    return 0;
}
