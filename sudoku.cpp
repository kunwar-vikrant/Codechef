#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>



using namespace std;

bool check(unordered_map<char, int> m){

    for(auto n : m){
        // cout<<"Printing inside isValidRow:"<<endl;
        // cout<<n.first<<"-"<<n.second<<endl;
        // cout<<"inside validRow"<<endl;
            if(n.first != '.' && n.second > 1){
                return false;
            }

            // cout<<n.first<<"-"<<n.second<<endl;
        }
        // cout<<"Done !!!"<<endl<<endl;
        return true;
}
bool isValidRow(vector<vector<char>> board, int n){

    unordered_map<char, int> m;
    for(int i = 0 ; i < n; i++){

        for(int j = 0; j < n; j++)
        {
            if(m[board[i][j]]){
                m[board[i][j]]++;
            }else{
                m[board[i][j]] = 1;
            }
        }
        if(!check(m))
            return false;
        else
            m.clear();
    }

    return true;
}



bool isValidCol(vector<vector<char>> board, int n){

    unordered_map<char, int> m;
    for(int i = 0 ; i < n; i++){

        for(int j = 0; j < n; j++)
        {
            if(m[board[j][i]]){
                m[board[j][i]]++;
            }else{
                m[board[j][i]] = 1;
            }
        }
        if(!check(m))
            return false;
        else
            m.clear();
    }

    return true;

}

bool isValid(int x, int y, vector<vector<char>> board){
    
    unordered_map<char, int> m;
    for(int i = x; i < x+3; i++){
        
        for(int j = y; j < y+3; j++){
            
            if(m[board[i][j]]){
                m[board[i][j]]++;
            }else{
                m[board[i][j]] = 1;
            }
        }
    }
    
    for(auto n : m){
        if(n.first != '.' && n.second > 1){
            return false;
        }

        // cout<<n.first<<"-"<<n.second<<endl;
    }
    cout<<"Done !!!"<<endl<<endl;
    return true;
}
    
bool isValidSudoku(vector<vector<char>>& board) {
    
    int n = board.size();
    for(int i = 0; i < n; i += 3){
        
        for(int j = 0; j < n; j += 3){
            
            if(!isValid(i, j, board) || !isValidRow(board, n) || !isValidCol(board, n)){
                return false;
            }
        }
    }
    
    return true;
}


int main(){

    int n;
    cout<<"Enter board Size:"<<endl;
    cin>>n;

    vector<vector<char> > board;
    vector<char> tmp(n);
    // char tmp;

    for(int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){
            cin>>tmp[j];
            // board[i][j] = tmp;
        }

        board.push_back(tmp);
        // tmp.clear();
    }
    cout<<"Printing Board"<<endl;
    for(int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){

            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }

    // cout<<"Done!"<<endl;
    cout<<"Result : "<<isValidSudoku(board);


}