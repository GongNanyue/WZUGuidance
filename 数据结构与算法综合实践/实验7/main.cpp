#include <iostream>
#include <fstream>
#include <chrono>
#include <set>


namespace my {
    // ����������
    template<typename T, typename Compare = std::less<T> >
    // Compare Ϊ�ȽϺ����������ڱȽ�����Ԫ�صĴ�С
    class BinaryTree {
    private:
        // �ڵ���
        struct node {
            T data; // ����
            node *left; // ������
            node *right; // ������
            node *parent; // ���ڵ�

            // ���캯��
            explicit node(const T &d, node *l = NULL, node *r = NULL, node *p = NULL) : data(d), left(l), right(r),
                                                                                        parent(p) {}
        };

        node *root; // ���ڵ�
        Compare cmp; // �ȽϺ�������

    public:
        // �չ��캯��
        // ���ڵ�����Ϊ�� ���Ҵ���Ƚ���
        BinaryTree() : root(NULL), cmp(Compare()) {}

        // ��������
        ~BinaryTree() {
            clear();
        }

        // �����
        void clear() {
            clear(root);
        }

        // ��յ�ǰ�ڵ��µ���
        void clear(node *t) {
            if (t == NULL) return;
            clear(t->left);
            clear(t->right);
            delete t;
        }

        // ����Ԫ��
        node *find(const T &x) const {
            return find(x, root);
        }

        // �ڵ�ǰ�ڵ��²���Ԫ��
        node *find(const T &x, node *t) const {
            if (t == NULL || t->data == x) return t; // �����ǰ�ڵ�Ϊ����ô����NULL���ߵ�ǰ�ڵ��ֵ����x ���ص�ǰ�ڵ�
            if (cmp(x, t->data)) return find(x, t->left); // ���xС�ڵ�ǰ�ڵ��ֵ ��ô���������в���
            else return find(x, t->right); // �������������в���
        }

        // �ж��Ƿ����Ԫ��
        bool contain(const T &x) const {
            return find(x) != NULL;
        }

        // ����Ԫ��
        bool insert(const T &x) {
            if (root == NULL) { // ������ڵ�Ϊ�� ��ôֱ�Ӳ���
                root = new node(x); // �����½ڵ�
                return true; // �����½ڵ㷵��true
            }
            node *t = root; // ����Ӹ��ڵ㿪ʼ����
            while (true) {
                if (t->data == x) return false; // �����ԭ���ڵ� ��ô����false
                if (cmp(x, t->data)) { // ���xС�ڵ�ǰ�ڵ��ֵ
                    if (t->left == NULL) { // ���������Ϊ��
                        t->left = new node(x, NULL, NULL, t); // �����½ڵ�
                        return true;
                    }
                    t = t->left; // ����������������в���
                } else {
                    if (t->right == NULL) { // ���������Ϊ��
                        t->right = new node(x, NULL, NULL, t); // �����½ڵ�
                        return true;
                    }
                    t = t->right; // ����������������в���
                }
            }
        }


        bool remove(const T &x) {
            node *t = find(x);
            if (t == NULL) return false;
            if (t->left != NULL && t->right != NULL) {
                node *tmp = t->right;
                while (tmp->left != NULL) tmp = tmp->left; //
                t->data = tmp->data;
                t = tmp;
            }
            node *child = t->left != NULL ? t->left : t->right;
            if (t == root) {
                root = child;
                if (root != NULL) root->parent = NULL;
            } else {
                node *parent = t->parent;
                if (parent->left == t) parent->left = child;
                else parent->right = child;
                if (child != NULL) child->parent = parent;
            }
            delete t;
            return true;
        }
    };

    // ��C����ַ�������
    size_t strlen(const char *s) {
        size_t len = 0;
        while (s[len] != '\0') {
            len++;
        }
        return len;
    }

    // ����C����ַ���
    void strcpy(char *dest, const char *src) {
        size_t i = 0;
        while (src[i] != '\0') {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }

    // �ж��Ƿ�Ϊ�հ��ַ�
    bool isspace(char c) {
        return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' || c == '\v';
    }

    // ����Сֵ
    template<typename T>
    T min(const T &a, const T &b) {
        return a < b ? a : b;
    }

    // �����ֵ
    template<typename T>
    T max(const T &a, const T &b) {
        return a > b ? a : b;
    }

    // �ַ�����
    class string {
    public:

        // Ĭ�Ϲ��캯�� ����һ���������κ��ַ����ַ���
        string() : m_data(new char[10]), m_size(0), m_capacity(10) {
            m_data[0] = '\0';
        }

        // ���캯�� ��C����ַ����й����ַ���
        string(const char *str) : m_data(new char[my::strlen(str) + 1]), m_size(my::strlen(str)),
                                  m_capacity(my::strlen(str) + 1) {
            my::strcpy(m_data, str);
        }

        // �������캯��
        string(const string &other) : m_data(new char[other.m_capacity]), m_size(other.m_size),
                                      m_capacity(other.m_capacity) {
            my::strcpy(m_data, other.m_data);
        }

        // ��������
        ~string() {
            delete[] m_data;
        }

        // ����ַ���
        void erase() {
            delete[] m_data;
            m_data = new char[1];
            m_data[0] = '\0';
            m_size = 0;
            m_capacity = 1;
        }

        // ׷��C����ַ���
        void append(const char *str, size_t n) {
            if (m_size + n + 1 > m_capacity) {
                reserve(m_size + n + 1);
            }
            my::strcpy(m_data + m_size, str);
            m_size += n;
            m_data[m_size] = '\0';
        }

        // ���ƹ��캯��
        string &operator=(const string &other) {
            if (this != &other) {
                char *temp = new char[other.m_capacity];
                my::strcpy(temp, other.m_data);
                delete[] m_data;
                m_data = temp;
                m_size = other.m_size;
                m_capacity = other.m_capacity;
            }
            return *this;
        }

        // ׷���ַ���
        string operator+(const string &other) const {
            string newString;
            newString.m_size = m_size + other.m_size;
            newString.m_capacity = newString.m_size + 1;
            newString.m_data = new char[newString.m_capacity];
            my::strcpy(newString.m_data, m_data);
            my::strcpy(newString.m_data + m_size, other.m_data);
            return newString;
        }

        // ɢ�зº���
        class hash {
        public:
            size_t operator()(const string &str) const {
                size_t hash = 0;
                for (size_t i = 0; i < str.size(); ++i) {
                    hash = hash * 131 + str[i];
                }
                return hash;
            }
        };

        // ��������
        bool operator==(const string &other) const {
            if (m_size != other.m_size) { // ������Ȳ���� ��ôֱ�ӷ���false
                return false;
            }
            for (size_t i = 0; i < m_size; ++i) { // ��������Ƚ��ַ�
                if (m_data[i] != other.m_data[i]) {
                    return false;
                }
            }
            return true;
        }

        bool operator!=(const string &other) const {
            return !(*this == other);
        }

        // С�������
        bool operator<(const string &other) const {
            size_t minSize = min(m_size, other.m_size); // ����С����
            for (size_t i = 0; i < minSize; ++i) {
                if (m_data[i] < other.m_data[i]) { // ����Ƚ��ַ�
                    return true;
                } else if (m_data[i] > other.m_data[i]) {
                    return false;
                }
            }
            return m_size < other.m_size; // ���ǰ����ַ������ ��ô����С���ַ���С
        }

        // operator >
        bool operator>(const string &other) const {
            return other < *this;
        }

        // operator <=
        bool operator<=(const string &other) const {
            return !(other < *this);
        }

        // operator >=
        bool operator>=(const string &other) const {
            return !(*this < other);
        }

        // ȡ���ַ����е��ַ�
        char &operator[](size_t index) {
            return m_data[index];
        }

        // ȡ���ַ����е��ַ�
        const char &operator[](size_t index) const {
            return m_data[index];
        }

        // �����ַ�������
        size_t size() const {
            return m_size;
        }

        // �����ַ�������
        size_t capacity() const {
            return m_capacity;
        }

        // ����
        void reserve(size_t new_capacity) {
            if (new_capacity > m_capacity) {
                char *temp = new char[new_capacity];
                my::strcpy(temp, m_data);
                delete[] m_data;
                m_data = temp;
                m_capacity = new_capacity;
            }
        }

        // ���������ַ�������
        void resize(size_t new_size) {
            if (new_size > m_capacity) {
                reserve(new_size);
            }
            for (size_t i = m_size; i < new_size; ++i) {
                m_data[i] = '\0';
            }
            m_size = new_size;
        }

        // ���ַ���ĩβ׷���ַ�
        void push_back(char c) {
            if (m_size + 1 > m_capacity) {
                reserve(m_capacity * 2);
            }
            m_data[m_size] = c;
            m_data[m_size + 1] = '\0';
            ++m_size;
        }

        // ����C����ַ���
        const char *c_str() const {
            return m_data;
        }

        // C++����������
        friend std::ostream &operator<<(std::ostream &os, const string &str) {
            os << str.m_data;
            return os;
        }

        // C++�����������
        friend std::istream &operator>>(std::istream &is, string &str) {
            char c = '\0'; // ��str�е��������
            while (is.get(c) && my::isspace(c)); // �����հ��ַ�
            if (is) { // �������������
                str.m_size = 0; // ��str�е��������
                do {
                    if (str.m_size + 1 >= str.m_capacity) {
                        // ����ռ䲻�� ��ô����
                        str.reserve(str.m_capacity * 2);
                    }
                    str.m_data[str.m_size] = c;
                    ++str.m_size;
                } while (is.get(c) && !my::isspace(c)); // ��ȡ�ǿհ��ַ�
                str.m_data[str.m_size] = '\0'; // ��ĩβ���'\0'
                if (is) is.unget(); // ������������� ��ô������ȡ���ַ��Ż�������
                else is.clear(is.rdstate() & ~std::ios_base::failbit); // ������������־
            }
            return is;
        }

    private:
        char *m_data; // �ַ�������
        size_t m_size; // �ַ�������
        size_t m_capacity; // �ַ�������
    };

    template<typename T>
    void swap(T &a, T &b) {
        T tmp = a;
        a = b;
        b = tmp;
    }

    // ���ֺ���
    template<class RandomIt, class Compare = std::less<> >
    RandomIt partition(RandomIt first, RandomIt last, Compare comp) {
        RandomIt pivot = last - 1; // ����
        RandomIt i = first; // iָ��С����������һ��Ԫ��
        for (RandomIt j = first; j < pivot; ++j) { //
            if (comp(*j, *pivot)) { // ���jָ���Ԫ��С������
                my::swap(*i, *j); // ����i��jָ���Ԫ��
                ++i; // i����ƶ�һλ
            }
        }
        my::swap(*i, *pivot); // ������ŵ���ȷ��λ��
        return i;
    }

    // ��������
    template<class RandomIt, class Compare = std::less<> >
    // Compare Ϊ�ȽϺ����������ڱȽ�����Ԫ�صĴ�С
    void quickSort(RandomIt first, RandomIt last, Compare comp) {
        if (first < last) { // ���first < last ��ô��������
            RandomIt pivot = my::partition(first, last, comp); // ������
            quickSort(first, pivot, comp); // ����벿������
            quickSort(pivot + 1, last, comp); // ���Ұ벿������
        }
    }


    // �Զ����ݵ�����
    template<typename T>
    class vector {
    public:
        // Ĭ�Ϲ��캯��
        vector() : m_size(0), m_capacity(1), m_data(new T[m_capacity]) {}

        // ���캯��
        vector(int size) : m_size(size), m_capacity(size), m_data(new T[m_capacity]) {}


        vector(int size, const T &val) : m_size(size), m_capacity(size), m_data(new T[m_capacity]) {
            for (int i = 0; i < m_size; i++) {
                m_data[i] = val;
            }
        }

        // �������캯��
        vector(const vector &other) : m_size(other.m_size), m_capacity(other.m_capacity), m_data(new T[m_capacity]) {
            for (int i = 0; i < m_size; i++) {
                m_data[i] = other.m_data[i];
            }
        }

        // ��������
        ~vector() {
            delete[] m_data;
        }

        // ���ƹ��캯��
        vector &operator=(const vector &other) {
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

        // ���������С
        int size() const {
            return m_size;
        }

        // ������������
        int capacity() const {
            return m_capacity;
        }

        // �ж������Ƿ�Ϊ��
        bool empty() const {
            return m_size == 0;
        }

        // �����±������
        T &operator[](int index) {
            if (index < 0 || index >= m_size) {
                throw std::out_of_range("Index out of range");
            }
            return m_data[index];
        }

        // at���� ������Χ�׳��쳣
        T &at(int index) {
            if (index < 0 || index >= m_size) {
                throw std::out_of_range("Index out of range");
            }
            return m_data[index];
        }

        // �����±���������س�����
        const T &operator[](int index) const {
            if (index < 0 || index >= m_size) {
                throw std::out_of_range("Index out of range");
            }
            return m_data[index];
        }

        // at���� ������Χ�׳��쳣 ���س�����
        const T &at(int index) const {
            if (index < 0 || index >= m_size) {
                throw std::out_of_range("Index out of range");
            }
            return m_data[index];
        }

        // ���������׵�ַ
        T *begin() {
            return m_data;
        }

        // ��������β��ַ
        T *end() {
            return m_data + m_size;
        }

        // β������Ԫ��
        void push_back(const T &val) {
            if (m_size == m_capacity) {
                reserve(m_capacity * 2);
            }
            m_data[m_size++] = val;
        }

        // β��ɾ��Ԫ��
        void pop_back() {
            if (m_size > 0) {
                m_size--;
            }
        }

        // �����㹻����
        void reserve(int newCapacity) {
            // ������������ڵ�ǰ���� ��ô���·����ڴ�
            if (newCapacity > m_capacity) {
                T *newData = new T[newCapacity]; // ����������
                for (int i = 0; i < m_size; i++) { // ��ԭ�����е�Ԫ�ؿ�������������
                    newData[i] = m_data[i];
                }
                delete[] m_data; // �ͷ�ԭ�����ڴ�
                m_data = newData; // ��m_dataָ��������
                m_capacity = newCapacity; // ��������
            }
        }

        // �������������С
        void resize(int newSize) {
            if (newSize > m_capacity) { // ����´�С���ڵ�ǰ���� ��ô����
                reserve(newSize);
            }
            for (int i = m_size; i < newSize; i++) { // ����Ԫ�س�ʼ��ΪĬ��ֵ
                m_data[i] = T();
            }
            m_size = newSize; // ���´�С
        }

    private:
        int m_size; // �����С
        int m_capacity; // ��������
        T *m_data; // �����׵�ַ
    };
}


struct Car {
    my::string id;
    my::string name;

    Car() {}

    Car(const my::string &id, const my::string &name) : id(id), name(name) {}


    bool operator==(const Car &rhs) const {
        return id == rhs.id;
    }

    bool operator!=(const Car &rhs) const {
        return !(rhs == *this);
    }

    bool operator<(const Car &rhs) const {
        return id < rhs.id;
    }

    bool operator>(const Car &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const Car &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const Car &rhs) const {
        return !(*this < rhs);
    }
};


int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

    std::ifstream in1("Car100000000.in"), in2("Car100000000_s.in");
    std::ofstream out("100000000.out");

    my::BinaryTree<Car> s;
    Car c;
    while (in1 >> c.id >> c.name) {
        s.insert(c);
    }

    my::string id;
    while (in2 >> id) {
        auto it = s.find(Car(id, my::string()));
        if (it != nullptr) {
            out << id << " " << it->data.name << "\n";
        } else {
            out << id << " " << "***" << "\n";
        }
    }


    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << "[ms]" << std::endl;
    return 0;
}