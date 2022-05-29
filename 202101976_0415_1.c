#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct {
	int key;
}element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

HeapType* create()
{
	return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h)
{
	h->heap_size = 0;
}

void insert_max_heap(HeapType *h, element item)
{
	int i;
	i = ++(h->heap_size);

	while ( (i!=1) && (h->heap[i/2].key < item.key))
	{
		h->heap[i] = h->heap[i / 2];
		i = i / 2;
	}

	h->heap[i] = item;
}

element delete_max_heap(HeapType *h)
{
	int parent,child;
	element item, tmp;

	item = h->heap[1];
	tmp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;

	while (child <= h->heap_size)
	{

		if ( (h->heap_size > child)  &&  ((h->heap[child+1].key) > (h->heap[child].key))  )
		{
			child++;
		}
		if (tmp.key >= h->heap[child].key)
			break;

		h->heap[parent] = h->heap[child];
		parent = child;
		child = child * 2;
	}

	h->heap[parent] = tmp;
	return item;
}

void heap_sort(element a[], int n)
{
	HeapType* h;
	h = create();

	init(h);
	for (int i = 0; i < n; i++)
	{
		insert_max_heap(h, a[i]);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		a[i] = delete_max_heap(h);
	}
	free(h);
}


int main(void)
{
	element list[8] = { 23, 56, 11, 9, 56, 99, 27, 34 };
	heap_sort(list, 8);

	for (int i = 0; i < 8; i++)
	{
		printf("%d ", list[i].key);
	}
	printf("\n");
	return 0;
}