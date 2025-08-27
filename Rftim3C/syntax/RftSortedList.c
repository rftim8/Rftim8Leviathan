#include "RftSortedList.h"

typedef struct node {
	int key;
	struct node* next;
}NODE;

static NODE* prim = 0, * last = 0;

static void Add(int x) {
	NODE* p, * q, * r;
	p = (NODE*)malloc(sizeof(NODE));
	p->key = x;
	p->next = 0;
	if (0 == prim) {
		prim = p;
		last = p;
	}
	else {
		if (x < prim->key) {
			p->next = prim;
			prim = p;
		}
		else {
			if (x > last->key) {
				last->next = p;
				last = p;
			}
			else {
				for (q = r = prim; q != 0 && q->key < x; r = q, q = q->next) {
					;
				}
				r->next = p;
				p->next = q;
			}
		}
	}
}

static void Delete(int x) {
	NODE* p, * q;
	if (prim->key == x) {
		p = prim;
		prim = prim->next;
		free(p);
	}
	else {
		for (p = q = prim; p != 0; q = p, p = p->next) {
			if (p->key == x) {
				q->next = p->next;
				if (p == last) {
					last = q;
				}
				free(p);
			}
		}
	}
}

static void Show() {
	for (NODE* p = prim; p != 0; p = p->next) {
		printf("%d  ", p->key);
	}
	printf("\n");
}

void RftSortedList() {
	Add(3);
	Add(1);
	Add(2);
	Add(5);
	Show();

	Delete(2);
	Show();

	Add(10);
	Add(15);
	Add(12);
	Show();
}
