class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n=encoded.size();
       
        int xr=encoded[0];
        
        int allxre=xr;
        for(int i=1;i<encoded.size();i++){
            xr^=encoded[i];
            allxre^=xr;
        }
        
        int allxr=1;
        for(int i=2;i<=encoded.size()+1;i++){
            allxr^=i;
        }
        int f=allxr^allxre;
        // cout<<f<<" ";
        vector<int>ans;
        ans.push_back(f);
        for(int i=0;i<encoded.size();i++){
            int v=f^encoded[i];
            f=v;
            ans.push_back(v);
        }
        return ans;
        
    }
};