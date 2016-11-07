#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <stdlib.h>
#include <stdio.h>

#define  MAXSIZE 11

struct HashNode;
typedef struct HashNode *hNode;
struct HashTable;
typedef struct HashTable *hTable;

struct HashNode{
	int elem;
	hNode next;
};

typedef hNode hList;
struct HashTable
{
	int TableSize;
	hList *hl;
};


hNode DeleteList(hNode hn);
void MakeEmpty(hTable ht);
int Hash(int val);
hTable InitialHashTable(hTable ht,int size);
hTable InsertHash(hTable ht,int elem);
hNode FindHashNode(hTable ht,int elem);


#endif