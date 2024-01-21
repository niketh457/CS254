#include <bits/stdc++.h>
#include "merge_sort.h"
using namespace std;

int main(){
        freopen("input_a.txt", "r", stdin); 
        freopen("output_a.txt", "w", stdout);
	
	int size;
	
	cin >> size;
	
	vector<int> arr(size);
	
	for(int i = 0; i < size; i++){
            cin >> arr[i];
	}

	cout << "Given array is \n";
	for(int &i: arr)
	    cout << i << " ";
	
	cout << endl;

	merge_sort(arr, 0, size - 1);

	cout << "\nSorted array is \n";
	for(int &i: arr)
	    cout << i << " ";
	
	cout << endl;
	
	return 0;
}

