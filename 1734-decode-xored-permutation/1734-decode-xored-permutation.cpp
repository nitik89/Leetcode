class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n=encoded.size();
        vector<int>vec(n);
        int xr=encoded[0];
        vec[0]=xr;
        for(int i=1;i<encoded.size();i++){
            xr^=encoded[i];
            vec[i]=xr;
        }
        int allxre=vec[0];
        for(int i=1;i<vec.size();i++){
            allxre^=vec[i];
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