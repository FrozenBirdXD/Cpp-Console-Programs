#include <iostream>

#include "ArrayList.hpp"
#include "ArrayList.cpp"

int main()
{
    ArrayList<int> list{3};
    std::cout << "Initial length: " << list.sizeOfArray() << std::endl;

    list.add(10);
    list.add(20);
    list.add(30);
    list.add(40);
    list.add(50);
    list.add(60);
    list.add(70);

    std::cout << "Initial list contents: ";
    for (int i = 0; i < list.length(); ++i)
    {
        std::cout << list.get(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "Length after content added: " << list.sizeOfArray() << std::endl;
    list.remove(2);
    list.remove(2);
    list.remove(2);

    std::cout << "Length after content removed: " << list.sizeOfArray() << std::endl;

    std::cout << "List after removal: ";
    for (int i = 0; i < list.length(); ++i)
    {
        std::cout << list.get(i) << " ";
    }
    std::cout << std::endl;

    list.clear();
    std::cout << "List after clear: ";
    for (int i = 0; i < list.length(); ++i)
    {
        std::cout << list.get(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}