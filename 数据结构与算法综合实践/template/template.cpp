
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