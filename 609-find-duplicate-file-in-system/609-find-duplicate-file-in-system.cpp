class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<paths.size();i++){
            string loc=paths[i];
            int j=0;
            string curr="";
            while(j<loc.size()&&(loc[j]!='/'&&loc[j]!=' ')){
                curr.push_back(loc[j]);
                j++;
            }
            
            int tr=0;
            if(loc[j]=='/'){
                curr.push_back('/');
                tr=1;
            }
            j++;
            while(j<loc.size()&&tr&&loc[j]!=' '){
                curr.push_back(loc[j]);
                j++;
            }
            curr.push_back('/');
            // cout<<curr<<" ";
            while(j<loc.size()){
                string temp="";
                string data="";
                while(j<loc.size()&&loc[j]==' '){
                    j++;
                }
                while(j<loc.size()&&loc[j]!='('){
                    temp.push_back(loc[j]);
                    j++;
                }
                j++;
                while(j<loc.size()&&loc[j]!=')'){
                    data.push_back(loc[j]);
                    j++;
                }
                j++;
                // cout<<temp<<" "<<data<<"\n";
                mp[data].push_back(curr+temp);
            }
            
        }
        vector<vector<string>>ans;
        for(auto x:mp){
            if(x.second.size()>1){
            ans.push_back(x.second);
            }
        }
        return ans;
    }
};