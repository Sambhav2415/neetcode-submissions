class Solution {
public:
    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,1,-1};
    int n,m;
    bool ans(int r,int c,vector<vector<char>>& board, string&word,vector<vector<bool>>&vis,int idx){
        if(idx == word.size()){
            return true;
        }
        vis[r][c] = true;
        for(int i=0;i<4;i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr >=0&&nr<n&&nc>=0&&nc<m&& board[nr][nc]==word[idx] &&!vis[nr][nc]){
                if(ans(nr,nc,board,word,vis,idx+1)){
                    return true;
                }
            }
        }
        vis[r][c] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == word[0]){
                    if(ans(i,j,board,word,vis,1)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
