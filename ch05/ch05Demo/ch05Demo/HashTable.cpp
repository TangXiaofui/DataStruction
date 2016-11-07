#include "HashTable.h"


hNode DeleteList(hNode hn)
{
	if (hn != NULL)
	{
		DeleteList(hn->next);
		free(hn);

	}
	return NULL;
}

void MakeEmpty(hTable ht)
{
	if (ht != NULL)
	{
		int len = ht->TableSize;
		int i = 0;
		for ( i = 0 ; i < len ; i++)
		{
			DeleteList(ht->hl[i]);
		}
		free(ht);
	}
}

int Hash(int val)
{
	return val % 11;
}
hTable InitialHashTable(hTable ht,int size)
{
	if (ht != NULL)
	{
		MakeEmpty(ht);
	}
	ht = (hTable)malloc(sizeof(struct HashTable));
	ht->TableSize = size > MAXSIZE ? MAXSIZE : size;
	ht->hl = (hList *)malloc(sizeof(hList) * ht->TableSize);
	
	int i = 0;
	for (i = 0 ; i < ht->TableSize ;i++)
	{
		ht->hl[i] = (hNode)malloc(sizeof(struct HashNode));
		ht->hl[i]->elem = 0;
		ht->hl[i]->next = NULL;
	}
	return ht;
}

hNode FindHashNode(hTable ht,int elem)
{
	if (ht != NULL)
	{
		hNode p = ht->hl[Hash(elem)];
		while(p != NULL && p->elem != elem)
		{
			p = p->next;
		}
		return p;
	}

}

hTable InsertHash(hTable ht,int elem)
{
	if (ht != NULL)
	{
		hNode p = FindHashNode(ht,elem);
		if ( p == NULL)
		{
			p = (hNode)malloc(sizeof(struct HashNode));
			if (p != NULL)
			{
				hNode temp = ht->hl[Hash(elem)];
				p->elem = elem;
				p->next = temp->next;
				temp->next = p;
			}
		}
	}
	return ht;
}