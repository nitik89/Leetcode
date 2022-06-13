class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& que, int intLength) {
        int v=intLength;
        if(intLength%2==0){
            intLength--;
        }
        int len=ceil(intLength/2);
        vector<long long>an;
       int no=pow(10,len);
        
        
        for(int i=0;i<que.size();i++){
           long long val=que[i]+no-1;
            long long n=val;
            long long rev=0;
            if(v%2!=0){
            n=n/10;
            }
            else{
                no=no*10;
            }
            // cout<<n<<" ";
              while (n != 0) {
       long long  remainder = n % 10;
        rev = rev * 10 + remainder;
        n /= 10;
    }
            // cout<<val<<" ";
             // cout<<val<<" "<<rev<<"\n";
           long long ans=val*(no)+rev;
            
             
            no=pow(10,len);
            if(no*9<que[i]){
                an.push_back(-1);
            }
            else{
            an.push_back(ans);
            }
        }
        return an;
        
    }
};