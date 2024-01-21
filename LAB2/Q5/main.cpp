#include <bits/stdc++.h>
using namespace std;

int main(){

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    
    int n; cin >> n;
    vector<int> a(n);
    
    for(int i=0; i<n; i++)
        cin >> a[i];
        
    int mn1 = INT_MAX, mn2 = INT_MAX;
    
    // O(n)
    for(int i=0; i<n; i++){
        if(a[i] <= mn1){
            mn2 = mn1;
            mn1 = a[i];
        }
        else if(a[i] < mn2)
                mn2 = a[i];
        
        cout << "First minima: " << mn1 << " and second minima: " << mn2 << endl;
    
    }
    
    return 0;

}
