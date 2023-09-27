//
//  main.cpp
//  Data_Structures
//
//  Robert Parry on 16/09/2023.
//

#include <iostream>

class Node
{
    public:
        int data;
        Node* next;
        Node* prev;
        
        Node(int data) {
            this->data = data;
            this->next = nullptr;
            this->prev = nullptr;
        }
};


class LinkedList
{
    private:
        Node* head;
        
    public:
        LinkedList()
        {
            head = nullptr;
        }
        
        void insert(int data)
        {
            Node* newNode = new Node(data);
            newNode->next = head;
            head = newNode;
        }
        
        void print()
        {
            Node* current = head;
            while (current != nullptr)
            {
                std::cout << current->data << " ";
                current = current->next;
                
            }
            std::cout << std::endl;
        }
};

class DoublyLinkedList
{
    private:
    Node* head;
    Node* tail;
    
    public:
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }
    
    void insert(int data)
    {
        Node* newNode = new Node(data);
        if(!head) {
            head = newNode;
            tail = newNode;
        } else
        {
            tail ->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
        
    void printForward() {
        Node* current = head;
            while (current != nullptr) {
                std::cout << current->data << " ";
                current = current->next;
            }
            std::cout << std::endl;
        }

    void printBackward() {
        Node* current = tail;
            while (current != nullptr) {
                std::cout << current->data << " ";
                current = current->prev;
            }
            std::cout << std::endl;
        }
};

int main(int argc, const char * argv[])
    {
    LinkedList robsList;
    
    robsList.insert(1);
    robsList.insert(2);
    robsList.insert(3);
    robsList.insert(4);
    robsList.insert(5);

    std::cout << "Finished inserting data!" << std::endl;
    
    robsList.print();
    
    return 0;
}
