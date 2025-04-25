
#include <vector>
#include <iostream>

template<typename T>
class MyDec {
private:
    static const size_t BLOCK_SIZE = 4; // Fixed block size
    std::vector<std::vector<T>> m_map; // Map holding blocks of data
    size_t front_index; // Index of the front element
    size_t back_index;  // Index of the back element

public:
    MyDec(); // Default constructor
    MyDec(const std::vector<T>& values); // Constructor with initial values

    void display() const; // Display contents
    void push_back(const T& value); // Add element to the back
    void push_front(const T& value); // Add element to the front
    void pop_back(); // Remove element from the back
    void pop_front(); // Remove element from the front
    T& front(); // Access the front element
    const T& front() const; // Access the front element (const version)
    T& back(); // Access the back element
    const T& back() const; // Access the back element (const version)
    bool empty() const; // Check if deque is empty
    size_t size() const; // Get size of the deque

    class iterator { // Iterator declaration
    private:
        MyDec* container; // Pointer to the container
        size_t index; // Global index in the deque

    public:
        iterator(MyDec* container, size_t index);

        T& operator*(); // Dereference operator
        iterator& operator++(); //increment
        iterator operator++(int); // increment
        iterator& operator--(); // decrement
        iterator operator--(int); // decrement
        bool operator==(const iterator& other) const; // Equality comparison
        bool operator!=(const iterator& other) const; // Inequality comparison
    };

    iterator begin(); // Begin iterator
    iterator end(); // End iterator
};


template<typename T>
MyDec<T>::MyDec() 
    : front_index(0), 
    back_index(0) 
{
    m_map.push_back(std::vector<T>(BLOCK_SIZE)); // Initialize first block
}

template<typename T>
MyDec<T>::MyDec(const std::vector<T>& values)
    : front_index(0), back_index(values.size()) 
{
    size_t count_blocks = (values.size() + BLOCK_SIZE - 1) / BLOCK_SIZE; // Calculate required blocks
    m_map.resize(count_blocks, std::vector<T>(BLOCK_SIZE)); // Resize map to hold blocks

    for (size_t i = 0; i < values.size(); ++i) 
    {
        size_t blockIndex = i / BLOCK_SIZE;
        size_t elementIndex = i % BLOCK_SIZE;
        m_map[blockIndex][elementIndex] = values[i];
    }
}

template<typename T>
void MyDec<T>::display() const 
{
    for (size_t block = 0; block < m_map.size(); ++block) 
    {
        for (size_t element = 0; element < BLOCK_SIZE; ++element) 
        {
            if (block * BLOCK_SIZE + element >= front_index &&
                block * BLOCK_SIZE + element < back_index) 
            {
                std::cout << m_map[block][element] << " ";
            }
        }
    }
    std::cout << std::endl;
}

template<typename T>
void MyDec<T>::push_back(const T& value) 
{
    if (back_index % BLOCK_SIZE == 0) 
    {
        m_map.push_back(std::vector<T>(BLOCK_SIZE)); // Add a new block if needed
    }
    size_t blockIndex = back_index / BLOCK_SIZE;
    size_t elementIndex = back_index % BLOCK_SIZE;
    m_map[blockIndex][elementIndex] = value;
    ++back_index;
}

template<typename T>
void MyDec<T>::push_front(const T& value) 
{
    if (front_index % BLOCK_SIZE == 0) 
    {
        m_map.insert(m_map.begin(), std::vector<T>(BLOCK_SIZE)); // Add a new block at the front if needed
    }
    --front_index;
    size_t blockIndex = front_index / BLOCK_SIZE;
    size_t elementIndex = front_index % BLOCK_SIZE;
    m_map[blockIndex][elementIndex] = value;
}

template<typename T>
void MyDec<T>::pop_back() 
{
    if (back_index == front_index) 
    {
        std::cerr << "Deque is empty. " << std::endl;
        return;
    }
    --back_index;
    if (back_index % BLOCK_SIZE == 0) 
    {
        m_map.pop_back(); // Remove empty block
    }
}

template<typename T>
void MyDec<T>::pop_front() 
{
    if (front_index == back_index) 
    {
        std::cerr << "Deque is empty. " << std::endl;
        return;
    }
    ++front_index;
    if (front_index % BLOCK_SIZE == 0) 
    {
        m_map.erase(m_map.begin()); // Remove empty block
    }
}

template<typename T>
T& MyDec<T>::front() 
{
    size_t blockIndex = front_index / BLOCK_SIZE;
    size_t elementIndex = front_index % BLOCK_SIZE;
    return m_map[blockIndex][elementIndex];
}

template<typename T>
const T& MyDec<T>::front() const 
{
    size_t blockIndex = front_index / BLOCK_SIZE;
    size_t elementIndex = front_index % BLOCK_SIZE;
    return m_map[blockIndex][elementIndex];
}

template<typename T>
T& MyDec<T>::back() 
{
    size_t blockIndex = (back_index - 1) / BLOCK_SIZE;
    size_t elementIndex = (back_index - 1) % BLOCK_SIZE;
    return m_map[blockIndex][elementIndex];
}

template<typename T>
const T& MyDec<T>::back() const 
{
    size_t blockIndex = (back_index - 1) / BLOCK_SIZE;
    size_t elementIndex = (back_index - 1) % BLOCK_SIZE;
    return m_map[blockIndex][elementIndex];
}

template<typename T>
bool MyDec<T>::empty() const 
{
    return front_index == back_index;
}

template<typename T>
size_t MyDec<T>::size() const 
{
    return back_index - front_index;
}

template<typename T>
typename MyDec<T>::iterator MyDec<T>::begin() 
{
    return iterator(this, front_index);
}

template<typename T>
typename MyDec<T>::iterator MyDec<T>::end() 
{
    return iterator(this, back_index);
}

template<typename T>
MyDec<T>::iterator::iterator(MyDec* container, size_t index)
                            : container(container), 
                            index(index) 
{
}

template<typename T>
T& MyDec<T>::iterator::operator*() 
{
    size_t blockIndex = index / BLOCK_SIZE;
    size_t elementIndex = index % BLOCK_SIZE;
    return container->m_map[blockIndex][elementIndex];
}

template<typename T>
typename MyDec<T>::iterator& MyDec<T>::iterator::operator++() 
{
    ++index;
    return *this;
}

template<typename T>
typename MyDec<T>::iterator MyDec<T>::iterator::operator++(int) 
{
    iterator temp = *this;
    ++index;
    return temp;
}

template<typename T>
typename MyDec<T>::iterator& MyDec<T>::iterator::operator--() 
{
    --index;
    return *this;
}

template<typename T>
typename MyDec<T>::iterator MyDec<T>::iterator::operator--(int) 
{
    iterator temp = *this;
    --index;
    return temp;
}

template<typename T>
bool MyDec<T>::iterator::operator==(const iterator& other) const 
{
    return container == other.container && index == other.index;
}

template<typename T>
bool MyDec<T>::iterator::operator!=(const iterator& other) const 
{
    return !(*this == other);
}


int main() {
    std::vector<int> values = {1, 2, 3, 4, 5, 6, 7, 8};
    MyDec<int> myDec(values);

    std::cout << "Initial contents using display: ";
    myDec.display();

    std::cout << "Using  MyDec: ";
    for (auto it = myDec.begin(); it != myDec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}

