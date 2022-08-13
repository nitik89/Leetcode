class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int>mp;
        for(auto x:words){
            mp[x]++;
        }
        int n=s.size();
        int m=words.size();
        int total=words[0].size()*(m);
        int p=words[0].size();
       
        vector<int>ans;
        // cout<<s.size<<" ";
        for(int i=0;i<=(int)s.size()-total;i++){
            unordered_map<string,int>mp1;
            // cout<<i<<" ";
            int b=0;
            for(int j=i;j<total+i;j+=p){
                
                string str=s.substr(j,p);
               // if(i==9){
               //     cout<<str<<" ";
               // }
                mp1[str]++;
                if(mp1[str]>mp[str]){
                  // cout<<i<<" ";
                    b=1;
                    break;
                }
            }
            if(b==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};