class MyCircularQueue {
private:
    int front, rear, sz;
    vector<int> q;
public:
    MyCircularQueue(int k) {
        front=-1;
        rear=-1;
        q.resize(k);
        sz=k;
    }
    
    bool enQueue(int value) {
        //check if q is full
        //cout<<"enqueue: "<<value<<"\n";
        if(isFull()) return false;
        
        if(front==-1) front=0;
        rear=(rear+1)%sz;
        q[rear] = value;
        return true;
    }
    
    bool deQueue() {
        // check if queue empty
        //cout<<"deQueue "<<"\n";
        if(isEmpty()) return false;
        if(rear-front+1==1) {
            rear=-1;
            front=-1;
            return true;
        }
        front=(front+1)%sz;
        
        return true;
        
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return q[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return q[rear];
    }
    
    bool isEmpty() {
        return (front==-1 && rear==-1);
    }
    
    bool isFull() {
        return ((front==0 && rear==sz-1) || ((rear+1)%sz==front));
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