#include <bits/stdc++.h>
using namespace std;

int brute_force(vector<int> &arr){

    int n = arr.size();
    int ans = 0;

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            
            if(arr[i] > arr[j]){
                ans++;
            }
        }
    }

    return ans;
}

int merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; 
    int left = low;     
    int right = mid + 1; 

    int cnt = 0;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1);
            right++;
        }
    }


    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high) {
    int cnt = 0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2 ;
    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid + 1, high);
    cnt += merge(arr, low, mid, high); 
    return cnt;
}

int numberOfInversions(vector<int>&a, int n) {
    return mergeSort(a, 0, n - 1);
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

        cout << "By bruteforce method "<< brute_force(arr) << '\n';
        cout << "By better approach " << numberOfInversions(arr, n) << '\n';
        // cout << "By Divide and conquer " << optimal(arr, 0, n-1) << '\n';
    }

return 0;
}