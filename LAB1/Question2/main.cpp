#include <bits/sidc++.h>

using namespace std;


int max_profit(vector<int> &weights, vector<int>& prices, int weight) {

	/*The function declares two variables, n and curr, and initializes them to the size of the vector prices and a vector of zeros with length weight + 1, respectively.The variable n will store the number of items available, and the vector curr will store the current maximum profit for each possible weight from 0 to weight.*/

	int n = prices.size();

	vector<int> curr(weight + 1), prev(weight + 1);

	/*The function also declares another vector, prev, and copies the values of curr into it.The vector prev will store the previous maximum profit for each possible weight from 0 to weight, before considering the current item.*/

	for (int i = 0; i <= weight; i++) {
		if (weights[0] <= i) {
			prev[i] = prices[0];
		}
	}

	/*The function uses a for loop to iterate over each element of the vector prev, denoted by i.For each element, it checks if the weight of the first item, weights[0], is less than or equal to i.If so, it assigns the price of the first item, prices[0], to prev[i].This way, after the loop ends, prev will contain the maximum profit for each possible weight from 0 to weight, considering only the first item*/

	for (int i = 1; i < n; i++) {

		int present_weight = weights[i];
		int present_price = prices[i];

		/*The function uses a nested for loop to iterate over each element of the vector curr, denoted by j.For each element, it calculates two values : not_take and take.The value not_take is equal to the previous maximum profit for the same weight, prev[j].The value take is equal to zero, unless the current weight, j, is greater than or equal to the present weight, present_weight.In that case, take is equal to the previous maximum profit for the remaining weight, prev[j - present_weight], plus the present price, present_price.The function then assigns the maximum of not_take and take to curr[j].This way, after the loop ends, curr will contain the maximum profit for each possible weight from 0 to weight, considering the current item and the previous items.*/

		for (int j = 0; j <= weight; j++) {
			
			int not_take = prev[j];

			int take = 0;

			if (j - present_weight >= 0) {
				take += prev[j - present_weight] + present_price;
			}

			curr[j] = max(take, not_take);
		}

		prev = curr;
	}

	return curr[weight];

}


int main(){
   
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   
   
   int size, max_weight;
   cin >> size >> max_weight;
   
   vector<int> weights(size), values(size);
   
   for(int i = 0; i < size; i++){
       cin >> weights[i];
   }
   
   for(int i = 0; i < size; i++){
       cin >> values[i];
   }
   
   cout << max_profit(weights, values, max_weight);

   return 0;
  
}

