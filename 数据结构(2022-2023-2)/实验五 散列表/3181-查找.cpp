int find(HashTable *h, ElementType key) {
    //计算散列值 
    int pos = hash(h, key);
    //初始化探测步长
    int di = 1;
    //循环查找
    while (h->cells[pos].flag == USED && h->cells[pos].key != key) {
        //平方探测法 
        pos = (pos + di) % h->capacity;
        //更新探测步长 
        di += 2;
        //如果回到原点，说明散列表已满，返回-1 
        if (pos == hash(h, key)) { return -1; }
    }
    //返回找到的槽的下标
    return pos;
}
