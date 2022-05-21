// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


 // } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
        vector<int>gas(n);
        vector<int>cost(n);
        for(int i=0;i<n;i++){
            gas[i]=(p[i].petrol);
            cost[i]=(p[i].distance);
        }
        int curr=0,startidx=-1;
        for(int i=0;i<gas.size();i++){
            if(curr==0&&startidx==-1){
                curr=gas[i];
                if(cost[i]<=curr){
                    startidx=i;
                    curr-=cost[i];
                }
                else{
                    curr=0;
                    startidx=-1;
                }
            }
        
            else if(startidx!=-1) {
                curr+=gas[i];
                if(curr>=cost[i]){
                    curr-=cost[i];
                }
                else{
                    startidx=-1;
                    curr=0;
                }
                
            }
        }
       
        if(startidx==-1){
            return -1;
        }
        for(int i=0;i<startidx;i++){
             curr+=gas[i];
                if(curr>=cost[i]){
                    curr-=cost[i];
                }
                else{
                    return -1;
                }
        }
        return startidx;
    }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}
  // } Driver Code Ends