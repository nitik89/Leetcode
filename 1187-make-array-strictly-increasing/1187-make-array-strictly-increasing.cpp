class Solution {
public:
    int dp[2002][2002][2];
    int getAns(vector<int>&vec1,vector<int>&vec2,int i,int j,bool swap){
        if(i==vec1.size()){
            return 0;
        }
        if(dp[i][j][swap]!=-1){
            return dp[i][j][swap];
        }
        int prev=swap?vec2[j-1]:vec1[i-1];
        int idx=upper_bound(vec2.begin()+j,vec2.end(),prev)-vec2.begin();//prev ka idx
        int ans=1e9;
        if(vec1[i]>prev){
            ans=min(ans,getAns(vec1,vec2,i+1,idx,false));//no swap thing
        }
        if(idx<vec2.size()){
        ans=min(ans,1+getAns(vec1,vec2,i+1,idx+1,true));
        }
        return dp[i][j][swap]=ans;
        
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        memset(dp,-1,sizeof dp);
        vector<int>temp;
        temp.push_back(-1);
        for(auto x:arr1){
            temp.push_back(x);
        }
       int ans=getAns(temp,arr2,1,0,false);
        return ans==1e9?-1:ans;
    }
};