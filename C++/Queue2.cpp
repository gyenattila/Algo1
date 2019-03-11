#include <iostream>

struct E
{
    int key;
    E* next;
};

template<typename T>
class Queue
{
private:
    E* q;
    int size;

public:
    Queue();
    ~Queue();
    void add(T x);
    T rem();
    T getFirst();
    int length();
    bool isEmpty();
    void setEmpty();

};

template <typename T>
Queue<T>::Queue()
{
    q = new E;
    q->next = q;
    size = 0;
}

template<typename T>
T Queue<T>::rem()
{
    if (size != 0)
    {
        E* r = q->next->next;
        int x = q->next->key;
        delete q->next;
        q->next = r;
        size--;
        return x;
    }
    std::cerr << "ERROR" << std::endl;
    return -1;
}

template<typename T>
void Queue<T>::add(T x)
{
    E* r = q->next;
    q->key = x;
    q->next = new E;
    q = q->next;
    q->next = r;
    size++;
}

template<typename T>
T Queue<T>::getFirst()
{
    if (size != 0)
        return q->next->key;
    std::cerr << "ERROR" << std::endl;
    return -1;
}

template<typename T>
int Queue<T>::length()
{
    return size;
}

template <typename T>
bool Queue<T>::isEmpty()
{
    return size == 0;
}

template<typename T>
Queue<T>::~Queue()
{
    E* p = q->next;
    while(p != q)
    {
        E* r = p;
        p = p->next;
        delete r;    
    }
    delete q;
}

template<typename T>
void Queue<T>::setEmpty()
{
    E* p = q->next;
    while(p != q)
    {
        E* r = p;
        p = p->next;
        delete r;
    }
    q->next = q;
    size = 0;
}

int main()
{
    Queue<int> q;
    q.add(1);
    q.add(2);
    q.add(3);
    std::cout << q.getFirst() << std::endl;
    q.rem();
    std::cout << q.getFirst() << std::endl;
    std::cout << q.length() << std::endl;
    q.setEmpty();
    std::cout << q.getFirst() << std::endl;
    std::cout << q.length() << std::endl;
    std::cout << q.rem() << std::endl;
}