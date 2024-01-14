#include <bits/stdc++.h>

using namespace std;

int maxSum(vector<int> &arr){
    
    int n = arr.size();
    
    int max_element = -1e9;
    int second_max = -1e9;
    
    for(int &i: arr){
        max_element = max(max_element, i);
    }
    
    for(int &i: arr){
        if(i != max_element){
           second_max = max(second_max, i);
        }
    }
    
    return max_element + second_max;

}

int main(){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    

    int size;
    cin >> size;
	 	    
    vector<int> arr(size);
    
    for(int i = 0; i < size; i++){
          cin >> arr[i]; 
    }
	    
    cout << maxSum(arr) << endl;
    
    return 0;
}
