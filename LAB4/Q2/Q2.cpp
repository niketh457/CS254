#include<bits/stdc++.h>

using namespace std;

long long median(vector<long long> &a, vector<long long> &b){
    int m = a.size(), n = b.size();
    vector<long long> c(m+n);

    int i = 0, j = 0, k = 0;

    while(k <= (m+n)/2 && i<m && j<n){

        if(a[i] <= b[j]){
            c[k] = a[i];
            i++;
        }
        else {
            c[k] = b[j];
            j++;
        }

        k++;
    }
    if(k <= (m+n)/2){
        for(; j < n; j++){
            c[k] = b[j];
            k++;
        }
        for(; i < m; i++){
            c[k] = a[i];
            k++;
        }

    }

    if((m+n)%2){
        return c[(m+n)/2];
    }
    
    return (c[(m+n)/2-1]+c[(m+n)/2])/2;      
    
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    int m,n;
    cin >> m >> n;

    vector<long long> a(m),b(n);

    for(int i = 0; i < m; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }

    cout << "The median of the complete array is " << median(a, b);


}