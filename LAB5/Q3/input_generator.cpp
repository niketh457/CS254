#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("input.txt", "w", stdout);

    int t = rand();

    if(t == 0)t = rand();

    cout << t << endl;

    while(t--){
        int n = rand()%50;

        if(n == 0)n = rand()%100;

        cout << n << endl;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j){
                    cout << 0 << ' ';
                    continue;
                }

                int x = rand();

                cout << x%2 << ' ';
            }
            cout << endl;
        }

    }

return 0;
}