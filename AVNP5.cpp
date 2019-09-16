#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int findVowel(string s){

	int c = 0;
	// transform(s.begin(), s.end(), s.begin(), ::tolower);
	for(int i = 0; i < s.length(); i++){
		if(s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'i' || s[i] == 'u'){
			c++;
		}
	}

	return c;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;

	while(t--){

		string s;
		cin>>s;

		int q;
		cin>>q;

		char c;

		string tmp = "";

		for(int i = 0; i < q; i++){
			cin>>c;
			if(c == 'F'){
				int l, r;
				cin>>l>>r;
				tmp = s.substr(l-1, r-l+1);
				int count = findVowel(tmp);
				cout<<count<<endl;
				continue;
			}else if(c == 'U'){
				int l;
				char r;
				cin>>l>>r;
				s[l-1] = r;
				continue;
			}
		}
	}

	return 0;

}