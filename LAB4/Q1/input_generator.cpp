#include <bits/stdc++.h>

using namespace std;
int main() {

    freopen("input.txt","w",stdout);

	int tt = rand()%100; 

	cout<< tt <<"\n"; 
	while(tt--)
	{
       int n = rand()%1000; 
       cout << n <<"\n"; 
       
       for(int i = 0; i < n; i++){
            cout<<(rand()%1000) - 123<<" ";
       } cout<<"\n";
    }
    return 0;
}