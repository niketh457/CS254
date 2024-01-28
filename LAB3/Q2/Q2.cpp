#include <bits/stdc++.h>

using namespace std;

int max_subarray(vector<int> &arr, int start, int end){

    if(start == end)
        return arr[start];

    int mid = start + (end - start)/2;

    int left_max = max_subarray(arr, start, mid);
    int right_max = max_subarray(arr, mid+1, end);

    int total_max1 = 0, total_max2 = 0;
    int ans = 0;

    for(int i = mid; i >= 0; i--){
        ans += arr[i];
        total_max1 = max(total_max1, ans);
    }

    ans = 0;

    for(int i = mid+1; i <= end; i++){
        ans += arr[i];
        total_max2 = max(total_max2, ans);
    }

    int total_max = total_max1 + total_max2;

    return max(total_max, max(right_max, left_max));
}

int main() {

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cin.tie(NULL);
	int tt;
	cin >> tt; 
	while(tt--)
	{
       int n;
       cin>>n;
       
       vector<int> arr(n);

       for(int i = 0; i < n; i++)
        cin >> arr[i];

       int result = max_subarray(arr, 0, n-1);
       cout << "Max Subarry sum is " << result << "\n";
    }
    return 0;
}
