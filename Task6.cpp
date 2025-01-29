#include <iostream>
using namespace std;

template <typename T>
class Node {                                        // Node class to represent each element in the linked list
public:
    T data;                                         // Data stored in the node
    Node* next;                                     // Pointer to the next node

    Node(T data) : data(data), next(nullptr) {}         // Constructor to initialize the node
};


template <typename T>
class LinkedList {                                  // LinkedList class to manage the entire linked list
private:
    Node<T>* head;                            

public:
    LinkedList() : head(nullptr) {}                     // Constructor to initialize an empty list

    void insert(T data) {                                   // Constructor to initialize an empty list
        Node<T>* newNode = new Node<T>(data); 

        if (head == nullptr) {
                                                        // If the list is empty, the new node becomes the head
            head = newNode;
        } else {
            Node<T>* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }


    void print() {                                      // Function to print the contents of the list
        Node<T>* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to free dynamically allocated memory
    ~LinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    LinkedList<int> list;  // Create a linked list of integers

    // Insert integers to list
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    cout << "Linked List: ";
    list.print(); 

    return 0;
}
