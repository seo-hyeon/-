#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
typedef struct {
	int key;
} element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

void init(HeapType* h)
{
	h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element item) 
{
	element temp;
	int i;

	h->heap_size++;
	i = h->heap_size;

	h->heap[i] = item;
	
	for (; i > 1; i /= 2)
	{
		if (h->heap[i].key> h->heap[i / 2].key)
		{
			temp = h->heap[i];
			h->heap[i] = h->heap[i / 2];
			h->heap[i / 2] = temp;
		}
		else
			break;
	}
}

element delete_max_heap(HeapType* h)
{
	element del, temp;
	int i;

	del = h->heap[1];
	h->heap[1] = h->heap[h->heap_size];
	h->heap_size--;

	for (i = 1; i < h->heap_size; )
	{
		if (h->heap[i * 2].key > h->heap[i * 2 + 1].key)
		{
			temp = h->heap[i];
			h->heap[i] = h->heap[i * 2];
			h->heap[i * 2] = temp;
			i = i * 2;
		}
		else
		{
			temp = h->heap[i];
			h->heap[i] = h->heap[i * 2 + 1];
			h->heap[i * 2 + 1] = temp;
			i = i * 2 + 1;
		}
	}

	return del;
}

void preorder(HeapType *h, int root)
{
	if (root <= h->heap_size && h->heap[root].key != NULL)
	{
		printf("%d ", h->heap[root].key);

		preorder(h, root * 2);
		preorder(h, root * 2 + 1);
	}
}

void print_heap(HeapType *h)
{
	int i, num = 2;

	for (i = 1; i <= h->heap_size; i++)
	{
		printf("%d ", h->heap[i].key);

		if (i == num - 1)
		{
			printf("\n");
			num += num;
		}
	}
	printf("\n");
}

int find(HeapType *h, int root, int key)
{
	int result;

	if (root > h->heap_size)
		return 0;
	else if (h->heap[root].key == key)
		return root;
	else
	{
		result = find(h, root * 2, key);

		if (result != 0)
			return result;

		result = find(h, root * 2 + 1, key);

		if (result != 0)
			return result;
	}
	/*
	int i;

	for (i = 1; i <= h->heap_size; i++)
		if (h->heap[i].key == key)
			return i;

	return 0;
	*/
}

void print_sorted_value(HeapType h)
{
	int i, index = h.heap_size;
	int result[MAX_ELEMENT];

	for (i = index; i > 0; i--)
		result[i] = delete_max_heap(&h).key;

	for (i = 1; i <= index; i++)
		printf("%d ", result[i]);
	printf("\n");
	/*
	int length = 0, i, bin = 1;

	for (i = h.heap_size; i > 1; i /= 2)
		length++;

	for (; length > 0; length--)
	{
		for (i = 0; i < length; i++)
			bin *= 2;

		for (i = bin; i < bin * 2 && i <= h.heap_size; i++)
			printf("%d ", h.heap[i].key);
		
		bin = 1;
	}*/
}

void modify_priority(HeapType *h, int oldKey, int newKey)
{
	int index;
	element del, temp;
	int i;

	index = find(h, 1, oldKey);

	del = h->heap[index];
	h->heap[index] = h->heap[h->heap_size];
	h->heap_size--;

	for (i = index; i < h->heap_size; )
	{
		if (i * 2 > h->heap_size)
			break;
		else if (h->heap[i * 2].key < h->heap[i * 2 + 1].key)
		{
			temp = h->heap[i];
			h->heap[i] = h->heap[i * 2 + 1];
			h->heap[i * 2 + 1] = temp;
			i = i * 2 + 1;
		}
		else
		{
			temp = h->heap[i];
			h->heap[i] = h->heap[i * 2];
			h->heap[i * 2] = temp;
			i = i * 2;
		}
	}
	temp.key = newKey;

	insert_max_heap(h, temp);
}

int main(void)
{
	element e1 = { 10 }, e2 = { 5 }, e3 = { 30 }, eA = { 9 }, eB = { 19 }, eC = { 39 };
	element e4, e5, e6;
	int index;
	int key, oldKey, newKey;
	HeapType heap;  //히프 생성

	init(&heap);

	printf("Step1: 삽입된 10, 5, 30에 추가적으로 9, 19, 39를 <삽입>한다.");
	insert_max_heap(&heap, e1);
	insert_max_heap(&heap, e2);
	insert_max_heap(&heap, e3);
	insert_max_heap(&heap, eA);
	insert_max_heap(&heap, eB);
	insert_max_heap(&heap, eC);

	printf("\nStep2: preorder, print_heap 함수 테스트\n");
	preorder(&heap, 1);
	printf("\n\n");
	print_heap(&heap);
	
	e4 = delete_max_heap(&heap);
	printf("\n 삭제: 루트(%d)가 삭제됨\n", e4.key);
	print_heap(&heap);

	printf("\nStep3: find 함수 테스트\n");
	printf("찾을 key 입력(-1 for exit): ");
	scanf("%d", &key);
	while (key != -1) {
		if ((index = find(&heap, 1, key)) == 0)
			printf("%d는 없음\n", key);
		else
			printf("%d은 [%d]에 있음\n", key, index);
		printf("찾을 key 입력(-1 for exit): ");
		scanf("%d", &key);
	}
	
	printf("\nStep4: print_sorted_value 함수 테스트\n");
	print_sorted_value(heap);
	
	printf("\nStep5: modify_priority 함수 테스트\n");
	printf("바꿀 key 입력(-1 for exit): ");
	scanf("%d", &oldKey);
	while (oldKey != -1)
	{
		printf("새 key 입력: ");
		scanf("%d", &newKey);
		modify_priority(&heap, oldKey, newKey);
		print_heap(&heap);

		printf("바꿀 key 입력(-1 for exit): ");
		scanf("%d", &oldKey);
	}
}