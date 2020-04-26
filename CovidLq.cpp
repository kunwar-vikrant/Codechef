#include<iostream>
#include<algorithm>

using namespace std;

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

		int one_indx = 0;

		for(int i = 0; i < n; i++){
			if(arr[i] == 1){
				one_indx = i;
				break;
			}
		}
		int first_one = one_indx;
		bool b = true;
		for(int i = one_indx+1; i < n; i++){
			
			if(arr[i] == 1 && i < first_one+6){
				b = false;
			}else if(arr[i] == 1 && i >= first_one+6){
				first_one = i;
			}
		}

		if(b == true){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}

	}
}