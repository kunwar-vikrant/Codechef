#include<stdio.h>
#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

int main(){


	int t;
	cin>>t;

	while(t--){

		string s;
		cin>>s;

		char current = s[0], next = s[0];
		int count = 0, j = 0, i = 0;

		string tmp = "";

		while(i < s.length()){

			count = 1;
			current = next;
			next = s[i+1];
            j = i+1;
            
			while(current == next && j < s.length()){

				count++;
				cout<<" J is :"<<j<<" and s[j+1] :" <<s[j+1]<<endl;
                j++;
				next = s[j];
				cout<<"Current : "<<current<<endl;
				cout<<"Now next : "<< next<<endl;

			}
            
			tmp += current;
			tmp += to_string(count);
			i = j;
		}
	

		int str_len = s.length();
		int final_l = tmp.length();
		
		cout<<"Initial length of string "<<s<<" : "<< str_len<<endl;
		cout<<"Final length of string "<<tmp<<" : "<< final_l<<endl;
	}
#include<stdio.h>
#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

int main(){


	int t;
	cin>>t;

	while(t--){

		string s;
		cin>>s;

		char current = s[0], next = s[0];
		int count = 0, j = 0, i = 0;

		string tmp = "";

		while(i < s.length()){

			count = 1;
			current = next;
			next = s[i+1];
            j = i+1;
            
			while(current == next && j < s.length()){

				count++;
				// cout<<" J is :"<<j<<" and s[j+1] :" <<s[j+1]<<endl;
                j++;
				next = s[j];
				// cout<<"Current : "<<current<<endl;
				// cout<<"Now next : "<< next<<endl;

			}
            
			tmp += current;
			tmp += to_string(count);
			i = j;
		}
	

		int str_len = s.length();
		int final_l = tmp.length();
		
		cout<<"Initial length of string "<<s<<" : "<< str_len<<endl;
		cout<<"Final length of string "<<tmp<<" : "<< final_l<<endl;
	}

}