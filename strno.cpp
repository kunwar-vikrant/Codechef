#include<iostream>
#include<vector>
#include<queue>
#include <climits> 
#include<cmath>

using namespace std;

int primes(int n){

	int c = 0;
	while(n%2 == 0){

		n = n/2;
		c += 1;
	}

	int sq = sqrt(n);
	for(int i = 3 ; i <= sq; i++){

		while(n % i == 0){
			n = n /i;
			c++;
		}

		if(n > 2){
			c++;
		}
	}

	return c;
}

int main(){

	int t;
	cin>>t;

	while(t--){

		int x,k;
		cin>>x>>k;
		int s = primes(x);
		
		if(x == 1){
			if(k == 0){
				cout<<1<<endl;
			}else{
				cout<<0<<endl;
			}
		}
		else if(k <= s){
			cout<<1<<endl;
		}else{
			cout<<0<<endl;
		}
	}
} 