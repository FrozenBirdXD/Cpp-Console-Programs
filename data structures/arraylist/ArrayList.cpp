#include "ArrayList.hpp"

template <class T>
void ArrayList<T>::add(const T &element)
{
    if (numOfElements == size)
    {
        doubleArraySize();
    }
    array[numOfElements] = element;
    numOfElements++;
}

template <class T>
void ArrayList<T>::set(const int index, const T &element)
{
    if (index < 0 || index >= numOfElements)
    {
        throw std::out_of_range("Index out of bounds");
    }
    array[index] = element;
}

template <class T>
T ArrayList<T>::get(const int index)
{
    if (index < 0 || index >= numOfElements)
    {
        throw std::out_of_range("Index out of bounds");
    }
    return array[index];
}

template <class T>
T ArrayList<T>::remove(const int index)
{
    if (index < 0 || index >= numOfElements)
    {
        throw std::out_of_range("Index out of bounds");
    }
    T element = array[index];

    for (int i = index; i < numOfElements - 1; ++i)
    {
        array[i] = array[i + 1];
    }

    numOfElements--;

    if (size >= 10 && size / numOfElements <= size / 3)
    {
        halveArraySize();
    }

    return element;
}

template <class T>
int ArrayList<T>::indexOf(const T &element)
{
    for (int i = 0; i < numOfElements; ++i)
    {
        if (element == array[i])
        {
            return i;
        }
    }
    return -1;
}

template <class T>
int ArrayList<T>::length()
{
    return numOfElements;
}

template <class T>
bool ArrayList<T>::contains(const T &element)
{
    for (const T &e : array)
    {
        if (e == element)
        {
            return true;
        }
    }
    return false;
}

template <class T>
void ArrayList<T>::clear()
{
    delete[] array;
    array = new T[5];
    numOfElements = 0;
}

template <class T>
bool ArrayList<T>::isEmpty()
{
    return numOfElements == 0;
}

template <class T>
void ArrayList<T>::halveArraySize()
{
    T *newArray = new T[size / 2];
    for (int i = 0; i < numOfElements; ++i)
    {
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
    size /= 2;
}

template <class T>
void ArrayList<T>::doubleArraySize()
{
    T *newArray = new T[size * 2];
    for (int i = 0; i < numOfElements; ++i)
    {
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
    size *= 2;
}

template <class T>
int ArrayList<T>::sizeOfArray()
{
    return size;
}
