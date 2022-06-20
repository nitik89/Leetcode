class Solution {
public:
 static bool compare (string& first, string& second) {
        return first.size() > second.size();
    }
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(),words.end(),compare);
        unordered_map<string,int>mp;
        unordered_map<string,int>an;
        for(int i=0;i<words.size();i++){
            if(an.count(words[i])==0&&mp.count(words[i])==0){
                an[words[i]]=1;
            }
           
            for(int j=0;j<words[i].size();j++){
                string temp=words[i].substr(j);
                // cout<<temp<<" ";
                mp[temp]=1;
            }
        }
        int cnt=0;
        for(auto x:an){
            // cout<<x.first<<" "<<x.second<<"\n";
            if(x.second>0){
                // cout<<x.first<<" ";
                cnt+=x.first.size()+1;
            }
        }
            return cnt;
    }
};