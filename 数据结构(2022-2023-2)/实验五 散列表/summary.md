```cpp
#include <bits/stdc++.h>
using namespace std;

#define USED 1
#define EMPTY 0

typedef int ElementType;

typedef struct
{
    ElementType key; 
    int flag;        
}Cell;

typedef struct
{
    Cell *cells;  
    int capacity; 
    int size;     
}HashTable;


bool isPrime(int n){
	if(n < 2)return false;
	for(int i = 2;i <= n / i;++i)
		if(n % i == 0)
			return false;
	return true; 
}

int nextPrime(int n){
	while(!isPrime(n))
		++n;
	return n;
}


HashTable * create(int capacity){
	HashTable *table = new HashTable;
	table->capacity = nextPrime(capacity);
	table->cells = new Cell[table->capacity];
	return table;
}

int hash(HashTable * h,ElementType key){
	return key % h->capacity;
}

int find(HashTable * h,ElementType key){
	int idx = hash(h,key);
	for(int i = 0; ;++i){
		int di =  i * i;
		int nid = (idx + di) % h->capacity;
		if(h->cells[nid].flag == EMPTY) return nid;
		else if(h->cells[nid].key == key) return nid;
	}
}

/* 
void insert(HashTable * h,ElementType key){
	int idx = find(h,key);
	if(h->cells[idx].flag == EMPTY){
		h->cells[idx].key = key;
		h->cells[idx].flag = USED;
		h->size++;
	}	
}
*/
void rehash(HashTable * h){
	HashTable *nh = new HashTable;
	nh->capacity = nextPrime(h->capacity * 2);
	nh->size = 0;
	nh->cells = new Cell[nh->capacity];
	
	
	
	for(int i = 0;i < h->capacity;++i)
		if(h->cells[i].flag == USED)
			insert(nh,h->cells[i].key);
	
	delete[] h->cells;
	h->cells = nh->cells;
	h->capacity = nh->capacity;
	h->size = nh->size;
}

void insert(HashTable * h,ElementType key){
	int idx = find(h,key);
	if(h->cells[idx].flag == EMPTY){
		h->cells[idx].key = key;
		h->cells[idx].flag = USED;
		h->size++;
	}
	
	if(h->size * 2 >= h->capacity)
		rehash(h);
}

void destroy (HashTable * h){
	delete[] h->cells;
	delete h;
}
int main(){
	
	 
	
	return 0;
} 

```
