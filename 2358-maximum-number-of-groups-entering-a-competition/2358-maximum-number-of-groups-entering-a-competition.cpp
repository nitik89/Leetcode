class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        long long n=grades.size()/2;
        for(long long i=grades.size();i>=1;i--){
            long long sum=i*(i+1)/2;
            if(sum<=grades.size()){
                return i;
            }
        }
        return 0;
    }
};