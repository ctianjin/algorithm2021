class MyCircularDeque {

private:
    int head = 0; 
	int tail = 0; 
	int capacity; 
	int *array = NULL;

public:
    MyCircularDeque(int k) {
        head = 0;
	    tail = 0;
        capacity = k +1;
	    array = new int[capacity];
    }
    
    bool insertFront(int value) {
        if ((tail+1) % capacity == head)   
		return false;
		
        head = (head-1+capacity) % capacity;
	    array[head] = value;
        return true;
    }
    
    bool insertLast(int value) {
        if ((tail+1) % capacity == head)   
		return false;
		
	    array[tail] = value;
	    tail = (tail+1) % capacity;
        return true;
    }
    
    bool deleteFront() {
        if (head == tail)   
		return false;
		
		head = (head+1) % capacity;
        return true;
    }
    
    bool deleteLast() {
        if (head == tail)   
		return false;
		
		tail = (tail-1+capacity) % capacity;
        return true;
    }
    
    int getFront() {
        if (head == tail)   
		return -1;
		
        return array[head];
    }
    
    int getRear() {
        if (head == tail)   
		return -1;
		
        return array[(tail-1+capacity) % capacity];
    }
    
    bool isEmpty() {
        return head == tail;
    }
    
    bool isFull() {
        return (tail+1) % capacity == head;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */