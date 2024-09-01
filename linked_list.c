#include<stdio.h>
#include<stdlib.h>
#include "typedef.h"

/*	Topics covered	*/
//	1. Double linked list
//	2. Insert a node at the end
//	3. Insert a node at any position
//	4. Insert a node at the head
//	5. Illustration of function pointer
//	6. Reverse the linked list

struct node * (*proc_func_ptr)(int data);

struct node * proc_insert_node(int data)
{
	struct node * node;
	node = (struct node *)malloc(sizeof(struct node));
	node->data = data;
	node->next_ptr = NULL;
	node->prev_ptr = NULL;
	return node;
}

void proc_insert_node_pos(struct node **node, int data, int pos)
{
	struct node *temp;
	int tmp_pos,tmp_data,tmp_;
	tmp_pos = pos;
	printf("%d",((struct node *)*node)->next_ptr);
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
	int len,j;
	
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
	temp1->next_ptr = NULL;
	return temp3;
}

void proc_linked(void)
{
	struct node *head, *temp, *tail, *temp1,*temp2;
	int data,pos,length;
	proc_func_ptr = proc_insert_node;
	
	head = proc_func_ptr(10);
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

	//printf("%d\t%d\t%d\n", head,head->prev_ptr, head->next_ptr);
	//printf("%d\t%d\t%d\n", head->next_ptr,head->next_ptr->prev_ptr, head->next_ptr->next_ptr);
	//printf("%d\t%d\t%d\n", head->next_ptr->next_ptr,head->next_ptr->next_ptr->prev_ptr, head->next_ptr->next_ptr->next_ptr);
	//Search the element in the list.
	//insert a node in the list
	pos = 1;
	proc_insert_node_pos(&head, 5, pos);
	
//printf("%d %d", &head, head->next_ptr);
	
	printf("\nEnter the data to search:");
	scanf("%d", &data);

	// Reverse the linked list 
	head = proc_reverse_list(head);
	// Search with Iterative Brute force method, parse through all nodes O(N)
	temp = head;
	printf("%d", temp->data);
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
	
	
	//Search with 2 pointers (Head & Tail) O(2N) = O(N)
	temp = head;
	length = 0;
	//find tail
	while(temp->next_ptr != NULL)
	{
		temp = temp->next_ptr;
		length++;
	}
	tail = temp;
	temp = head;
	pos = 0;
	while((temp->next_ptr!=NULL)|(tail->prev_ptr!=NULL))
	{
		if(temp->data==data)
		{
			printf("\nHead Found at pos %d",pos);
			break;
		}
		if(tail->data == data)
		{
			printf("\nTail Found at pos %d",length-pos);
			break;
		}
		pos++;
		temp = temp->next_ptr;
		tail = tail->prev_ptr;
	}
	
	
}