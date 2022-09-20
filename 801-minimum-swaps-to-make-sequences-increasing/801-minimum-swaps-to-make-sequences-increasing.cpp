class Solution {
public:
    int dp[100001][2];
//     int getAns(vector<int>&vec1,vector<int>&vec2,int i,bool sec){
//         if(i==vec1.size()){
//             return 0;
//         }
//         if(dp[i][sec]!=-1){
//             return dp[i][sec];
//         }
//         if(i==0){
//             int m1=getAns(vec1,vec2,i+1,false);
//             int m2=1+getAns(vec1,vec2,i+1,true);
//             return min(m1,m2);
//         }
//         else{
//             int ans=INT_MAX;
//             if(sec){
//                 if(vec2[i-1]<vec1[i]&&vec1[i-1]<vec2[i]){
//                     ans=min(ans,getAns(vec1,vec2,i+1,false));
                    
//                 }
//                 if(vec1[i-1]<vec1[i]&&vec2[i-1]<vec2[i]){
//                 ans=min(ans,1+getAns(vec1,vec2,i+1,true));
//                 }
//             }
//             else{
//                 if(vec1[i-1]<vec1[i]&&vec2[i-1]<vec2[i]){
//                     ans=min(ans,getAns(vec1,vec2,i+1,false));
//                 }
//                 if(vec2[i-1]<vec1[i]&&vec1[i-1]<vec2[i]){
//                     ans=min(ans,1+getAns(vec1,vec2,i+1,true));
//                 }
//                 }
            
//             return dp[i][sec]=ans;
//         }
//     }
    int minSwap(vector<int>& vec1, vector<int>& vec2) {
        memset(dp,0,sizeof dp);
        int a1=0,a2=0;
        for(int i=vec1.size()-2;i>=0;i--){
            int t1=0,t2=0;
            for(int s=0;s<=1;s++){
                int ans=INT_MAX;
            if(s){
                if(vec2[i+1]>vec1[i]&&vec1[i+1]>vec2[i]){
                    ans=min(ans,a1);
                }
                
                    
                
                if(vec1[i+1]>vec1[i]&&vec2[i+1]>vec2[i]){
                ans=min(ans,1+a2);
                }
            }
            else{
                if(vec1[i+1]>vec1[i]&&vec2[i+1]>vec2[i]){
                    ans=min(ans,a1);
                }
                if(vec2[i+1]>vec1[i]&&vec1[i+1]>vec2[i]){
                    ans=min(ans,1+a2);
                }
                }
                if(s==0){
                    t1=ans;
                }
                else{
                    t2=ans;
                }
            }
            a1=t1;
            a2=t2;
            
                
                
            }
        return min(1+a2,a1);
        }
    
};