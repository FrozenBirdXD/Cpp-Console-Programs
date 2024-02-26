#ifndef ARRAYLIST_H
#define ARRAYLIST_H

template <class T>
class ArrayList
{
    T *array;

    void doubleArraySize();
    void halveArraySize();

public:
    ArrayList();
    explicit ArrayList(int);
    ~ArrayList();

    void add(const T &);
    void set(int, const T &);
    void clear();
    bool isEmpty();
    bool contains(const T &);
    int indexOf(const T &);
    T remove(const T &);
    T get(int);
    int getSize();
};

#endif