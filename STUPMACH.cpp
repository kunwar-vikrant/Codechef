#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

	int t;
	cin>>t;

	while(t--){

		int n;
		vector<int> v(n);

		for(int i = 0; i < n; i++){
			cin>>v[i];
		}

		int count = 0, minIndex = 0;
		vector<int> t = v;

		while(t.size() > 0){

			minIndex = min_element(v.begin(),v.end()) - v.begin();
			count += (minIndex+1);
			vector<T>::const_iterator first = v.begin();
			vector<T>::const_iterator last = v.begin() + minIndex-1;
			vector<T> t(first, last);
		}

		count += n;
		cout<<"Total : "<<count<<endl;
	}
}