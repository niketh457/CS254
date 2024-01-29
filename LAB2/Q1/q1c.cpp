#include <iostream>
#include <vector>
#include <unordered_set>
#include "merge_sort.h"

using namespace std;

vector<int> intersection_srt(vector<int> &a, vector<int> &b){
	
	unordered_set<int> req;
	vector<int> ans;
	
	for(int &i: a)
		req.emplace(i);
		
	for(int &i: b){
		if(req.find(i) != req.end())
			ans.emplace_back(i);
	
	}
	
	return ans;
		
}

int main(){

        freopen("input_c.txt", "r", stdin); 
        freopen("output_c.txt", "w", stdout);
        
	int size_a, size_b;
	
	cin >> size_a >> size_b;
	vector<int> a(size_a), b(size_b);
	
	for(int i = 0; i < size_a; i++)
		cin >> a[i];
		
	for(int i = 0; i < size_b; i++)
		cin >> b[i];
	
	vector<int> c = union_set(a, b);
	
	merge_sort(c, 0, c.size() - 1);
	
	return 0;

}
