class Solution {
public:
    int dp[1001];
    int getAns(vector<vector<int>>&books,int wd,int idx){
        if(idx==books.size()){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int currWd=0;
        int height=0;
        int ans=INT_MAX;
       for(int i=idx;i<books.size();i++){
          
 
          currWd+=books[i][0];
          // cout<<height<<" ";
           if(currWd>wd){
               break;
            
           }
           else{
             height=max(books[i][1],height);

           }
            ans=min(ans,height+getAns(books,wd,i+1));
           
           }
        return dp[idx]=ans;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memset(dp,-1,sizeof dp);
       return getAns(books,shelfWidth,0);
    }
};