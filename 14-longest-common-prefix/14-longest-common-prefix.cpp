class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int curr=strs[0].size();
        for(int i=1;i<strs.size();i++){
            int len=min((int)strs[i].size(),curr);
            int j=0;
            int size=0;
            while(j<len){
                if(strs[i][j]!=strs[i-1][j]){
                  break;  
                }
                size++;
                j++;
            }
            curr=min(curr,size);
            
        }
        return strs[0].substr(0,curr);
    }
};