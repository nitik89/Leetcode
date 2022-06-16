class Solution {
public:
    bool digitCount(string num) {
       vector<int>val(10,0);
        for(auto x:num){
            val[x - '0']++;
        }
        for(int i=0;i<num.size();i++){
            if(val[i]!=(num[i] - '0')){
                // cout<<i<<" ";
                return false;
            }
        }
        return true;
    }
};