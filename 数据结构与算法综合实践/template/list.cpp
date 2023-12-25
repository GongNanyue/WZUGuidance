template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(const T& d = T{}, Node* p = nullptr, Node* n = nullptr)
            : data{d}, prev{p}, next{n} {}
        Node(T&& d, Node* p = nullptr, Node* n = nullptr)
            : data{std::move(d)}, prev{p}, next{n} {}
    };

public:
    class Iterator {
    public:
        Iterator(Node* n = nullptr) : node{n} {}
        T& operator*() { return node->data; }
        const T& operator*() const { return node->data; }
        Iterator& operator++() {
            node = node->next;
            return *this;
        }
        Iterator& operator--() {
            node = node->prev;
            return *this;
        }
        bool operator==(const Iterator& rhs) const {
            return node == rhs.node;
        }
        bool operator!=(const Iterator& rhs) const {
            return node != rhs.node;
        }

    private:
        Node* node;
        friend class List<T>;
    };

public:
    List() : head{new Node}, tail{new Node} {
        head->next = tail;
        tail->prev = head;
    }
    ~List() {
        while (!empty()) {
            pop_front();
        }
        delete head;
        delete tail;
    }
    List(const List& rhs) : List{} {
        for (auto& x : rhs) {
            push_back(x);
        }
    }
    List& operator=(const List& rhs) {
        List tmp{rhs};
        std::swap(head, tmp.head);
        std::swap(tail, tmp.tail);
        return *this;
    }
    List(List&& rhs) noexcept : head{rhs.head}, tail{rhs.tail} {
        rhs.head = nullptr;
        rhs.tail = nullptr;
    }
    List& operator=(List&& rhs) noexcept {
        std::swap(head, rhs.head);
        std::swap(tail, rhs.tail);
        return *this;
    }

    Iterator begin() { return Iterator{head->next}; }
    Iterator end() { return Iterator{tail}; }
    Iterator begin() const { return Iterator{head->next}; }
    Iterator end() const { return Iterator{tail}; }

    bool empty() const { return head->next == tail; }
    int size() const {
        int count = 0;
        for (auto it = begin(); it != end(); ++it) {
            ++count;
        }
        return count;
    }

    T& front() { return *begin(); }
    const T& front() const { return *begin(); }
    T& back() { return *(--end()); }
    const T& back() const { return *(--end()); }

    void push_front(const T& x) { insert(begin(), x); }
    void push_front(T&& x) { insert(begin(), std::move(x)); }
    void push_back(const T& x) { insert(end(), x); }
    void push_back(T&& x) { insert(end(), std::move(x)); }
    void pop_front() { erase(begin()); }
    void pop_back() { erase(--end()); }

    Iterator insert(Iterator it, const T& x) {
        Node* p = it.node;
        ++size_;
        return Iterator{p->prev = p->prev->next = new Node{x, p->prev, p}};
    }
    Iterator insert(Iterator it, T&& x) {
        Node* p = it.node;
        ++size_;
        return Iterator{p->prev = p->prev->next = new Node{std::move(x), p->prev, p}};
    }
    Iterator erase(Iterator it) {
        Node* p = it.node;
        Iterator ret{p->next};
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        --size_;
        return ret;
    }
    Iterator erase(Iterator from, Iterator to) {
        for (Iterator it = from; it != to;) {
            it = erase(it);
        }
        return to;
    }
    void clear() { erase(begin(), end()); }

private:
    Node* head;
    Node* tail;
    int size_ = 0;
};
