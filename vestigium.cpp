#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>



using namespace std;

int isValidRow(vector<vector<int>> board, int n){

    unordered_map<int, int> m;
    int row_count = 0;
    for(int i = 0 ; i < n; i++){

        for(int j = 0; j < n; j++)
        {
            if(m[board[i][j]]){
                row_count++;
                break;
            }else{
                m[board[i][j]] = 1;
            }
        }
        m.clear();
    }

    return row_count;
}



int isValidCol(vector<vector<int>> board, int n){

    unordered_map<int, int> m;
    int col_count = 0;
    for(int i = 0 ; i < n; i++){

        for(int j = 0; j < n; j++)
        {
            if(m[board[j][i]]){
                col_count++;
                break;
            }else{
                m[board[j][i]] = 1;
            }
        }
        m.clear();
    }

    return col_count;

}


int main(){

    int t;
    cin>>t;

    int case_num = t;
    while(t--){

        int n;
        cin>>n;

        vector<vector<int>> board(n , vector<int> (n, 0));
        int diagonal_sum = 0, tmp;

        for(int i = 0; i < n; i++){

            for(int j = 0; j < n; j++){
                cin>>tmp;
                board[i][j] = tmp;
                if(i == j){
                    diagonal_sum += board[i][j];
                }
            }
        }

        int row_count = 0, col_count = 0;
        row_count = isValidRow(board, n);
        col_count = isValidCol(board, n);

        cout<<"Case #"<<case_num-t<<": "<<diagonal_sum<<" "<<row_count<<" "<<col_count<<endl;


    }
}