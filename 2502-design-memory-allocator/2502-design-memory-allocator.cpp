class Allocator {
public:
   vector<int>vec;
    int N;
    Allocator(int n) {
        vec.resize(n,0);
        N=n;
    }
    
    int allocate(int size, int m) {
        for(int i=0;i<vec.size();i++){
            int s=i,j=i,cnt=0;
            while(j<vec.size()&&vec[j]==0&&cnt<size){
                j++;
                cnt++;
            }
            j--;
            if(j-s+1>=size){
                for(int k=s;k<=j;k++){
                    vec[k]=m;
                }
                return s;
            }
            i=j+1;
        }
        return -1;
    }
    
    int free(int m) {
        int cnt=0;
        for(int i=0;i<N;i++){
            if(vec[i]==m){
                vec[i]=0;
                cnt++;
            }
        }
        return cnt;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */