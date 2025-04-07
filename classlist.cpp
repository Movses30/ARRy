#include <iostream>

template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;
        Node* start;
        Node(const T& data) : data(data), next(NULL), start(NULL) {}
    };

    Node* head; // | hed | data<body>| nextptr |  
                // |x_009|   value   |  x_012  |
    Node* nextPtr;
    size_t list_size;

public:
    // Constructor
    List() 
        : head(NULL), 
        nextPtr(NULL), 
        list_size(0)
    {
    }

    // Destructor
    ~List()
    {
        for (Node* temp = head; head != NULL; temp = head) 
        {
            head = head->next;
            delete temp;
        }
    }

    // Push operations
    void push_back(const T& value) 
    {
        Node* newNode = new Node(value);
        if (!nextPtr) 
        {
            head = nextPtr = newNode;
        }
        else 
        {
            nextPtr->next = newNode;
            newNode->start = nextPtr;
            nextPtr = newNode;
        }
        ++list_size;
    }

    void push_front(const T& value) 
    {
        Node* newNode = new Node(value);
        if (!head) 
        {
            head = newNode;
            nextPtr = newNode;
        }
        else 
        {
            head->start = newNode;
            newNode->next = head;
            head = newNode;
        }
        ++list_size;
    }

    // Pop operations
    void pop_back() 
    {
        if (!nextPtr) 
            return;
        Node* temp = nextPtr;
        nextPtr = nextPtr->start;
        if (nextPtr) 
            nextPtr->next = NULL;
        else
            head = NULL;
        delete temp;
        --list_size;
    }

    void pop_front() 
    {
        if (!head) 
            return;
        Node* temp = head;
        head = head->next;
        if (head) 
            head->start = NULL;
        else 
            nextPtr = NULL;
        delete temp;
        --list_size;
    }

    // Access operations
    T& front() 
    {
        if (!head) 
            throw std::out_of_range("List is empty");
        return 
            head->data;
    }

    T& back() 
    {
        if (!nextPtr) 
            throw std::out_of_range("List is empty");
        return 
            nextPtr->data;
    }

    // Size management
    size_t size() const 
    {
        return list_size;
    }

    bool empty() const 
    {
        return list_size == 0;
    }

    // Insertion operations
    void insert(size_t index, const T& value) 
    {
        if (index > list_size) 
            throw std::out_of_range("Index out of range");
        if (index == 0) 
        {
            push_front(value);
            return;
        }
        if (index == list_size) 
        {
            push_back(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* current = head;
        for (size_t i = 0; i < index; ++i) 
        {
            current = current->next;
        }
        newNode->next = current;
        newNode->start = current->start;
        current->start->next = newNode;
        current->start = newNode;
        ++list_size;
    }

    void insert(Node* index, const T& value) 
    {
        if (!index) 
            throw std::invalid_argument("Invalid indexition");
        Node* newNode = new Node(value);// create new area for new elem 
        newNode->next = index->next;  // newNods next assigne oldnode ntxtptr 
        newNode->start = index;       // oldptr assigne newstr first
        if (index->next)
            index->next->start = newNode;
        index->next = newNode;
        if (index == nextPtr) 
            nextPtr = newNode;
        ++list_size;
    }

    // Deletion operations
    void erase(size_t index) 
    {
        if (index >= list_size) 
            throw std::out_of_range("Index out of range");
        if (index == 0) {
            pop_front();
            return;
        }
        if (index == list_size - 1) 
        {
            pop_back();
            return;
        }
        Node* current = head;
        for (size_t i = 0; i < index; ++i) 
        {
            current = current->next;
        }
        current->start->next = current->next;
        current->next->start = current->start;
        delete current;
        --list_size;
    }

    // Reverse list
    void reverse() 
    {
        Node* current = head;
        Node* temp = NULL;
        while (current) 
        {
            //svap
            temp = current->start;
            current->start = current->next;
            current->next = temp;
            current = current->start;
        }
        if (temp) {
            head = temp->start;
        }
    }


    class iterator 
    {
    private:
        Node* node;
    public:
        iterator(Node* node) 
            : node(node) 
        {
        }

        T& operator*() 
        { 
            return node->data; 
        }
        iterator& operator++()
        {
            node = node->next;
            return *this;
        }
        bool operator!=(const iterator& other) const {
            return node != other.node;
        }
    };
    iterator begin() const {
        return iterator(head);
    }

    iterator end() const {
        return iterator(nullptr);
    }

    // Merge 
    void merge(List& other) 
    {
        if (this == &other) // if &other is ecual this noting marge
            return;
        if (!other.head) 
            return;
        if (!head) 
        {
            head = other.head;
            nextPtr = other.nextPtr;
        } 
        else 
        {
            nextPtr->next = other.head;
            other.head->start = nextPtr;
            nextPtr = other.nextPtr;
        }
        list_size += other.list_size;
        other.head =  NULL;
        other.nextPtr = NULL;
        other.list_size = 0;
    }
        //splice 
    void splice(Node* index, List& other) {
        if (this == &other || !index || !other.head) 
            return;
        if (index == nextPtr) {
            merge(other);//
            return;
        }
        Node* next_node = index->next;
        index->next = other.head;
        other.head->start = index;
        other.nextPtr->next = next_node;
        if (next_node) next_node->start = other.nextPtr;
        list_size += other.list_size;
        other.head = other.nextPtr = NULL;
        other.list_size = 0;
    }
};

int main() {
    List<int> list;
    list.push_back(1);
    list.push_back(3);
    list.push_back(2487);
    list.push_back(267);
    list.push_back(254);
    list.push_back(232);
    list.push_back(1111);
    list.push_back(2);
    list.push_front(0);

    std::cout << "Front: " << list.front() << std::endl;
    std::cout << "Back: " << list.back() << std::endl;


    std::cout << "Size: " << list.size() << std::endl;
    std::cout << "Empty: " << list.empty() << std::endl;

    list.insert(1, 5);
    list.erase(1);

    list.reverse();

    for ( List<int>::iterator it = list.begin(); it != list.end(); ++it)
    {
        std::cout << " it \t "<<*it << std::endl;
    }

    return 0;
}

