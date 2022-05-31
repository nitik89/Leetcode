class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string>st;
        if(s.length()<k)
        {
            return false;
        }
        for(int i=0;i<=s.size()-k;i++){
            string temp="";
            temp=s.substr(i,k);
            st.insert(temp);
        }
        long long p=pow(2,k);
         // cout<<p<<" "<<st.size();
        return st.size()==p;
    }
};