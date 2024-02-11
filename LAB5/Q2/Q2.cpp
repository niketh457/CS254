#include <bits/stdc++.h>
using namespace std;

int min_throws(int i, unordered_map<int, int>& h,int dp[],int n)
{
	if (i >= n) return 0;

	else if (dp[i] != -1)
		return dp[i];

	int min_value = INT_MAX;

	for (int j = 1; j <= 6; j++) {

		int k = i + j;
		if (h.count(k) > 0) {
			if (h[k] < k) continue;
			k = h[k];
		}
		min_value = min(min_value, min_throws(k, h, dp, n) + 1);
	}
	dp[i] = min_value;
	return dp[i];
}


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--)
    {
	    int n, m;
        cin >> n >> m;

        int dp[n+1];
        
        for(int i = 0; i < n+1; i++){
	    	dp[i] = -1;
	    }
	    unordered_map<int, int> h;
	    for(int i = 0; i < m; i++){
            int x,y; cin >> x >> y;
	    	h[x] = y;
	    }
    
        cout << "Min Dice throws required is "<< min_throws(1, h, dp,n) << endl;
    }
	return 0;
}
