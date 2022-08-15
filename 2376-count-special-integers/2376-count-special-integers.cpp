class Solution {
public:
int fact(int n)
{
    if (n <= 1)
        return 1;
    return n*fact(n-1);
}
 
int perm(int n, int r)
{
    return fact(n)/fact(n-r);
}
    int countSpecialNumbers(int n) {
        
        string str=to_string(n);
        int cnt=0;
        for(int i=1;i<str.size();i++){
            cnt+=9*perm(9,str.size()-i-1);
        }
        unordered_set<int>st;
        for(int i=0;i<str.size();i++){
            bool hasprev=false;
            for(int j=i>=1?0:1;j<=9;j++){
                if(st.count(j)) continue;
                if(j<(str[i] - '0')){
                    cnt+=perm(9-i,str.size()-i-1);
                }
                else if(j==(str[i] - '0')){
                     hasprev=true;
                    st.insert(j);
                }
            }
            if(!hasprev){
                return cnt;
            }
        }
          cnt++;
        
        vector<int>vec(10,0);
        for(int i=0;i<str.size();i++){
            vec[str[i] - '0']++;
            if(vec[str[i] - '0']>1){
                cnt--;
                break;
            }
        }
        return cnt;
    }
};