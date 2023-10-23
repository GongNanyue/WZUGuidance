#include <functional>
#include <fstream>
#include <chrono>
#include <iostream>

namespace my {
    // 二叉搜索树
    template<typename T, typename Compare = std::less<T> >
    // Compare 为比较函数对象，用于比较两个元素的大小
    class BinaryTree {
    private:
        // 节点类
        struct node {
            T data; // 数据
            node *left; // 左子树
            node *right; // 右子树
            node *parent; // 父节点

            // 构造函数
            explicit node(const T &d, node *l = NULL, node *r = NULL, node *p = NULL) : data(d), left(l), right(r),
                                                                                        parent(p) {}
        };

        node *root; // 根节点
        Compare cmp; // 比较函数对象

    public:
        // 空构造函数
        // 将节点设置为空 并且传入比较器
        BinaryTree() : root(NULL), cmp(Compare()) {}

        // 析构函数
        ~BinaryTree() {
            clear();
        }

        // 清空树
        void clear() {
            clear(root);
        }

        // 清空当前节点下的树
        void clear(node *t) {
            if (t == NULL) return;
            clear(t->left);
            clear(t->right);
            delete t;
        }

        // 查找元素
        node *find(const T &x) const {
            return find(x, root);
        }

        // 在当前节点下查找元素
        node *find(const T &x, node *t) const {
            if (t == NULL || t->data == x) return t; // 如果当前节点为空那么返回NULL或者当前节点的值等于x 返回当前节点
            if (cmp(x, t->data)) return find(x, t->left); // 如果x小于当前节点的值 那么在左子树中查找
            else return find(x, t->right); // 否则在右子树中查找
        }

        // 判断是否包含元素
        bool contain(const T &x) const {
            return find(x) != NULL;
        }

        // 插入元素
        bool insert(const T &x) {
            if (root == NULL) { // 如果根节点为空 那么直接插入
                root = new node(x); // 创建新节点
                return true; // 创建新节点返回true
            }
            node *t = root; // 否则从根节点开始查找
            while (true) {
                if (t->data == x) return false; // 如果有原来节点 那么返回false
                if (cmp(x, t->data)) { // 如果x小于当前节点的值
                    if (t->left == NULL) { // 如果左子树为空
                        t->left = new node(x, NULL, NULL, t); // 创建新节点
                        return true;
                    }
                    t = t->left; // 否则继续在左子树中查找
                } else {
                    if (t->right == NULL) { // 如果右子树为空
                        t->right = new node(x, NULL, NULL, t); // 创建新节点
                        return true;
                    }
                    t = t->right; // 否则继续在右子树中查找
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
        string() : m_data(new char[1]), m_size(0), m_capacity(1) {
            m_data[0] = '\0';
        }

        // 构造函数 从C风格字符串中构造字符串
        explicit string(const char *str) : m_data(new char[my::strlen(str) + 1]), m_size(my::strlen(str)),
                                           m_capacity(my::strlen(str) + 1) {
            my::strcpy(m_data, str);
        }

        // 拷贝构造函数
        string(const string &other) : m_data(new char[other.m_capacity]), m_size(other.m_size),
                                      m_capacity(other.m_capacity) {
            my::strcpy(m_data, other.m_data);
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
                    if (str.m_size + 1 > str.m_capacity) { // 如果空间不足 那么扩容
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
}

struct stu {
    my::string id;
    int score;
    int rank;
    int sameRank;

    stu() {}

    stu(const my::string &id, int score, int rank, int sameRank)
            : id(id), score(score), rank(rank), sameRank(sameRank) {}

    bool operator==(const stu &rhs) const {
        return id == rhs.id;
    }

    bool operator!=(const stu &rhs) const {
        return !(rhs == *this);
    }

    bool operator<(const stu &rhs) const {
        return id < rhs.id;
    }
};

int main() {
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

    std::ifstream data("P04_TextData500.in");
    std::ifstream query("P04_TextData500b.in");
    std::ofstream output("500.out");
    my::BinaryTree<stu> tree; // 创建二叉搜索树
    stu s; // 创建学生对象
    while (data >> s.id >> s.score >> s.rank >> s.sameRank) { // 读取数据
        tree.insert(s); // 插入数据
    }
    my::string id; // 创建学号字符串
    while (query >> id) { // 读取查询
        auto it = tree.find(stu(id, 0, 0, 0)); // 查找学号
        if (it != NULL) { // 如果找到
            output << it->data.id << " " << it->data.score << " " << it->data.rank << " " << it->data.sameRank << "\n";
        } else { // 否则输出not found
            output << "not found" << std::endl;
        }
    }

    data.close();
    query.close();
    output.close();
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms"
              << std::endl;
    return 0;
}