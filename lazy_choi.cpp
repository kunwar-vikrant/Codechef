#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

#define MOD (1000000000+7);

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;

	while(t--){

		int n,k;
		cin>>n>>k;

		int arr[k];
		for(int i = 0; i < k; i++){
			cin>>arr[i];
		}

		sort(arr, arr+k);

		int dp[n+1] = {0};

		if(!(binary_search(arr, arr+k, 0)))
			dp[0] = 1;

		if(!(binary_search(arr, arr+k, 1)))
			dp[1] = 1;

		if(!(binary_search(arr, arr+k, 2)))
			dp[2] = 2;

		for(int i = 3; i < n+1; i++){
			if(binary_search(arr, arr+k, i)){
				dp[i] = 0;
				continue;
			}
			else 
				dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
		}

		long long int res = dp[n]%MOD;
		cout<<res<<endl;
	}

	return 0;

}