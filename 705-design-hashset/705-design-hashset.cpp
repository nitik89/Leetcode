class MyHashSet {
public:
    bool vis[1000001];
    MyHashSet() {
        memset(vis,false,sizeof(vis));
    }
    
    void add(int key) {
        vis[key]=1;
    }
    
    void remove(int key) {
        vis[key]=0;
    }
    
    bool contains(int key) {
        return vis[key];
    }
};
