#include <iostream>


template<typename T>
class List
{
private:
    struct Node
    {
        T element;
        Node* prev = nullptr;
        Node* next = nullptr;

    };

    Node* first = nullptr;
    Node* last = nullptr;

    int elementsCount = 0;

};

int main()
{
    

    return 0;
}