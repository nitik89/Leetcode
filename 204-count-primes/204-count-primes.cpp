class Solution {
public:
    int countPrimes(int n) {
        int cnt=0;
        vector<bool>vec(n+1,true);
        for(int i=2;i<n;i++){
            if(vec[i]){
                for(int j=2;j*i<n;j++){
                    vec[j*i]=false;
                }
                cnt++;
            }
        }
        return cnt;
    }
};