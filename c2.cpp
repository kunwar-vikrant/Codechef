#include <iostream>
#include <bits/stdc++.h> 
using namespace std; 


int main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;

	while(t--){

		int n;
		cin>>n;

		int arr[n];
		arr[0] = 0;
		bool found = false;

		for(int i = 1; i < n; i++){

			int t = arr[i-1];
			for(int j = i-2; j >= 0; j--){
				if(arr[j] == t){
					arr[i] = i-j-1;
					found = true;
					break;
				}
			}
			if(!found){
				arr[i] = 0;
			}
			found = false;
		}

		// for(int i = 0; i < n; i++){
		// 	cout<<arr[i]<<" ";
		// }
		// cout<<endl;

		int x = arr[n-1];
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			if(arr[i] == x){
				count++;
			}
		}
		cout<<count<<endl;
	}
}