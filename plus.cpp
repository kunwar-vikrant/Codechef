#include<iostream>
#include<vector>

using namespace std;

int main(){


    int n;
    cout<<"Enter size:"<<endl;
    cin>>n;

    vector<int> digits(n);
    cout<<"Enter vector:"<<endl;
    for(int i = 0; i < n; i++){
        cin>>digits[i];
    }

    int carry = 0, i = n-1;
    
     if(digits[i] + 1 >= 10) {
        cout<<"True:!!!";
        digits[i] = (digits[i] + 1)%10;
        carry = 1;
        i = n-2;
     }else{
        digits[i] = digits[i] + 1;
        i = n-2;
     }
    
    while(i >= 0){
        
        if(digits[i] + carry >= 10) {
            digits[i] = (digits[i] + carry)%10;
            carry = 1;
        }else{
            digits[i] = (digits[i] + carry);
            carry = 0;
        }
        i--;
    }
    
    if(carry == 1){
        digits.insert(digits.begin(), 1);
    }

    cout<<"Final vector:"<<endl;
    for(int i = 0; i < n; i++){
        cout<<digits[i];
    }
}

    