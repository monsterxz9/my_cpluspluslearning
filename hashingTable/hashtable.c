#include <stdio.h>
#include <stdlib.h>

#define SIZE 9
typedef struct Element {
    int key;
} *Element;

typedef struct HashTable {
    Element *table;
} HashTable;

void init(HashTable *hashtable) {
    hashtable->table = malloc(sizeof(Element) * SIZE);
    for (int i = 0; i < SIZE; ++i) {
        hashtable->table[i] = NULL;
    }
}

int hash(int key) {
    return key % SIZE;
}

void insert(HashTable *hashtable, Element element) {
    int hashCode = hash(element->key);
    // 这里可以添加更复杂的冲突处理逻辑
    hashtable->table[hashCode] = element;
}

_Bool find(HashTable *hashtable, int key) {
    int hashCode = hash(key);
    if (hashtable->table[hashCode] == NULL) {
        return 0;
    }
    return hashtable->table[hashCode]->key == key;
}

Element create(int key) {
    Element element = malloc(sizeof(struct Element));
    element->key = key;
    return element;
}

int main() {
    HashTable hashTable;
    init(&hashTable);

    insert(&hashTable, create(10));
    insert(&hashTable, create(7));
    insert(&hashTable, create(13));
    insert(&hashTable, create(29));

    printf("%d\n", find(&hashTable, 29));
    printf("%d\n", find(&hashTable, 10));

    // 这里应该添加代码来释放分配的内存
    return 0;
}
