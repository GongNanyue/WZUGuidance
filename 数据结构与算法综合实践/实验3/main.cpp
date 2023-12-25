#include <tuple>
#include <cstring>
#include <iostream>
#include <fstream>
#include <chrono>

template<typename T>
struct node {
    T data;
    node<T> *next;

    node(T data, node<T> *next) : data(data), next(next) {}

};

template<typename T>
struct LinkedList {
    // 链表
    node<T> *head{nullptr}; // 头指针
    node<T> *tail{nullptr}; // 尾指针

    void insertTail(T data) {
        // 尾插法
        auto *node = new ::node<T>(data, nullptr);
        if (head == nullptr) { // 空链表
            head = node;
            tail = node;
        } else { // 非空链表
            tail->next = node;
            tail = node;
        }
    }

    ~LinkedList() {
        auto *p = head;
        while (p != nullptr) { // 释放链表
            auto *q = p->next;
            delete p;
            p = q;
        }
    }
};

struct Stu {
    char id[20];
    int score;

    bool operator<(const Stu &rhs) const {
        // 重载小于号
        // 先按分数排序，分数相同按学号排序
        if (score != rhs.score) return score > rhs.score;
        else return strcmp(id, rhs.id) < 0;
    }

    bool operator>(const Stu &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const Stu &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const Stu &rhs) const {
        return !(*this < rhs);
    }

    Stu(char *id, int score) : score(score) {
        for (int i = 0; id[i]; ++i)
            this->id[i] = id[i];
    }

    Stu() = default;
};

void quickSort(LinkedList<Stu> &l) {
    if (l.head == l.tail) return;// 递归终止条件

    auto pivot = l.head->data;// 选取枢纽元
    LinkedList<Stu> left, mid, right;
    for (auto p = l.head; p != nullptr; p = p->next) {
        // 将链表分为三部分
        if (p->data < pivot) left.insertTail(p->data); // 小于枢纽元
        else if (p->data > pivot) right.insertTail(p->data); // 大于枢纽元
        else mid.insertTail(p->data); // 等于枢纽元
    }
    quickSort(left);// 递归排序
    quickSort(right);
    // 合并链表
    auto p = l.head;
    auto q = left.head;
    while (q != nullptr) {// 将左链表合并到原链表
        p->data = q->data;
        p = p->next;
        q = q->next;
    }
    q = mid.head;
    while (q != nullptr) {// 将中间链表合并到原链表
        p->data = q->data;
        p = p->next;
        q = q->next;
    }
    q = right.head;
    while (q != nullptr) {// 将右链表合并到原链表
        p->data = q->data;
        p = p->next;
        q = q->next;
    }
}



int arr[751];

int main() {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    std::ifstream in1("C:\\Users\\Administrator\\Desktop\\03\\P03_TextData500000.in");
    std::ofstream out1("output.txt");

    Stu s{};
    LinkedList<Stu> list;
    while (in1 >> s.id >> s.score) {
        list.insertTail(s);
    }
    quickSort(list);
    auto *p = list.head;
    // 计算每个分数的人数
    while (p != nullptr) {
        arr[p->data.score]++;
        p = p->next;
    }
    // 计算每个分数的排名
    p = list.head;
    int idx = 1, score = list.head->data.score;
    while (p != nullptr) {
        if (score != p->data.score) {
            // 分数不同，排名加上上一个分数的人数
            idx += arr[score];
            score = p->data.score;
        }
        out1 << p->data.id << " " << p->data.score << " " << idx << " " << arr[p->data.score] << std::endl;
        p = p->next;
    }


    in1.close();
    out1.close();
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count()
              << "[ms]" << std::endl;
}