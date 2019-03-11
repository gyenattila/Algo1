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
    E* first;
    E* last;
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
    first = last = new E;
    first->next = nullptr;
    size = 0;
}

template<typename T>
T Queue<T>::rem()
{
    if (size != 0)
    {
        int x = first->key;
        E* s = first;
        first = first->next;
        delete s;
        size--;
        return x;
    }
    std::cerr << "ERROR" << std::endl;
    return -1;
}

template<typename T>
void Queue<T>::add(T x)
{
    last->next = new E;
    last->key = x;
    last = last->next;
    last->next = nullptr;
    size++;
}

template<typename T>
T Queue<T>::getFirst()
{
    if (size != 0)
        return first->key;
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
    while(first != nullptr)
    {
        E* p = first;
        first = first->next;
        delete p;    
    }
}

template<typename T>
void Queue<T>::setEmpty()
{
    while(first != last)
    {
        E* p = first;
        first = first->next;
        delete p;
    }
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