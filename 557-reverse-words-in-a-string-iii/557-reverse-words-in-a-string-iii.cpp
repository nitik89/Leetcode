class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        for(int i=0;i<s.size();i++){
            
            string temp="";
            while(i<s.size()&&s[i]!=' '){
                temp.push_back(s[i]);
                i++;
            }
            reverse(temp.begin(),temp.end());
            ans+=temp+" ";
        }
        ans.pop_back();
        return ans;
    }
};