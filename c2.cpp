#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int main(){

	int t;
	cin>>t;

	while(t--){

		int n;
		cin>>n;
		vector<int> v(n);

		for(int i = 0; i < n; i++){
			cin>>v[i];
		}

		int count = 0, minIndex = 0, minElement = 0;
		vector<int> t;
		
		for(int i = 0; i < n; i++){
			t.push_back(v[i]);
			t[i] -= 1;
		}
		int sz = t.size();
		while(sz >= 1){

// 			minIndex = min_element(t.begin(),t.end()) - t.begin();
			minElement = *min_element(t.begin(), t.end());
			
			
			for(int i = t.size()-1; i >= 0; i--){
			    if(t[i] == minElement){
			        minIndex = i;
			        break;
			    }
			}

			if(minElement == 0){
			    t.clear();
			    t.resize(minIndex);
			    for(int i = 0; i < minIndex; i++){
			        t[i] = v[i];
			    }
			 //   copy(v.begin(), v.begin() + minIndex, t.begin());
			    sz = t.size();

			}else if(sz == 1){
			    count += 1;
			    break;
			}
			else{
			    t.clear();
			    t.resize(minIndex+1);
			    for(int i = 0; i <= minIndex; i++){
			        t[i] = v[i];
			    }
			 //   copy(v.begin(), v.begin() + (minIndex+1), t.begin());
			    count += (minIndex+1);
			    
			    for(int i = 0; i < t.size(); i++){
			        t[i] -= 1;
			    }
			    sz = t.size();
			   
			}
			
			
			
			 

		}
		count += n;
		cout<<count<<endl;
	}
}