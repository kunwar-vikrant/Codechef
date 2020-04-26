#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>


using namespace std;

// vector<vector<int>> find_duplicates(vector<vector<int>> v, int n){

// 	vector<vecto<int>> r;
// 	for(int i = 0; i < n; i++){

// 		for(int j = 0; j < v[i].size(); j++){
			
// 		}
// 	}
// }

int main(){

	int n;
	cout<<"Enter Size of the array :"<<endl;
	cin>>n;

	vector<int> v(n);
	cout<<"Enter vector Elements "<<endl;
	for(int i = 0; i < n; i++){
		cin>>v[i];
	}

	vector<vector<int> > result;
	for(int i = 0; i < n-2; i++){

		
		unordered_set<int> s;
		int curr_sum = 0-v[i];

		for(int j = i+1; j < n; j++){

			if(s.find(curr_sum-v[j]) != s.end()){
				result.push_back({v[i],curr_sum-v[j], v[j]});
				// result.push_back();
				// result.push_back();
			}

			s.insert(v[j]);
		}
	}

	// find_duplicates(result, result.size());
	for(int i = 0; i < result.size(); i++){

		for(int j = 0; j < result[i].size(); j++){

			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}


}