class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& que) {
        int n=s.size();
        vector<vector<int>>vec(n,vector<int>(26,0));
        vec[0][s[0] - 'a']++;
        for(int i=1;i<s.size();i++){
            vec[i]=vec[i-1];
            vec[i][s[i] - 'a']++;
        }
        vector<bool>ans;
        int k=0;
        for(auto x:que){
            int l=x[0];
            int r=x[1];
            int rep=x[2];
            int len=r-l+1;
            int c=0;
            for(int i=0;i<26;i++){
                int cnt=vec[r][i]-(l-1>=0?vec[l-1][i]:0);
                c+=cnt/2;
            }
            if(len%2==0){
                
                if(len<=2*c+(len-2*c)/2+rep){
                    ans.push_back(true);
                }
                else{
                    ans.push_back(false);
                }
            }
            else{
                if(len<=2*c+1+(len-2*c)/2+rep){
                    ans.push_back(true);
                }
                else{
                    ans.push_back(false);
                }
            }
        }
        return ans;
    }
};