#include "RftStackList.h"

typedef struct node
{
	int key;
	struct node *next;
} NODE;

NODE *prim = 0;

static void push(int x)
{
	NODE *p = 0;
	p = (NODE *)malloc(sizeof(NODE));
	p->key = x;
	p->next = 0;

	if (prim == 0)
		prim = p;
	else
	{
		p->next = prim;
		prim = p;
	}
}

static int pop()
{
	int x = prim->key;
	NODE *p = prim;
	prim = prim->next;
	free(p);
	return x;
}

static int top()
{
	return prim->key;
}

void RftStackList()
{
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);

	printf("%d\n", top());
	printf("%d\n", pop());
	printf("%d\n", top());
	printf("%d\n", pop());
	printf("%d\n", top());
}
