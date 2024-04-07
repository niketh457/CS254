#include <iostream>
#include <vector>

using namespace std;

class disjointSet{

    int size;
    vector<int> parent;
    vector<int> setSize;

    public:
        disjointSet(int n){
            this -> size = n;
            parent.resize(n);
            setSize.resize(n, 1);
        }

        int findParent(int x){

            while(parent[x] != x){
                x = parent[x];
            }

            return x;
        }

        void unionElements(int a, int b){

            if(parent[a] == parent[b]){
                return;
            }

            if(setSize[parent[a]] <= setSize[parent[b]]){
                setSize[parent[b]] += setSize[parent[a]];


            }
        }
};