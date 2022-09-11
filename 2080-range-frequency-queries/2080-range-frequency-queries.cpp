class RangeFreqQuery {
public:

vector<unordered_map<int,int>> tree;
int n=0;
void construct(int i, int l, int r, vector<int>& arr){
    if (l > r)  return;

    if(l==r){
        tree[i].insert({arr[l], 1});
        return;
    }
    if(l != r){
        
        int mid = (l + r)/2;

        construct(2*i+1, l, mid, arr);
        construct(2*i+2, mid+1, r, arr);
        // merge child1 and child2 in parent
        for (auto itr: tree[2*i+1]){
            tree[i][itr.first] += itr.second;
        }
        for (auto itr: tree[2*i+2]){
            tree[i][itr.first] += itr.second;
        }
    }
}
RangeFreqQuery(vector<int>& arr) {
    n = arr.size();
    int x = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2, x) - 1;
    tree.resize(max_size);
    
    construct(0, 0, n-1, arr);
}
int getSum(int si, int sl, int sr, int ql, int qr, int val){
    if(sr<ql || qr<sl){ return 0; }
    
    if(ql<=sl && sr<=qr){
        return tree[si].find(val)!=tree[si].end() ? tree[si][val]: 0;
    }
    
    int mid = (sl + sr)/2;
    return getSum(2*si+1, sl, mid, ql, qr, val) + getSum(2*si+2, mid+1, sr, ql, qr, val);
}

int query(int left, int right, int value) {
    return getSum(0, 0, n-1, left, right, value);
}
};