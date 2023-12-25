#include <bits/stdc++.h>
using ll = long long;


namespace my {

    bool isspace(char c) {
        return c == ' ' || c == '\n' || c == '\t' || c == '\r' || c == '\v' || c == '\f';
    }

    char *strcpy(char *__dst, const char *__src) {
        char *temp = __dst;
        while (*__src != '\0') {
            *__dst = *__src;
            ++__dst;
            ++__src;
        }
        *__dst = '\0';
        return temp;
    }

    size_t strlen(const char *__str) {
        size_t len = 0;
        while (*__str != '\0') {
            ++len;
            ++__str;
        }
        return len;
    }

    template<typename T>
    T min(const T &a, const T &b) {
        return a < b ? a : b;
    }

    template<typename T>
    T max(const T &a, const T &b) {
        return a > b ? a : b;
    }


    class string {
    public:

        string() : m_data(new char[1]), m_size(0), m_capacity(1) {
            m_data[0] = '\0';
        }

        explicit string(const char *str) : m_data(new char[my::strlen(str) + 1]), m_size(my::strlen(str)),
                                           m_capacity(my::strlen(str) + 1) {
            my::strcpy(m_data, str);
        }

        string(const string &other) : m_data(new char[other.m_capacity]), m_size(other.m_size),
                                      m_capacity(other.m_capacity) {
            my::strcpy(m_data, other.m_data);
        }

        ~string() {
            delete[] m_data;
        }

        void erase() {
            delete[] m_data;
            m_data = new char[1];
            m_data[0] = '\0';
            m_size = 0;
            m_capacity = 1;
        }


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

        // operator +
        string operator+(const string &other) const {
            string newString;
            newString.m_size = m_size + other.m_size;
            newString.m_capacity = newString.m_size + 1;
            newString.m_data = new char[newString.m_capacity];
            my::strcpy(newString.m_data, m_data);
            my::strcpy(newString.m_data + m_size, other.m_data);
            return newString;
        }

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

        bool operator==(const string &other) const {
            if (m_size != other.m_size) {
                return false;
            }
            for (size_t i = 0; i < m_size; ++i) {
                if (m_data[i] != other.m_data[i]) {
                    return false;
                }
            }
            return true;
        }

        bool operator!=(const string &other) const {
            return !(*this == other);
        }

        bool operator<(const string &other) const {
            size_t minSize = min(m_size, other.m_size);
            for (size_t i = 0; i < minSize; ++i) {
                if (m_data[i] < other.m_data[i]) {
                    return true;
                } else if (m_data[i] > other.m_data[i]) {
                    return false;
                }
            }
            return m_size < other.m_size;
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

        char &operator[](size_t index) {
            return m_data[index];
        }

        const char &operator[](size_t index) const {
            return m_data[index];
        }

        size_t size() const {
            return m_size;
        }

        size_t capacity() const {
            return m_capacity;
        }

        void reserve(size_t new_capacity) {
            if (new_capacity > m_capacity) {
                char *temp = new char[new_capacity];
                my::strcpy(temp, m_data);
                delete[] m_data;
                m_data = temp;
                m_capacity = new_capacity;
            }
        }

        void resize(size_t new_size) {
            if (new_size > m_capacity) {
                reserve(new_size);
            }
            for (size_t i = m_size; i < new_size; ++i) {
                m_data[i] = '\0';
            }
            m_size = new_size;
        }

        void push_back(char c) {
            if (m_size + 1 > m_capacity) {
                reserve(m_capacity * 2);
            }
            m_data[m_size] = c;
            m_data[m_size + 1] = '\0';
            ++m_size;
        }

        const char *c_str() const {
            return m_data;
        }

        friend std::ostream &operator<<(std::ostream &os, const string &str) {
            os << str.m_data;
            return os;
        }

        friend std::istream &operator>>(std::istream &is, string &str) {
            char c = '\0';
            while (is.get(c) && my::isspace(c));
            if (is) {
                str.m_size = 0;
                do {
                    if (str.m_size + 1 > str.m_capacity) {
                        str.reserve(str.m_capacity * 2);
                    }
                    str.m_data[str.m_size] = c;
                    ++str.m_size;
                } while (is.get(c) && !my::isspace(c));
                str.m_data[str.m_size] = '\0';
                if (is) is.unget();
                else is.clear(is.rdstate() & ~std::ios_base::failbit);
            }
            return is;
        }

    private:
        char *m_data;
        size_t m_size;
        size_t m_capacity;
    };
}
int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    std::ifstream fin("1.txt");


    std::string str;
    while (fin >> str) {
        std::cout << str << "\n";
    }

    return 0;
}