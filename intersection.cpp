#include<iostream>
#include<bits\stdc++.h>

using namespace std;

int main(){

	int m, n, tmp;
	cin>>m>>n;

	vector<int> v1(m), v2(n);
	for(int i = 0; i < m; i++){
		cin>>v1[i];
	} 

	for(int i = 0; i < n; i++){
		cin>>v2[i];
	}


	vector<int> result;
	for(int i = 0; i < m; i++){

		tmp = v1[i];
		for(int j = 0; j < n; j++){

			if(tmp == v2[j]){
				result.push_back(v2[j]);
				v2[j] = -1;
				break;
			}
		}
	}

	for(int i = 0; i < result.size(); i++){
		cout<<result[i]<<"-";
	}
}