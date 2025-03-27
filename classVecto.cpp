#include <iostream>
#include <stdexcept>

class intVector
{
private:
    int* data;
    size_t capacityV;
    size_t sizeV;

public:
    // Constructor
    intVector()
        : data(nullptr),
        capacityV(0),
        sizeV(0)
    {
    }

    // Destructor
    ~intVector() 
    {
        delete[] data;
    }

    // Copy Constructor
    intVector(const intVector& other)
        : data(new int[other.capacityV]),
        capacityV(other.capacityV),
        sizeV(other.sizeV) 
    {
        for (size_t i = 0; i < sizeV; ++i) 
        {
            data[i] = other.data[i];
        }
    }

    // Move Constructor
     /*The double && indicates that the other object is a move reference. 
     Move references allow the resources of an object to be moved to another object without copying them.*/ 
    intVector(intVector&& other) noexcept
        : data(other.data),
        capacityV(other.capacityV),
        sizeV(other.sizeV) 
    {
        other.data = nullptr;
        other.capacityV = 0;
        other.sizeV = 0;
    }

    // Copy Assignment Operator
    intVector& operator=(const intVector& other) 
    {
        if (this != &other) 
        {
            delete[] data;
            capacityV = other.capacityV;
            sizeV = other.sizeV;
            data = new int[capacityV];
            for (size_t i = 0; i < sizeV; ++i) 
            {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // Move Assignment Operator
    intVector& operator=(intVector&& other) noexcept 
    {
        if (this != &other) 
        {
            delete[] data;
            data = other.data;
            capacityV = other.capacityV;
            sizeV = other.sizeV;
            other.data = nullptr;
            other.capacityV = 0;
            other.sizeV = 0;
        }
        return *this;
    }

    // Push Back
    void push_back(int value)
    {
        if (sizeV == capacityV)
        {
            size_t newCapacity;
            if (capacityV == 0)
            {
                newCapacity = 1; // assign 1 for adding e
            }
            else
            {
                newCapacity = capacityV * 2;
            }

            reserve(newCapacity);
        }
        data[sizeV++] = value;
    }

    // Pop Back
    void pop_back()
    {
        if (sizeV > 0)
        {
            sizeV--;
        }
    }

    // Access Operations
    int& operator[](int index) 
    {
        return data[index];
    }

    int& at(size_t index) 
    {
        if (index >= sizeV) 
        {
            throw std::out_of_range("Index out of bounds");// help internet
        }
        return data[index];
    }

    int front() 
    {
        if (sizeV > 0) 
        {
            return data[0];
        } else {
            throw std::out_of_range("Vector is empty");
        }
    }

    int back() const 
    {
        if (sizeV > 0) 
        {
            return data[sizeV - 1];
        } else {
            throw std::out_of_range("Vector is empty");
        }
    }

    // Size & Capacity Management
    size_t size() const
    {
        return sizeV;
    }

    size_t capacity() const 
    {
        return capacityV;
    }

    bool empty() const 
    {
        return sizeV == 0;
    }

    void reserve(size_t new_capacity) 
    {
        if (new_capacity > capacityV) 
        {
            int* new_data = new int[new_capacity];
            for (size_t i = 0; i < sizeV; ++i) 
            {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
            capacityV = new_capacity;
        }
    }


    void resize(size_t new_size) 
    {
        if (new_size > capacityV) 
        {
            reserve(new_size);
        }
        sizeV = new_size;
    }

    int* begin() 
    {
        return data;
    }

    int* end() 
    {
        return data + sizeV;
    }

    int* rbegin() 
    {
        return data + sizeV - 1;
    }

    int* rend() 
    {
        return data - 1;
    }
};

int main() {
    intVector v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(9);

    intVector B(v); // use Copy Constructor-ը

    for (auto elem : B)
        std::cout << " elem \t " << elem << std::endl;

    for (auto it = v.begin(); it != v.end(); it++) {
        std::cout << " it \t " << *it << std::endl;
    }
    std::cout << "Size: " << v.size() << ", Capacity: " << v.capacity() << std::endl;

    // Test front,  and pop_back
    std::cout << "Front: " << v.front() << ", Back: " << v.back() << std::endl;
    v.pop_back();

    std::cout << "Size after pop_back: " << v.size() << std::endl;

    return 0;
}
