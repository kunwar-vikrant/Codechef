#include<iostream>
#include<algorithm>

using namespace std;

bool great(int x, int y){
	return x > y;
}

int main(){

	int t;
	cin>>t;

	while(t--){

		int n;
		cin>>n;

		long int arr[n];
		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}
		sort(arr, arr+n, great);
		long int total = 0, years_passed = 0, profit = 0, i = 0;
		while(i < n){

			profit = arr[i]-years_passed;
			if(profit > 0){
				total += profit;
			}

			years_passed++;
			i++;
		}

		cout<<"Total ->"<<total%1000000007<<endl;
	}
}