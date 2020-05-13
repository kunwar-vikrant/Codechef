#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int forward(int arr[], int index, int n){

	int initial = arr[index];
	int c = 0;

	for(int i = index+1; i < n; i++){

		if(initial + 2 >= arr[i]){
			c++;
			initial = arr[i];
		}else{
			break;
		}
	}
	// cout<<"Forward :" <<c<<endl;
	return c;
}

int backward(int arr[], int index, int n){

	int initial = arr[index];
	int c = 0;
	for(int i = index - 1; i >= 0; i--){
		if(arr[i] + 2 >= initial){
			c++;
			initial = arr[i];
		}else{
			break;
		}
	}
	// cout<<"Backward :" <<c<<endl;

	return c;
}

int main(){
	
	int t;
	cin>>t;

	while(t--){

		int n;
		cin>>n;

		int arr[n];
		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}

		vector<int> result;
		int start = 0, initial = 0, j = 0, c = 0;

		for(int i = 0; i < n; i++){

			c = forward(arr, i, n) + backward(arr, i, n);
			result.push_back(c);

		}

		// for(auto i : result){
		// 	cout<<i<<"-";
		// }
		// cout<<endl;

		int minimum = *min_element(result.begin(), result.end());
		int maximum = *max_element(result.begin(), result.end());

		cout<<minimum+1<<" "<<maximum+1<<endl;
	}
}