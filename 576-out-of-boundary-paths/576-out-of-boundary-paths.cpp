#define MOD 1000000007

class Solution {
private:
    vector<vector<vector<int>>> memo;
    int numberOfPaths(int i, int j, int m, int n, int maxMoves){
        // check to see if we go over our boundary
        if(i >= m || i < 0 || j >= n || j < 0) return 1;
        
        // check to see if we've used up all our moves
        if(maxMoves <= 0) return 0;
        
        if(memo.at(i).at(j).at(maxMoves) != -1) 
            return memo.at(i).at(j).at(maxMoves);
        
        int numPaths = 0;
        numPaths += numberOfPaths(i - 1, j, m, n, maxMoves - 1); numPaths %= MOD;
        numPaths += numberOfPaths(i + 1, j, m, n, maxMoves - 1); numPaths %= MOD;
        numPaths += numberOfPaths(i, j - 1, m, n, maxMoves - 1); numPaths %= MOD;
        numPaths += numberOfPaths(i, j + 1, m, n, maxMoves - 1); numPaths %= MOD;
        
        return memo.at(i).at(j).at(maxMoves) = numPaths;
    }
    
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memo = vector(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return numberOfPaths(startRow, startColumn, m, n, maxMove);
    }
};