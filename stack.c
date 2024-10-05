#include<stdio.h>
#include<stdlib.h>

#include "typedef.h"
#include "stack.h"

/*struct stack
{
	uint8 s_data;
	struct stack *next_ptr;
};*/

uint8 proc_stack_isEmpty(const struct stack **head)
{
	if(*head != NULL)
	{return 0;}
	else
	{return 1;}
}

uint8 stack_size(const struct stack **head)
{
	struct stack *p1;
	uint8 stack_len;
	
	p1 = (struct stack *)*head;
	stack_len = 0;
	while(p1 != NULL)
	{
		++stack_len;
		p1 = p1->next_ptr;
	}
	
	return stack_len;
}

void proc_stack_push(struct stack **head, uint8 data)
{
	struct stack *p1;
	uint8 i;
	static uint8 first_entry = 1;
	static uint8 stack_len = 0;

	if(stack_len < MAX_STACK_LENGTH)
	{
		p1 = malloc(sizeof(struct stack));
		p1->s_data = data;
		if(first_entry)
		{
			p1->next_ptr = NULL;
			first_entry = 0;
		}
		else
		{
			p1->next_ptr = *head;
		}
		*head = p1;
		stack_len++;
	}
	else
	{
		printf("Stack full!!!\n");
	}
}

uint8 proc_stack_pop(struct stack **head)
{
	struct stack *p1;
	if(head!=NULL)
	{
		if(*head!=NULL)
		{
			p1 = *head;
			*head = (*head)->next_ptr;
			return (p1->s_data);
		}
		else
		{
			printf("The stack is empty\n");
		}
	}
	else
	{
		printf("The stack is empty\n");
	}
}

void print_stack (struct stack **head)
{
	struct stack *p1;
	p1 = (struct stack *)*head;
	printf("\nStack contents :\n");
	while(p1 != NULL) 
	{
		printf("%d\n", p1->s_data);
		if(p1->next_ptr != NULL)
		{p1 = p1->next_ptr;}
		else
		{return;}
	}
}

void proc_stack(void)
{
	struct stack *s_head;
	uint8 is_Empty;
	
	proc_stack_push(&s_head,10);
	proc_stack_push(&s_head,20);
	proc_stack_push(&s_head,30);
	proc_stack_push(&s_head,40);
	proc_stack_push(&s_head,50);
	proc_stack_push(&s_head,60);
	
	printf("Stack size = %d\n", stack_size(&s_head));
	is_Empty = proc_stack_isEmpty(&s_head);
	if (!is_Empty)
		printf("The stack is not empty\n");
	else
		printf("The stack is empty\n");
	//printf("\n Stack contents :\n");
	print_stack(&s_head);

	printf("Data popped %d\n", proc_stack_pop(&s_head));
	print_stack(&s_head);
	printf("Data popped %d\n", proc_stack_pop(&s_head));
	print_stack(&s_head);
	printf("Data popped %d\n", proc_stack_pop(&s_head));
	print_stack(&s_head);
	printf("Data popped %d\n", proc_stack_pop(&s_head));
	print_stack(&s_head);
	printf("Data popped %d\n", proc_stack_pop(&s_head));
	proc_stack_pop(&s_head);

	is_Empty = proc_stack_isEmpty(&s_head);
	if (!is_Empty)
		printf("The stack is not empty\n");
	else
		printf("The stack is empty\n");

}