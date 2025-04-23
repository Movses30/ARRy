#include <iostream>
#include <vector>
#include <memory> // For unique_ptr

template<typename T>
class MyDec {
private:
    static const size_t BLOCK_SIZE = 4; // Fixed block size
    std::vector<std::vector<T>> m_map; // Map holding blocks of data
    size_t front_index; // Index of the front element
    size_t back_index;  // Index of the back element

public:
    MyDec() : front_index(0), back_index(0) {
        m_map.push_back(std::vector<T>(BLOCK_SIZE)); // Initialize first block
    }

    // Constructor with values
    MyDec(const std::vector<T>& values)
        : front_index(0), back_index(values.size()) {
        size_t count_blocks = (values.size() + BLOCK_SIZE - 1) / BLOCK_SIZE; // Calculate required blocks
        // values.size() = 10 և BLOCK_SIZE = 4, count_blocks = (10 + 4 - 1) / 4 = 3։
        m_map.resize(count_blocks, std::vector<T>(BLOCK_SIZE)); // Resize map to hold blocks

        // Assign values to appropriate blocks
        for (size_t i = 0; i < values.size(); ++i) {
            size_t blockIndex = i / BLOCK_SIZE;
            size_t elementIndex = i % BLOCK_SIZE;
            m_map[blockIndex][elementIndex] = values[i];
        }
    }

    // Display the content of the deque
    void display() const {
        for (size_t block = 0; block < m_map.size(); ++block) {
            for (size_t element = 0; element < BLOCK_SIZE; ++element) {
                if (block * BLOCK_SIZE + element >= front_index && block * BLOCK_SIZE + element < back_index) {
                    std::cout << m_map[block][element] << " ";
                }
            }
        }
        std::cout << std::endl;
    }

    void push_back(const T& value) {
        if (back_index % BLOCK_SIZE == 0) {
            m_map.push_back(std::vector<T>(BLOCK_SIZE)); // Add a new block if needed
        }
        size_t blockIndex = back_index / BLOCK_SIZE;
        size_t elementIndex = back_index % BLOCK_SIZE;
        m_map[blockIndex][elementIndex] = value;
        ++back_index;
    }

    void push_front(const T& value) {
        if (front_index % BLOCK_SIZE == 0) {
            m_map.insert(m_map.begin(), std::vector<T>(BLOCK_SIZE)); // Insert a new block at the front if needed
        }
        --front_index;
        size_t blockIndex = front_index / BLOCK_SIZE;
        size_t elementIndex = front_index % BLOCK_SIZE;
        m_map[blockIndex][elementIndex] = value;
    }

    void pop_back() {
        if (back_index == front_index) {
            std::cerr << "Deque is empty. Cannot pop_back." << std::endl;
            return;
        }
        --back_index;
        if (back_index % BLOCK_SIZE == 0) {
            m_map.pop_back(); // Remove empty block
        }
    }

    void pop_front() {
        if (front_index == back_index) {
            std::cerr << "Deque is empty. Cannot pop_front." << std::endl;
            return;
        }
        ++front_index;
        if (front_index % BLOCK_SIZE == 0) {
            m_map.erase(m_map.begin()); // Remove empty block
        }
    }

    T& front() {
        size_t blockIndex = front_index / BLOCK_SIZE;
        size_t elementIndex = front_index % BLOCK_SIZE;
        return m_map[blockIndex][elementIndex];
    }

    const T& front() const {
        size_t blockIndex = front_index / BLOCK_SIZE;
        size_t elementIndex = front_index % BLOCK_SIZE;
        return m_map[blockIndex][elementIndex];
    }

    T& back() {
        size_t blockIndex = (back_index - 1) / BLOCK_SIZE;
        size_t elementIndex = (back_index - 1) % BLOCK_SIZE;
        return m_map[blockIndex][elementIndex];
    }

    const T& back() const {
        size_t blockIndex = (back_index - 1) / BLOCK_SIZE;
        size_t elementIndex = (back_index - 1) % BLOCK_SIZE;
        return m_map[blockIndex][elementIndex];
    }

    bool empty() const {
        return front_index == back_index;
    }

    size_t size() const {
        return back_index - front_index;
    }
};

int main() {
    // Example usage
    std::vector<int> values = {1, 2, 3, 4, 5, 6, 7, 8};
    MyDec<int> myDec(values);

    std::cout << "Initial contents: ";
    myDec.display();


    return 0;
}

