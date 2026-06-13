class Solution {
public:
    int m,n;
    vector<int> rt = {0,0,1,-1};
    vector<int> ct = {1,-1,0,0};
    bool wordCheck(vector<vector<char>>&board,string&word,int i,vector<vector<bool>>&vis,int r,int c){
        if(i == word.size()){
            return true;
        }
        for(int j=0;j<4;j++){
            int nr = r+rt[j];
            int nc = c+ct[j];
            if(nr>=0 && nr<m && nc>=0 && nc<n && board[nr][nc]==word[i] && !vis[nr][nc]){
                vis[nr][nc] = true;
                if(wordCheck(board,word,i+1,vis,nr,nc)){
                    return true;
                }
                vis[nr][nc] = false;
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    vis[i][j] = true;
                    if(wordCheck(board,word,1,vis,i,j)){
                        return true;
                    }
                    vis[i][j] = false;
                }
            }
        }
        return false;
    }
};
