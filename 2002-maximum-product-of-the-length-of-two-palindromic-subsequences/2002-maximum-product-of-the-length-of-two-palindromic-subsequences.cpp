class Solution {
public:
    int ans;
    bool isPal(string &str){
        int i=0,j=str.size()-1;
        while(i<=j){
            if(str[i]==str[j]){
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    void getAns(string &s,int i,string &a,string &b){
        if(i>=s.size()){
            
            if(isPal(a)&&isPal(b)){
                // cout<<a<<" "<<b<<"\n";
                int x=(int)a.size()*(int)b.size();
                ans=max(ans,x);
            }
            return;
        }
        a.push_back(s[i]);
        getAns(s,i+1,a,b);
        a.pop_back();
         b.push_back(s[i]);
        getAns(s,i+1,a,b);
        b.pop_back();
        getAns(s,i+1,a,b);
    }
    int maxProduct(string s) {
        ans=INT_MIN;
        string a="",b="";
        getAns(s,0,a,b);
        return ans;
    }
};