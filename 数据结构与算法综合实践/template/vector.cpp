template <typename T>
class Vector {
public:
    Vector() : m_size(0), m_capacity(1), m_data(new T[m_capacity]) {}
    Vector(int size) : m_size(size), m_capacity(size), m_data(new T[m_capacity]) {}
    Vector(int size, const T& val) : m_size(size), m_capacity(size), m_data(new T[m_capacity]) {
        for (int i = 0; i < m_size; i++) {
            m_data[i] = val;
        }
    }
    Vector(const Vector& other) : m_size(other.m_size), m_capacity(other.m_capacity), m_data(new T[m_capacity]) {
        for (int i = 0; i < m_size; i++) {
            m_data[i] = other.m_data[i];
        }
    }
    ~Vector() {
        delete[] m_data;
    }

    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] m_data;
            m_size = other.m_size;
            m_capacity = other.m_capacity;
            m_data = new T[m_capacity];
            for (int i = 0; i < m_size; i++) {
                m_data[i] = other.m_data[i];
            }
        }
        return *this;
    }

    int size() const {
        return m_size;
    }

    int capacity() const {
        return m_capacity;
    }

    bool empty() const {
        return m_size == 0;
    }

    T& operator[](int index) {
        if (index < 0 || index >= m_size) {
            throw std::out_of_range("Index out of range");
        }
        return m_data[index];
    }

    const T& operator[](int index) const {
        if (index < 0 || index >= m_size) {
            throw std::out_of_range("Index out of range");
        }
        return m_data[index];
    }

    void push_back(const T& val) {
        if (m_size == m_capacity) {
            reserve(m_capacity * 2);
        }
        m_data[m_size++] = val;
    }

    void pop_back() {
        if (m_size > 0) {
            m_size--;
        }
    }

    void reserve(int newCapacity) {
        if (newCapacity > m_capacity) {
            T* newData = new T[newCapacity];
            for (int i = 0; i < m_size; i++) {
                newData[i] = m_data[i];
            }
            delete[] m_data;
            m_data = newData;
            m_capacity = newCapacity;
        }
    }

    void resize(int newSize) {
        if (newSize > m_capacity) {
            reserve(newSize);
        }
        for (int i = m_size; i < newSize; i++) {
            m_data[i] = T();
        }
        m_size = newSize;
    }

private:
    int m_size;
    int m_capacity;
    T* m_data;
};
