class Solution {
public:
    unordered_map<char,pair<int,int>>mp;
    int dp[301][8][8][8][8];
    int getAns(int i,int x1,int y1,int x2,int y2,string &word){
        if(i>=word.size()){
            return 0;
        }
        int curx=mp[word[i]].first;
        int cury=mp[word[i]].second;
        int ans=INT_MAX;
        if(dp[i][x1+1][y1+1][x2+1][y2+1]!=-1){
            return dp[i][x1+1][y1+1][x2+1][y2+1];
        }
        if(x1==-1&&y1==-1){
            
           ans=min(ans,getAns(i+1,curx,cury,x2,y2,word));
        }
        else{
           ans=min(ans,abs(x1-curx)+abs(y1-cury)+getAns(i+1,curx,cury,x2,y2,word));
        }
        if(x2==-1&&y2==-1){
           ans=min(ans,getAns(i+1,x1,y1,curx,cury,word));
        }
        else{
            ans=min(ans,abs(x2-curx)+abs(y2-cury)+getAns(i+1,x1,y1,curx,cury,word));
        }
        return dp[i][x1+1][y1+1][x2+1][y2+1]=ans;
    }
    int minimumDistance(string word) {
        for(int i=0;i<word.length();i++) word[i]=tolower(word[i]);
        memset(dp,-1,sizeof dp);
        mp['a']={0,0};
      mp['b']={0,1};
      mp['c']={0,2};
      mp['d']={0,3};mp['e']={0,4};mp['f']={0,5};
      mp['g']={1,0};mp['h']={1,1};
      mp['i']={1,2};mp['j']={1,3};mp['k']={1,4};mp['l']={1,5};
      mp['m']={2,0};mp['n']={2,1};mp['o']={2,2};mp['p']={2,3};mp['q']={2,4};
      mp['r']={2,5};mp['s']={3,0};mp['t']={3,1};mp['u']={3,2};mp['v']={3,3};
      mp['w']={3,4};mp['x']={3,5};mp['y']={4,0};
      mp['z']={4,1};
      return getAns(0,-1,-1,-1,-1,word);
    }
};