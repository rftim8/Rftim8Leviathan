#pragma once
#include "rft_global_c.h"

typedef struct node
{
    int key;
    struct node *next;
} NODE;

static NODE *prim = 0, *last = 0;

static void addNode(int x)
{
    NODE *p;
    p = (NODE *)malloc(sizeof(NODE));
    p->key = x;
    p->next = 0;

    if (0 == prim)
    {
        prim = p;
        last = p;
    }
    else
    {
        last->next = p;
        last = p;
    }
}

static void deleteNode(int x)
{
    NODE *p, *q;

    if (prim->key == x)
    {
        p = prim;
        prim = prim->next;
        free(p);
    }
    else
    {
        for (p = q = prim; p != 0; q = p, p = p->next)
        {
            if (p->key == x)
            {
                q->next = p->next;

                if (p == last)
                    last = q;

                free(p);
                break;
            }
        }
    }
}

static void showNode()
{
    for (NODE *p = prim; p != 0; p = p->next)
    {
        printf("%d ", p->key);
    }

    printf("\n");
}

static void list_0()
{
    addNode(3);
    addNode(1);
    addNode(2);
    addNode(5);
    showNode();

    deleteNode(2);
    showNode();

    addNode(10);
    addNode(15);
    addNode(12);
    showNode();
}

////-----------------------------------------------------------------------------------------------------
///*
// * C Program to Read a Linked List in Reverse
// *//*
// #include <stdio.h>
// #include <stdlib.h>
// struct node {
//	int num;
//	struct node *next;
//};
// void create(struct node **);
// void reversedisplay(struct node *);
// void release(struct node **);
// void display(struct node *);
// int main() {
//	struct node *p = NULL;
//	struct node_occur *head = NULL;
//	int n;
//	printf("Enter data into the list\n");
//	create(&p);
//	printf("Displaying the nodes in the list:\n");
//	display(p);
//	printf("Displaying the list in reverse:\n");
//	reversedisplay(p);
//	release(&p);
//	return 0;
//}
// void reversedisplay(struct node *head) {
//	if (head != NULL) {
//		reversedisplay(head->next);
//		printf("%d\t", head->num);
//	}
//}
// void create(struct node **head) {
//	int c, ch;
//	struct node *temp, *rear;
//	do {
//		printf("Enter number: ");
//		scanf_f("%d", &c);
//		temp = (struct node *) malloc(sizeof(struct node));
//		temp->num = c;
//		temp->next = NULL;
//		if (*head == NULL) {
//			*head = temp;
//		} else {
//			rear->next = temp;
//		}
//		rear = temp;
//		printf("Do you wish to continue [1/0]: ");
//		scanf_f("%d", &ch);
//	} while (ch != 0);
//	printf("\n");
//}
// void display(struct node *p) {
//	while (p != NULL) {
//		printf("%d\t", p->num);
//		p = p->next;
//	}
//	printf("\n");
//}
// void release(struct node **head) {
//	struct node *temp = *head;
//	*head = (*head)->next;
//	while ((*head) != NULL) {
//		free(temp);
//		temp = *head;
//		(*head) = (*head)->next;
//	}
//}
//*/
////---------------------------------------------------------------------------------------------------------
//	/*
//	 * C program to search for an element in linked list
//	 */
// #include <stdio.h>
// #include <stdlib.h>
// struct node
//{
//	int a;
//	struct node* next;
//};
// void generate(struct node**, int);
// void search(struct node*, int, int);
// void delete(struct node**);
// int main()
//{
//	struct node* head;
//	int key, num;
//	printf("Enter the number of nodes: ");
//	scanf_f("%d", &num);
//	generate(&head, num);
//	printf("\nEnter key to search: ");
//	scanf_f("%d", &key);
//	search(head, key, num);
//	delete(&head);
//}
// void generate(struct node** head, int num)
//{
//	int i;
//	struct node* temp;
//	for (i = 0; i < num; i++)
//	{
//		temp = (struct node*)malloc(sizeof(struct node));
//		temp->a = rand() % num;
//		printf("%d    ", temp->a);
//		if (*head == NULL)
//		{
//			*head = temp;
//			(*head)->next = NULL;
//		}
//		else
//		{
//			temp->next = *head;
//			*head = temp;
//		}
//	}
//}
// void search(struct node* head, int key, int index)
//{
//	if (head->a == key)
//	{
//		printf("Key found at Position: %d\n", index);
//	}
//	if (head->next == NULL)
//	{
//		return;
//	}
//	search(head->next, key, index - 1);
//}
// void delete(struct node** head)
//{
//	struct node* temp;
//	while (*head != NULL)
//	{
//		temp = *head;
//		*head = (*head)->next;
//		free(temp);
//	}
//}
////-----------------------------------------------------------------------------------------------------------
//	/*
//	 * C Program to Search for an Element in the Linked List without
//	 * using Recursion
//	 */
// #include <stdio.h>
// #include <stdlib.h>
// struct node
//{
//	int a;
//	struct node* next;
//};
// void generate(struct node**, int);
// void search(struct node*, int);
// void delete(struct node**);
// int main()
//{
//	struct node* head = NULL;
//	int key, num;
//	printf("Enter the number of nodes: ");
//	scanf_f("%d", &num);
//	printf("\nDisplaying the list\n");
//	generate(&head, num);
//	printf("\nEnter key to search: ");
//	scanf_f("%d", &key);
//	search(head, key);
//	delete(&head);
//	return 0;
//}
// void generate(struct node** head, int num)
//{
//	int i;
//	struct node* temp;
//	for (i = 0; i < num; i++)
//	{
//		temp = (struct node*)malloc(sizeof(struct node));
//		temp->a = rand() % num;
//		if (*head == NULL)
//		{
//			*head = temp;
//			temp->next = NULL;
//		}
//		else
//		{
//			temp->next = *head;
//			*head = temp;
//		}
//		printf("%d  ", temp->a);
//	}
//}
// void search(struct node* head, int key)
//{
//	while (head != NULL)
//	{
//		if (head->a == key)
//		{
//			printf("key found\n");
//			return;
//		}
//		head = head->next;
//	}
//	printf("Key not found\n");
//}
// void delete(struct node** head)
//{
//	struct node* temp;
//	while (*head != NULL)
//	{
//		temp = *head;
//		*head = (*head)->next;
//		free(temp);
//	}
//}
////-------------------------------------------------------------------------------------------------------------
//	/*
//	 * Recursive C program to reverse nodes of a linked list and display
//	 * them
//	 */
// #include <stdio.h>
// #include <stdlib.h>
// struct node
//{
//	int data;
//	struct node* next;
//};
// void print_reverse_recursive(struct node*);
// void print(struct node*);
// void create_new_node(struct node*, int);
////Driver Function
// int main()
//{
//	struct node* head = NULL;
//	insert_new_node(&head, 1);
//	insert_new_node(&head, 2);
//	insert_new_node(&head, 3);
//	insert_new_node(&head, 4);
//	printf("LinkedList : ");
//	print(head);
//	printf("\nLinkedList in reverse order : ");
//	print_reverse_recursive(head);
//	printf("\n");
//	return 0;
// }
////Recursive Reverse
// void print_reverse_recursive(struct node* head)
//{
//	if (head == NULL)
//	{
//		return;
//	}
//	//Recursive call first
//	print_reverse(head->next);
//	//Print later
//	printf("%d ", head->data);
// }
////Print the linkedlist normal
// void print(struct node* head)
//{
//	if (head == NULL)
//	{
//		return;
//	}
//	printf("%d ", head->data);
//	print(head->next);
// }
////New data added in the start
// void insert_new_node(struct node** head_ref, int new_data)
//{
//	struct node* new_node = (struct node*)malloc(sizeof(struct node));
//	new_node->data = new_data;
//	new_node->next = (*head_ref);
//	(*head_ref) = new_node;
// }
////----------------------------------------------------------------------------------------------------------
//	/*
//	 * Recursive C program to display members of a linked list
//	 */
// #include <stdio.h>
// #include <stdlib.h>
// struct node
//{
//	int a;
//	struct node* next;
//};
// void generate(struct node**);
// void display(struct node*);
// void delete(struct node**);
// int main()
//{
//	struct node* head = NULL;
//	generate(&head);
//	display(head);
//	delete(&head);
//	return 0;
//}
// void generate(struct node** head)
//{
//	int num = 10, i;
//	struct node* temp;
//	for (i = 0; i < num; i++)
//	{
//		temp = (struct node*)malloc(sizeof(struct node));
//		temp->a = i;
//		if (*head == NULL)
//		{
//			*head = temp;
//			(*head)->next = NULL;
//		}
//		else
//		{
//			temp->next = *head;
//			*head = temp;
//		}
//	}
//}
// void display(struct node* head)
//{
//	printf("%d    ", head->a);
//	if (head->next == NULL)
//	{
//		return;
//	}
//	display(head->next);
//}
// void delete(struct node** head)
//{
//	struct node* temp;
//	while (*head != NULL)
//	{
//		temp = *head;
//		*head = (*head)->next;
//		free(temp);
//	}
//}
////--------------------------------------------------------------------------------------------------------------
//	/*
//	 * C Program to Display all the Nodes in a Linked List without using
//	 * Recursion
//	 */
// #include <stdio.h>
// #include <stdlib.h>
// struct node
//{
//	int a;
//	struct node* next;
//};
// void generate(struct node**);
// void display(struct node*);
// void delete(struct node**);
// int main()
//{
//	struct node* head = NULL;
//	generate(&head);
//	display(head);
//	delete(&head);
//	return 0;
//}
// void generate(struct node** head)
//{
//	int num = 10, i;
//	struct node* temp;
//	for (i = 0; i < num; i++)
//	{
//		temp = (struct node*)malloc(sizeof(struct node));
//		temp->a = i;
//		if (*head == NULL)
//		{
//			*head = temp;
//			(*head)->next = NULL;
//		}
//		else
//		{
//			temp->next = *head;
//			*head = temp;
//		}
//	}
//}
// void display(struct node* head)
//{
//	while (head != NULL)
//	{
//		printf("%d   ", head->a);
//		head = head->next;
//	}
//	printf("\n");
//}
// void delete(struct node** head)
//{
//	struct node* temp;
//	while (*head != NULL)
//	{
//		temp = *head;
//		*head = (*head)->next;
//		free(temp);
//	}
//}
////--------------------------------------------------------------------------------------------------------
//	/*
//	 * C Program to Display the Nodes of a Linked List in Reverse without
//	 * using Recursion
//	 */
// #include <stdio.h>
// #include <stdlib.h>
// struct node
//{
//	int visited;
//	int a;
//	struct node* next;
//};
// void generate(struct node**);
// void display(struct node*);
// void linear(struct node*);
// void delete(struct node**);
// int main()
//{
//	struct node* head = NULL;
//	generate(&head);
//	printf("\nPrinting the list in linear order\n");
//	linear(head);
//	printf("\nPrinting the list in reverse order\n");
//	display(head);
//	delete(&head);
//	return 0;
//}
// void display(struct node* head)
//{
//	struct node* temp = head, * prev = head;
//	while (temp->visited == 0)
//	{
//		while (temp->next != NULL && temp->next->visited == 0)
//		{
//			temp = temp->next;
//		}
//		printf("%d  ", temp->a);
//		temp->visited = 1;
//		temp = head;
//	}
//}
// void linear(struct node* head)
//{
//	while (head != NULL)
//	{
//		printf("%d  ", head->a);
//		head = head->next;
//	}
//	printf("\n");
//}
// void generate(struct node** head)
//{
//	int num, i;
//	struct node* temp;
//	printf("Enter length of list: ");
//	scanf_f("%d", &num);
//	for (i = num; i > 0; i--)
//	{
//		temp = (struct node*)malloc(sizeof(struct node));
//		temp->a = i;
//		temp->visited = 0;
//		if (*head == NULL)
//		{
//			*head = temp;
//			(*head)->next = NULL;
//		}
//		else
//		{
//			temp->next = *head;
//			*head = temp;
//		}
//	}
//}
// void delete(struct node** head)
//{
//	struct node* temp;
//	while (*head != NULL)
//	{
//		temp = *head;
//		*head = (*head)->next;
//		free(temp);
//	}
//}
////---------------------------------------------------------------------------------------------------------
//	/*
//	 * C program to find the number of occurences of a given number in a
//	 * list
//	 */
// #include <stdio.h>
// void occur(int[], int, int, int, int*);
// int main()
//{
//	int size, key, count = 0;
//	int list[20];
//	int i;
//	printf("Enter the size of the list: ");
//	scanf_f("%d", &size);
//	printf("Printing the list:\n");
//	for (i = 0; i < size; i++)
//	{
//		list[i] = rand() % size;
//		printf("%d    ", list[i]);
//	}
//	printf("\nEnter the key to find it's occurence: ");
//	scanf_f("%d", &key);
//	occur(list, size, 0, key, &count);
//	printf("%d occurs for %d times.\n", key, count);
//	return 0;
//}
// void occur(int list[], int size, int index, int key, int* count)
//{
//	if (size == index)
//	{
//		return;
//	}
//	if (list[index] == key)
//	{
//		*count += 1;
//	}
//	occur(list, size, index + 1, key, count);
//}
////----------------------------------------------------------------------------------------------------------
//	/*
//	 * C Program Count the Number of Occurrences of an Element in the Linked List
//	 * without using Recursion
//	 */
// #include <stdio.h>
// int occur(int[], int, int);
// int main()
//{
//	int size, key, count;
//	int list[20];
//	int i;
//	printf("Enter the size of the list: ");
//	scanf_f("%d", &size);
//	printf("Printing the list:\n");
//	for (i = 0; i < size; i++)
//	{
//		list[i] = rand() % size;
//		printf("%d    ", list[i]);
//	}
//	printf("\nEnter the key to find it's occurence: ");
//	scanf_f("%d", &key);
//	count = occur(list, size, key);
//	printf("%d occurs for %d times.\n", key, count);
//	return 0;
//}
// int occur(int list[], int size, int key)
//{
//	int i, count = 0;
//	for (i = 0; i < size; i++)
//	{
//		if (list[i] == key)
//		{
//			count += 1;
//		}
//	}
//	return count;
//}
////----------------------------------------------------------------------------------------------------------
//	/*
//	 * C program to find the length of a string
//	 */
// #include <stdio.h>
// int length(char[], int);
// int main()
//{
//	char word[20];
//	int count;
//	printf("Enter a word to count it's length: ");
//	scanf_f("%s", word);
//	count = length(word, 0);
//	printf("The number of characters in %s are %d.\n", word, count);
//	return 0;
//}
// int length(char word[], int index)
//{
//	if (word[index] == '\0')
//	{
//		return 0;
//	}
//	return (1 + length(word, index + 1));
//}
////---------------------------------------------------------------------------------------------------------
//	/*
//	 * C Program find the Length of the Linked List without using Recursion
//	 */
// #include <stdio.h>
// #include <stdlib.h>
// struct node
//{
//	int a;
//	struct node* next;
//};
// void generate(struct node**);
// int length(struct node*);
// void delete(struct node**);
// int main()
//{
//	struct node* head = NULL;
//	int count;
//	generate(&head);
//	count = length(head);
//	printf("The number of nodes are: %d\n", count);
//	delete(&head);
//	return 0;
//}
// void generate(struct node** head)
//{
//	/* for unknown number of nodes use num = rand() % 20; */
//	int num = 10, i;
//	struct node* temp;
//	for (i = 0; i < num; i++)
//	{
//		temp = (struct node*)malloc(sizeof(struct node));
//		temp->a = i;
//		if (*head == NULL)
//		{
//			*head = temp;
//			(*head)->next = NULL;
//		}
//		else
//		{
//			temp->next = *head;
//			*head = temp;
//		}
//	}
//}
// int length(struct node* head)
//{
//	int num = 0;
//	while (head != NULL)
//	{
//		num += 1;
//		head = head->next;
//	}
//	return num;
//}
// void delete(struct node** head)
//{
//	struct node* temp;
//	while (*head != NULL)
//	{
//		temp = *head;
//		*head = (*head)->next;
//		free(temp);
//	}
//}
////----------------------------------------------------------------------------------------------------------
//	/*
//	 * C Program to Print the Alternate Nodes in a Linked List using Recursion
//	 */
// #include <stdio.h>
// #include <stdlib.h>
// struct node
//{
//	int a;
//	struct node* next;
//};
// void generate(struct node**);
// void display(struct node*);
// void delete(struct node**);
// int main()
//{
//	struct node* head = NULL;
//	generate(&head);
//	printf("\nDisplaying the alternate nodes\n");
//	display(head);
//	delete(&head);
//	return 0;
//}
// void display(struct node* head)
//{
//	static flag = 0;
//	if (head != NULL)
//	{
//		if (!(flag % 2))
//		{
//			printf("%d  ", head->a);
//		}
//		flag++;
//		display(head->next);
//	}
//}
// void generate(struct node** head)
//{
//	int num, i;
//	struct node* temp;
//	printf("Enter length of list: ");
//	scanf_f("%d", &num);
//	for (i = num; i > 0; i--)
//	{
//		temp = (struct node*)malloc(sizeof(struct node));
//		temp->a = i;
//		if (*head == NULL)
//		{
//			*head = temp;
//			(*head)->next = NULL;
//		}
//		else
//		{
//			temp->next = *head;
//			*head = temp;
//		}
//	}
//}
// void delete(struct node** head)
//{
//	struct node* temp;
//	while (*head != NULL)
//	{
//		temp = *head;
//		*head = (*head)->next;
//		free(temp);
//	}
//}
////----------------------------------------------------------------------------------------------------------
//	/*
//	 * C Program to Print the Alternate Nodes in a Linked List without
//	 * using Recursion
//	 */
// #include <stdio.h>
// #include <stdlib.h>
// struct node
//{
//	int a;
//	struct node* next;
//};
// void generate(struct node**);
// void display(struct node*);
// void delete(struct node**);
// int main()
//{
//	struct node* head = NULL;
//	generate(&head);
//	printf("\nDisplaying the alternate nodes\n");
//	display(head);
//	delete(&head);
//	return 0;
//}
// void display(struct node* head)
//{
//	int flag = 0;
//	while (head != NULL)
//	{
//		if (!(flag % 2))
//		{
//			printf("%d  ", head->a);
//		}
//		flag++;
//		head = head->next;
//	}
//}
// void generate(struct node** head)
//{
//	int num, i;
//	struct node* temp;
//	printf("Enter length of list: ");
//	scanf_f("%d", &num);
//	for (i = num; i > 0; i--)
//	{
//		temp = (struct node*)malloc(sizeof(struct node));
//		temp->a = i;
//		if (*head == NULL)
//		{
//			*head = temp;
//			(*head)->next = NULL;
//		}
//		else
//		{
//			temp->next = *head;
//			*head = temp;
//		}
//	}
//}
// void delete(struct node** head)
//{
//	struct node* temp;
//	while (*head != NULL)
//	{
//		temp = *head;
//		*head = (*head)->next;
//		free(temp);
//	}
//}}
////---------------------------------------------------------------------------------------------------------
///*
// * C Program to Implement a Stack using Linked List
// */
// #include <stdio.h>
// #include <stdlib.h>
// struct node
//{
//	int info;
//	struct node* ptr;
//}*top, * top1, * temp;
// int topelement();
// void push(int data);
// void pop();
// void empty();
// void display();
// void destroy();
// void stack_count();
// void create();
// int count = 0;
// void main()
//{
//	int no, ch, e;
//	printf("\n 1 - Push");
//	printf("\n 2 - Pop");
//	printf("\n 3 - Top");
//	printf("\n 4 - Empty");
//	printf("\n 5 - Exit");
//	printf("\n 6 - Dipslay");
//	printf("\n 7 - Stack Count");
//	printf("\n 8 - Destroy stack");
//	create();
//	while (1)
//	{
//		printf("\n Enter choice : ");
//		scanf_f("%d", &ch);
//		switch (ch)
//		{
//		case 1:
//			printf("Enter data : ");
//			scanf_f("%d", &no);
//			push(no);
//			break;
//		case 2:
//			pop();
//			break;
//		case 3:
//			if (top == NULL)
//				printf("No elements in stack");
//			else
//			{
//				e = topelement();
//				printf("\n Top element : %d", e);
//			}
//			break;
//		case 4:
//			empty();
//			break;
//		case 5:
//			exit(0);
//		case 6:
//			display();
//			break;
//		case 7:
//			stack_count();
//			break;
//		case 8:
//			destroy();
//			break;
//		default:
//			printf(" Wrong choice, Please enter correct choice  ");
//			break;
//		}
//	}
//}
///* Create empty stack */
// void create()
//{
//	top = NULL;
// }
///* Count stack elements */
// void stack_count()
//{
//	printf("\n No. of elements in stack : %d", count);
// }
///* Push data into stack */
// void push(int data)
//{
//	if (top == NULL)
//	{
//		top = (struct node*)malloc(1 * sizeof(struct node));
//		top->ptr = NULL;
//		top->info = data;
//	}
//	else
//	{
//		temp = (struct node*)malloc(1 * sizeof(struct node));
//		temp->ptr = top;
//		temp->info = data;
//		top = temp;
//	}
//	count++;
// }
///* Display stack elements */
// void display()
//{
//	top1 = top;
//	if (top1 == NULL)
//	{
//		printf("Stack is empty");
//		return;
//	}
//	while (top1 != NULL)
//	{
//		printf("%d ", top1->info);
//		top1 = top1->ptr;
//	}
// }
///* Pop Operation on stack */
// void pop()
//{
//	top1 = top;
//	if (top1 == NULL)
//	{
//		printf("\n Error : Trying to pop from empty stack");
//		return;
//	}
//	else
//		top1 = top1->ptr;
//	printf("\n Popped value : %d", top->info);
//	free(top);
//	top = top1;
//	count--;
// }
///* Return top element */
// int topelement()
//{
//	return(top->info);
// }
///* Check if stack is empty or not */
// void empty()
//{
//	if (top == NULL)
//		printf("\n Stack is empty");
//	else
//		printf("\n Stack is not empty with %d elements", count);
// }
///* Destroy entire stack */
// void destroy()
//{
//	top1 = top;
//	while (top1 != NULL)
//	{
//		top1 = top->ptr;
//		free(top);
//		top = top1;
//		top1 = top1->ptr;
//	}
//	free(top1);
//	top = NULL;
//	printf("\n All stack elements destroyed");
//	count = 0;
// }
////---------------------------------------------------------------------------------------------------------
//	/*
//	 * C Program to Demonstrate Circular Single Linked List
//	 */
// #include <stdio.h>
// #include <stdlib.h>
// struct node
//{
//	int data;
//	struct node* link;
//};
// struct node* head = NULL, * x, * y, * z;
// void create();
// void ins_at_beg();
// void ins_at_pos();
// void del_at_beg();
// void del_at_pos();
// void traverse();
// void search();
// void sort();
// void update();
// void rev_traverse(struct node* p);
// void main()
//{
//	int ch;
//	printf("\n 1.Creation \n 2.Insertion at beginning \n 3.Insertion at remaining");
//	printf("\n4.Deletion at beginning \n5.Deletion at remaining \n6.traverse");
//	printf("\n7.Search\n8.sort\n9.update\n10.Exit\n");
//	while (1)
//	{
//		printf("\n Enter your choice:");
//		scanf_f("%d", &ch);
//		switch (ch)
//		{
//		case 1:
//			create();
//			break;
//		case 2:
//			ins_at_beg();
//			break;
//		case 3:
//			ins_at_pos();
//			break;
//		case 4:
//			del_at_beg();
//			break;
//		case 5:
//			del_at_pos();
//			break;
//		case 6:
//			traverse();
//			break;
//		case 7:
//			search();
//			break;
//		case 8:
//			sort();
//			break;
//		case 9:
//			update();
//			break;
//		case 10:
//			rev_traverse(head);
//			break;
//		default:
//			exit(0);
//		}
//	}
//}
///*Function to create a new circular linked list*/
// void create()
//{
//	int c;
//	x = (struct node*)malloc(sizeof(struct node));
//	printf("\n Enter the data:");
//	scanf_f("%d", &x->data);
//	x->link = x;
//	head = x;
//	printf("\n If you wish to continue press 1 otherwise 0:");
//	scanf_f("%d", &c);
//	while (c != 0)
//	{
//		y = (struct node*)malloc(sizeof(struct node));
//		printf("\n Enter the data:");
//		scanf_f("%d", &y->data);
//		x->link = y;
//		y->link = head;
//		x = y;
//		printf("\n If you wish to continue press 1 otherwise 0:");
//		scanf_f("%d", &c);
//	}
// }
///*Function to insert an element at the begining of the list*/
// void ins_at_beg()
//{
//	x = head;
//	y = (struct node*)malloc(sizeof(struct node));
//	printf("\n Enter the data:");
//	scanf_f("%d", &y->data);
//	while (x->link != head)
//	{
//		x = x->link;
//	}
//	x->link = y;
//	y->link = head;
//	head = y;
// }
///*Function to insert an element at any position the list*/
// void ins_at_pos()
//{
//	struct node* ptr;
//	int c = 1, pos, count = 1;
//	y = (struct node*)malloc(sizeof(struct node));
//	if (head == NULL)
//	{
//		printf("cannot enter an element at this place");
//	}
//	printf("\n Enter the data:");
//	scanf_f("%d", &y->data);
//	printf("\n Enter the position to be inserted:");
//	scanf_f("%d", &pos);
//	x = head;
//	ptr = head;
//	while (ptr->link != head)
//	{
//		count++;
//		ptr = ptr->link;
//	}
//	count++;
//	if (pos > count)
//	{
//		printf("OUT OF BOUND");
//		return;
//	}
//	while (c < pos)
//	{
//		z = x;
//		x = x->link;
//		c++;
//	}
//	y->link = x;
//	z->link = y;
// }
///*Function to delete an element at any begining of the list*/
// void del_at_beg()
//{
//	if (head == NULL)
//		printf("\n List is empty");
//	else
//	{
//		x = head;
//		y = head;
//		while (x->link != head)
//		{
//			x = x->link;
//		}
//		head = y->link;
//		x->link = head;
//		free(y);
//	}
// }
///*Function to delete an element at any position the list*/
// void del_at_pos()
//{
//	if (head == NULL)
//		printf("\n List is empty");
//	else
//	{
//		int c = 1, pos;
//		printf("\n Enter the position to be deleted:");
//		scanf_f("%d", &pos);
//		x = head;
//		while (c < pos)
//		{
//			y = x;
//			x = x->link;
//			c++;
//		}
//		y->link = x->link;
//		free(x);
//	}
// }
///*Function to display the elements in the list*/
// void traverse()
//{
//	if (head == NULL)
//		printf("\n List is empty");
//	else
//	{
//		x = head;
//		while (x->link != head)
//		{
//			printf("%d->", x->data);
//			x = x->link;
//		}
//		printf("%d", x->data);
//	}
// }
///*Function to search an element in the list*/
// void search()
//{
//	int search_val, count = 0, flag = 0;
//	printf("\nenter the element to search\n");
//	scanf_f("%d", &search_val);
//	if (head == NULL)
//		printf("\nList is empty nothing to search");
//	else
//	{
//		x = head;
//		while (x->link != head)
//		{
//			if (x->data == search_val)
//			{
//				printf("\nthe element is found at %d", count);
//				flag = 1;
//				break;
//			}
//			count++;
//			x = x->link;
//		}
//		if (x->data == search_val)
//		{
//			printf("element found at postion %d", count);
//		}
//		if (flag == 0)
//		{
//			printf("\nelement not found");
//		}
//	}
// }
///*Function to sort the list in ascending order*/
// void sort()
//{
//	struct node* ptr, * nxt;
//	int temp;
//	if (head == NULL)
//	{
//		printf("empty linkedlist");
//	}
//	else
//	{
//		ptr = head;
//		while (ptr->link != head)
//		{
//			nxt = ptr->link;
//			while (nxt != head)
//			{
//				if (nxt != head)
//				{
//					if (ptr->data > nxt->data)
//					{
//						temp = ptr->data;
//						ptr->data = nxt->data;
//						nxt->data = temp;
//					}
//				}
//				else
//				{
//					break;
//				}
//				nxt = nxt->link;
//			}
//			ptr = ptr->link;
//		}
//	}
// }
///*Function to update an element at any position the list*/
// void update()
//{
//	struct node* ptr;
//	int search_val;
//	int replace_val;
//	int flag = 0;
//	if (head == NULL)
//	{
//		printf("\n empty list");
//	}
//	else
//	{
//		printf("enter the value to be edited\n");
//		scanf_f("%d", &search_val);
//		fflush(stdin);
//		printf("enter the value to be replace\n");
//		scanf_f("%d", &replace_val);
//		ptr = head;
//		while (ptr->link != head)
//		{
//			if (ptr->data == search_val)
//			{
//				ptr->data = replace_val;
//				flag = 1;
//				break;
//			}
//			ptr = ptr->link;
//		}
//		if (ptr->data == search_val)
//		{
//			ptr->data = replace_val;
//			flag = 1;
//		}
//		if (flag == 1)
//		{
//			printf("\nUPdate sucessful");
//		}
//		else
//		{
//			printf("\n update not successful");
//		}
//	}
// }
///*Function to display the elements of the list in reverse order*/
// void rev_traverse(struct node* p)
//{
//	int i = 0;
//	if (head == NULL)
//	{
//		printf("empty linked list");
//	}
//	else
//	{
//		if (p->link != head)
//		{
//			i = p->data;
//			rev_traverse(p->link);
//			printf(" %d", i);
//		}
//		if (p->link == head)
//		{
//			printf(" %d", p->data);
//		}
//	}
// }
////------------------------------------------------------------------------------------------------------------
///*
// * C Program to Implement Doubly Linked List using Singly Linked List
// */
// #include <stdio.h>
// #include <stdlib.h>
// struct node
//{
//	int num;
//	struct node* next;
//};
// void create(struct node**);
// void move(struct node*);
// void release(struct node**);
// void display(struct node*);
// int main()
//{
//	struct node* p = NULL, * q = NULL;
//	int result, count;
//	printf("Enter data into the list\n");
//	create(&p);
//	printf("Displaying list:\n");
//	display(p);
//	move(p);
//	release(&p);
//	return 0;
//}
// void move(struct node* head)
//{
//	struct node* p, * q;
//	int ch;
//	p = q = head;
//	printf("\nPointer at %d\n", head->num);
//	do
//	{
//		printf("Select option:\n1. Move front\n2. Move back\n3. Exit\nYour choice: ");
//		scanf_f("%d", &ch);
//		switch (ch)
//		{
//		case 1: if (q->next != NULL)
//		{
//			q = q->next;
//			printf("\nPointer at %d\n", q->num);
//		}
//			  else
//		{
//			printf("\nPointer at last node %d. Cannot move ahead.\n", q->num);
//		}
//			  break;
//		case 2: while (p->next != q)
//		{
//			p = p->next;
//		}
//			  if (p == q)
//			  {
//				  printf("\nPointer at first node %d. Cannot move behind.\n", q->num);
//			  }
//			  else
//			  {
//				  q = p;
//				  p = head;
//				  printf("\nPointer at %d\n", q->num);
//			  }
//			  break;
//		case 3: return;
//		default: printf("\nInvalid choice entered. Try again\n");
//		}
//	} while (1);
//}
// void create(struct node** head)
//{
//	int c, ch;
//	struct node* temp, * rear;
//	do
//	{
//		printf("Enter number: ");
//		scanf_f("%d", &c);
//		temp = (struct node*)malloc(sizeof(struct node));
//		temp->num = c;
//		temp->next = NULL;
//		if (*head == NULL)
//		{
//			*head = temp;
//		}
//		else
//		{
//			rear->next = temp;
//		}
//		rear = temp;
//		printf("Do you wish to continue [1/0]: ");
//		scanf_f("%d", &ch);
//	} while (ch != 0);
//	printf("\n");
//}
// void display(struct node* head)
//{
//	while (head != NULL)
//	{
//		printf("%d\t", head->num);
//		head = head->next;
//	}
//	printf("\n");
//}
// void release(struct node** head)
//{
//	struct node* temp;
//	while ((*head) != NULL)
//	{
//		temp = *head;
//		(*head) = (*head)->next;
//		free(temp);
//	}
//	//-----------------------------------------------------------------------------------------------------------
//		/*
//		 * C Program to Implement Singly Linked List using Dynamic Memory Allocation
//		 */
// #include <stdio.h>
// #include <malloc.h>
// #define ISEMPTY printf("\nEMPTY LIST:");
//		 /*
//		  * Node Declaration
//		  */
//	struct node
//	{
//		int value;
//		struct node* next;
//	};
//	snode* create_node(int);
//	void insert_node_first();
//	void insert_node_last();
//	void insert_node_pos();
//	void sorted_ascend();
//	void delete_pos();
//	void search();
//	void update_val();
//	void display();
//	void rev_display(snode*);
//	typedef struct node snode;
//	snode* newnode, * ptr, * prev, * temp;
//	snode* first = NULL, * last = NULL;
//	/*
//	 * Main :contains menu
//	 */
//	int main()
//	{
//		int ch;
//		char ans = 'Y';
//		while (ans == 'Y' || ans == 'y')
//		{
//			printf("\n---------------------------------\n");
//			printf("\nOperations on singly linked list\n");
//			printf("\n---------------------------------\n");
//			printf("\n1.Insert node at first");
//			printf("\n2.Insert node at last");
//			printf("\n3.Insert node at position");
//			printf("\n4.Sorted Linked List in Ascending Order");
//			printf("\n5.Delete Node from any Position");
//			printf("\n6.Update Node Value");
//			printf("\n7.Search Element in the linked list");
//			printf("\n8.Display List from Beginning to end");
//			printf("\n9.Display List from end using Recursion");
//			printf("\n10.Exit\n");
//			printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
//			printf("\nEnter your choice");
//			scanf_f("%d", &ch);
//			switch (ch)
//			{
//			case 1:
//				printf("\n...Inserting node at first...\n");
//				insert_node_first();
//				break;
//			case 2:
//				printf("\n...Inserting node at last...\n");
//				insert_node_last();
//				break;
//			case 3:
//				printf("\n...Inserting node at position...\n");
//				insert_node_pos();
//				break;
//			case 4:
//				printf("\n...Sorted Linked List in Ascending Order...\n");
//				sorted_ascend();
//				break;
//			case 5:
//				printf("\n...Deleting Node from any Position...\n");
//				delete_pos();
//				break;
//			case 6:
//				printf("\n...Updating Node Value...\n");
//				update_val();
//				break;
//			case 7:
//				printf("\n...Searching Element in the List...\n");
//				search();
//				break;
//			case 8:
//				printf("\n...Displaying List From Beginning to End...\n");
//				display();
//				break;
//			case 9:
//				printf("\n...Displaying List From End using Recursion...\n");
//				rev_display(first);
//				break;
//			case 10:
//				printf("\n...Exiting...\n");
//				return 0;
//				break;
//			default:
//				printf("\n...Invalid Choice...\n");
//				break;
//			}
//			printf("\nYOU WANT TO CONTINUE (Y/N)");
//			scanf_f(" %c", &ans);
//		}
//		return 0;
//	}
//	/*
//	 * Creating Node
//	 */
//	snode* create_node(int val)
//	{
//		newnode = (snode*)malloc(sizeof(snode));
//		if (newnode == NULL)
//		{
//			printf("\nMemory was not allocated");
//			return 0;
//		}
//		else
//		{
//			newnode->value = val;
//			newnode->next = NULL;
//			return newnode;
//		}
//	}
//	/*
//	 * Inserting Node at First
//	 */
//	void insert_node_first()
//	{
//		int val;
//		printf("\nEnter the value for the node:");
//		scanf_f("%d", &val);
//		newnode = create_node(val);
//		if (first == last && first == NULL)
//		{
//			first = last = newnode;
//			first->next = NULL;
//			last->next = NULL;
//		}
//		else
//		{
//			temp = first;
//			first = newnode;
//			first->next = temp;
//		}
//		printf("\n----INSERTED----");
//	}
//	/*
//	 * Inserting Node at Last
//	 */
//	void insert_node_last()
//	{
//		int val;
//		printf("\nEnter the value for the Node:");
//		scanf_f("%d", &val);
//		newnode = create_node(val);
//		if (first == last && last == NULL)
//		{
//			first = last = newnode;
//			first->next = NULL;
//			last->next = NULL;
//		}
//		else
//		{
//			last->next = newnode;
//			last = newnode;
//			last->next = NULL;
//		}
//		printf("\n----INSERTED----");
//	}
//	/*
//	 * Inserting Node at position
//	 */
//	void insert_node_pos()
//	{
//		int pos, val, cnt = 0, i;
//		printf("\nEnter the value for the Node:");
//		scanf_f("%d", &val);
//		newnode = create_node(val);
//		printf("\nEnter the position ");
//		scanf_f("%d", &pos);
//		ptr = first;
//		while (ptr != NULL)
//		{
//			ptr = ptr->next;
//			cnt++;
//		}
//		if (pos == 1)
//		{
//			if (first == last && first == NULL)
//			{
//				first = last = newnode;
//				first->next = NULL;
//				last->next = NULL;
//			}
//			else
//			{
//				temp = first;
//				first = newnode;
//				first->next = temp;
//			}
//			printf("\nInserted");
//		}
//		else if (pos > 1 && pos <= cnt)
//		{
//			ptr = first;
//			for (i = 1; i < pos; i++)
//			{
//				prev = ptr;
//				ptr = ptr->next;
//			}
//			prev->next = newnode;
//			newnode->next = ptr;
//			printf("\n----INSERTED----");
//		}
//		else
//		{
//			printf("Position is out of range");
//		}
//	}
//	/*
//	 * Sorted Linked List
//	 */
//	void sorted_ascend()
//	{
//		snode* nxt;
//		int t;
//		if (first == NULL)
//		{
//			ISEMPTY;
//			printf(":No elements to sort\n");
//		}
//		else
//		{
//			for (ptr = first; ptr != NULL; ptr = ptr->next)
//			{
//				for (nxt = ptr->next; nxt != NULL; nxt = nxt->next)
//				{
//					if (ptr->value > nxt->value)
//					{
//						t = ptr->value;
//						ptr->value = nxt->value;
//						nxt->value = t;
//					}
//				}
//			}
//			printf("\n---Sorted List---");
//			for (ptr = first; ptr != NULL; ptr = ptr->next)
//			{
//				printf("%d\t", ptr->value);
//			}
//		}
//	}
//	/*
//	 * Delete Node from specified position in a non-empty list
//	 */
//	void delete_pos()
//	{
//		int pos, cnt = 0, i;
//		if (first == NULL)
//		{
//			ISEMPTY;
//			printf(":No node to delete\n");
//		}
//		else
//		{
//			printf("\nEnter the position of value to be deleted:");
//			scanf_f(" %d", &pos);
//			ptr = first;
//			if (pos == 1)
//			{
//				first = ptr->next;
//				printf("\nElement deleted");
//			}
//			else
//			{
//				while (ptr != NULL)
//				{
//					ptr = ptr->next;
//					cnt = cnt + 1;
//				}
//				if (pos > 0 && pos <= cnt)
//				{
//					ptr = first;
//					for (i = 1; i < pos; i++)
//					{
//						prev = ptr;
//						ptr = ptr->next;
//					}
//					prev->next = ptr->next;
//				}
//				else
//				{
//					printf("Position is out of range");
//				}
//				free(ptr);
//				printf("\nElement deleted");
//			}
//		}
//	}
//	/*
//	 * Updating Node value in a non-empty list
//	 */
//	void update_val()
//	{
//		int oldval, newval, flag = 0;
//		if (first == NULL)
//		{
//			ISEMPTY;
//			printf(":No nodes in the list to update\n");
//		}
//		else
//		{
//			printf("\nEnter the value to be updated:");
//			scanf_f("%d", &oldval);
//			printf("\nEnter the newvalue:");
//			scanf_f("%d", &newval);
//			for (ptr = first; ptr != NULL; ptr = ptr->next)
//			{
//				if (ptr->value == oldval)
//				{
//					ptr->value = newval;
//					flag = 1;
//					break;
//				}
//			}
//			if (flag == 1)
//			{
//				printf("\nUpdated Successfully");
//			}
//			else
//			{
//				printf("\nValue not found in List");
//			}
//		}
//	}
//	/*
//	 * searching an element in a non-empty list
//	 */
//	void search()
//	{
//		int flag = 0, key, pos = 0;
//		if (first == NULL)
//		{
//			ISEMPTY;
//			printf(":No nodes in the list\n");
//		}
//		else
//		{
//			printf("\nEnter the value to search");
//			scanf_f("%d", &key);
//			for (ptr = first; ptr != NULL; ptr = ptr->next)
//			{
//				pos = pos + 1;
//				if (ptr->value == key)
//				{
//					flag = 1;
//					break;
//				}
//			}
//			if (flag == 1)
//			{
//				printf("\nElement %d found at %d position\n", key, pos);
//			}
//			else
//			{
//				printf("\nElement %d not found in list\n", key);
//			}
//		}
//	}
//	/*
//	 * Displays non-empty List from Beginning to End
//	 */
//	void display()
//	{
//		if (first == NULL)
//		{
//			ISEMPTY;
//			printf(":No nodes in the list to display\n");
//		}
//		else
//		{
//			for (ptr = first; ptr != NULL; ptr = ptr->next)
//			{
//				printf("%d\t", ptr->value);
//			}
//		}
//	}
//	/*
//	 * Display non-empty list in Reverse Order
//	 */
//	void rev_display(snode * ptr)
//	{
//		int val;
//		if (ptr == NULL)
//		{
//			ISEMPTY;
//			printf(":No nodes to display\n");
//		}
//		else
//		{
//			if (ptr != NULL)
//			{
//				val = ptr->value;
//				rev_display(ptr->next);
//				printf("%d\t", val);
//			}
//		}
//	}
//	//-----------------------------------------------------------------------------------------------------------
//	/*
//	 * C program to illustrate the operations of singly linked list
//	 */
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #define MAX 30
//	struct emp_data
//	{
//		int  empno;
//		char empName[MAX];
//		char designation[MAX];
//		struct emp_data* next;
//	};
//	/* ********************************************************************/
//	/*  Function to insert a node at the front of the linked list.        */
//	/*  front: front pointer, id: employee ID, name: employee name        */
//	/*  desg: Employee designation                                        */
//	/*  Returns the new front pointer.                                    */
//	/* ********************************************************************/
//	struct emp_data* insert(struct emp_data* front, int id, char name[],
//		char desg[])
//	{
//		struct emp_data* newnode;
//		newnode = (struct emp_data*)malloc(sizeof(struct emp_data));
//		if (newnode == NULL)
//		{
//			printf("\n Allocation failed \n");
//			exit(2);
//		}
//		newnode->empno = id;
//		strcpy(newnode->empName, name);
//		strcpy(newnode->designation, desg);
//		newnode->next = front;
//		front = newnode;
//		return(front);
//	}
//	/*  End of insert() */
//	/*  Function to display a node in a linked list */
//	void printNode(struct emp_data* p)
//	{
//		printf("\n Employee Details...\n");
//		printf("\n Emp No       : %d", p->empno);
//		printf("\n Name           : %s", p->empName);
//		printf("\n Designation    : %s\n", p->designation);
//		printf("-------------------------------------\n");
//	}
//	/*  End of printNode() */
//	/*  ********************************************************/
//	/*  Function to deleteNode a node based on employee number */
//	/*  front: front pointer, id: Key value                    */
//	/*  Returns: the modified list.                            */
//	/*  ********************************************************/
//	struct emp_data* deleteNode(struct emp_data* front, int id)
//	{
//		struct emp_data* ptr;
//		struct emp_data* bptr;
//		if (front->empno == id)
//		{
//			ptr = front;
//			printf("\n Node deleted:");
//			printNode(front);
//			front = front->next;
//			free(ptr);
//			return(front);
//		}
//		for (ptr = front->next, bptr = front; ptr != NULL; ptr = ptr->next,
//			bptr = bptr->next)
//		{
//			if (ptr->empno == id)
//			{
//				printf("\n Node deleted:");
//				printNode(ptr);
//				bptr->next = ptr->next;
//				free(ptr);
//				return(front);
//			}
//		}
//		printf("\n Employee Number %d not found ", id);
//		return(front);
//	}
//	/*  End of deleteNode() */
//	/* ****************************************************************/
//	/*  Function to search the nodes in a linear fashion based emp ID */
//	/*  front: front pointer, key: key ID.                            */
//	/* ****************************************************************/
//	void search(struct emp_data* front, int key)
//	{
//		struct emp_data* ptr;
//		for (ptr = front; ptr != NULL; ptr = ptr->next)
//		{
//			if (ptr->empno == key)
//			{
//				printf("\n Key found:");
//				printNode(ptr);
//				return;
//			}
//		}
//		printf("\n Employee Number %d not found ", key);
//	}
//	/*  End of search() */
//	/*  Function to display the linked list */
//	void display(struct emp_data* front)
//	{
//		struct emp_data* ptr;
//		for (ptr = front; ptr != NULL; ptr = ptr->next)
//		{
//			printNode(ptr);
//		}
//	}
//	/*  End of display() */
//	/*  Function to display the menu of operations on a linked list */
//	void menu()
//	{
//		printf("---------------------------------------------\n");
//		printf("Press 1 to INSERT a node into the list       \n");
//		printf("Press 2 to DELETE a node from the list       \n");
//		printf("Press 3 to DISPLAY the list                 \n");
//		printf("Press 4 to SEARCH the list                   \n");
//		printf("Press 5 to EXIT                              \n");
//		printf("---------------------------------------------\n");
//	}
//	/*  End of menu() */
//	/*  Function to select the option */
//	char option()
//	{
//		char choice;
//		printf("\n\n>> Enter your choice: ");
//		switch (choice = getche())
//		{
//		case '1':
//		case '2':
//		case '3':
//		case '4':
//		case '5':   return(choice);
//		default:   printf("\n Invalid choice.");
//		}
//		return choice;
//	}
//	/*  End of option() */
//	/*  The main() program begins */
//	void main()
//	{
//		struct emp_data* linkList;
//		char name[21], desig[51];
//		char choice;
//		int eno;
//		linkList = NULL;
//		printf("\n Welcome to demonstration of singly linked list \n");
//		menu();
//		do
//		{
//			/*  choose oeration to be performed */
//			choice = option();
//			switch (choice)
//			{
//			case '1':
//				printf("\n Enter the Employee Number      : ");
//				scanf_f("%d", &eno);
//				printf("Enter the Employee name        : ");
//				fflush(stdin);
//				gets(name);
//				printf("Enter the Employee Designation : ");
//				gets(desig);
//				linkList = insert(linkList, eno, name, desig);
//				break;
//			case '2':
//				printf("\n\n Enter the employee number to be deleted: ");
//				scanf_f("%d", &eno);
//				linkList = deleteNode(linkList, eno);
//				break;
//			case '3':
//				if (linkList == NULL)
//				{
//					printf("\n List empty.");
//					break;
//				}
//				display(linkList);
//				break;
//			case '4':
//				printf("\n\n Enter the employee number to be searched: ");
//				scanf_f("%d", &eno);
//				search(linkList, eno);
//				break;
//			case '5': break;
//			}
//		} while (choice != '5');
//	}
//	//-----------------------------------------------------------------------------------------------------------
//		/*
//		 * C Program to Implement Circular Doubly Linked List
//		 */
// #include <stdio.h>
// #include <stdlib.h>
//	struct node
//	{
//		int val;
//		struct node* next;
//		struct node* prev;
//	};
//	typedef struct node n;
//	n* create_node(int);
//	void add_node();
//	void insert_at_first();
//	void insert_at_end();
//	void insert_at_position();
//	void delete_node_position();
//	void sort_list();
//	void update();
//	void search();
//	void display_from_beg();
//	void display_in_rev();
//	n* new, * ptr, * prev;
//	n* first = NULL, * last = NULL;
//	int number = 0;
//	void main()
//	{
//		int ch;
//		printf("\n linked list\n");
//		printf("1.insert at beginning \n 2.insert at end\n 3.insert at position\n4.sort linked list\n 5.delete node at position\n 6.updatenodevalue\n7.search element \n8.displaylist from beginning\n9.display list from end\n10.exit ");
//		while (1)
//		{
//			printf("\n enter your choice:");
//			scanf_f("%d", &ch);
//			switch (ch)
//			{
//			case 1:
//				insert_at_first();
//				break;
//			case 2:
//				insert_at_end();
//				break;
//			case 3:
//				insert_at_position();
//				break;
//			case 4:
//				sort_list();
//				break;
//			case 5:
//				delete_node_position();
//				break;
//			case 6:
//				update();
//				break;
//			case 7:
//				search();
//				break;
//			case 8:
//				display_from_beg();
//				break;
//			case 9:
//				display_in_rev();
//				break;
//			case 10:
//				exit(0);
//			case 11:
//				add_node();
//				break;
//			default:
//				printf("\ninvalid choice");
//			}
//		}
//	}
//	/*
//	 *MEMORY ALLOCATED FOR NODE DYNAMICALLY
//	 */
//	n* create_node(int info)
//	{
//		number++;
//		new = (n*)malloc(sizeof(n));
//		new->val = info;
//		new->next = NULL;
//		new->prev = NULL;
//		return new;
//	}
//	/*
//	 *ADDS NEW NODE
//	 */
//	void add_node()
//	{
//		int info;
//		printf("\nenter the value you would like to add:");
//		scanf_f("%d", &info);
//		new = create_node(info);
//		if (first == last && first == NULL)
//		{
//			first = last = new;
//			first->next = last->next = NULL;
//			first->prev = last->prev = NULL;
//		}
//		else
//		{
//			last->next = new;
//			new->prev = last;
//			last = new;
//			last->next = first;
//			first->prev = last;
//		}
//	}
//	/*
//	 *INSERTS ELEMENT AT FIRST
//	 */
//	void insert_at_first()
//	{
//		int info;
//		printf("\nenter the value to be inserted at first:");
//		scanf_f("%d", &info);
//		new = create_node(info);
//		if (first == last && first == NULL)
//		{
//			printf("\ninitially it is empty linked list later insertion is done");
//			first = last = new;
//			first->next = last->next = NULL;
//			first->prev = last->prev = NULL;
//		}
//		else
//		{
//			new->next = first;
//			first->prev = new;
//			first = new;
//			first->prev = last;
//			last->next = first;
//			printf("\n the value is inserted at begining");
//		}
//	}
//	/*
//	 *INSERTS ELEMNET AT END
//	 */
//	void insert_at_end()
//	{
//		int info;
//		printf("\nenter the value that has to be inserted at last:");
//		scanf_f("%d", &info);
//		new = create_node(info);
//		if (first == last && first == NULL)
//		{
//			printf("\ninitially the list is empty and now new node is inserted but at first");
//			first = last = new;
//			first->next = last->next = NULL;
//			first->prev = last->prev = NULL;
//		}
//		else
//		{
//			last->next = new;
//			new->prev = last;
//			last = new;
//			first->prev = last;
//			last->next = first;
//		}
//	}
//	/*
//	 *INSERTS THE ELEMENT AT GIVEN POSITION
//	 */
//	void insert_at_position()
//	{
//		int info, pos, len = 0, i;
//		n* prevnode;
//		printf("\n enter the value that you would like to insert:");
//		scanf_f("%d", &info);
//		printf("\n enter the position where you have to enter:");
//		scanf_f("%d", &pos);
//		new = create_node(info);
//		if (first == last && first == NULL)
//		{
//			if (pos == 1)
//			{
//				first = last = new;
//				first->next = last->next = NULL;
//				first->prev = last->prev = NULL;
//			}
//			else
//				printf("\n empty linked list you cant insert at that particular position");
//		}
//		else
//		{
//			if (number < pos)
//				printf("\n node cant be inserted as position is exceeding the linkedlist length");
//			else
//			{
//				for (ptr = first, i = 1; i <= number; i++)
//				{
//					prevnode = ptr;
//					ptr = ptr->next;
//					if (i == pos - 1)
//					{
//						prevnode->next = new;
//						new->prev = prevnode;
//						new->next = ptr;
//						ptr->prev = new;
//						printf("\ninserted at position %d succesfully", pos);
//						break;
//					}
//				}
//			}
//		}
//	}
//	/*
//	 *SORTING IS DONE OF ONLY NUMBERS NOT LINKS
//	 */
//	void sort_list()
//	{
//		n* temp;
//		int tempval, i, j;
//		if (first == last && first == NULL)
//			printf("\nlinked list is empty no elements to sort");
//		else
//		{
//			for (ptr = first, i = 0; i < number; ptr = ptr->next, i++)
//			{
//				for (temp = ptr->next, j = i; j < number; j++)
//				{
//					if (ptr->val > temp->val)
//					{
//						tempval = ptr->val;
//						ptr->val = temp->val;
//						temp->val = tempval;
//					}
//				}
//			}
//			for (ptr = first, i = 0; i < number; ptr = ptr->next, i++)
//				printf("\n%d", ptr->val);
//		}
//	}
//	/*
//	 *DELETION IS DONE
//	 */
//	void delete_node_position()
//	{
//		int pos, count = 0, i;
//		n* temp, * prevnode;
//		printf("\n enter the position which u wanted to delete:");
//		scanf_f("%d", &pos);
//		if (first == last && first == NULL)
//			printf("\n empty linked list you cant delete");
//		else
//		{
//			if (number < pos)
//				printf("\n node cant be deleted at position as it is exceeding the linkedlist length");
//			else
//			{
//				for (ptr = first, i = 1; i <= number; i++)
//				{
//					prevnode = ptr;
//					ptr = ptr->next;
//					if (pos == 1)
//					{
//						number--;
//						last->next = prevnode->next;
//						ptr->prev = prevnode->prev;
//						first = ptr;
//						printf("%d is deleted", prevnode->val);
//						free(prevnode);
//						break;
//					}
//					else if (i == pos - 1)
//					{
//						number--;
//						prevnode->next = ptr->next;
//						ptr->next->prev = prevnode;
//						printf("%d is deleted", ptr->val);
//						free(ptr);
//						break;
//					}
//				}
//			}
//		}
//	}
//	/*
//	 *UPDATION IS DONE FRO GIVEN OLD VAL
//	 */
//	void update()
//	{
//		int oldval, newval, i, f = 0;
//		printf("\n enter the value old value:");
//		scanf_f("%d", &oldval);
//		printf("\n enter the value new value:");
//		scanf_f("%d", &newval);
//		if (first == last && first == NULL)
//			printf("\n list is empty no elemnts for updation");
//		else
//		{
//			for (ptr = first, i = 0; i < number; ptr = ptr->next, i++)
//			{
//				if (ptr->val == oldval)
//				{
//					ptr->val = newval;
//					printf("value is updated to %d", ptr->val);
//					f = 1;
//				}
//			}
//			if (f == 0)
//				printf("\n no such old value to be get updated");
//		}
//	}
//	/*
//	 *SEARCHING USING SINGLE KEY
//	 */
//	void search()
//	{
//		int count = 0, key, i, f = 0;
//		printf("\nenter the value to be searched:");
//		scanf_f("%d", &key);
//		if (first == last && first == NULL)
//			printf("\nlist is empty no elemnets in list to search");
//		else
//		{
//			for (ptr = first, i = 0; i < number; i++, ptr = ptr->next)
//			{
//				count++;
//				if (ptr->val == key)
//				{
//					printf("\n the value is found at position at %d", count);
//					f = 1;
//				}
//			}
//			if (f == 0)
//				printf("\n the value is not found in linkedlist");
//		}
//	}
//	/*
//	 *DISPLAYING IN BEGINNING
//	 */
//	void display_from_beg()
//	{
//		int i;
//		if (first == last && first == NULL)
//			printf("\nlist is empty no elemnts to print");
//		else
//		{
//			printf("\n%d number of nodes are there", number);
//			for (ptr = first, i = 0; i < number; i++, ptr = ptr->next)
//				printf("\n %d", ptr->val);
//		}
//	}
//	/*
//	 * DISPLAYING IN REVERSE
//	 */
//	void display_in_rev()
//	{
//		int i;
//		if (first == last && first == NULL)
//			printf("\nlist is empty there are no elments");
//		else
//		{
//			for (ptr = last, i = 0; i < number; i++, ptr = ptr->prev)
//			{
//				printf("\n%d", ptr->val);
//			}
//		}
//	}
//	//----------------------------------------------------------------------------------------------------------
//		/*
//		 * C Program to Implement Binary Tree using Linked List
//		 */
// #include <stdio.h>
// #include <malloc.h>
//	struct node {
//		struct node* left;
//		char data;
//		struct node* right;
//	};
//	struct node* constructTree(int);
//	void inorder(struct node*);
//	char array[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', '\0', '\0', 'H' };
//	int leftcount[] = { 1,   3,   5,   -1,   9,  -1,  -1,   -1,   -1,  -1 };
//	int rightcount[] = { 2,   4,   6,   -1,  -1,  -1,  -1,   -1,   -1,  -1 };
//	void main() {
//		struct node* root;
//		root = constructTree(0);
//		printf("In-order Traversal: \n");
//		inorder(root);
//	}
//	struct node* constructTree(int index) {
//		struct node* temp = NULL;
//		if (index != -1) {
//			temp = (struct node*)malloc(sizeof(struct node));
//			temp->left = constructTree(leftcount[index]);
//			temp->data = array[index];
//			temp->right = constructTree(rightcount[index]);
//		}
//		return temp;
//	}
//	void inorder(struct node* root) {
//		if (root != NULL) {
//			inorder(root->left);
//			printf("%c\t", root->data);
//			inorder(root->right);
//		}
//	}
//	//-----------------------------------------------------------------------------------------------------------
//	/*
//	 * C Program to Implement a Doubly Linked List & provide Insertion, Deletion & Display Operations
//	 */
// #include <stdio.h>
// #include <stdlib.h>
//	struct node
//	{
//		struct node* prev;
//		int n;
//		struct node* next;
//	}*h, * temp, * temp1, * temp2, * temp4;
//	void insert1();
//	void insert2();
//	void insert3();
//	void traversebeg();
//	void traverseend(int);
//	void sort();
//	void search();
//	void update();
//	void delete();
//	int count = 0;
//	void main()
//	{
//		int ch;
//		h = NULL;
//		temp = temp1 = NULL;
//		printf("\n 1 - Insert at beginning");
//		printf("\n 2 - Insert at end");
//		printf("\n 3 - Insert at position i");
//		printf("\n 4 - Delete at i");
//		printf("\n 5 - Display from beginning");
//		printf("\n 6 - Display from end");
//		printf("\n 7 - Search for element");
//		printf("\n 8 - Sort the list");
//		printf("\n 9 - Update an element");
//		printf("\n 10 - Exit");
//		while (1)
//		{
//			printf("\n Enter choice : ");
//			scanf_f("%d", &ch);
//			switch (ch)
//			{
//			case 1:
//				insert1();
//				break;
//			case 2:
//				insert2();
//				break;
//			case 3:
//				insert3();
//				break;
//			case 4:
//				delete();
//				break;
//			case 5:
//				traversebeg();
//				break;
//			case 6:
//				temp2 = h;
//				if (temp2 == NULL)
//					printf("\n Error : List empty to display ");
//				else
//				{
//					printf("\n Reverse order of linked list is : ");
//					traverseend(temp2->n);
//				}
//				break;
//			case 7:
//				search();
//				break;
//			case 8:
//				sort();
//				break;
//			case 9:
//				update();
//				break;
//			case 10:
//				exit(0);
//			default:
//				printf("\n Wrong choice menu");
//			}
//		}
//	}
//	/* TO create an empty node */
//	void create()
//	{
//		int data;
//		temp = (struct node*)malloc(1 * sizeof(struct node));
//		temp->prev = NULL;
//		temp->next = NULL;
//		printf("\n Enter value to node : ");
//		scanf_f("%d", &data);
//		temp->n = data;
//		count++;
//	}
//	/*  TO insert at beginning */
//	void insert1()
//	{
//		if (h == NULL)
//		{
//			create();
//			h = temp;
//			temp1 = h;
//		}
//		else
//		{
//			create();
//			temp->next = h;
//			h->prev = temp;
//			h = temp;
//		}
//	}
//	/* To insert at end */
//	void insert2()
//	{
//		if (h == NULL)
//		{
//			create();
//			h = temp;
//			temp1 = h;
//		}
//		else
//		{
//			create();
//			temp1->next = temp;
//			temp->prev = temp1;
//			temp1 = temp;
//		}
//	}
//	/* To insert at any position */
//	void insert3()
//	{
//		int pos, i = 2;
//		printf("\n Enter position to be inserted : ");
//		scanf_f("%d", &pos);
//		temp2 = h;
//		if ((pos < 1) || (pos >= count + 1))
//		{
//			printf("\n Position out of range to insert");
//			return;
//		}
//		if ((h == NULL) && (pos != 1))
//		{
//			printf("\n Empty list cannot insert other than 1st position");
//			return;
//		}
//		if ((h == NULL) && (pos == 1))
//		{
//			create();
//			h = temp;
//			temp1 = h;
//			return;
//		}
//		else
//		{
//			while (i < pos)
//			{
//				temp2 = temp2->next;
//				i++;
//			}
//			create();
//			temp->prev = temp2;
//			temp->next = temp2->next;
//			temp2->next->prev = temp;
//			temp2->next = temp;
//		}
//	}
//	/* To delete an element */
//	void delete()
//	{
//		int i = 1, pos;
//		printf("\n Enter position to be deleted : ");
//		scanf_f("%d", &pos);
//		temp2 = h;
//		if ((pos < 1) || (pos >= count + 1))
//		{
//			printf("\n Error : Position out of range to delete");
//			return;
//		}
//		if (h == NULL)
//		{
//			printf("\n Error : Empty list no elements to delete");
//			return;
//		}
//		else
//		{
//			while (i < pos)
//			{
//				temp2 = temp2->next;
//				i++;
//			}
//			if (i == 1)
//			{
//				if (temp2->next == NULL)
//				{
//					printf("Node deleted from list");
//					free(temp2);
//					temp2 = h = NULL;
//					return;
//				}
//			}
//			if (temp2->next == NULL)
//			{
//				temp2->prev->next = NULL;
//				free(temp2);
//				printf("Node deleted from list");
//				return;
//			}
//			temp2->next->prev = temp2->prev;
//			if (i != 1)
//				temp2->prev->next = temp2->next;    /* Might not need this statement if i == 1 check */
//			if (i == 1)
//				h = temp2->next;
//			printf("\n Node deleted");
//			free(temp2);
//		}
//		count--;
//	}
//	/* Traverse from beginning */
//	void traversebeg()
//	{
//		temp2 = h;
//		if (temp2 == NULL)
//		{
//			printf("List empty to display \n");
//			return;
//		}
//		printf("\n Linked list elements from begining : ");
//		while (temp2->next != NULL)
//		{
//			printf(" %d ", temp2->n);
//			temp2 = temp2->next;
//		}
//		printf(" %d ", temp2->n);
//	}
//	/* To traverse from end recursively */
//	void traverseend(int i)
//	{
//		if (temp2 != NULL)
//		{
//			i = temp2->n;
//			temp2 = temp2->next;
//			traverseend(i);
//			printf(" %d ", i);
//		}
//	}
//	/* To search for an element in the list */
//	void search()
//	{
//		int data, count = 0;
//		temp2 = h;
//		if (temp2 == NULL)
//		{
//			printf("\n Error : List empty to search for data");
//			return;
//		}
//		printf("\n Enter value to search : ");
//		scanf_f("%d", &data);
//		while (temp2 != NULL)
//		{
//			if (temp2->n == data)
//			{
//				printf("\n Data found in %d position", count + 1);
//				return;
//			}
//			else
//				temp2 = temp2->next;
//			count++;
//		}
//		printf("\n Error : %d not found in list", data);
//	}
//	/* To update a node value in the list */
//	void update()
//	{
//		int data, data1;
//		printf("\n Enter node data to be updated : ");
//		scanf_f("%d", &data);
//		printf("\n Enter new data : ");
//		scanf_f("%d", &data1);
//		temp2 = h;
//		if (temp2 == NULL)
//		{
//			printf("\n Error : List empty no node to update");
//			return;
//		}
//		while (temp2 != NULL)
//		{
//			if (temp2->n == data)
//			{
//				temp2->n = data1;
//				traversebeg();
//				return;
//			}
//			else
//				temp2 = temp2->next;
//		}
//		printf("\n Error : %d not found in list to update", data);
//	}
//	/* To sort the linked list */
//	void sort()
//	{
//		int i, j, x;
//		temp2 = h;
//		temp4 = h;
//		if (temp2 == NULL)
//		{
//			printf("\n List empty to sort");
//			return;
//		}
//		for (temp2 = h; temp2 != NULL; temp2 = temp2->next)
//		{
//			for (temp4 = temp2->next; temp4 != NULL; temp4 = temp4->next)
//			{
//				if (temp2->n > temp4->n)
//				{
//					x = temp2->n;
//					temp2->n = temp4->n;
//					temp4->n = x;
//				}
//			}
//		}
//		traversebeg();
//	}
//	//----------------------------------------------------------------------------------------------------------
//	/*
//	 * C Program to Implement Queue Data Structure using Linked List
//	 */
// #include <stdio.h>
// #include <stdlib.h>
//	struct node
//	{
//		int info;
//		struct node* ptr;
//	}*front, * rear, * temp, * front1;
//	int frontelement();
//	void enq(int data);
//	void deq();
//	void empty();
//	void display();
//	void create();
//	void queuesize();
//	int count = 0;
//	void main()
//	{
//		int no, ch, e;
//		printf("\n 1 - Enque");
//		printf("\n 2 - Deque");
//		printf("\n 3 - Front element");
//		printf("\n 4 - Empty");
//		printf("\n 5 - Exit");
//		printf("\n 6 - Display");
//		printf("\n 7 - Queue size");
//		create();
//		while (1)
//		{
//			printf("\n Enter choice : ");
//			scanf_f("%d", &ch);
//			switch (ch)
//			{
//			case 1:
//				printf("Enter data : ");
//				scanf_f("%d", &no);
//				enq(no);
//				break;
//			case 2:
//				deq();
//				break;
//			case 3:
//				e = frontelement();
//				if (e != 0)
//					printf("Front element : %d", e);
//				else
//					printf("\n No front element in Queue as queue is empty");
//				break;
//			case 4:
//				empty();
//				break;
//			case 5:
//				exit(0);
//			case 6:
//				display();
//				break;
//			case 7:
//				queuesize();
//				break;
//			default:
//				printf("Wrong choice, Please enter correct choice  ");
//				break;
//			}
//		}
//	}
//	/* Create an empty queue */
//	void create()
//	{
//		front = rear = NULL;
//	}
//	/* Returns queue size */
//	void queuesize()
//	{
//		printf("\n Queue size : %d", count);
//	}
//	/* Enqueing the queue */
//	void enq(int data)
//	{
//		if (rear == NULL)
//		{
//			rear = (struct node*)malloc(1 * sizeof(struct node));
//			rear->ptr = NULL;
//			rear->info = data;
//			front = rear;
//		}
//		else
//		{
//			temp = (struct node*)malloc(1 * sizeof(struct node));
//			rear->ptr = temp;
//			temp->info = data;
//			temp->ptr = NULL;
//			rear = temp;
//		}
//		count++;
//	}
//	/* Displaying the queue elements */
//	void display()
//	{
//		front1 = front;
//		if ((front1 == NULL) && (rear == NULL))
//		{
//			printf("Queue is empty");
//			return;
//		}
//		while (front1 != rear)
//		{
//			printf("%d ", front1->info);
//			front1 = front1->ptr;
//		}
//		if (front1 == rear)
//			printf("%d", front1->info);
//	}
//	/* Dequeing the queue */
//	void deq()
//	{
//		front1 = front;
//		if (front1 == NULL)
//		{
//			printf("\n Error: Trying to display elements from empty queue");
//			return;
//		}
//		else
//			if (front1->ptr != NULL)
//			{
//				front1 = front1->ptr;
//				printf("\n Dequed value : %d", front->info);
//				free(front);
//				front = front1;
//			}
//			else
//			{
//				printf("\n Dequed value : %d", front->info);
//				free(front);
//				front = NULL;
//				rear = NULL;
//			}
//		count--;
//	}
//	/* Returns the front element of queue */
//	int frontelement()
//	{
//		if ((front != NULL) && (rear != NULL))
//			return(front->info);
//		else
//			return 0;
//	}
//	/* Display if queue is empty or not */
//	void empty()
//	{
//		if ((front == NULL) && (rear == NULL))
//			printf("\n Queue empty");
//		else
//			printf("Queue not empty");
//	}
//	//-----------------------------------------------------------------------------------------------------------
//		/*
//		 * C Program to Find the Largest Element in a Doubly Linked List
//		 */
// #include <stdio.h>
// #include <stdlib.h>
//	struct node
//	{
//		int num;
//		struct node* next;
//		struct node* prev;
//	};
//	void create(struct node**);
//	int max(struct node*);
//	void release(struct node**);
//	int main()
//	{
//		struct node* p = NULL;
//		int n;
//		printf("Enter data into the list\n");
//		create(&p);
//		n = max(p);
//		printf("The maximum number entered in the list is %d.\n", n);
//		release(&p);
//		return 0;
//	}
//	int max(struct node* head)
//	{
//		struct node* max, * q;
//		q = max = head;
//		while (q != NULL)
//		{
//			if (q->num > max->num)
//			{
//				max = q;
//			}
//			q = q->next;
//		}
//		return (max->num);
//	}
//	void create(struct node** head)
//	{
//		int c, ch;
//		struct node* temp, * rear;
//		do
//		{
//			printf("Enter number: ");
//			scanf_f("%d", &c);
//			temp = (struct node*)malloc(sizeof(struct node));
//			temp->num = c;
//			temp->next = NULL;
//			temp->prev = NULL;
//			if (*head == NULL)
//			{
//				*head = temp;
//			}
//			else
//			{
//				rear->next = temp;
//				temp->prev = rear;
//			}
//			rear = temp;
//			printf("Do you wish to continue [1/0]: ");
//			scanf_f("%d", &ch);
//		} while (ch != 0);
//		printf("\n");
//	}
//	void release(struct node** head)
//	{
//		struct node* temp = *head;
//		*head = (*head)->next;
//		while ((*head) != NULL)
//		{
//			free(temp);
//			temp = *head;
//			(*head) = (*head)->next;
//		}
//	}
//	//-------------------------------------------------------------------------------------------------------------
//		/*
//		 * C Program to Find the first Common Element between the 2 given Linked Lists
//		 */
// #include <stdio.h>
// #include <stdlib.h>
//	struct node
//	{
//		int num;
//		struct node* next;
//	};
//	void create(struct node**);
//	int find(struct node*, struct node*);
//	void release(struct node**);
//	void display(struct node*);
//	int main()
//	{
//		struct node* p = NULL, * q = NULL;
//		int result;
//		printf("Enter data into the list\n");
//		create(&p);
//		printf("Enter data into the list\n");
//		create(&q);
//		printf("Displaying list1:\n");
//		display(p);
//		printf("Displaying list2:\n");
//		display(q);
//		result = find(p, q);
//		if (result)
//		{
//			printf("The first matched element is %d.\n", result);
//		}
//		else
//		{
//			printf("No matching element found.\n");
//		}
//		release(&p);
//		return 0;
//	}
//	int find(struct node* p, struct node* q)
//	{
//		struct node* temp;
//		while (p != NULL)
//		{
//			temp = q;
//			while (temp != NULL)
//			{
//				if (temp->num == p->num)
//				{
//					return p->num;
//				}
//				temp = temp->next;
//			}
//			p = p->next;
//		}
//		/*Assuming 0 is not used in the list*/
//		return 0;
//	}
//	void create(struct node** head)
//	{
//		int c, ch;
//		struct node* temp, * rear;
//		do
//		{
//			printf("Enter number: ");
//			scanf_f("%d", &c);
//			temp = (struct node*)malloc(sizeof(struct node));
//			temp->num = c;
//			temp->next = NULL;
//			if (*head == NULL)
//			{
//				*head = temp;
//			}
//			else
//			{
//				rear->next = temp;
//			}
//			rear = temp;
//			printf("Do you wish to continue [1/0]: ");
//			scanf_f("%d", &ch);
//		} while (ch != 0);
//		printf("\n");
//	}
//	void display(struct node* head)
//	{
//		while (head != NULL)
//		{
//			printf("%d\t", head->num);
//			head = head->next;
//		}
//		printf("\n");
//	}
//	void release(struct node** head)
//	{
//		struct node* temp;
//		while ((*head) != NULL)
//		{
//			temp = *head;
//			(*head) = (*head)->next;
//			free(temp);
//		}
//	}
//	//----------------------------------------------------------------------------------------------------------
//		/*
//		 * C Program to Find Number of Occurences of All Elements in a Linked List
//		 */
// #include <stdio.h>
// #include <stdlib.h>
//	struct node
//	{
//		int num;
//		struct node* next;
//	};
//	struct node_occur
//	{
//		int num;
//		int times;
//		struct node_occur* next;
//	};
//	void create(struct node**);
//	void occur(struct node*, struct node_occur**);
//	void release(struct node**);
//	void release_2(struct node_occur**);
//	void display(struct node*);
//	void disp_occur(struct node_occur*);
//	int main()
//	{
//		struct node* p = NULL;
//		struct node_occur* head = NULL;
//		int n;
//		printf("Enter data into the list\n");
//		create(&p);
//		printf("Displaying the occurence of each node in the list:\n");
//		display(p);
//		occur(p, &head);
//		disp_occur(head);
//		release(&p);
//		release_2(&head);
//		return 0;
//	}
//	void occur(struct node* head, struct node_occur** result)
//	{
//		struct node* p;
//		struct node_occur* temp, * prev;
//		p = head;
//		while (p != NULL)
//		{
//			temp = *result;
//			while (temp != NULL && temp->num != p->num)
//			{
//				prev = temp;
//				temp = temp->next;
//			}
//			if (temp == NULL)
//			{
//				temp = (struct node_occur*)malloc(sizeof(struct node_occur));
//				temp->num = p->num;
//				temp->times = 1;
//				temp->next = NULL;
//				if (*result != NULL)
//				{
//					prev->next = temp;
//				}
//				else
//				{
//					*result = temp;
//				}
//			}
//			else
//			{
//				temp->times += 1;
//			}
//			p = p->next;
//		}
//	}
//	void create(struct node** head)
//	{
//		int c, ch;
//		struct node* temp, * rear;
//		do
//		{
//			printf("Enter number: ");
//			scanf_f("%d", &c);
//			temp = (struct node*)malloc(sizeof(struct node));
//			temp->num = c;
//			temp->next = NULL;
//			if (*head == NULL)
//			{
//				*head = temp;
//			}
//			else
//			{
//				rear->next = temp;
//			}
//			rear = temp;
//			printf("Do you wish to continue [1/0]: ");
//			scanf_f("%d", &ch);
//		} while (ch != 0);
//		printf("\n");
//	}
//	void display(struct node* p)
//	{
//		while (p != NULL)
//		{
//			printf("%d\t", p->num);
//			p = p->next;
//		}
//		printf("\n");
//	}
//	void disp_occur(struct node_occur* p)
//	{
//		printf("***************************\n  Number\tOccurence\n***************************\n");
//		while (p != NULL)
//		{
//			printf("    %d\t\t%d\n", p->num, p->times);
//			p = p->next;
//		}
//	}
//	void release(struct node** head)
//	{
//		struct node* temp = *head;
//		*head = (*head)->next;
//		while ((*head) != NULL)
//		{
//			free(temp);
//			temp = *head;
//			(*head) = (*head)->next;
//		}
//	}
//	void release_2(struct node_occur** head)
//	{
//		struct node_occur* temp = *head;
//		*head = (*head)->next;
//		while ((*head) != NULL)
//		{
//			free(temp);
//			temp = *head;
//			(*head) = (*head)->next;
//		}
//	}
//	//----------------------------------------------------------------------------------------------------------
//		/*
//		 * C Program to Detect the Cycle in a Linked List
//		 */
// #include <stdio.h>
// #include <stdlib.h>
//	struct node
//	{
//		int num;
//		struct node* next;
//	};
//	void create(struct node**);
//	void makecycle(struct node**);
//	void release(struct node**);
//	int detectcycle(struct node*);
//	int main()
//	{
//		struct node* p = NULL;
//		int result;
//		printf("Enter data into the list\n");
//		create(&p);
//		makecycle(&p); //comment it to avoid cycle creation
//		printf("Identifying if a cycle exists.\n");
//		result = detectcycle(p);
//		if (result)
//		{
//			printf("Cycle detected in the linked list.\n");
//		}
//		else
//		{
//			printf("No cycle detected in the linked list.\n");
//		}
//		release(&p);
//		return 0;
//	}
//	void makecycle(struct node** p)
//	{
//		struct node* rear, * front;
//		int n, count = 0, i;
//		front = rear = *p;
//		while (rear->next != NULL)
//		{
//			rear = rear->next;
//			count++;
//		}
//		if (count)
//		{
//			n = rand() % count;
//		}
//		else
//		{
//			n = 1;
//		}
//		for (i = 0; i < n - 1; i++)
//		{
//			front = front->next;
//		}
//		rear->next = front;
//		/*At this point a cycle is generated in the list*/
//	}
//	int detectcycle(struct node* head)
//	{
//		int flag = 1, count = 1, i;
//		struct node* p, * q;
//		p = q = head;
//		q = q->next;
//		while (1)
//		{
//			q = q->next;
//			if (flag)
//			{
//				p = p->next;
//			}
//			if (q == p)
//			{
//				/*Deleting the loop to deallocate the list*/
//				q = q->next;
//				while (q != p)
//				{
//					count++;
//					q = q->next;
//				}
//				q = p = head;
//				for (i = 0; i < count; i++)
//				{
//					q = q->next;
//				}
//				while (p != q)
//				{
//					p = p->next;
//					q = q->next;
//				}
//				q->next = NULL;
//				return 1;
//			}
//			else if (q->next == NULL)
//			{
//				return 0;
//			}
//			flag = !flag;
//		}
//	}
//	void create(struct node** head)
//	{
//		int c, ch;
//		struct node* temp, * rear;
//		do
//		{
//			printf("Enter number: ");
//			scanf_f("%d", &c);
//			temp = (struct node*)malloc(sizeof(struct node));
//			temp->num = c;
//			temp->next = NULL;
//			if (*head == NULL)
//			{
//				*head = temp;
//			}
//			else
//			{
//				rear->next = temp;
//			}
//			rear = temp;
//			printf("Do you wish to continue [1/0]: ");
//			scanf_f("%d", &ch);
//		} while (ch != 0);
//		printf("\n");
//	}
//	void release(struct node** head)
//	{
//		struct node* temp = *head;
//		temp = temp->next;
//		while ((*head) != NULL)
//		{
//			free(temp);
//			temp = *head;
//			(*head) = (*head)->next;
//		}
//	}
//	//--------------------------------------------------------------------------------------------------------
//		/*
//		 * C Program to Check whether a Singly Linked List is a Palindrome
//		 */
// #include <stdio.h>
// #include <stdlib.h>
//	struct node
//	{
//		int num;
//		struct node* next;
//	};
//	int create(struct node**);
//	int palin_check(struct node*, int);
//	void release(struct node**);
//	int main()
//	{
//		struct node* p = NULL;
//		int result, count;
//		printf("Enter data into the list\n");
//		count = create(&p);
//		result = palin_check(p, count);
//		if (result == 1)
//		{
//			printf("The linked list is a palindrome.\n");
//		}
//		else
//		{
//			printf("The linked list is not a palindrome.\n");
//		}
//		release(&p);
//		return 0;
//	}
//	int palin_check(struct node* p, int count)
//	{
//		int i = 0, j;
//		struct node* front, * rear;
//		while (i != count / 2)
//		{
//			front = rear = p;
//			for (j = 0; j < i; j++)
//			{
//				front = front->next;
//			}
//			for (j = 0; j < count - (i + 1); j++)
//			{
//				rear = rear->next;
//			}
//			if (front->num != rear->num)
//			{
//				return 0;
//			}
//			else
//			{
//				i++;
//			}
//		}
//		return 1;
//	}
//	int create(struct node** head)
//	{
//		int c, ch, count = 0;
//		struct node* temp;
//		do
//		{
//			printf("Enter number: ");
//			scanf_f("%d", &c);
//			count++;
//			temp = (struct node*)malloc(sizeof(struct node));
//			temp->num = c;
//			temp->next = *head;
//			*head = temp;
//			printf("Do you wish to continue [1/0]: ");
//			scanf_f("%d", &ch);
//		} while (ch != 0);
//		printf("\n");
//		return count;
//	}
//	void release(struct node** head)
//	{
//		struct node* temp = *head;
//		while ((*head) != NULL)
//		{
//			(*head) = (*head)->next;
//			free(temp);
//			temp = *head;
//		}
//	}
//	//---------------------------------------------------------------------------------------------------------
//		/*
//		 * C Program to Check whether 2 Lists are Same
//		 */
// #include <stdio.h>
// #include <stdlib.h>
//	struct node
//	{
//		int num;
//		struct node* next;
//	};
//	void feedmember(struct node**);
//	int compare(struct node*, struct node*);
//	void release(struct node**);
//	int main()
//	{
//		struct node* p = NULL;
//		struct node* q = NULL;
//		int result;
//		printf("Enter data into first list\n");
//		feedmember(&p);
//		printf("Enter data into second list\n");
//		feedmember(&q);
//		result = compare(p, q);
//		if (result == 1)
//		{
//			printf("The 2 list are equal.\n");
//		}
//		else
//		{
//			printf("The 2 lists are unequal.\n");
//		}
//		release(&p);
//		release(&q);
//		return 0;
//	}
//	int compare(struct node* p, struct node* q)
//	{
//		while (p != NULL && q != NULL)
//		{
//			if (p->num != q->num)
//			{
//				return 0;
//			}
//			else
//			{
//				p = p->next;
//				q = q->next;
//			}
//		}
//		if (p != NULL || q != NULL)
//		{
//			return 0;
//		}
//		else
//		{
//			return 1;
//		}
//	}
//	void feedmember(struct node** head)
//	{
//		int c, ch;
//		struct node* temp;
//		do
//		{
//			printf("Enter number: ");
//			scanf_f("%d", &c);
//			temp = (struct node*)malloc(sizeof(struct node));
//			temp->num = c;
//			temp->next = *head;
//			*head = temp;
//			printf("Do you wish to continue [1/0]: ");
//			scanf_f("%d", &ch);
//		} while (ch != 0);
//		printf("\n");
//	}
//	void release(struct node** head)
//	{
//		struct node* temp = *head;
//		while ((*head) != NULL)
//		{
//			(*head) = (*head)->next;
//			free(temp);
//			temp = *head;
//		}
//	}
//	//------------------------------------------------------------------------------------------------------------
//		/*
//		 * C Program to Add Corresponding Positioned Elements of 2 Linked Lists
//		 */
// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>
//	struct node
//	{
//		int num;
//		struct node* next;
//	};
//	int feednumber(struct node**);
//	struct node* addlist(struct node*, struct node*, int, int);
//	void release(struct node**);
//	void display(struct node*);
//	int main()
//	{
//		struct node* p = NULL;
//		struct node* q = NULL;
//		struct node* res = NULL;
//		int pcount = 0, qcount = 0;
//		printf("Enter first number\n");
//		pcount = feednumber(&p);
//		printf("Enter second number\n");
//		qcount = feednumber(&q);
//		printf("Displaying list1: ");
//		display(p);
//		printf("Displaying list2: ");
//		display(q);
//		res = addlist(p, q, pcount, qcount);
//		printf("Displaying the resulting list: ");
//		display(res);
//		release(&p);
//		release(&q);
//		release(&res);
//		return 0;
//	}
//	/*Function to create nodes of numbers*/
//	int feednumber(struct node** head)
//	{
//		char ch, dig;
//		int count = 0;
//		struct node* temp, * rear = NULL;
//		ch = getchar();
//		while (ch != '\n')
//		{
//			dig = atoi(&ch);
//			temp = (struct node*)malloc(sizeof(struct node));
//			temp->num = dig;
//			temp->next = NULL;
//			count++;
//			if ((*head) == NULL)
//			{
//				*head = temp;
//				rear = temp;
//			}
//			else
//			{
//				rear->next = temp;
//				rear = rear->next;
//			}
//			ch = getchar();
//		}
//		return count;
//	}
//	/*Function to display the list of numbers*/
//	void display(struct node* head)
//	{
//		while (head != NULL)
//		{
//			printf("%d", head->num);
//			head = head->next;
//		}
//		printf("\n");
//	}
//	/*Function to free the allocated list of numbers*/
//	void release(struct node** head)
//	{
//		struct node* temp = *head;
//		while ((*head) != NULL)
//		{
//			(*head) = (*head)->next;
//			free(temp);
//			temp = *head;
//		}
//	}
//	/*Function to add the list of numbers and store them in 3rd list*/
//	struct node* addlist(struct node* p, struct node* q, int pcount, int qcount)
//	{
//		struct node* ptemp, * qtemp, * result = NULL, * temp;
//		int i, carry = 0;
//		while (pcount != 0 && qcount != 0)
//		{
//			ptemp = p;
//			qtemp = q;
//			for (i = 0; i < pcount - 1; i++)
//			{
//				ptemp = ptemp->next;
//			}
//			for (i = 0; i < qcount - 1; i++)
//			{
//				qtemp = qtemp->next;
//			}
//			temp = (struct node*)malloc(sizeof(struct node));
//			temp->num = ptemp->num + qtemp->num + carry;
//			carry = temp->num / 10;
//			temp->num = temp->num % 10;
//			temp->next = result;
//			result = temp;
//			pcount--;
//			qcount--;
//		}
//		/*both or one of the 2 lists have been read completely by now*/
//		while (pcount != 0)
//		{
//			ptemp = p;
//			for (i = 0; i < pcount - 1; i++)
//			{
//				ptemp = ptemp->next;
//			}
//			temp = (struct node*)malloc(sizeof(struct node));
//			temp->num = ptemp->num + carry;
//			carry = temp->num / 10;
//			temp->num = temp->num % 10;
//			temp->next = result;
//			result = temp;
//			pcount--;
//		}
//		while (qcount != 0)
//		{
//			qtemp = q;
//			for (i = 0; i < qcount - 1; i++)
//			{
//				qtemp = qtemp->next;
//			}
//			temp = (struct node*)malloc(sizeof(struct node));
//			temp->num = qtemp->num + carry;
//			carry = temp->num / 10;
//			temp->num = temp->num % 10;
//			temp->next = result;
//			result = temp;
//			qcount--;
//		}
//		return result;
//	}
//	//----------------------------------------------------------------------------------------------------------
//		/*
//		 * C Program to Reverse only First N Elements of a Linked List
//		 */
// #include <stdio.h>
// #include <stdlib.h>
//	struct node
//	{
//		int num;
//		struct node* next;
//	};
//	void create(struct node**);
//	void reverse(struct node**, int);
//	void release(struct node**);
//	void display(struct node*);
//	int main()
//	{
//		struct node* p = NULL;
//		int n;
//		printf("Enter data into the list\n");
//		create(&p);
//		printf("Displaying the nodes in the list:\n");
//		display(p);
//		printf("Enter the number N to reverse first N node: ");
//		scanf_f("%d", &n);
//		printf("Reversing the list...\n");
//		if (n > 1)
//		{
//			reverse(&p, n - 2);
//		}
//		printf("Displaying the reversed list:\n");
//		display(p);
//		release(&p);
//		return 0;
//	}
//	void reverse(struct node** head, int n)
//	{
//		struct node* p, * q, * r, * rear;
//		p = q = r = *head;
//		if (n == 0)
//		{
//			q = q->next;
//			p->next = q->next;
//			q->next = p;
//			*head = q;
//		}
//		else
//		{
//			p = p->next->next;
//			q = q->next;
//			r->next = NULL;
//			rear = r;
//			q->next = r;
//			while (n > 0 && p != NULL)
//			{
//				r = q;
//				q = p;
//				p = p->next;
//				q->next = r;
//				n--;
//			}
//			*head = q;
//			rear->next = p;
//		}
//	}
//	void create(struct node** head)
//	{
//		int c, ch;
//		struct node* temp, * rear;
//		do
//		{
//			printf("Enter number: ");
//			scanf_f("%d", &c);
//			temp = (struct node*)malloc(sizeof(struct node));
//			temp->num = c;
//			temp->next = NULL;
//			if (*head == NULL)
//			{
//				*head = temp;
//			}
//			else
//			{
//				rear->next = temp;
//			}
//			rear = temp;
//			printf("Do you wish to continue [1/0]: ");
//			scanf_f("%d", &ch);
//		} while (ch != 0);
//		printf("\n");
//	}
//	void display(struct node* p)
//	{
//		while (p != NULL)
//		{
//			printf("%d\t", p->num);
//			p = p->next;
//		}
//		printf("\n");
//	}
//	void release(struct node** head)
//	{
//		struct node* temp = *head;
//		*head = (*head)->next;
//		while ((*head) != NULL)
//		{
//			free(temp);
//			temp = *head;
//			(*head) = (*head)->next;
//		}
//	}
//	//----------------------------------------------------------------------------------------------------------
//		/*
//		 * C Program to Reverse a Linked List
//		 */
// #include <stdio.h>
// #include <stdlib.h>
//	struct node
//	{
//		int num;
//		struct node* next;
//	};
//	void create(struct node**);
//	void reverse(struct node**);
//	void release(struct node**);
//	void display(struct node*);
//	int main()
//	{
//		struct node* p = NULL;
//		int n;
//		printf("Enter data into the list\n");
//		create(&p);
//		printf("Displaying the nodes in the list:\n");
//		display(p);
//		printf("Reversing the list...\n");
//		reverse(&p);
//		printf("Displaying the reversed list:\n");
//		display(p);
//		release(&p);
//		return 0;
//	}
//	void reverse(struct node** head)
//	{
//		struct node* p, * q, * r;
//		p = q = r = *head;
//		p = p->next->next;
//		q = q->next;
//		r->next = NULL;
//		q->next = r;
//		while (p != NULL)
//		{
//			r = q;
//			q = p;
//			p = p->next;
//			q->next = r;
//		}
//		*head = q;
//	}
//	void create(struct node** head)
//	{
//		int c, ch;
//		struct node* temp, * rear;
//		do
//		{
//			printf("Enter number: ");
//			scanf_f("%d", &c);
//			temp = (struct node*)malloc(sizeof(struct node));
//			temp->num = c;
//			temp->next = NULL;
//			if (*head == NULL)
//			{
//				*head = temp;
//			}
//			else
//			{
//				rear->next = temp;
//			}
//			rear = temp;
//			printf("Do you wish to continue [1/0]: ");
//			scanf_f("%d", &ch);
//		} while (ch != 0);
//		printf("\n");
//	}
//	void display(struct node* p)
//	{
//		while (p != NULL)
//		{
//			printf("%d\t", p->num);
//			p = p->next;
//		}
//		printf("\n");
//	}
//	void release(struct node** head)
//	{
//		struct node* temp = *head;
//		*head = (*head)->next;
//		while ((*head) != NULL)
//		{
//			free(temp);
//			temp = *head;
//			(*head) = (*head)->next;
//		}
//	}
//	//---------------------------------------------------------------------------------------------------------
//		/*
//		 * C Program to Remove Duplicates from a Linked List
//		 */
// #include <stdio.h>
// #include <stdlib.h>
//	struct node
//	{
//		int num;
//		struct node* next;
//	};
//	void create(struct node**);
//	void dup_delete(struct node**);
//	void release(struct node**);
//	void display(struct node*);
//	int main()
//	{
//		struct node* p = NULL;
//		struct node_occur* head = NULL;
//		int n;
//		printf("Enter data into the list\n");
//		create(&p);
//		printf("Displaying the nodes in the list:\n");
//		display(p);
//		printf("Deleting duplicate elements in the list...\n");
//		dup_delete(&p);
//		printf("Displaying non-deleted nodes in the list:\n");
//		display(p);
//		release(&p);
//		return 0;
//	}
//	void dup_delete(struct node** head)
//	{
//		struct node* p, * q, * prev, * temp;
//		p = q = prev = *head;
//		q = q->next;
//		while (p != NULL)
//		{
//			while (q != NULL && q->num != p->num)
//			{
//				prev = q;
//				q = q->next;
//			}
//			if (q == NULL)
//			{
//				p = p->next;
//				if (p != NULL)
//				{
//					q = p->next;
//				}
//			}
//			else if (q->num == p->num)
//			{
//				prev->next = q->next;
//				temp = q;
//				q = q->next;
//				free(temp);
//			}
//		}
//	}
//	void create(struct node** head)
//	{
//		int c, ch;
//		struct node* temp, * rear;
//		do
//		{
//			printf("Enter number: ");
//			scanf_f("%d", &c);
//			temp = (struct node*)malloc(sizeof(struct node));
//			temp->num = c;
//			temp->next = NULL;
//			if (*head == NULL)
//			{
//				*head = temp;
//			}
//			else
//			{
//				rear->next = temp;
//			}
//			rear = temp;
//			printf("Do you wish to continue [1/0]: ");
//			scanf_f("%d", &ch);
//		} while (ch != 0);
//		printf("\n");
//	}
//	void display(struct node* p)
//	{
//		while (p != NULL)
//		{
//			printf("%d\t", p->num);
//			p = p->next;
//		}
//		printf("\n");
//	}
//	void release(struct node** head)
//	{
//		struct node* temp = *head;
//		*head = (*head)->next;
//		while ((*head) != NULL)
//		{
//			free(temp);
//			temp = *head;
//			(*head) = (*head)->next;
//		}
//	}
//	//----------------------------------------------------------------------------------------------------------
//		/*
//		 * C Program to Read a Linked List in Reverse
//		 */
// #include <stdio.h>
// #include <stdlib.h>
//	struct node
//	{
//		int num;
//		struct node* next;
//	};
//	void create(struct node**);
//	void reversedisplay(struct node*);
//	void release(struct node**);
//	void display(struct node*);
//	int main()
//	{
//		struct node* p = NULL;
//		struct node_occur* head = NULL;
//		int n;
//		printf("Enter data into the list\n");
//		create(&p);
//		printf("Displaying the nodes in the list:\n");
//		display(p);
//		printf("Displaying the list in reverse:\n");
//		reversedisplay(p);
//		release(&p);
//		return 0;
//	}
//	void reversedisplay(struct node* head)
//	{
//		if (head != NULL)
//		{
//			reversedisplay(head->next);
//			printf("%d\t", head->num);
//		}
//	}
//	void create(struct node** head)
//	{
//		int c, ch;
//		struct node* temp, * rear;
//		do
//		{
//			printf("Enter number: ");
//			scanf_f("%d", &c);
//			temp = (struct node*)malloc(sizeof(struct node));
//			temp->num = c;
//			temp->next = NULL;
//			if (*head == NULL)
//			{
//				*head = temp;
//			}
//			else
//			{
//				rear->next = temp;
//			}
//			rear = temp;
//			printf("Do you wish to continue [1/0]: ");
//			scanf_f("%d", &ch);
//		} while (ch != 0);
//		printf("\n");
//	}
//	void display(struct node* p)
//	{
//		while (p != NULL)
//		{
//			printf("%d\t", p->num);
//			p = p->next;
//		}
//		printf("\n");
//	}
//	void release(struct node** head)
//	{
//		struct node* temp = *head;
//		*head = (*head)->next;
//		while ((*head) != NULL)
//		{
//			free(temp);
//			temp = *head;
//			(*head) = (*head)->next;
//		}
//	}
//	//-----------------------------------------------------------------------------------------------------------
//		/*
//		 * C Program to Print Middle most Node of a Linked List
//		 */
// #include <stdio.h>
// #include <stdlib.h>
//	struct node
//	{
//		int num;
//		struct node* next;
//	};
//	void create(struct node**);
//	void middlenode(struct node*);
//	void release(struct node**);
//	int main()
//	{
//		struct node* p = NULL;
//		printf("Enter data into the list\n");
//		create(&p);
//		middlenode(p);
//		release(&p);
//		return 0;
//	}
//	void middlenode(struct node* head)
//	{
//		struct node* p, * q;
//		int flag = 0;
//		q = p = head;
//		/*for every two hops of q, one hop for p*/
//		while (q->next != NULL)
//		{
//			q = q->next;
//			if (flag)
//			{
//				p = p->next;
//			}
//			flag = !flag;
//		}
//		if (flag)
//		{
//			printf("List contains even number of nodes\nThe middle two node's values are: %d  %d\n", p->next->num, p->num);
//		}
//		else
//		{
//			printf("The middle node of the list is: %d\n", p->num);
//		}
//	}
//	void create(struct node** head)
//	{
//		int c, ch;
//		struct node* temp;
//		do
//		{
//			printf("Enter number: ");
//			scanf_f("%d", &c);
//			temp = (struct node*)malloc(sizeof(struct node));
//			temp->num = c;
//			temp->next = *head;
//			*head = temp;
//			printf("Do you wish to continue [1/0]: ");
//			scanf_f("%d", &ch);
//		} while (ch != 0);
//		printf("\n");
//	}
//	void release(struct node** head)
//	{
//		struct node* temp = *head;
//		*head = (*head)->next;
//		while ((*head) != NULL)
//		{
//			free(temp);
//			temp = *head;
//			(*head) = (*head)->next;
//		}
//	}
//	//--------------------------------------------------------------------------------------------------------
//		/*
//		 * C Program to Find Intersection & Union of 2 Linked Lists
//		 */
// #include <stdio.h>
// #include <stdlib.h>
//	struct node
//	{
//		int num;
//		struct node* next;
//	};
//	void create(struct node**);
//	void findunion(struct node*, struct node*, struct node**);
//	void findintersect(struct node*, struct node*, struct node**);
//	void display(struct node*);
//	void release(struct node**);
//	int main()
//	{
//		struct node* phead, * qhead, * intersect, * unionlist;
//		phead = qhead = intersect = unionlist = NULL;
//		printf("Enter elements in the list 1\n");
//		create(&phead);
//		printf("\nEnter elements in the list 2\n");
//		create(&qhead);
//		findunion(phead, qhead, &unionlist);
//		findintersect(phead, qhead, &intersect);
//		printf("\nDisplaying list 1:\n");
//		display(phead);
//		printf("Displaying list 2:\n");
//		display(qhead);
//		printf("Displaying the union of the 2 lists:\n");
//		display(unionlist);
//		printf("Displaying the intersection of the 2 lists:\n");
//		if (intersect == NULL)
//		{
//			printf("Null\n");
//		}
//		else
//		{
//			display(intersect);
//		}
//		release(&phead);
//		release(&qhead);
//		release(&unionlist);
//		release(&intersect);
//		return 0;
//	}
//	void findintersect(struct node* p, struct node* q, struct node** intersect)
//	{
//		struct node* ptemp, * qtemp, * itemp, * irear, * ifront;
//		ptemp = p;
//		while (ptemp != NULL)
//		{
//			qtemp = q;
//			ifront = *intersect;
//			while (qtemp != NULL && ptemp->num != qtemp->num)
//			{
//				qtemp = qtemp->next;
//			}
//			if (qtemp != NULL)
//			{
//				if (ifront != NULL)
//				{
//					if (ifront->num == qtemp->num)
//					{
//						ptemp = ptemp->next;
//						continue;
//					}
//					ifront = ifront->next;
//				}
//				itemp = (struct node*)malloc(sizeof(struct node));
//				itemp->num = qtemp->num;
//				itemp->next = NULL;
//				if (*intersect == NULL)
//				{
//					*intersect = itemp;
//				}
//				else
//				{
//					irear->next = itemp;
//				}
//				irear = itemp;
//			}
//			ptemp = ptemp->next;
//		}
//	}
//	void findunion(struct node* p, struct node* q, struct node** unionlist)
//	{
//		struct node* utemp, * ufront, * urear;
//		int flag = 0;
//		while (p != NULL)
//		{
//			ufront = *unionlist;
//			while (ufront != NULL)
//			{
//				if (ufront->num == p->num)
//				{
//					flag = 1;
//				}
//				ufront = ufront->next;
//			}
//			if (flag)
//			{
//				flag = 0;
//			}
//			else
//			{
//				utemp = (struct node*)malloc(sizeof(struct node));
//				utemp->num = p->num;
//				utemp->next = NULL;
//				if (*unionlist == NULL)
//				{
//					*unionlist = utemp;
//				}
//				else
//				{
//					urear->next = utemp;
//				}
//				urear = utemp;
//			}
//			p = p->next;
//		}
//		while (q != NULL)
//		{
//			ufront = *unionlist;
//			while (ufront != NULL)
//			{
//				if (ufront->num == q->num)
//				{
//					flag = 1;
//				}
//				ufront = ufront->next;
//			}
//			if (flag)
//			{
//				flag = 0;
//			}
//			else
//			{
//				utemp = (struct node*)malloc(sizeof(struct node));
//				utemp->num = q->num;
//				utemp->next = NULL;
//				if (*unionlist == NULL)
//				{
//					*unionlist = utemp;
//				}
//				else
//				{
//					urear->next = utemp;
//				}
//				urear = utemp;
//			}
//			q = q->next;
//		}
//	}
//	void create(struct node** head)
//	{
//		struct node* temp, * rear;
//		int ch, a;
//		do
//		{
//			printf("Enter a number: ");
//			scanf_f("%d", &a);
//			temp = (struct node*)malloc(sizeof(struct node));
//			temp->num = a;
//			temp->next = NULL;
//			if (*head == NULL)
//			{
//				*head = temp;
//			}
//			else
//			{
//				rear->next = temp;
//			}
//			rear = temp;
//			printf("Do you want to continue [1/0] ? ");
//			scanf_f("%d", &ch);
//		} while (ch != 0);
//	}
//	void display(struct node* head)
//	{
//		while (head != NULL)
//		{
//			printf("%d   ", head->num);
//			head = head->next;
//		}
//		printf("\n");
//	}
//	void release(struct node** head)
//	{
//		struct node* temp = *head;
//		while ((*head) != NULL)
//		{
//			(*head) = (*head)->next;
//			free(temp);
//			temp = *head;
//		}
//	}
//	//------------------------------------------------------------------------------------------------------------
//		/*
//		 * C Program to Convert a given Singly Linked List to a Circular List
//		 */
// #include <stdio.h>
// #include <stdlib.h>
//	struct node
//	{
//		int num;
//		struct node* next;
//	};
//	void create(struct node**);
//	void tocircular(struct node**);
//	void release(struct node**);
//	void display(struct node*);
//	int main()
//	{
//		struct node* p = NULL;
//		int result, count;
//		printf("Enter data into the list\n");
//		create(&p);
//		tocircular(&p);
//		printf("Circular list generated\n");
//		display(p);
//		release(&p);
//		return 0;
//	}
//	void tocircular(struct node** p)
//	{
//		struct node* rear;
//		rear = *p;
//		while (rear->next != NULL)
//		{
//			rear = rear->next;
//		}
//		rear->next = *p;
//		/*After this the singly linked list is now circular*/
//	}
//	void create(struct node** head)
//	{
//		int c, ch;
//		struct node* temp;
//		do
//		{
//			printf("Enter number: ");
//			scanf_f("%d", &c);
//			temp = (struct node*)malloc(sizeof(struct node));
//			temp->num = c;
//			temp->next = *head;
//			*head = temp;
//			printf("Do you wish to continue [1/0]: ");
//			scanf_f("%d", &ch);
//		} while (ch != 0);
//		printf("\n");
//	}
//	void display(struct node* head)
//	{
//		struct node* temp = head;
//		printf("Displaying the list elements\n");
//		printf("%d\t", temp->num);
//		temp = temp->next;
//		while (head != temp)
//		{
//			printf("%d\t", temp->num);
//			temp = temp->next;
//		}
//		printf("and back to %d\t%d ..\n", temp->num, temp->next->num);
//	}
//	void release(struct node** head)
//	{
//		struct node* temp = *head;
//		temp = temp->next;
//		(*head)->next = NULL;
//		(*head) = temp->next;
//		while ((*head) != NULL)
//		{
//			free(temp);
//			temp = *head;
//			(*head) = (*head)->next;
//		}
//	}
//	//------------------------------------------------------------------------------------------------------------
//		/*
//		 * C Program to Convert a Binary Tree into a Singly Linked List by Traversing Level by Level
//		 */
//	<pre>
// #include <stdio.h>
// #include <stdlib.h>
//		/*structure type to create a tree*/
//		struct node
//	{
//		int num;
//		struct node* left;
//		struct node* right;
//	};
//	/*
//	 * structure type to point to the nodes of a tree
//	 * and also create self-referential list used for
//	 * queueing.
//	 */
//	struct queue
//	{
//		struct node* nodeptr;
//		struct queue* next;
//	};
//	/* resulting singly linked list */
//	struct list
//	{
//		int num;
//		struct list* next;
//	};
//	void createTree(struct node**);
//	void createlistbfs(struct node*, struct list**);
//	void delete(struct node**);
//	void display(struct list*);
//	void deleteList(struct list**);
//	int main()
//	{
//		struct node* root = NULL;
//		struct list* head = NULL;
//		createTree(&root);
//		createlistbfs(root, &head);
//		printf("Displaying the list generated at node by node level of the tree: ");
//		display(head);
//		deleteList(&head);
//		delete(&root);
//		return 0;
//	}
//	void createTree(struct node** root)
//	{
//		struct node* temp, * p, * q;
//		int a, ch;
//		do
//		{
//			printf("Enter a number for a node: ");
//			scanf_f("%d", &a);
//			temp = (struct node*)malloc(sizeof(struct node));
//			temp->num = a;
//			temp->left = NULL;
//			temp->right = NULL;
//			p = q = *root;
//			if (*root == NULL)
//			{
//				*root = temp;
//			}
//			else
//			{
//				while (1)
//				{
//					q = p;
//					if (p->num >= temp->num)
//					{
//						p = p->left;
//					}
//					else
//					{
//						p = p->right;
//					}
//					if (p == NULL)
//					{
//						break;
//					}
//				}
//				if (q->num >= temp->num)
//					q->left = temp;
//				else
//					q->right = temp;
//			}
//			printf("Do you want to continue? [1/0]: ");
//			scanf_f("%d", &ch);
//		} while (ch != 0);
//	}
//	void createlistbfs(struct node* root, struct list** head)
//	{
//		struct queue* qhead, * qrear, * qtemp, * qrelease;
//		struct list* temp, * rear;
//		if (root == NULL)
//		{
//			return;
//		}
//		qhead = (struct queue*)malloc(sizeof(struct queue));
//		qhead->nodeptr = root;
//		qhead->next = NULL;
//		qrear = qhead;
//		while (qhead != NULL)
//		{
//			temp = (struct list*)malloc(sizeof(struct list));
//			temp->num = qhead->nodeptr->num;
//			temp->next = NULL;
//			if (*head == NULL)
//			{
//				*head = temp;
//			}
//			else
//			{
//				rear->next = temp;
//			}
//			rear = temp;
//			if (qhead->nodeptr->left != NULL)
//			{
//				qtemp = (struct queue*)malloc(sizeof(struct queue));
//				qtemp->nodeptr = qhead->nodeptr->left;
//				qtemp->next = NULL;
//				qrear->next = qtemp;
//				qrear = qtemp;
//			}
//			if (qhead->nodeptr->right != NULL)
//			{
//				qtemp = (struct queue*)malloc(sizeof(struct queue));
//				qtemp->nodeptr = qhead->nodeptr->right;
//				qtemp->next = NULL;
//				qrear->next = qtemp;
//				qrear = qtemp;
//			}
//			qrelease = qhead;
//			qhead = qhead->next;
//			free(qrelease);
//		}
//	}
//	void delete(struct node** root)
//	{
//		if (*root == NULL)
//		{
//			return;
//		}
//		else
//		{
//			if ((*root)->left != NULL)
//			{
//				delete(&((*root)->left));
//			}
//			if ((*root)->right != NULL)
//			{
//				delete(&((*root)->right));
//			}
//		}
//	}
//	void display(struct list* head)
//	{
//		while (head != NULL)
//		{
//			printf("%d  ", head->num);
//			head = head->next;
//		}
//	}
//	void deleteList(struct list** head)
//	{
//		struct list* temp;
//		temp = *head;
//		while (temp != NULL)
//		{
//			*head = (*head)->next;
//			free(temp);
//			temp = *head;
//		}
//	}
//	//------------------------------------------------------------------------------------------------------------
//		/*
//		 * C Program to Construct a Balanced Binary Search Tree
//		 * which has same data members as the given Doubly Linked List
//		 */
// #include <stdio.h>
// #include <stdlib.h>
//	struct node
//	{
//		int num;
//		struct node* left;
//		struct node* right;
//	};
//	void create(struct node**);
//	void treemaker(struct node**, int);
//	void display(struct node*);
//	void displayTree(struct node*);
//	void delete(struct node**);
//	int main()
//	{
//		struct node* headList = NULL, * rootTree, * p;
//		int count = 1, flag = 0;
//		create(&headList);
//		printf("Displaying the doubly linked list:\n");
//		display(headList);
//		rootTree = p = headList;
//		while (p->right != NULL)
//		{
//			p = p->right;
//			count = count + 1;
//			if (flag)
//			{
//				rootTree = rootTree->right;
//			}
//			flag = !flag;
//		}
//		treemaker(&rootTree, count / 2);
//		printf("Displaying the tree: (Inorder)\n");
//		displayTree(rootTree);
//		printf("\n");
//		return 0;
//	}
//	void create(struct node** head)
//	{
//		struct node* rear, * temp;
//		int a, ch;
//		do
//		{
//			printf("Enter a number: ");
//			scanf_f("%d", &a);
//			temp = (struct node*)malloc(sizeof(struct node));
//			temp->num = a;
//			temp->right = NULL;
//			temp->left = NULL;
//			if (*head == NULL)
//			{
//				*head = temp;
//			}
//			else
//			{
//				rear->right = temp;
//				temp->left = rear;
//			}
//			rear = temp;
//			printf("Do you wish to continue [1/0] ?: ");
//			scanf_f("%d", &ch);
//		} while (ch != 0);
//	}
//	void treemaker(struct node** root, int count)
//	{
//		struct node* quarter, * thirdquarter;
//		int n = count, i = 0;
//		if ((*root)->left != NULL)
//		{
//			quarter = (*root)->left;
//			for (i = 1; (i < count / 2) && (quarter->left != NULL); i++)
//			{
//				quarter = quarter->left;
//			}
//			(*root)->left->right = NULL;
//			(*root)->left = quarter;
//			/*
//			 * Uncomment the following line to see when the pointer changes
//			 */
//			 //printf("%d's left child is now %d\n", (*root)->num, quarter->num);
//			if (quarter != NULL)
//			{
//				treemaker(&quarter, count / 2);
//			}
//		}
//		if ((*root)->right != NULL)
//		{
//			thirdquarter = (*root)->right;
//			for (i = 1; (i < count / 2) && (thirdquarter->right != NULL); i++)
//			{
//				thirdquarter = thirdquarter->right;
//			}
//			(*root)->right->left = NULL;
//			(*root)->right = thirdquarter;
//			/*
//			 * Uncomment the following line to see when the pointer changes
//			 */
//			 //printf("%d's right child is now %d\n", (*root)->num, thirdquarter->num);
//			if (thirdquarter != NULL)
//			{
//				treemaker(&thirdquarter, count / 2);
//			}
//		}
//	}
//	void display(struct node* head)
//	{
//		while (head != NULL)
//		{
//			printf("%d  ", head->num);
//			head = head->right;
//		}
//		printf("\n");
//	}
//	/*DisplayTree performs inorder traversal*/
//	void displayTree(struct node* root)
//	{
//		if (root != NULL)
//		{
//			displayTree(root->left);
//			printf("%d  ", root->num);
//			displayTree(root->right);
//		}
//	}
//	void delete(struct node** root)
//	{
//		if (*root != NULL)
//		{
//			displayTree((*root)->left);
//			displayTree((*root)->right);
//			free(*root);
//		}
//	}
//	//-----------------------------------------------------------------------------------------------------------
//		/*
//		 * C Program that takes an Ordered Binary tree & Rearranges the
//		 * Internal Pointers to make a Circular Doubly Linked List out
//		 * of the Tree Nodes
//		 */
// #include <stdio.h>
// #include <stdlib.h>
//	struct node
//	{
//		int num;
//		struct node* left;
//		struct node* right;
//		int used;
//	};
//	void create(struct node**);
//	void release(struct node**);
//	void display(struct node*, int);
//	struct node* transformdet(struct node*);
//	struct node* transform(struct node*);
//	int main()
//	{
//		struct node* root = NULL, * head;
//		printf("Creating binary tree:\n");
//		create(&root);
//		printf("Displaying binary tree:\n");
//		display(root, 0);
//		head = transform(root);
//		printf("\nDisplaying circular linked list:\n");
//		display(head, 1);
//		root->left->right = NULL;
//		release(&root);
//		return 0;
//	}
//	struct node* transformdet(struct node* root)
//	{
//		struct node* left, * right;
//		if (root == NULL)
//		{
//			return root;
//		}
//		if (root->left != NULL)
//		{
//			left = transformdet(root->left);
//			while (left->right != NULL)
//			{
//				left = left->right;
//			}
//			left->right = root;
//			root->left = left;
//		}
//		if (root->right != NULL)
//		{
//			right = transformdet(root->right);
//			while (right->left != NULL)
//			{
//				right = right->left;
//			}
//			right->left = root;
//			root->right = right;
//		}
//		return root;
//	}
//	struct node* transform(struct node* root)
//	{
//		struct node* rear;
//		if (root == NULL)
//		{
//			return root;
//		}
//		root = transformdet(root);
//		rear = root;
//		while (root->left != NULL)
//		{
//			root = root->left;
//		}
//		while (rear->right != NULL)
//		{
//			rear = rear->right;
//		}
//		root->left = rear;
//		rear->right = root;
//		return (root);
//	}
//	void create(struct node** root)
//	{
//		struct node* temp, * p, * q;
//		int a, ch;
//		do
//		{
//			p = *root;
//			printf("Enter a number in the tree: ");
//			scanf_f("%d", &a);
//			temp = (struct node*)malloc(sizeof(struct node));
//			temp->num = a;
//			temp->used = 0;
//			temp->left = temp->right = NULL;
//			if (*root == NULL)
//			{
//				*root = temp;
//			}
//			else
//			{
//				while (p != NULL)
//				{
//					q = p;
//					if (p->num >= temp->num)
//					{
//						p = p->right;
//					}
//					else
//					{
//						p = p->left;
//					}
//				}
//				if (q->num >= temp->num)
//				{
//					q->right = temp;
//				}
//				else
//				{
//					q->left = temp;
//				}
//			}
//			printf("Do you want to add more numbers? [1/0]\n");
//			scanf_f("%d", &ch);
//		} while (ch != 0);
//	}
//	void display(struct node* root, int n)
//	{
//		struct node* temp;
//		if (root != NULL && !n)
//		{
//			display(root->left, 0);
//			printf("%d   ", root->num);
//			display(root->right, 0);
//		}
//		else if (root != NULL && n)
//		{
//			temp = root;
//			printf("%d   ", temp->num);
//			temp = temp->right;
//			while (temp != root)
//			{
//				printf("%d   ", temp->num);
//				temp = temp->right;
//			}
//			printf("\n");
//		}
//	}
//	void release(struct node** root)
//	{
//		if (*root != NULL)
//		{
//			release(&(*root)->right);
//			free(*root);
//		}
//	}
//	//----------------------------------------------------------------------------------------------------------
//		/*
//		 * C Program to Support Infinite Precision Arithmetic & Store a
//		 * Number as a List of Digits
//		 */
// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>
//	struct node
//	{
//		int num;
//		struct node* next;
//	};
//	int feednumber(struct node**);
//	void release(struct node**);
//	void display(struct node*);
//	int main()
//	{
//		struct node* p = NULL;
//		int pcount = 0, qcount = 0;
//		printf("Enter number of any length\n");
//		pcount = feednumber(&p);
//		printf("Number of integers entered are: %d\n", pcount);
//		printf("Displaying the number entered:\n");
//		display(p);
//		release(&p);
//		return 0;
//	}
//	/*Function to create nodes of numbers*/
//	int feednumber(struct node** head)
//	{
//		char ch, dig;
//		int count = 0;
//		struct node* temp, * rear = NULL;
//		ch = getchar();
//		while (ch != '\n')
//		{
//			dig = atoi(&ch);
//			temp = (struct node*)malloc(sizeof(struct node));
//			temp->num = dig;
//			temp->next = NULL;
//			count++;
//			if ((*head) == NULL)
//			{
//				*head = temp;
//				rear = temp;
//			}
//			else
//			{
//				rear->next = temp;
//				rear = rear->next;
//			}
//			ch = getchar();
//		}
//		return count;
//	}
//	/*Function to display the list of numbers*/
//	void display(struct node* head)
//	{
//		while (head != NULL)
//		{
//			printf("%d", head->num);
//			head = head->next;
//		}
//		printf("\n");
//	}
//	/*Function to free the allocated list of numbers*/
//	void release(struct node** head)
//	{
//		struct node* temp = *head;
//		while ((*head) != NULL)
//		{
//			(*head) = (*head)->next;
//			free(temp);
//			temp = *head;
//		}
//	}
//	//----------------------------------------------------------------------------------------------------------
//		/*
//		 * C Program to Solve Josephus Problem using Linked List
//		 */
// #include <stdio.h>
// #include <stdlib.h>
//	struct node
//	{
//		int num;
//		struct node* next;
//	};
//	void create(struct node**);
//	void display(struct node*);
//	int survivor(struct node**, int);
//	int main()
//	{
//		struct node* head = NULL;
//		int survive, skip;
//		create(&head);
//		printf("The persons in circular list are:\n");
//		display(head);
//		printf("Enter the number of persons to be skipped: ");
//		scanf_f("%d", &skip);
//		survive = survivor(&head, skip);
//		printf("The person to survive is : %d\n", survive);
//		free(head);
//		return 0;
//	}
//	int survivor(struct node** head, int k)
//	{
//		struct node* p, * q;
//		int i;
//		q = p = *head;
//		while (p->next != p)
//		{
//			for (i = 0; i < k - 1; i++)
//			{
//				q = p;
//				p = p->next;
//			}
//			q->next = p->next;
//			printf("%d has been killed.\n", p->num);
//			free(p);
//			p = q->next;
//		}
//		*head = p;
//		return (p->num);
//	}
//	void create(struct node** head)
//	{
//		struct node* temp, * rear;
//		int a, ch;
//		do
//		{
//			printf("Enter a number: ");
//			scanf_f("%d", &a);
//			temp = (struct node*)malloc(sizeof(struct node));
//			temp->num = a;
//			temp->next = NULL;
//			if (*head == NULL)
//			{
//				*head = temp;
//			}
//			else
//			{
//				rear->next = temp;
//			}
//			rear = temp;
//			printf("Do you want to add a number [1/0]? ");
//			scanf_f("%d", &ch);
//		} while (ch != 0);
//		rear->next = *head;
//	}
//	void display(struct node* head)
//	{
//		struct node* temp;
//		temp = head;
//		printf("%d   ", temp->num);
//		temp = temp->next;
//		while (head != temp)
//		{
//			printf("%d   ", temp->num);
//			temp = temp->next;
//		}
//		printf("\n");
//	}
//	//-----------------------------------------------------------------------------------------------------------
//		/*
//		 * C Program to Print Nth Node from the last of a Linked List
//		 */
// #include <stdio.h>
// #include <stdlib.h>
//	struct node
//	{
//		int num;
//		struct node* next;
//	};
//	void create(struct node**);
//	void nthnode(struct node*, int);
//	void release(struct node**);
//	int main()
//	{
//		struct node* p = NULL;
//		int n;
//		printf("Enter data into the list\n");
//		create(&p);
//		printf("Enter the value n to find nth position from the last node: ");
//		scanf_f("%d", &n);
//		nthnode(p, n);
//		release(&p);
//		return 0;
//	}
//	void nthnode(struct node* head, int n)
//	{
//		struct node* p, * q;
//		int i;
//		q = p = head;
//		for (i = 0; i < n && q != NULL; i++)
//		{
//			q = q->next;
//		}
//		if (i < n)
//		{
//			printf("Entered n = %d is larger than the number of elements = %d in list. Please try again.\n", n, i);
//		}
//		else
//		{
//			while (q->next != NULL)
//			{
//				q = q->next;
//				p = p->next;
//			}
//			printf("%d is %d nodes from the last node.\n", p->num, n);
//		}
//	}
//	void create(struct node** head)
//	{
//		int c, ch;
//		struct node* temp, * rear;
//		do
//		{
//			printf("Enter number: ");
//			scanf_f("%d", &c);
//			temp = (struct node*)malloc(sizeof(struct node));
//			temp->num = c;
//			temp->next = NULL;
//			if (*head == NULL)
//			{
//				*head = temp;
//			}
//			else
//			{
//				rear->next = temp;
//			}
//			rear = temp;
//			printf("Do you wish to continue [1/0]: ");
//			scanf_f("%d", &ch);
//		} while (ch != 0);
//		printf("\n");
//	}
//	void release(struct node** head)
//	{
//		struct node* temp = *head;
//		*head = (*head)->next;
//		while ((*head) != NULL)
//		{
//			free(temp);
//			temp = *head;
//			(*head) = (*head)->next;
//		}
//	}
//	//-----------------------------------------------------------------------------------------------------------
//		/*
//		 * C Program to Modify the Linked List such that All Even Numbers
//		 * appear before all the Odd Numbers in the Modified Linked List
//		 */
// #include <stdio.h>
// #include <stdlib.h>
//	struct node
//	{
//		int num;
//		struct node* next;
//	};
//	void create(struct node**);
//	void generate_evenodd(struct node*, struct node**);
//	void release(struct node**);
//	void display(struct node*);
//	int main()
//	{
//		struct node* p = NULL, * q = NULL;
//		int key, result;
//		printf("Enter data into the list\n");
//		create(&p);
//		printf("Displaying the nodes in the list:\n");
//		display(p);
//		generate_evenodd(p, &q);
//		printf("Displaying the list with even and then odd:\n");
//		display(q);
//		release(&p);
//		return 0;
//	}
//	void generate_evenodd(struct node* list, struct node** head)
//	{
//		struct node* even = NULL, * odd = NULL, * temp;
//		struct node* reven, * rodd;
//		while (list != NULL)
//		{
//			temp = (struct node*)malloc(sizeof(struct node));
//			temp->num = list->num;
//			temp->next = NULL;
//			if (list->num % 2 == 0)
//			{
//				if (even == NULL)
//				{
//					even = temp;
//				}
//				else
//				{
//					reven->next = temp;
//				}
//				reven = temp;
//			}
//			else
//			{
//				if (odd == NULL)
//				{
//					odd = temp;
//				}
//				else
//				{
//					rodd->next = temp;
//				}
//				rodd = temp;
//			}
//			list = list->next;
//		}
//		reven->next = odd;
//		*head = even;
//	}
//	void create(struct node** head)
//	{
//		int c, ch;
//		struct node* temp, * rear;
//		do
//		{
//			printf("Enter number: ");
//			scanf_f("%d", &c);
//			temp = (struct node*)malloc(sizeof(struct node));
//			temp->num = c;
//			temp->next = NULL;
//			if (*head == NULL)
//			{
//				*head = temp;
//			}
//			else
//			{
//				rear->next = temp;
//			}
//			rear = temp;
//			printf("Do you wish to continue [1/0]: ");
//			scanf_f("%d", &ch);
//		} while (ch != 0);
//		printf("\n");
//	}
//	void display(struct node* p)
//	{
//		while (p != NULL)
//		{
//			printf("%d\t", p->num);
//			p = p->next;
//		}
//		printf("\n");
//	}
//	void release(struct node** head)
//	{
//		struct node* temp = *head;
//		*head = (*head)->next;
//		while ((*head) != NULL)
//		{
//			free(temp);
//			temp = *head;
//			(*head) = (*head)->next;
//		}
//	}
//	//---------------------------------------------------------------------------------------------------------
//		/*
//		 * C Program to Interchange two Elements of the List without
//		 * touching the Key Field
//		 */
// #include <stdio.h>
// #include <stdlib.h>
//	struct node
//	{
//		int num;
//		struct node* next;
//	};
//	void create(struct node**);
//	void release(struct node**);
//	void change(struct node**, int, int);
//	void display(struct node*);
//	int main()
//	{
//		struct node* p = NULL;
//		int num1, num2;
//		printf("Enter data into the list\n");
//		create(&p);
//		printf("Circular list generated\n");
//		display(p);
//		printf("Enter node position: ");
//		scanf_f("%d", &num1);
//		printf("Enter node position to exchange with: ");
//		scanf_f("%d", &num2);
//		change(&p, num1 - 2, num2 - 2);
//		printf("After interchanging, ");
//		display(p);
//		release(&p);
//		return 0;
//	}
//	void change(struct node** head, int num1, int num2)
//	{
//		struct node* p1, * q1, * r1;
//		struct node* p2, * q2, * r2;
//		p1 = q1 = r1 = *head;
//		p2 = q2 = r2 = *head;
//		if (num1 == num2)
//		{
//			return;
//		}
//		else if ((p1->next == NULL && num1 > 0) || (p1->next->next == NULL && num1 > 1))
//		{
//			printf("List smaller than entered node position.\n");
//		}
//		else if ((p2->next == NULL && num2 > 0) || (p2->next->next == NULL && num2 > 1))
//		{
//			printf("List smaller than entered node position.\n");
//		}
//		else
//		{
//			if (num1 >= 0 && num2 >= 0)
//			{
//				p1 = p1->next->next;
//				q1 = q1->next;
//				while (num1 > 0)
//				{
//					r1 = q1;
//					q1 = p1;
//					p1 = p1->next;
//					num1--;
//				}
//				p2 = p2->next->next;
//				q2 = q2->next;
//				while (num2 > 0)
//				{
//					r2 = q2;
//					q2 = p2;
//					p2 = p2->next;
//					num2--;
//				}
//				r2->next = q1;
//				q2->next = p1;
//				r1->next = q2;
//				q1->next = p2;
//			}
//			else if (num1 == -1)
//			{
//				p2 = p2->next->next;
//				q2 = q2->next;
//				while (num2 > 0)
//				{
//					r2 = q2;
//					q2 = p2;
//					p2 = p2->next;
//					num2--;
//				}
//				if (p1->next != q2)
//				{
//					q2->next = p1->next;
//					p1->next = p2;
//					r2->next = p1;
//				}
//				else
//				{
//					p1->next = q2->next;
//					q2->next = p1;
//				}
//				*head = q2;
//			}
//			else if (num2 == -1)
//			{
//				p1 = p1->next->next;
//				q1 = q1->next;
//				while (num1 > 0)
//				{
//					r1 = q1;
//					q1 = p1;
//					p1 = p1->next;
//					num1--;
//				}
//				if (p2->next != q1)
//				{
//					q1->next = p2->next;
//					p2->next = p1;
//					r1->next = p2;
//				}
//				else
//				{
//					p2->next = q1->next;
//					q1->next = p2;
//				}
//				*head = q1;
//			}
//		}
//	}
//	void create(struct node** head)
//	{
//		int c, ch;
//		struct node* temp, * rear;
//		do
//		{
//			printf("Enter number: ");
//			scanf_f("%d", &c);
//			temp = (struct node*)malloc(sizeof(struct node));
//			temp->num = c;
//			temp->next = NULL;
//			if (*head == NULL)
//			{
//				*head = temp;
//			}
//			else
//			{
//				rear->next = temp;
//			}
//			rear = temp;
//			printf("Do you wish to continue [1/0]: ");
//			scanf_f("%d", &ch);
//		} while (ch != 0);
//		printf("\n");
//	}
//	void display(struct node* head)
//	{
//		struct node* temp = head;
//		printf("Displaying the list elements\n");
//		while (temp != NULL)
//		{
//			printf("%d\t", temp->num);
//			temp = temp->next;
//		}
//		printf("\n");
//	}
//	void release(struct node** head)
//	{
//		struct node* temp = *head;
//		*head = (*head)->next;
//		while ((*head) != NULL)
//		{
//			free(temp);
//			temp = *head;
//			(*head) = (*head)->next;
//		}
//	}
//	//---------------------------------------------------------------------------------------------------------
//		/*
//		 * C Program to Interchange the two Adjacent Nodes given a circular
//		 * Linked List
//		 */
// #include <stdio.h>
// #include <stdlib.h>
//	struct node
//	{
//		int num;
//		struct node* next;
//	};
//	void create(struct node**);
//	void tocircular(struct node**);
//	void release(struct node**);
//	void change(struct node**, int);
//	void display(struct node*);
//	int main()
//	{
//		struct node* p = NULL;
//		int num;
//		printf("Enter data into the list\n");
//		create(&p);
//		tocircular(&p);
//		printf("Circular list generated\n");
//		display(p);
//		printf("Enter node position to interchange with it's adjacent: ");
//		scanf_f("%d", &num);
//		change(&p, num - 2);
//		printf("After interchanging, ");
//		display(p);
//		release(&p);
//		return 0;
//	}
//	void tocircular(struct node** p)
//	{
//		struct node* rear;
//		rear = *p;
//		while (rear->next != NULL)
//		{
//			rear = rear->next;
//		}
//		rear->next = *p;
//		/*After this the singly linked list is now circular*/
//	}
//	void change(struct node** head, int num)
//	{
//		struct node* p, * q, * r;
//		p = q = r = *head;
//		p = p->next->next;
//		q = q->next;
//		while (num != 0)
//		{
//			r = q;
//			q = p;
//			p = p->next;
//			num--;
//		}
//		r->next = p;
//		q->next = p->next;
//		p->next = q;
//	}
//	void create(struct node** head)
//	{
//		int c, ch;
//		struct node* temp, * rear;
//		do
//		{
//			printf("Enter number: ");
//			scanf_f("%d", &c);
//			temp = (struct node*)malloc(sizeof(struct node));
//			temp->num = c;
//			temp->next = NULL;
//			if (*head == NULL)
//			{
//				*head = temp;
//			}
//			else
//			{
//				rear->next = temp;
//			}
//			rear = temp;
//			printf("Do you wish to continue [1/0]: ");
//			scanf_f("%d", &ch);
//		} while (ch != 0);
//		printf("\n");
//	}
//	void display(struct node* head)
//	{
//		struct node* temp = head;
//		printf("Displaying the list elements\n");
//		printf("%d\t", temp->num);
//		temp = temp->next;
//		while (head != temp)
//		{
//			printf("%d\t", temp->num);
//			temp = temp->next;
//		}
//		printf("\n");
//	}
//	void release(struct node** head)
//	{
//		struct node* temp = *head;
//		temp = temp->next;
//		(*head)->next = NULL;
//		(*head) = temp->next;
//		while ((*head) != NULL)
//		{
//			free(temp);
//			temp = *head;
//			(*head) = (*head)->next;
//		}
//	}
//	//------------------------------------------------------------------------------------------------------------

#pragma region SortedList
typedef struct node0
{
    int key;
    struct node0 *next;
} NODE0;

static NODE0 *prim0 = 0, *last0 = 0;

static void add_node0(int x)
{
    NODE0 *p, *q, *r;
    p = (NODE0 *)malloc(sizeof(NODE0));
    p->key = x;
    p->next = 0;

    if (0 == prim0)
    {
        prim0 = p;
        last0 = p;
    }
    else
    {
        if (x < prim0->key)
        {
            p->next = prim0;
            prim0 = p;
        }
        else
        {
            if (x > last0->key)
            {
                last0->next = p;
                last0 = p;
            }
            else
            {
                for (q = r = prim0; q != 0 && q->key < x; r = q, q = q->next)
                {
                    ;
                }
                r->next = p;
                p->next = q;
            }
        }
    }
}

static void delete_node0(int x)
{
    NODE0 *p, *q;

    if (prim0->key == x)
    {
        p = prim0;
        prim0 = prim0->next;
        free(p);
    }
    else
    {
        for (p = q = prim0; p != 0; q = p, p = p->next)
        {
            if (p->key == x)
            {
                q->next = p->next;

                if (p == last0)
                    last0 = q;

                free(p);
            }
        }
    }
}

static void show_node0()
{
    for (NODE0 *p = prim0; p != 0; p = p->next)
    {
        printf("%d  ", p->key);
    }

    printf("\n");
}

static void sortedList()
{
    add_node0(3);
    add_node0(1);
    add_node0(2);
    add_node0(5);
    show_node0();

    delete_node0(2);
    show_node0();

    add_node0(10);
    add_node0(15);
    add_node0(12);
    show_node0();
}
#pragma endregion

#pragma region StackList
typedef struct node_1
{
    int key;
    struct node_1 *next;
} NODE_1;

NODE_1 *prim_1 = 0;

static void push_1(int x)
{
    NODE_1 *p = 0;
    p = (NODE_1 *)malloc(sizeof(NODE_1));
    p->key = x;
    p->next = 0;

    if (prim_1 == 0)
        prim_1 = p;
    else
    {
        p->next = prim_1;
        prim_1 = p;
    }
}

static int pop_1()
{
    int x = prim_1->key;
    NODE_1 *p = prim_1;
    prim_1 = prim_1->next;
    free(p);

    return x;
}

static int top_1()
{
    return prim_1->key;
}

static void stackList()
{
    push_1(10);
    push_1(20);
    push_1(30);
    push_1(40);
    push_1(50);

    printf("%d\n", top_1());
    printf("%d\n", pop_1());
    printf("%d\n", top_1());
    printf("%d\n", pop_1());
    printf("%d\n", top_1());
}

#pragma endregion