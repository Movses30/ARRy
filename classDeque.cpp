#include <iostream>
#include <stdexcept>

template <typename Type>
class Deque 
{
private:
    Type* data;
    size_t capacity;
    size_t frontIndex;
    size_t backIndex;
    size_t count;

    void resize() 
    {
        size_t newCapacity = capacity * 2;// new capacity
        Type* newData = new Type[newCapacity];// new arr whit new capacity

        for (size_t i = 0; i < count; ++i) 
        {// add i is point to block [appropriate block elem ]
            newData[i] = data[(frontIndex + i) % capacity];
        }

        delete[] data;// deleted old arry
        data = newData;// asigne newData 
        capacity = newCapacity;// asigne new capacity
        frontIndex = 0;
        backIndex = count;
    }

public:
    // Default Constructor
    Deque()
        : capacity(10),
          frontIndex(0),
          backIndex(0),
          count(0) 
    {
        data = new Type[capacity];
    }

    // Destructor
    ~Deque() 
    {
        delete[] data;// clear memory
    }

    // Push Operations
    void push_back(const Type& value) 
    {
        if (count == capacity) 
        {
            resize();
        }
        data[backIndex] = value;
        backIndex = (backIndex + 1) % capacity;
        ++count;
    }

    void push_front(const Type& value) 
    {
        if (count == capacity) 
        {
            resize();
        }
        if (frontIndex == 0)
            frontIndex = capacity - 1;
        else
            frontIndex = frontIndex - 1;
        data[frontIndex] = value;
        ++count;
    }

    // Pop Operations
    Type pop_back() 
    {
        if (count == 0) 
        {
            throw std::out_of_range("Deque is empty");
        }
        if (backIndex == 0)
            backIndex = capacity - 1;
        else
            backIndex = backIndex - 1;
        Type value = data[backIndex];
        --count;
        return value;
    }

    Type pop_front() 
    {
        if (count == 0) 
        {
            throw std::out_of_range("Deque is empty");
        }
        Type value = data[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        --count;
        return value;
    }

    // Size Management
    size_t size() const 
    {
        return count;
    }

    bool empty() const 
    {
        return count == 0;
    }

    // Access Operations
    Type& front() 
    {
        if (count == 0) 
        {
            throw std::out_of_range("Deque is empty");
        }
        return data[frontIndex];
    }

    Type& back() 
    {
        if (count == 0) 
        {
            throw std::out_of_range("Deque is empty");
        }
        size_t index;
        if (backIndex == 0) 
        {
            index = capacity - 1;
        } 
        else 
        {
            index = backIndex - 1;
        }

        return data[index];
    }
    class Iterator {
    private:
        Type* ptr;
    public:
        Iterator(Type* p) : ptr(p) {}

        Type& operator*() {
            return *ptr;
        }

        Iterator& operator++() {
            ++ptr;
            return *this;
        }

        Iterator operator++(int) {
            Iterator temp = *this;
            ++ptr;
            return temp;
        }

        bool operator!=(const Iterator& other) const {
            return ptr != other.ptr;
        }
    };

    Iterator begin() {
        return Iterator(&data[frontIndex]);
    }

    Iterator end() {
        return Iterator(&data[backIndex]);
    }
};

int main() {
    Deque<int> deque;

    // Push operations
    deque.push_back(10);
    deque.push_front(20);
    deque.push_back(30);
    deque.push_back(30);
    deque.push_back(30);
    deque.push_back(30);
    deque.push_back(30);
    deque.push_back(30);

    // Access operations
    std::cout << "Front: " << deque.front() << std::endl;
    std::cout << "Back: " << deque.back() << std::endl;

    // Pop operations
    std::cout << "Pop back: " << deque.pop_back() << std::endl;
    std::cout << "Pop front: " << deque.pop_front() << std::endl;

    // Size management
    std::cout << "Size: " << deque.size() << std::endl;
    std::cout << "Is empty: " << (deque.empty() ? "Yes" : "No") << std::endl;


    std::cout << "Elements in deque: ";
    for (auto it = deque.begin(); it != deque.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;


    return 0;
}

