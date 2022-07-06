class Solution {
public:
    int mx=INT_MAX;
    void getAns(vector<int>&cookies,int n,vector<int>&space,int j){
        
        if(j==n){
            int mx1=INT_MIN;
            for(auto x:space){
                mx1=max(x,mx1);
            }
            mx=min(mx1,mx);
            return;
        }
        for(int i=0;i<space.size();i++){
            space[i]+=cookies[j];
            getAns(cookies,n,space,j+1);
            space[i]-=cookies[j];
        }
        
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int n=cookies.size();
        vector<int>space(k,0);
        getAns(cookies,n,space,0);
        return mx;
    }
};