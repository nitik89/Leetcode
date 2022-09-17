class Solution {
public:
   
     
    int countDaysTogether(string aa, string la, string ab, string lb) {
        vector<int>vec={0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<int>pre(13,0);
        for(int i=1;i<13;i++){
            pre[i]+=vec[i]+pre[i-1];
        }
      
        int aa1=stoi(aa.substr(0,2));
        int aa2=stoi(aa.substr(3,2));
        int ab1=stoi(la.substr(0,2));
        int ab2=stoi(la.substr(3,2));
        
        int ba1=stoi(ab.substr(0,2));
        int ba2=stoi(ab.substr(3,2));
        int bb1=stoi(lb.substr(0,2));
        int bb2=stoi(lb.substr(3,2));
        
        int da=pre[aa1-1]+aa2;
        int dl=pre[ab1-1]+ab2;
        int br=pre[ba1-1]+ba2;
        int bl=pre[bb1-1]+bb2;
        // cout<<pre[aa1]<<" ";
        // cout<<da<<" "<<dl<<" "<<br<<" "<<bl<<"\n";
        if(dl<br){
            return 0;
        }
        if(bl<da){
            return 0;
        }
        return min(bl,dl)-max(da,br)+1;
        // return 1;
        
    }
};