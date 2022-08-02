class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum=0;
        for(auto x:chalk){
            sum+=x;
        }
        int diff=k%sum;
        for(int i=0;i<chalk.size();i++){
            diff-=chalk[i];
            if(diff<0){
                return i;
            }
        }
        return -1;
    }
};