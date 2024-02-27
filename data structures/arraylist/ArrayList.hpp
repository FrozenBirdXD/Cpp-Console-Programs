#ifndef ARRAYLIST_H
#define ARRAYLIST_H

template <class T>
class ArrayList
{
    T *array;
    int size;
    int numOfElements;

    void doubleArraySize();
    void halveArraySize();

public:
    ArrayList() : array(new T[5]), size(5), numOfElements(0) {}
    explicit ArrayList(int initialCapacity) : array(new T[initialCapacity]), size(initialCapacity), numOfElements(0) {}
    ~ArrayList() { delete[] array; }

    void add(const T &);
    void set(const int, const T &);
    void clear();
    bool isEmpty();
    bool contains(const T &);
    int indexOf(const T &);
    T remove(int);
    T get(int);
    int length();
    int sizeOfArray();
};

#endif