class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(),tiles.end());
        
        int n=tiles.size();
        vector<long long>pre(n+1,0);
        vector<int>end(n,0);
        long long sum=0;
        for(int i=0;i<tiles.size();i++){
            sum+=(tiles[i][1]-tiles[i][0]+1);
            pre[i+1]=sum;
            end[i]=tiles[i][1];
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            int crpt=tiles[i][0]+carpetLen-1;//extension of this carpet
            int idx=upper_bound(end.begin(),end.end(),crpt)-end.begin();
            int sum=pre[idx]-pre[i];
            
           if(idx<n&&tiles[idx][0]<=crpt){
               sum=sum+crpt-tiles[idx][0]+1;
           }
            ans=max(ans,sum);
        }
        return ans;
        
    }
};