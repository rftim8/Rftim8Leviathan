#include "RftStackArray.h"

static int tab[100];
static int n = 0;

static void push(int x) {
	tab[n++] = x;
}

static int pop() {
	int x = tab[--n];
	return x;
}

static int top() {
	return tab[n - 1];
}

void RftStackArray() {
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
	printf("%d\n", top());
	printf("%d\n", pop());
	printf("%d\n", top());
}
