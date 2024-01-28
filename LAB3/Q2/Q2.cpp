#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef long double ld;
using namespace std;

struct Node {
    int ms;
    int mp;
    int mss;
    int tsum;
};

Node getNode(int x) {
    Node a;
    a.ms = x;
    a.mp = x;
    a.mss = x;
    a.tsum = x;
    return a;
}

Node mergeNodes(const Node &left, const Node &right) {
    Node result;
    result.ms = result.mp = result.mss = result.tsum = 0;
    
    result.mp = max({left.mp, left.tsum + right.mp, left.tsum + right.tsum});
    result.mss = max({right.mss, right.tsum + left.mss, left.tsum + right.tsum});
    result.tsum = left.tsum + right.tsum;
    
    result.ms = max({result.mp, result.mss, result.tsum, left.ms, right.ms, left.mss + right.mp});

    return result;
}

Node max_subarray(int left, int right, int ar[]) {
    if (left == right) return getNode(ar[left]);

    int mid = (left + right) >> 1;
    
    Node leftNode = max_subarray(left, mid, ar);
    Node rightNode = max_subarray(mid + 1, right, ar);
    
    return mergeNodes(leftNode, rightNode);
}

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
