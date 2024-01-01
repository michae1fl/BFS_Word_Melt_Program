#ifndef BFS_WORD_MELT_PROGRAM_ARRAYQUEUE_H
#define BFS_WORD_MELT_PROGRAM_ARRAYQUEUE_H

#include <cassert>


template <class Base>
class ArrayQueue {
public:
    ArrayQueue();
    ArrayQueue(const ArrayQueue<Base> &q);
    ~ArrayQueue();

    void add(const Base &item);
    void remove();
    const Base &getFront() const;

    int getLength() const;

    const ArrayQueue<Base> &operator=(const ArrayQueue<Base> &q);

private:
    void doubleCapacity();

    Base *data;
    int length, capacity, front;
};

template<class Base>
ArrayQueue<Base>::ArrayQueue() {
    length = 0;
    front = 0;
    capacity = 5;
    data = new Base[capacity];
}


template<class Base>
ArrayQueue<Base>::ArrayQueue(const ArrayQueue<Base> &q) {

    length = q.length;
    front = q.front;
    capacity = q.capacity;
    data = new Base[capacity];

    for (int i = 0; i < capacity; i++) {
        data[i] = q.data[i];
    }

}


template<class Base>
ArrayQueue<Base>::~ArrayQueue() {

    delete [] data;
    length = 0;
    front = 0;
    capacity = 5;
    data = nullptr;
}


template<class Base>
void ArrayQueue<Base>::add(const Base &item) {

    if (length == capacity) {
        doubleCapacity();
    }

    data[(front + length) % capacity] = item;
    length ++;
}


template<class Base>
void ArrayQueue<Base>::remove() {

    front = (front +1) % capacity;
    length --;
}


template<class Base>
const Base &ArrayQueue<Base>::getFront() const {
    return data[front];
}


template<class Base>
int ArrayQueue<Base>::getLength() const {
    return length;
}


template<class Base>
const ArrayQueue<Base> &ArrayQueue<Base>::operator=(const ArrayQueue<Base> &q) {

    if (this == &q) {
        return *this;
    }

    length = q.length;
    front = q.front;
    capacity = q.capacity;

    if (data != nullptr) {
        delete [] data;
    }

    data = new Base[capacity];
    for (int i = 0; i < capacity; i++) {
        data[i] = q.data[i];
    }

    return *this;
}


template<class Base>
void ArrayQueue<Base>::doubleCapacity() {

    Base *bigData;
    int newCapacity = capacity * 2;

    bigData = new Base[newCapacity];

    for (int i = 0; i < capacity; i++) {
        bigData[i] = data[(front + i) % capacity];
    }

    delete [] data;
    capacity = newCapacity;
    data = bigData;
    front = 0;
}

#endif //BFS_WORD_MELT_PROGRAM_ARRAYQUEUE_H
