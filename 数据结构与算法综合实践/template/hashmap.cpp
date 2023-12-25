#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <memory> // for smart pointers

template<typename KeyType, typename ValueType, typename Hash = std::hash<KeyType>, typename Pred = std::equal_to<KeyType>>
class HashTable {
private:
    struct HashNode {
        KeyType key;
        ValueType value;
        std::unique_ptr<HashNode> next; // using unique_ptr for automatic memory management
        HashNode(const KeyType &k, const ValueType &v) : key(k), value(v), next(nullptr) {}
    };

    std::vector<std::list<std::unique_ptr<HashNode>>> table;
    size_t size;
    size_t capacity;
    const double loadFactor = 0.75;
    std::unique_ptr<Hash> hashFunction; // custom hash function
    std::unique_ptr<Pred> predFunction; // custom predicate function

    void resize() {
        if (size >= loadFactor * capacity) {
            capacity *= 2;
            std::vector<std::list<std::unique_ptr<HashNode>>> newTable(capacity);
            for (auto &bucket: table) {
                for (auto &node: bucket) {
                    size_t index = (*hashFunction)(node->key) % capacity;
                    newTable[index].push_back(std::move(node));
                }
            }
            table = std::move(newTable);
        }
    }

public:
    HashTable() : size(0), capacity(16), hashFunction(std::make_unique<Hash>()), predFunction(std::make_unique<Pred>()) {
        table.resize(capacity);
    }

    ~HashTable() {
        for (auto &bucket: table) {
            bucket.clear();
        }
    }

    void insert(const KeyType &key, const ValueType &value) {
        size_t index = (*hashFunction)(key) % capacity;
        for (auto &node: table[index]) {
            if ((*predFunction)(node->key, key)) {
                node->value = value;
                return;
            }
        }
        std::unique_ptr<HashNode> newNode(new HashNode(key, value));
        table[index].push_back(std::move(newNode));
        size++;
        resize();
    }

    bool remove(const KeyType &key) {
        size_t index = (*hashFunction)(key) % capacity;
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if ((*predFunction)((*it)->key, key)) {
                table[index].erase(it);
                size--;
                return true;
            }
        }
        return false;
    }

    bool contains(const KeyType &key) const {
        size_t index = (*hashFunction)(key) % capacity;
        for (auto &node: table[index]) {
            if ((*predFunction)(node->key, key)) {
                return true;
            }
        }
        return false;
    }

    ValueType &operator[](const KeyType &key) {
        size_t index = (*hashFunction)(key) % capacity;
        for (auto &node: table[index]) {
            if ((*predFunction)(node->key, key)) {
                return node->value;
            }
        }
        std::unique_ptr<HashNode> newNode(new HashNode(key, ValueType()));
        ValueType &value = newNode->value;
        table[index].push_back(std::move(newNode));
        size++;
        resize();
        return value;
    }

    size_t getSize() const {
        return size;
    }

    bool isEmpty() const {
        return size == 0;
    }
};

int main() {
    HashTable<int, int> mp;
    mp[1] = 2;
    mp[2] = 4;
    std::cout << mp[1];
}
