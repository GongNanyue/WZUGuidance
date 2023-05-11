
void up(Heap h, int i) {
    if (i > 1 && h->data[i] > h->data[i / 2]) {
        swap(h->data[i], h->data[i / 2]);
        up(h, i / 2);
    }
}

void down(Heap h, int i) {
    int minIdx = i;
    if (i * 2 <= h->size && h->data[minIdx] < h->data[i * 2])
        minIdx = i * 2;
    if (i * 2 + 1 <= h->size && h->data[minIdx] < h->data[i * 2 + 1])
        minIdx = i * 2 + 1;

    if (minIdx != i) {
        swap(h->data[i], h->data[minIdx]);
        down(h, minIdx);
    }
}
