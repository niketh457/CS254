#include <bits/stdc++.h>
using namespace std;
#define lmt 100

int main()
{
    freopen("input.txt","w",stdout);
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt = rand()%lmt;
	cout<<tt<<"\n";
	while (tt--)
	{
        int n=rand()%lmt,m=rand()%(n/2);  cout<<n<<" "<<m<<"\n";
		map<int,int> mp;
		for(int i = 0; i < m; i++){ mp[rand()%(n-1) + 1] = rand()%(n-1) + 1; }
        for(auto x : mp){
			cout<<x.first<<" "<<x.second<<"  ";
		}   cout<<"\n\n";
	}
}