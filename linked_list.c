#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include "typedef.h"
#include "linked_list.h"

/*	Topics covered	*/
//	1. Double linked list
//	2. Insert a node at the end
//	3. Insert a node at any position
//	4. Insert a node at the head
//	5. Illustration of function pointer
//	6. Reverse the linked list

struct node * (*proc_func_ptr)(uint8 data);
struct node *head=NULL;

struct node * proc_insert_node(uint8 data)
{
	struct node * node;
	node = (struct node *)malloc(sizeof(struct node));
	node->data = data;
	node->next_ptr = NULL;
	node->prev_ptr = NULL;
	return node;
}

//Function to insert a node for a single linked list
struct node * proc_insert_node2(struct node **node, uint8 data)
{
	struct node * head;
	while(*node!=NULL)
	{ 
		*node = (*node)->next_ptr;
	}
	*node = proc_insert_node(data);
}

void proc_insert_node_pos(struct node **node, uint8 data, uint8 pos)
{
	struct node *temp;
	uint8 tmp_pos,tmp_data,tmp_;
	tmp_pos = pos;
	//printf("%d",((struct node *)*node)->next_ptr);
	//return;
	while(((struct node *)*node)->next_ptr != NULL)
	{
		if(pos > 1)
		{
			*node = ((struct node *)*node)->next_ptr;
			pos--;
		}
		else
		{
			//Insert the node at the head position.
			if(tmp_pos == 0)
			{
				
				temp->data = ((struct node *)*node)->data;
				temp->next_ptr = ((struct node *)*node)->next_ptr;
				temp->prev_ptr = ((struct node *)*node)->prev_ptr;
				
				*node = proc_insert_node(data);
				printf("%d %d\n",&node,*node);
				
				((struct node *)*node)->next_ptr = proc_insert_node(temp->data);
				((struct node *)*node)->next_ptr->prev_ptr = ((struct node *)*node);
				((struct node *)*node)->next_ptr->next_ptr = temp->next_ptr;
			}
			else
			{
				temp = ((struct node *)*node)->next_ptr;
				((struct node *)*node)->next_ptr = proc_insert_node(data);
				((struct node *)*node)->next_ptr->prev_ptr = temp->prev_ptr;
				((struct node *)*node)->next_ptr->next_ptr = temp;
				((struct node *)*node)->next_ptr->next_ptr->prev_ptr = ((struct node *)*node)->next_ptr;
			}
			break;
		}
	}
}

struct node * proc_reverse_list(struct node *node)
{
	struct node *temp1, *temp2, *temp3;
	uint8 len,j;
	
	temp1 = node;							// NULL <- A <->B <-> C -> NULL
	temp2 = node;							// NULL <- C <->B <-> A -> NULL
	len = 0;
	while(temp1->next_ptr != NULL)
	{
		temp1 = temp1->next_ptr;
		len++;
	}
	temp3 = temp1;
	temp2 = NULL;
	while(len != 0)
	{
		temp1->next_ptr = temp1->prev_ptr;
		temp1->prev_ptr = temp2;
		temp2 = temp1;
		temp1 = temp1->next_ptr;
		len--;
	}
	temp1->prev_ptr = temp2;
	temp1->next_ptr = NULL;
	return temp3;
}

void proc_search_list_method1(struct node *node, uint8 data)
{
	struct node *temp;
	uint8 pos;
	// Search with Iterative Brute force method, parse through all nodes O(N)
	temp = node;
	//printf("%d", temp->data);
	pos = 0;
	do
	{
		if(temp->data == data)
		{
			printf("Found at place %d", pos);
			break;
		}
		temp = temp->next_ptr;
		pos++;
	}while(temp != NULL);
	
}

void proc_print_list(struct node * node)
{
	struct node *temp;
	temp = node;
	printf("\n\tData\tNode Address\t+1 Node Address -1 Node Address\n");
	while(temp !=NULL)
	{
		printf("%10d\t%10d\t%10d\t%10d\n", temp->data,&temp->data,temp->next_ptr, temp->prev_ptr);
		temp = temp->next_ptr;
	}
}

// Function to search with 2 pointers head and tail
void proc_search_list_method2(struct node *node, uint8 data)
{
	struct node *temp, *temp2, *tail;
	uint8 length,pos;
	//Search with 2 pointers (Head & Tail) O(2N) = O(N)
	temp = node;
	temp2 = node;
	length = 0;
	//find tail
	while(temp->next_ptr != NULL)
	{
		temp = temp->next_ptr;
		length++;
	}
	tail = temp;

	pos = 0;
	//proc_print_list(temp);
	while((temp2->next_ptr!=NULL)|(tail->prev_ptr!=NULL))
	{
		if(temp2->data==data)
		{
			printf("\nFound at pos %d by Head ptr",pos);
			break;
		}
		if(tail->data == data)
		{
			printf("\nFound at pos %d by Tail ptr",length-pos);
			break;
		}
		pos++;
		temp2 = temp2->next_ptr;
		tail = tail->prev_ptr;
	}
		
}

void proc_linked(void)
{
	//struct node *head=NULL, *temp, *tail, *temp1,*temp2; //The behavior changes with local *head structure while using scanf
	struct node *temp, *tail, *temp1,*temp2;
	uint8 data,pos,length;

	//proc_insert_node2(&head,10); //Inserting a node for a single linked list 
	head = proc_insert_node(10);
	head->next_ptr = proc_insert_node(20);
	head->next_ptr->prev_ptr = head;
	head->next_ptr->next_ptr = proc_insert_node(30);
	head->next_ptr->next_ptr->prev_ptr = head->next_ptr;
	head->next_ptr->next_ptr->next_ptr = proc_insert_node(40);
	head->next_ptr->next_ptr->next_ptr->prev_ptr = head->next_ptr->next_ptr;
	head->next_ptr->next_ptr->next_ptr->next_ptr = proc_insert_node(50);
	head->next_ptr->next_ptr->next_ptr->next_ptr->prev_ptr = head->next_ptr->next_ptr->next_ptr;
	head->next_ptr->next_ptr->next_ptr->next_ptr->next_ptr = proc_insert_node(60);
	head->next_ptr->next_ptr->next_ptr->next_ptr->next_ptr->prev_ptr = head->next_ptr->next_ptr->next_ptr->next_ptr;
	head->next_ptr->next_ptr->next_ptr->next_ptr->next_ptr->next_ptr = proc_insert_node(70);
	head->next_ptr->next_ptr->next_ptr->next_ptr->next_ptr->next_ptr->prev_ptr = head->next_ptr->next_ptr->next_ptr->next_ptr->next_ptr;
	head->next_ptr->next_ptr->next_ptr->next_ptr->next_ptr->next_ptr->next_ptr = proc_insert_node(80);
	head->next_ptr->next_ptr->next_ptr->next_ptr->next_ptr->next_ptr->next_ptr->prev_ptr = head->next_ptr->next_ptr->next_ptr->next_ptr->next_ptr->next_ptr;
	head->next_ptr->next_ptr->next_ptr->next_ptr->next_ptr->next_ptr->next_ptr->next_ptr = proc_insert_node(90);
	head->next_ptr->next_ptr->next_ptr->next_ptr->next_ptr->next_ptr->next_ptr->next_ptr->prev_ptr = head->next_ptr->next_ptr->next_ptr->next_ptr->next_ptr->next_ptr->next_ptr;
	printf("Printing the list\n");
	proc_print_list(head);
	//printf("%d\t%d\t%d\n", head,head->prev_ptr, head->next_ptr);
	//printf("%d\t%d\t%d\n", head->next_ptr,head->next_ptr->prev_ptr, head->next_ptr->next_ptr);
	//printf("%d\t%d\t%d\n", head->next_ptr->next_ptr,head->next_ptr->next_ptr->prev_ptr, head->next_ptr->next_ptr->next_ptr);
	//Search the element in the list.
	
	//insert a node in the list
	pos = 1;
	//proc_insert_node_pos(&head, 5, pos);
	//printf("List after inserting a node at position %d of the list\n", pos);
	//proc_print_list(head);
	// Reverse the linked list 
	head = proc_reverse_list(head);
	//printf("%d\n", head);
	//temp = head;
	printf("After reversing the list\n");
	proc_print_list(head);
	//printf("%d\n", head);
	//printf("Search in the list\n");
	//printf("Enter the data to search :");
	//data = 50;
	//scanf("%d", &data);
	//printf("%d\n", head);
	//proc_search_list_method2(head,data);
	
}