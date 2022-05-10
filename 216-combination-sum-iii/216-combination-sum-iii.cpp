class Solution {
public:
    void getAns(vector<int>temp,vector<vector<int>>&ans,vector<bool>&vis,int k,int n,int lo){
        if(k==0){
            if(n==0){
                ans.push_back(temp);
            }
            return;
        }
        for(int i=lo;i<=9;i++){
            if(vis[i]==false){
                vis[i]=true;
                temp.push_back(i);
                getAns(temp,ans,vis,k-1,n-i,i+1);
                temp.pop_back();
                vis[i]=false;
                
            }
        }
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        vector<vector<int>>ans;
        vector<bool>vis(10,false);
        getAns(temp,ans,vis,k,n,1);
        return ans;
    }
};