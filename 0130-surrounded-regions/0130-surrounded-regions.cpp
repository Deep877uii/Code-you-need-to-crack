class Solution {
public:
    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        vector<vector<char>> vis(n, vector<char>(m, 'X'));

        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(board[i][j] == 'O' &&
                   (i == 0 || j == 0 || i == n-1 || j == m-1)){

                    vis[i][j] = 'O';
                    q.push({i,j});
                }
            }
        }

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        while(!q.empty()){

            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            for(int i = 0; i < 4; i++){

                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                   vis[nrow][ncol] != 'O' && board[nrow][ncol] == 'O'){

                    vis[nrow][ncol] = 'O';
                    q.push({nrow,ncol});
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(board[i][j] == 'O' && vis[i][j] != 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};