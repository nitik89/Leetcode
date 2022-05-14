// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string smallestNumber(int S, int D){
        int n=D;
        string s=to_string(S);
        string ans="";
        for(int i=0;i<n;i++){
            if(i==n-1){
                if(S>=10){
                    return "-1";
                }
                ans+=(S + '0');
            }
            else{
            int no=9;
            while(no>=0&&S-no<1){
                no--;
            }
            D--;
            ans+=(no + '0');
            S-=no;
            
            }
            
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
}   // } Driver Code Ends