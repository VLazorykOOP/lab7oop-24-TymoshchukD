#include <iostream>

template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    // Nested Iterator class
    class Iterator {
    private:
        Node* current;

    public:
        Iterator(Node* node) : current(node) {}

        // Dereference operator
        T& operator*() {
            return current->data;
        }

        // Pre-increment
        Iterator& operator++() {
            if (current) current = current->next;
            return *this;
        }

        // Inequality comparison
        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
    };

    List() : head(nullptr), tail(nullptr) {}

    ~List() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Add element to the end
    void push_back(const T& value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Get iterator to the beginning
    Iterator begin() const {
        return Iterator(head);
    }

    // Get iterator to the end (nullptr)
    Iterator end() const {
        return Iterator(nullptr);
    }

    // Print all elements using iterator
    void print() const {
        for (Iterator it = begin(); it != end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
};

// Example usage
int main() {
    List<int> intList;
    intList.push_back(10);
    intList.push_back(20);
    intList.push_back(30);

    std::cout << "Integer list: ";
    intList.print();

    List<const char*> strList;
    strList.push_back("apple");
    strList.push_back("banana");
    strList.push_back("cherry");

    std::cout << "String list: ";
    strList.print();

    return 0;
}
