#include <bits/stdc++.h>
using namespace std;

void sort(vector<long long> &a, int m){
    int n = a.size();
    int i = 0, j = m, k = 0;
    long long md = 10000000000;
    while(k < n){
        if(j == n || (a[i]%md) < (a[j]%md)){
            a[k] += md*(a[i]%md); 
            i++; k++;
        }
        else if(i == m || (a[i]%md) >= (a[j]%md)){
            a[k] += md*(a[j]%md);
            j++; k++;
        }
    }
    for(int i=0; i<n; i++)
        a[i] = (a[i]/md);
}

int main(){

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    int n;
    cin >> n;
    
    vector<int> a(n);
    
    for(int i=0; i<n; i++)
        cin >> a[i];
        
    sort(a, n);
        
    for(int& x:a)
        cout << x << " ";
       
        
    return 0;
}
