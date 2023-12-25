#include <functional>
#include <exception>
#include <iostream>
#include <chrono>
#include <fstream>

namespace my {
    // 求C风格字符串长度
    size_t strlen(const char *s) {
        size_t len = 0;
        while (s[len] != '\0') {
            len++;
        }
        return len;
    }

    // 拷贝C风格字符串
    void strcpy(char *dest, const char *src) {
        size_t i = 0;
        while (src[i] != '\0') {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }

    // 判断是否为空白字符
    bool isspace(char c) {
        return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' || c == '\v';
    }

    // 求最小值
    template<typename T>
    T min(const T &a, const T &b) {
        return a < b ? a : b;
    }

    // 求最大值
    template<typename T>
    T max(const T &a, const T &b) {
        return a > b ? a : b;
    }

    // 字符串类
    class string {
    public:

        // 默认构造函数 构造一个不包含任何字符的字符串
        string() : m_data(new char[10]), m_size(0), m_capacity(10) {
            m_data[0] = '\0';
        }

        // 构造函数 从C风格字符串中构造字符串
        string(const char *str) : m_data(new char[my::strlen(str) + 1]), m_size(my::strlen(str)),
                                  m_capacity(my::strlen(str) + 1) {
            my::strcpy(m_data, str);
        }

        // 拷贝构造函数
        string(const string &other) : m_data(new char[other.m_capacity]), m_size(other.m_size),
                                      m_capacity(other.m_capacity) {
            my::strcpy(m_data, other.m_data);
        }

        string(char i) {
            m_data = new char[2];
            m_data[0] = i;
            m_data[1] = '\0';
            m_size = 1;
            m_capacity = 2;
        }

// 析构函数
        ~string() {
            delete[] m_data;
        }

        // 清空字符串
        void erase() {
            delete[] m_data;
            m_data = new char[1];
            m_data[0] = '\0';
            m_size = 0;
            m_capacity = 1;
        }

        // 追加C风格字符串
        void append(const char *str, size_t n) {
            if (m_size + n + 1 > m_capacity) {
                reserve(m_size + n + 1);
            }
            my::strcpy(m_data + m_size, str);
            m_size += n;
            m_data[m_size] = '\0';
        }

        // 复制构造函数
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

        // 追加字符串
        string operator+(const string &other) const {
            string newString;
            newString.m_size = m_size + other.m_size;
            newString.m_capacity = newString.m_size + 1;
            newString.m_data = new char[newString.m_capacity];
            my::strcpy(newString.m_data, m_data);
            my::strcpy(newString.m_data + m_size, other.m_data);
            return newString;
        }

        // 散列仿函数
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

        // 相等运算符
        bool operator==(const string &other) const {
            if (m_size != other.m_size) { // 如果长度不相等 那么直接返回false
                return false;
            }
            for (size_t i = 0; i < m_size; ++i) { // 否则逐个比较字符
                if (m_data[i] != other.m_data[i]) {
                    return false;
                }
            }
            return true;
        }

        bool operator!=(const string &other) const {
            return !(*this == other);
        }

        // 小于运算符
        bool operator<(const string &other) const {
            size_t minSize = min(m_size, other.m_size); // 求最小长度
            for (size_t i = 0; i < minSize; ++i) {
                if (m_data[i] < other.m_data[i]) { // 逐个比较字符
                    return true;
                } else if (m_data[i] > other.m_data[i]) {
                    return false;
                }
            }
            return m_size < other.m_size; // 如果前面的字符都相等 那么长度小的字符串小
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

        // 取出字符串中的字符
        char &operator[](size_t index) {
            return m_data[index];
        }

        // 取出字符串中的字符
        const char &operator[](size_t index) const {
            return m_data[index];
        }

        // 返回字符串长度
        size_t size() const {
            return m_size;
        }

        // 返回字符串容量
        size_t capacity() const {
            return m_capacity;
        }

        // 扩容
        void reserve(size_t new_capacity) {
            if (new_capacity > m_capacity) {
                char *temp = new char[new_capacity];
                my::strcpy(temp, m_data);
                delete[] m_data;
                m_data = temp;
                m_capacity = new_capacity;
            }
        }

        // 重新设置字符串长度
        void resize(size_t new_size) {
            if (new_size > m_capacity) {
                reserve(new_size);
            }
            for (size_t i = m_size; i < new_size; ++i) {
                m_data[i] = '\0';
            }
            m_size = new_size;
        }

        // 在字符串末尾追加字符
        void push_back(char c) {
            if (m_size + 1 > m_capacity) {
                reserve(m_capacity * 2);
            }
            m_data[m_size] = c;
            m_data[m_size + 1] = '\0';
            ++m_size;
        }

        // 返回C风格字符串
        const char *c_str() const {
            return m_data;
        }

        // C++流输出运算符
        friend std::ostream &operator<<(std::ostream &os, const string &str) {
            os << str.m_data;
            return os;
        }

        // C++流输入运算符
        friend std::istream &operator>>(std::istream &is, string &str) {
            char c = '\0'; // 将str中的数据清空
            while (is.get(c) && my::isspace(c)); // 跳过空白字符
            if (is) { // 如果输入流正常
                str.m_size = 0; // 将str中的数据清空
                do {
                    if (str.m_size + 1 >= str.m_capacity) {
                        // 如果空间不足 那么扩容
                        str.reserve(str.m_capacity * 2);
                    }
                    str.m_data[str.m_size] = c;
                    ++str.m_size;
                } while (is.get(c) && !my::isspace(c)); // 读取非空白字符
                str.m_data[str.m_size] = '\0'; // 在末尾添加'\0'
                if (is) is.unget(); // 如果输入流正常 那么将最后读取的字符放回输入流
                else is.clear(is.rdstate() & ~std::ios_base::failbit); // 否则清除错误标志
            }
            return is;
        }

    private:
        char *m_data; // 字符串数据
        size_t m_size; // 字符串长度
        size_t m_capacity; // 字符串容量
    };

    // 自动扩容的数组
    template<typename T>
    class vector {
    public:
        // 默认构造函数
        vector() : m_size(0), m_capacity(1), m_data(new T[m_capacity]) {}

        // 构造函数
        vector(int size) : m_size(size), m_capacity(size), m_data(new T[m_capacity]) {}


        vector(int size, const T &val) : m_size(size), m_capacity(size), m_data(new T[m_capacity]) {
            for (int i = 0; i < m_size; i++) {
                m_data[i] = val;
            }
        }

        // 拷贝构造函数
        vector(const vector &other) : m_size(other.m_size), m_capacity(other.m_capacity), m_data(new T[m_capacity]) {
            for (int i = 0; i < m_size; i++) {
                m_data[i] = other.m_data[i];
            }
        }

        // 析构函数
        ~vector() {
            delete[] m_data;
        }

        // 复制构造函数
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

        // 返回数组大小
        int size() const {
            return m_size;
        }

        // 返回数组容量
        int capacity() const {
            return m_capacity;
        }

        // 判断数组是否为空
        bool empty() const {
            return m_size == 0;
        }

        // 重载下标运算符
        T &operator[](int index) {
            if (index < 0 || index >= m_size) {
                throw std::out_of_range("Index out of range");
            }
            return m_data[index];
        }

        // at函数 超出范围抛出异常
        T &at(int index) {
            if (index < 0 || index >= m_size) {
                throw std::out_of_range("Index out of range");
            }
            return m_data[index];
        }

        // 重载下标运算符返回常引用
        const T &operator[](int index) const {
            if (index < 0 || index >= m_size) {
                throw std::out_of_range("Index out of range");
            }
            return m_data[index];
        }

        // at函数 超出范围抛出异常 返回常引用
        const T &at(int index) const {
            if (index < 0 || index >= m_size) {
                throw std::out_of_range("Index out of range");
            }
            return m_data[index];
        }

        // 返回数组首地址
        T *begin() {
            return m_data;
        }

        // 返回数组尾地址
        T *end() {
            return m_data + m_size;
        }

        // 尾部插入元素
        void push_back(const T &val) {
            if (m_size == m_capacity) {
                reserve(m_capacity * 2);
            }
            m_data[m_size++] = val;
        }

        // 尾部删除元素
        void pop_back() {
            if (m_size > 0) {
                m_size--;
            }
        }

        // 保持足够容量
        void reserve(int newCapacity) {
            // 如果新容量大于当前容量 那么重新分配内存
            if (newCapacity > m_capacity) {
                T *newData = new T[newCapacity]; // 创建新数组
                for (int i = 0; i < m_size; i++) { // 将原数组中的元素拷贝到新数组中
                    newData[i] = m_data[i];
                }
                delete[] m_data; // 释放原数组内存
                m_data = newData; // 将m_data指向新数组
                m_capacity = newCapacity; // 更新容量
            }
        }

        // 重新设置数组大小
        void resize(int newSize) {
            if (newSize > m_capacity) { // 如果新大小大于当前容量 那么扩容
                reserve(newSize);
            }
            for (int i = m_size; i < newSize; i++) { // 将新元素初始化为默认值
                m_data[i] = T();
            }
            m_size = newSize; // 更新大小
        }

    private:
        int m_size; // 数组大小
        int m_capacity; // 数组容量
        T *m_data; // 数组首地址
    };

    struct Word {
        my::string wd;
        int cnt;

        friend std::ostream &operator<<(std::ostream &os, const Word &word) {
            os << std::left << std::setw(20) << word.wd << " " << std::left << std::setw(8) << word.cnt << "\n";
            return os;
        }
    };

    class TrieTree {
    private:
        struct TrieNode {

            TrieNode *next[26]; // 指向下一个节点的指针数组
            int count; // 记录单词出现的次数

            TrieNode() : count(0) { //  构造函数
                for (int i = 0; i < 26; i++) {
                    next[i] = nullptr;
                }
            }
        };

        TrieNode *root; // 根节点
    public:
        TrieTree() { // 构造函数
            root = new TrieNode();
        }

        void insert(string word) { // 插入单词
            TrieNode *p = root; // 从根节点开始
            for (int i = 0; i < word.size(); i++) { // 逐个字符插入
                if (p->next[word[i] - 'a'] == nullptr) { // 如果当前节点的指针为空 那么创建新节点
                    p->next[word[i] - 'a'] = new TrieNode(); // 创建新节点
                }
                p = p->next[word[i] - 'a']; // 指向下一个节点
            }
            p->count++; // 单词出现次数加一
        }

        vector<Word> inorder() {
            vector<Word> res;
            inorder(root, "", res);
            return res;
        }

        void inorder(TrieNode *p, string str, vector<Word> &res) {
            if (p == nullptr) {
                return;
            }
            if (p->count > 0) {
                Word word;
                word.wd = str;
                word.cnt = p->count;
                res.push_back(word);
            }
            for (int i = 0; i < 26; i++) {
                if (p->next[i] != nullptr) {
                    inorder(p->next[i], str + (char) ('a' + i), res);
                }
            }
        }
    };
}


int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

    std::ifstream in1("dict5000.in");
    std::ofstream out("5000.out");

    my::TrieTree tree;
    my::string wd;
    while (in1 >> wd) {
        tree.insert(wd);
    }
    auto res = tree.inorder();
    for (int i = 0; i < res.size(); i++) {
        out << res[i];
    }

    in1.close();
    out.close();
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << "[ms]" << std::endl;
    return 0;
}