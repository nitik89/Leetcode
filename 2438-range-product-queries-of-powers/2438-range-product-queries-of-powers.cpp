class Solution {
public:
 
    vector<int> productQueries(int x, vector<vector<int>>& q) {
        vector<long long>v;
        vector<long long>vec;
        int mod=1e9+7;
         while (x > 0) 
    {
        v.push_back(x % 2);
        x = x / 2;
    }
  
   
    for (int i = 0; i < v.size(); i++) 
    {
        if (v[i] == 1) 
        {
            vec.push_back(pow(2,i));
        }
    }
        
       
        vector<int>ans;
        for(auto &x:q){
            int s=x[0];
            int e=x[1];
            long long div=1;
            for(int j=s;j<=e;j++){
                div*=vec[j]%mod;
                div=div%mod;
            }
            ans.push_back(div);
        }
        return ans;
        
    }
};