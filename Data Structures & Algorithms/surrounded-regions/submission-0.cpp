class Solution {
public:
    int n,m;
    void isSafe(vector<vector<char>>&board,vector<vector<bool>>&safe,int i,int j){
        safe[i][j] = true;
        int row[4] = {0,0,1,-1};
        int col[4] = {1,-1,0,0};
        for(int k=0;k<4;k++){
            int nr = i+row[k];
            int nc = j+col[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m && board[nr][nc]=='O' && !safe[nr][nc]){
                isSafe(board,safe,nr,nc);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        vector<vector<bool>> safe(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || i==n-1 || j==0 || j==m-1) && board[i][j]== 'O' && !safe[i][j]){
                    isSafe(board,safe,i,j);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'O' && !safe[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
