class Solution {
public:

vector<vector<int>>direction ={{1,0},{0,1},{0,-1},{-1,0}};
   bool find(int i , int j , int idx , string&word,vector<vector<char>>&board,int m,int n){

    if(idx==word.length())return true ;
    if(i<0 || j<0 || i>=m || j>=n || board[i][j]=='$') return false ;

    if(board[i][j]!=word[idx]) return false ;

    char temp = board[i][j];
    board[i][j]='$';

    for(auto &dir : direction){
        int new_i = i+dir[0];
        int new_j = j+dir[1];

        if(find(new_i,new_j,idx+1,word,board,m,n)){
            return true;
        }
    }
        board[i][j]=temp;
        return false;
   }

    bool exist(vector<vector<char>>& board, string word) {
        int  m = board.size();
        int n = board[0].size();
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n;j++){
                if(board[i][j]==word[0] && find(i,j,0,word,board,m,n)){
                    return true;
                }
            }
        }
        return false;
    }
};