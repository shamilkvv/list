#include <iostream>


template<typename T>
class List
{
private:

    //узел

    struct Node
    {
        T element;
        Node* prev = nullptr;
        Node* next = nullptr;

    };

    Node* first = nullptr;
    Node* last = nullptr;

    int elementsCount = 0;


public:
    List() {} // конструктор 

    List(const List<T>& l) //конструктор копирования 
    {
        elementsCount = l.elementsCount;

        for (Node* temp = l.first; temp != nullptr; temp = temp->next)
        {
            PushBack(temp->element);
        }

    }

    //добавление в конец

    void PushBack(const T& elem)
    {
        Node* node = new Node(elem, last, nullptr);

        if (last != nullptr)
        {
            last->next = node;
        }

        else
        {
            first = node;
        }

        last = node;
        ++elementsCount;
    }

    //добавление в начало 

    void PushFront(const T& elem)
    {
        Node* node = new Node(elem, first, nullptr);

        if (first != nullptr)
        {
            first->prev = node;
        }

        else
        {
            last = node;
        }

        first = node;
        ++elementsCount;

    }

    //удаление с конца

    void PopBack()
    {
        if (last != nullptr)
        {
            Node* temp = last;
            last = last->prev;

            if (last != nullptr)
            {
                last->next = nullptr; 
            }

            else
            {
                first = nullptr;
            }

            delete temp;
            elementsCount--;
        }

    }

    //удаление с начала

    void PopFront()
    {
        if (first != nullptr)
        {
            Node* temp = first;
            first = first->next;

            if (first != nullptr)
            {
                first->prev = nullptr;
            }

            else
            {
                last = nullptr;
            }

            delete temp;
            elementsCount--;

        }

    }

    //текущее кол-во элементов

    size_t Size()const
    {
        return elementsCount;
    }
};

int main()
{

    
    return 0;
}