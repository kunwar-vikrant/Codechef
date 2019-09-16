#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;

	while(t--){

		int n, z;
		cin>>n>>z;

		// int arr[n];
		priority_queue<int> pq;

		for(int i = 0; i < n; i++){
			int x;
			cin>>x;

			pq.push(x);
		}

		int times = 0;

		while(pq.top() != 0 && z > 0){

			int t = pq.top();
			int new_t = t/2;

			z = z-t;
			pq.pop();
			pq.push(new_t);
			times++;
		}

		if(z > 0){
			cout<<"Evacuate"<<endl;
		}else{
			cout<<times<<endl;
		}
	}

	return 0;
}