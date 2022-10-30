class Solution {
public:
    vector<string> twoEditWords(vector<string>& q, vector<string>& d) {
        vector<string>ans;
        for(int i=0;i<q.size();i++){
            string str=q[i];
            for(int j=0;j<d.size();j++){
                int cnt=0;
                for(int k=0;k<str.size();k++){
                    if(str[k]!=d[j][k]){
                        cnt++;
                    }
                }
                if(cnt<=2){
                    ans.push_back(str);
                    break;
                }
            }
        }
        return ans;
    }
};