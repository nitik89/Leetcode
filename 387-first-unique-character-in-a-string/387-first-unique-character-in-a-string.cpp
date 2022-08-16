class Solution {
public:
    int firstUniqChar(string s) {
          // ios_base::sync_with_stdio(0);
        int vec[256]={};
        for(auto &x:s){
            vec[x]++;
        }
        int idx=0;
        for(auto &x:s){
           
            if(vec[x] == 1){
                return idx;
            }
            idx++;
        }
        return -1;
    }
};