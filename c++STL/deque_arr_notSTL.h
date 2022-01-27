class Deque {

public:
    Deque(const int size = 16);
    ~Deque();

    bool empty() const;
    bool full() const;
    int size() const;
    int front() const;
    int back() const;
    void pushFront(const int data);
    void pushBack(const int data);
    int popFront();
    int popBack();

    void display() const;

private:
    int* deque;
    int maxSize;
    int dataSize;
    int frontIndex;
    int rearIndex;

};