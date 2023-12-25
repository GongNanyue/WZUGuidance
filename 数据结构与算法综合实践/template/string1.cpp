#ifndef DATASTRUCTURE_STRING_H
#define DATASTRUCTURE_STRING_H

#include <iostream>
#include <cstddef>
#include <stdexcept>

#include "CStr.h"
namespace my {
    class String {
    private:
        char *str;
        size_t len;
        size_t capacity;
    public:
        String() {
            str = new char[1];
            str[0] = '\0';
            len = 0;
            capacity = 1;
        }

        String(const char *s) {
            len = my::strlen(s);
            capacity = len + 1;
            str = new char[capacity];
            my::strcpy(str, s);
        }

        String(const String &other) {
            len = other.len;
            capacity = other.capacity;
            str = new char[capacity];
            my::strcpy(str, other.str);
        }

        ~String() {
            delete[] str;
        }

        void clear() {
            delete[] str;
            str = new char[1];
            str[0] = '\0';
            len = 0;
            capacity = 1;
        }

        static String to_String(int n) {
            char *s = new char[12];
            int i = 0;
            if (n < 0) {
                s[i++] = '-';
                n = -n;
            }
            do {
                s[i++] = n % 10 + '0';
            } while ((n /= 10) > 0);
            s[i] = '\0';
            String str(s);
            delete[] s;
            return str;
        }

        static String toString(long long n) {
            char *s = new char[21];
            int i = 0;
            if (n < 0) {
                s[i++] = '-';
                n = -n;
            }
            do {
                s[i++] = n % 10 + '0';
            } while ((n /= 10) > 0);
            s[i] = '\0';
            String str(s);
            delete[] s;
            return str;
        }

        size_t size() const {
            return len;
        }

        size_t cap() const {
            return capacity;
        }

        bool empty() const {
            return len == 0;
        }

        void reserve(size_t new_cap) {
            if (new_cap <= capacity) {
                return;
            }
            char *new_str = new char[new_cap];
            my::strcpy(new_str, str);
            delete[] str;
            str = new_str;
            capacity = new_cap;
        }

        String append(const String &other) {
            size_t new_len = len + other.len;
            if (new_len + 1 > capacity) {
                reserve(2 * new_len);
            }
            my::strcpy(str + len, other.str);
            len = new_len;
            return *this;
        }

        String append(const char c) {
            if (len + 2 > capacity) {
                reserve(len + 2);
            }
            str[len] = c;
            str[len + 1] = '\0';
            len++;
            return *this;
        }

        String operator+=(const String &other) {
            return append(other);
        }

        String operator+=(const char c) {
            return append(c);
        }

        String operator+(const String &other) {
            String new_str = *this;
            new_str += other;
            return new_str;
        }

        String operator+(const char c) {
            String new_str = *this;
            new_str += c;
            return new_str;
        }

        bool operator==(const String &other) const {
            if (len != other.len) {
                return false;
            }
            for (size_t i = 0; i < len; i++) {
                if (str[i] != other.str[i]) {
                    return false;
                }
            }
            return true;
        }

        bool operator<(const String &other) const {
            size_t min_len = len < other.len ? len : other.len;
            for (size_t i = 0; i < min_len; i++) {
                if (str[i] < other.str[i]) {
                    return true;
                } else if (str[i] > other.str[i]) {
                    return false;
                }
            }
            return len < other.len;
        }

        bool operator>(const String &rhs) const {
            return rhs < *this;
        }

        bool operator<=(const String &rhs) const {
            return !(rhs < *this);
        }

        bool operator>=(const String &rhs) const {
            return !(*this < rhs);
        }

        char &operator[](size_t index) {
            return str[index];
        }

        char &at(size_t index) {
            if (index >= len) {3
                throw std::out_of_range("String index out of range");
            }
            return str[index];
        }

        friend std::ostream &operator<<(std::ostream &os, const String &s) {
            os << s.str;
            return os;
        }

        friend std::istream &operator>>(std::istream &is, String &s) {
            char *buf = new char[1000];
            memset(buf, 0, 1000);
            is >> buf;
            s = buf;
            delete[] buf;
            return is;
        }

        struct hash {
            size_t operator()(const String &s) const {
                size_t h = 0;
                for (size_t i = 0; i < s.len; i++) {
                    h = h * 131 + s.str[i];
                }
                return h;
            }
        };

        struct euqal {
            bool operator()(const String &s1, const String &s2) const {
                return s1 == s2;
            }
        };
    };
}

#endif //DATASTRUCTURE_STRING_H
