using namespace std;

void merge(vector<int> &arr, int const start, int const mid, int const end){
	
	int left_size = mid - start + 1;
	
	int right_size = end - mid;
	
	vector<int> left(left_size);
	vector<int> right(right_size);
	
	for(int i = 0; i < left_size; i++){
		left[i] = arr[i + start];
	}
	
	for(int i = 0; i < right_size; i++){
		right[i] = arr[i + mid + 1];
	}
	
	int i = 0, j = 0;
	
	while(i < left_size && j < right_size){
		if(left[i] < right[j]){
			arr[i + j + start] = left[i];
			i++;
		}
		
		else{
			arr[i + j + start] = right[j];
			j++;
		}
		
	}
	
	while(i < left_size){
		arr[i + j + start] = left[i];
		i++;
	}
	
	while(j < right_size){
		arr[i + j + start] = right[j];
		j++;
	}
}

void merge_sort(vector<int> &arr, int start, int end){
	
	if(start >= end)
		return;
		
	int mid = start + (end - start)/2;
	
	merge_sort(arr, start, mid);
	merge_sort(arr, mid+1, end);
	
	merge(arr, start, mid, end);
}


