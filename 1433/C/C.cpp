/**
* https://codeforces.com/contest/1433/problem/C
*/
 
#include <iostream>
#include <vector>
 
using namespace std;
 
int FindDominant(int size, int* queue)
{
	//for(int )
	return -1;
}
 
 
int main()
{
	int n = 0;
	
	cin >> n;
	
	for(int cases = 0; cases < n; ++cases)
	{
		int caseSize = 0;
		
		cin >> caseSize;
		
		int* queue = new int[caseSize];
		
		int max = 0;
 
		vector<vector<int> > v;
		
		for(int i = 0; i < caseSize; ++i)
		{
			
			cin >> queue[i];
			if(queue[i] > max)
			{
				vector<int> vv;
				
				vv.push_back(i);
				v.push_back(vv);
				
				max = queue[i];
			}else if(max > 0 && queue[i] == max)
			{
				(v.back()).push_back(i);
			}
			//cout << queue[i] << " ";
		}
		
		int result = -1;
		
		for(vector<int>::iterator it = v.back().begin(); it != v.back().end(); ++it)
		{
			if(*it > 0 && queue[*it] > queue[*it - 1])
			{
				result = *it;
				break;
			}
			else if(*it < caseSize - 1 && queue[*it] > queue[*it + 1])
			{
				result = *it;
				break;
			}
		}
		
		
		//cout << FindDominant(caseSize, queue);
		
		cout << (result >= 0 ? result + 1 : -1) << endl;
		
		delete []queue;
	}
	
	
	return 0;
} 