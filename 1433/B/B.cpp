#include <iostream>

using namespace std;

int main()
{
	int n = 0;
	
	cin >> n;
	
	
	for(int i = 0; i < n; i++)
	{
		int j = 0;
		cin >> j;
		
		int* v = new int[j];

		int pos1 = -1,pos2 = -1,sum = 0;		
		for(; j > 0; j--)
		{

			cin >> v[j - 1];
			if(v[j - 1] == 1)
			{
				if(pos1 == -1)
				{
					pos1 = j - 1;
					
				}
				else
				{
					//Êä³ö½×¶Î
					//cout << "j - 1:" << j - 1 << endl; 
					if((pos1 - (j - 1)) > 1)
					{
						sum += pos1 - (j - 1) - 1;
					}
					
					pos1 = j - 1;
					
				}
				//cout << "pos1:" << pos1 << endl;
			}
			
			//cout << v[j - 1] << " " << endl;

		}
		
		cout << sum << endl;
	}
	
	return 0;
}
