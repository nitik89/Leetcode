class Solution {
public:
    int mx=INT_MAX;
    void getAns(vector<int>&cookies,int n,vector<int>&space,int j,int mx1){
        
        if(j==n){
           
            
            mx=min(mx1,mx);
            return;
        }
        for(int i=0;i<space.size();i++){
            space[i]+=cookies[j];
            getAns(cookies,n,space,j+1,max(mx1,space[i]));
            space[i]-=cookies[j];
        }
        
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int n=cookies.size();
        vector<int>space(k,0);
        getAns(cookies,n,space,0,INT_MIN);
        return mx;
    }
};