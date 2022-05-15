// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
vector<string>ans;
void getAns(set<string>st,string s,string curr){
    if(s.size()==0){
        curr.pop_back();
        ans.push_back(curr);
        return;
    }
    for(int i=0;i<s.size();i++){
        string temp=s.substr(0,i+1);
        if(st.find(temp)!=st.end()){
            getAns(st,s.substr(i+1),curr+temp+" ");
        }
    }
}
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        set<string>st;
        for(auto x:dict){
            st.insert(x);
        }
        getAns(st,s,"");
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends