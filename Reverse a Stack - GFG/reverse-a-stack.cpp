// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
vector<int>ans;
void getAns(stack<int>st,int i){
    if(st.empty()){
        return;
    }
    if(!st.empty()){
    int x=st.top();
    
    st.pop();
    getAns(st,i+1);
    ans[i]=x;
    }
      
}
    vector<int> Reverse(stack<int> St){
        ans.resize(St.size());
        getAns(St,0);
        return ans;
    }
};

// { Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        vector<int> ans=ob.Reverse(St);
        for(int i=0;i<N;i++){
            cout<<ans[i];
            if(i!=N-1) cout<<" ";
        }
        cout<<endl;
    }
}  // } Driver Code Ends