class Solution {
public:
    bool equalFrequency(string word) {
       unordered_map<char,int>mp;
        for(auto x:word){
            mp[x]++;
        }
        int i=0;
        for(auto x:word){
            mp[x]--;
            if(mp[x]==0){
                mp.erase(x);
            }
            int f=-1;
            int br=0;
            for(auto y:mp){
                if(f==-1){
                    f=y.second;
                }
                else if(f!=y.second){
                    br=1;
                    break;
                }
            }
            mp[x]++;
            if(br==0){
                return true;
            }
            i++;
        }
        return false;
    }
};