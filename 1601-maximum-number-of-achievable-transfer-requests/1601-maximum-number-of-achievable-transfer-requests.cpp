class Solution {
public:
    // int ans;
    int getAns(int n,int i,vector<vector<int>>&req,vector<int>&vec){
        if(i==req.size()){
            int br=1,ans=-1e6;
            for(auto x:vec){
                if(x>1){
                    br=0;
                    break;
                }
            }
            if(br){
                // cout<<cnt<<" ";
                return 0;
            }
            return ans;
        }
        vec[req[i][0]]--;
        vec[req[i][1]]++;
        int v1=getAns(n,i+1,req,vec)+1;
        vec[req[i][0]]++;
        vec[req[i][1]]--;
        int v2=getAns(n,i+1,req,vec);
        return max(v1,v2);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int>vec(n,1);
      
      return  getAns(n,0,requests,vec);
        
    }
};