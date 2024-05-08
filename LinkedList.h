#pragma once

#include <iostream>

template<class T>
class LinkedList
{
    struct Node
    {
        T data;
        Node* pNext;

        Node(T data, Node* pNext = nullptr) : data(data), pNext(pNext) {}
    };

    Node* head;
    Node* tail;
    int count;

    /**
     * Удаляет указанный элемент из списка.
     *
     * @param node элемент, который нужно удалить
     */
    void remove_node(Node* node)
    {
        Node* prev = node->pNext;
        Node* next = node->pNext->pNext;

        delete node;

        if (prev)
        {
            prev->pNext = next;
            if (next == nullptr)
            {
                tail = prev;
            }
        }
        else
        {
            head = next;
            if (next == nullptr)
            {
                tail = nullptr;
            }
        }

        count--;
    }

public:
    LinkedList()
    {
        count = 0;
        head = nullptr;
        tail = nullptr;
    }

    ~LinkedList()
    {
        while (head != nullptr)
        {
            Node* current = head;
            head = head->pNext;
            delete current;
        }
    }

    int size() const { return count; }
    bool is_empty() const { return count == 0; }

    /**
     * Добавляет элемент в конец списка
     * @param data указатель на данные
     */
    void push_back(T data)
    {
        count++;
        if (tail == nullptr)
        {
            head = new Node(data);
            tail = head;
            return;
        }

        tail->pNext = new Node(data);
        tail = tail->pNext;
    }

    /**
     * Добавляет элемент в начало списка
     * @param data указатель на данные
     */
    void push_front(T data)
    {
        count++;
        if (head == nullptr)
        {
            head = new Node(data);
            tail = head;
            return;
        }

        Node* new_head = new Node(data);
        new_head->pNext = head;
        head = new_head;
    }

    /**
     * Удаляет первый элемент списка
     */
    void remove_first()
    {
        if (is_empty()) return;

        Node* current = head;
        head = head->pNext;
        delete current;
        count--;
    }

    /**
     * Удаляет последний элемент списка
     */
    void remove_last()
    {
        if (is_empty()) return;

        if (head == tail)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node* current = head;
            while (current->pNext != tail)
            {
                current = current->pNext;
            }

            delete tail;
            tail = current;
            tail->pNext = nullptr;
        }

        count--;
    }

    /**
     * Удаляет элемент по индексу
     * @param ind индекс элемента
     */
    void remove_at(int ind)
    {
        //список пустой
        if (is_empty())
            return;

        //ошибка индекса
        else if (ind < 0 || ind >= size())
            return;

        //если нужно удалить первый элемент
        else if (ind == 0)
        {
            remove_first();
            return;
        }
        //если нужно удалить последний элемент
        else if (ind == size() - 1)
        {
            remove_last();
            return;
        }
        //если нужно удалить элемент где-то
        Node* current = head;
        for (int i = 0; i < ind; i++)
        {
            current = current->pNext;
        }

        remove_node(current);
    }

    /**
     * Очищает список
     */
    void clear()
    {
        while (head != nullptr)
        {
            Node* current = head;
            head = head->pNext;
            delete current;
        }

        count = 0;
        head = nullptr;
        tail = nullptr;
    }

    /**
     * Сортирует список
     */
    void sort()
    {
        if (count < 2) return;

        Node* current = head;
        while (current->pNext != nullptr)
        {
            Node* next = current->pNext;
            if (current->data > next->data)
            {
                std::swap(current->data, next->data);
            }

            current = next;
        }
    }

    /**
     * Выводит список в консоль
     */
    void print() const
    {
        if (head == nullptr)
        {
            std::cout << "LinkedList is empty.";
        }

        Node* current = this->head;
        while (current)
        {
            T curr = current->data;
            std::cout << curr << std::endl;
            current = current->pNext;
        }
    }

    /**
     * Находит индекс элемента, который содержит определенное количество треков
     * @param tr_num количество треков
     * @return индекс элемента или -1, если такого элемента нет
     */
    int find_by_tracks(const int tr_num)
    {
        if (is_empty()) return -1;

        int counter = 0;
        Node* current = head;
        while (current)
        {
            if (current->data.getTracks() == tr_num)
            {
                return counter;
            }

            counter++;
            current = current->pNext;
        }

        return -1;
    }

    /**
     * Оператор [], возвращает указатель на данные, содержащиеся в указанном элементе
     * @param index индекс элемента
     * @return указатель на данные или nullptr, если индекс некорректен
     */
    T& operator[](int index)
    {
        if (is_empty() || index < 0 || index >= size())
        {
            std::cout << "Index out of range!" << std::endl;
            
        }

        Node* current = head;
        for (int i = 0; i < index; i++)
        {
            current = current->pNext;
        }
        return current->data;
    }
};



