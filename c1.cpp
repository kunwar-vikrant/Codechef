#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include <bits/stdc++.h> 


using namespace std;

int main(){

	int t;
	cin>>t;

	while(t--){

		int n;
		cin>>n;
		// string arr[n];
		string s, tmp;
		cin>>s;
		tmp = s;

		// for(int i = 0; i < n; i++){
		// 	cin>>arr[i];
		// }
		
		for(int i = 1; i < n; i++){

			string st;
			cin>>st;
			bitset<10> r = bitset<10>(tmp) ^ bitset<10>(st);
			tmp = r.to_string();
		}

		// int res = 0, tmp;
		// for(int i = 0; i < n; i++){
		// 	tmp = stoi(arr[i]);
		// 	res += tmp;
		// }

		// cout<<res<<" : RES"<<endl;
		int count = 0;
		// string r = to_string(res);

		for(auto c : tmp){
			int tm = (int)c;
			if(tm % 2 != 0){
				count++;
			}
		}

		

		cout<<count<<endl;
	}
}