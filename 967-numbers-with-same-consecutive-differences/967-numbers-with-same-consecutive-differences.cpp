class Solution {
public:
    void getAns(vector<string> &ans,int n,int k,int idx,string str){
        if(idx==n){
            ans.push_back(str);
            return;
        }
        for(int i=0;i<=9;i++){
            if(idx==0&&i!=0){
               
                str+=to_string(i);
                getAns(ans,n,k,idx+1,str);
                str.pop_back();
                }

            else if(idx>0&&abs((str[idx-1]-'0')-i)==k){
                str+=to_string(i);
                getAns(ans,n,k,idx+1,str);
                str.pop_back();
            }
            
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<string>ans;
        getAns(ans,n,k,0,"");
        vector<int>ans1;
       for(string x:ans){
           int y=stoi(x);
           ans1.push_back(y);
       }
        return ans1;
    }
};