// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    string lookandsay(int n) {
         if(n==1){
            return "1";
        }
        string x=lookandsay(n-1);
        x.push_back(' ');
        string ans;
        int i=0;
        while(i<x.size()){
            if(x[i]==' '){
                break;
            }
            int cnt=1;
            char curr=x[i];
            while(i+1<x.size()&&x[i]==x[i+1]){
                cnt++;
                i++;
            }
            i++;
            ans.push_back(cnt + '0');
            ans.push_back(curr);
        }
        return ans;
    }   
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution obj;
        cout<<obj.lookandsay(n)<<endl;
    }
    return 0;
}  // } Driver Code Ends