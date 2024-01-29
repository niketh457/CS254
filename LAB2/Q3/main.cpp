#include <bits/stdc++.h>
using namespace std;

int gap(int g){
    if(g == 1)
        return 0;

    return (g + 1)/2;
}

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

void gap_method(vector<long long> &a, int m){
    int n = a.size();

    n -= m;

    int gap_req = gap(n + m);

    while(gap_req > 0){
        for(int i = 0; i < n+m-gap_req; i++){
            if(a[i] > a[i+gap_req]){
                swap(a[i], a[i+gap_req]);
            }
        }

        gap_req = gap(gap_req);
    }
}

int main(){

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    int n, m;
    cin >> n >> m;
    
    vector<long long> a(n);
    
    for(int i=0; i<n; i++)
        cin >> a[i];
        
    gap_method(a, m);
        
    for(auto& x:a)
        cout << x << " ";
       
        
    return 0;
}
