class Solution {
public:
    int ans;
    void getAns(int n,int i,vector<vector<int>>&req,int cnt,vector<int>&vec){
        if(i==req.size()){
            int br=1;
            for(auto x:vec){
                if(x>1){
                    br=0;
                    break;
                }
            }
            if(br){
                // cout<<cnt<<" ";
                ans=max(ans,cnt);
            }
            return;
        }
        vec[req[i][0]]--;
        vec[req[i][1]]++;
        getAns(n,i+1,req,cnt+1,vec);
        vec[req[i][0]]++;
        vec[req[i][1]]--;
        getAns(n,i+1,req,cnt,vec);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int>vec(n,1);
        ans=0;
        getAns(n,0,requests,0,vec);
        return ans;
    }
};