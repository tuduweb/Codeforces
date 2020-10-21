#include <iostream>

using namespace std;

int map[] = {1,3,6,10};

int main()
{
    int n = 0;

    cin >> n;

    int* v = new int[n];
    

    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for(int i = 0;i < n;i++)
    {
        int num = v[i],wei = 0,shu = 0;

        while(num >= 10)
        {
			num /=10;
            wei++;
		}
		
        //cout << wei << endl << num << endl;
        
        num = 10 * (num - 1);
        num+= map[wei];
        
        cout << num << endl;
        
    }
    
    delete v; 

    return 0;
}
