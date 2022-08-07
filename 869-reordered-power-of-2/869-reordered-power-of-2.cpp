class Solution {
public:
    bool reorderedPowerOf2(int n) {
        int v=pow(2,29);
        vector<pair<int,int>>vec={{},{0,3},{4,6},{7,9},{10,13},{14,16},{17,19},{20,23},{24,26},{27,29}};
        int dig=floor(log10(n) + 1);
        int num=n;
        unordered_map<int,int>mp;
        while(num>0){
            int v=num%10;
            mp[v]++;
            num=num/10;
        }
        int f=vec[dig].first;
        int l=vec[dig].second;
        for(int i=f;i<=l;i++){
            unordered_map<int,int>mp1;
           int v=pow(2,i);
            while(v>0){
            int k=v%10;
            mp1[k]++;
            v=v/10;
        }
            int k=0;
            for(auto x:mp1){
                if(mp[x.first]!=x.second){
                    k=1;
                    break;
                }
            }
            if(!k){
                return true;
            }
            
        }
        return false;
        
    }
};