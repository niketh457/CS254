#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int l, int h) {
  int high = arr[h];
  int x = l;
  for (int i=l;i<h;i++) {

    if (arr[i] < high) { 
      swap(arr[x], arr[i]);
      x++;
    }
  }
  swap(arr[x], arr[h]);
  return x;
}

int kthLargest_optimal(vector<int> &arr, int n, int k){

    if (n == 1) {
        return arr[0];
    }

    int l = 0;
    int h = n - 1;
    int target = n - k;
    
    while (l <= h) {
        int pivot = partition(arr, l, h);

        if (pivot < target) {     
            l = pivot + 1;
        }

        else if (pivot > target) {  
            h = pivot - 1;
        }

        else {       
            return arr[pivot];
        }
    }

    return -1;
}

int using_priority_queue(vector<int> &arr,int k){

    if(k > arr.size()){
        return -1;
    }

    priority_queue<int> pq(arr.begin(), arr.end());

    for(int i = 0; i < k-1; i++){
        pq.pop();
    }
    
    return pq.top();
}


int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;

    while(t--){
        int n; 
        cin >> n;

        vector<int> arr(n);

        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        cout << "Kth Largest element for the array (using priority heap) " << kthLargest_optimal(arr,n, 14) << endl;
        cout << "Kth Largest element for the array (optimal way) " << using_priority_queue(arr, 14) << endl;
    }
    
return 0;

}