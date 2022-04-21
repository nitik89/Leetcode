class Solution {
public:
    int nextGreaterElement(int n) {
        string str=to_string(n);
        int j=str.size()-1;
        for(int i=str.size()-1;i>=0;i--){
            if(str[i]<str[i+1]){
                j=i;
                break;
            }
        }
        int k=str.size()-1;
        while(k>=0){
            if(str[k]>str[j]){
                swap(str[k],str[j]);
                break;
            }
            k--;
        }
        reverse(str.begin()+j+1,str.end());
        long long x=stoll(str);
        if(x<=n||x>INT_MAX){
            return -1;
        }
        return x;
    }
};