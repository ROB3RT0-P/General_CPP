#include <iostream>

struct Node 
{
    int data;
    Node* prev;
    Node* next;
    
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList 
{
private:
    Node* head;
    Node* tail;
    
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    
    void append(int val) 
    {
        Node* newNode = new Node(val);
        if (!head) 
        {
            head = tail = newNode;
        } else 
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    void displayForward() 
    {
        Node* current = head;
        while (current) 
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
    
    void displayReverse() 
    {
        Node* current = tail;
        while (current) 
        {
            std::cout << current->data << " ";
            current = current->prev;
        }
        std::cout << std::endl;
    }
    
    ~DoublyLinkedList() 
    {
        Node* current = head;
        while (current) 
        {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() 
{
    DoublyLinkedList myList;

    myList.append(1);
    myList.append(2);
    myList.append(3);
    
    std::cout << "Forward: ";
    myList.displayForward();
    
    std::cout << "Reverse: ";
    myList.displayReverse();
    
    return 0;
}