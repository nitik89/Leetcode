class MyCircularQueue {
public:
    int arr[1000],rear=-1,front=0,size,sz=0;
    MyCircularQueue(int k) {
    size=k;
        cout<<size<<"\n";
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        sz++;
        // cout<<value<<" "<<sz<<"\n";
        rear=(rear+1)%size;
        arr[rear]=value;
        return true;
        
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
         // cout<<sz<<"\n";
        sz--;
        
        int save=arr[front];
        front=(front+1)%size;
        return true;
        //removes from the front
        
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }
    
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        return arr[rear];
    }
    
    bool isEmpty() { //see these cond
        if(sz==0){
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if(sz==size){
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */