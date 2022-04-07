class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        stack<int>lft;//find left min for left impact
        stack<int>rgt;
        int mod=1e9+7;
        vector<int>arr1(n,-1);
        vector<int>arr2(n,n);
        for(int i=0;i<arr.size();i++){
            
            while(!lft.empty()&&arr[lft.top()]>=arr[i]){
                lft.pop();
            }
            if(!lft.empty()){
                arr1[i]=lft.top();
            }
            lft.push(i);
        }
        
        for(int i=arr.size()-1;i>=0;i--){
            
            while(!rgt.empty()&&arr[rgt.top()]>arr[i]){
                rgt.pop();
            }
            if(!rgt.empty()){
                arr2[i]=rgt.top();
            }
            rgt.push(i);
        }
        long long sum=0;
        for(int i=0;i<n;i++){
            long long l=i-arr1[i];
            long long r=arr2[i]-i;
             // cout<<l<<" "<<r<<"\n";
           sum+=(arr[i]*(l%mod*r%mod)%mod)%mod;
            sum=sum%mod;
            
        }
        return sum%mod;
        
    }
};