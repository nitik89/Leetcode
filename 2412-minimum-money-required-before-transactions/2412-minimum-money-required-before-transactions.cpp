class Solution {
public:
    // bool ispos(vector<vector<int>>& tr,long long amt){
    //     for(int i=0;i<tr.size();i++){
    //         if(tr[i][0]>amt){
    //             return false;
    //         }
    //         amt=amt-tr[i][0]+tr[i][1];
    //     }
    //     return amt>=0;
    // }
    //  int i=0;
    //     sort(tr.begin(),tr.end(),[&](vector<int>&a,vector<int>&b){
    //         return a[0]-a[1]>b[0]-b[1];
    //     });
    //     for(auto x:tr){
    //         cout<<x[0]<<" "<<x[1]<<"\n";
    //     }
    //     long long sum=0;
    //     for(auto x:tr){
    //         sum+=x[0];
    //     }
    //     long long s=1,e=sum,ans=-1;
    //     while(s<=e){
    //         int mid=(s+e)/2;
    //         if(ispos(tr,mid)){
    //             ans=mid;
    //             e=mid-1;
    //         }
    //         else{
    //             s=mid+1;
    //         }
    //     }
    //     return ans;
    
     long long minimumMoney(vector<vector<int>>& A) {
        long long res = 0; int v = 0;
        for (auto& a : A) {
            v = max(v, min(a[0], a[1]));
            res += max(a[0] - a[1], 0);
        }
         cout<<v<<" ";
        return res + v;
    }
};





