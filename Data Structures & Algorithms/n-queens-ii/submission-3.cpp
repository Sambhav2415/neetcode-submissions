class Solution {
public:
    int ans=0;
    bool toCheck(vector<string> &board,int r , int c, int col){
        for(int i=0;i<r;i++){
            if(board[i][c] == 'Q'){
                return false;
            }
        }

        for(int i=r-1,j=c-1;i>=0&&j>=0;i--,j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        for(int i=r-1,j=c+1;i>=0&&j<col;i--,j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }

    void rec(vector<string>&board,int row,int col){
        if(row == col){
            ans++;
            return;
        }
        for(int i=0;i<col;i++){
            if(toCheck(board,row,i,col)){
                board[row][i] = 'Q';
                rec(board,row+1,col);
                board[row][i] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        vector<string> board(n,string(n,'.'));

        rec(board,0,n);

        return ans;
    }
};