class Solution {
public:
    bool con(string &str){
        string temp="abcdefghijklmnopqrstuvwxyz";
        for(int i=0;i<str.size();i++){
            for(auto x:temp){
                if(x==str[i]){
                    return true;
                }
            }
        }
        return false;
    }
    int maximumValue(vector<string>& strs) {
        int ans=INT_MIN;
        for(int i=0;i<strs.size();i++){
            string str=strs[i];
            
                if(con(str)){
                    ans=max((int)str.size(),ans);
                }
            else{
                int x=stoi(str);
                
                ans=max(ans,x);
            }
        }
        return ans;
    }
};