class Solution {
public:
    
    static bool mycmp(vector<int>&a,vector<int>&b){
        
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        
        else return a[0]<b[0];
        
    }
    
    
       int maxEnvelopes(vector<vector<int>>& e) 
    {

        int ans=0;
        sort(e.begin(),e.end(),mycmp);
        vector<int> dp;

        for(int i=0;i<e.size();i++)
        {

            auto it=lower_bound(dp.begin(),dp.end(),e[i][1]);
            if(it==dp.end())
                dp.push_back(e[i][1]);
            else
            {
                dp[it-dp.begin()]=e[i][1];
            }

        }
        return dp.size();
    }
};