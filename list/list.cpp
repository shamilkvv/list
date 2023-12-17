#include <iostream>


template<typename T>
class List
{
private:

    struct Node  //узлы
    {
        T element;
        Node* prev = nullptr;
        Node* next = nullptr;

    };

    Node* first = nullptr;
    Node* last = nullptr;

    size_t elementsCount = 0;


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

    void PushBack(const T& elem)   //добавление в конец
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

    

    void PushFront(const T& elem)   //добавление в начало 
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

   
    void PopBack()   //удаление с конца
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


    void PopFront()     //удаление с начала
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


    size_t Size()const      //текущее кол-во элементов
    {
        return elementsCount;
    }

    

    void clear()    // метод для очищения списка
    {
        while (elementsCount > 0)
        {
            PopBack();
        }
    }

    List& operator= (const List& l)     // оператор присваивания
    {
        clear();

        Node* node;
        for (node = l.first; node != nullptr; node = node->next)
        {
            PushBack(node->element);
        }

        elementsCount = l.elementsCount;

        return *this;
    }

    const T& Front()const
    {
        return first->element;
    }


    bool Empty()const
    {
        return first == nullptr;
    }

    ~List()
    {
        clear();
    }
};

    


int main()
{

    
    return 0;
}