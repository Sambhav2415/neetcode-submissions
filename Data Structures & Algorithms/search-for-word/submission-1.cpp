class Solution {
public:
    int m,n;
    vector<int> rt = {0,0,1,-1};
    vector<int> ct = {1,-1,0,0};
    string wor;
    bool rec(int r,int c,vector<vector<char>>& board,vector<vector<bool>>&vis,int i){
        if(i==wor.size()){
            return true;
        }
        vis[r][c] = true;
        for(int j=0;j<4;j++){
            int nr = r+rt[j];
            int nc = c+ct[j];
            if(nr>=0 && nr<m && nc>=0 && nc<n && board[nr][nc]==wor[i] && !vis[nr][nc]){
                // vis[nr][nc] = true;
                if(rec(nr,nc,board,vis,i+1)){
                    return true;
                }
                // vis[nr][nc] = false;
            }
        }
        vis[r][c] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        wor = word;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == word[0]){
                    if(rec(i,j,board,vis,1)){
                        return true;
                    }
                }
            }
        }
        return false;
    }   
};
