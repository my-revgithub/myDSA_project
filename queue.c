#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include "queue.h"

void queue_push(struct queue **queue, uint8 data, uint8 priority)
{
	struct queue *q, *temp;
	q = (struct queue *) malloc(sizeof(struct queue));
	
	q->q_priority = priority;
	q->q_data = data;
	q->q_next_ptr = NULL;
	q->q_prev_ptr = NULL;
	
	if(*queue == NULL)
	{
		//printf("reached");
		*queue = q;
	}
	else
	{
		temp = *queue;
		while(temp->q_next_ptr != NULL)
		{
			temp = temp->q_next_ptr;
		}
		temp->q_next_ptr = q;
		temp->q_next_ptr->q_prev_ptr = temp;
	}
	//printf("Queued data %d", (*queue)->q_data); 
}

uint8 queue_pop(struct queue **queue)
{
	struct queue *temp;
	uint8 tmp_prio;
	uint8 status,q_len;
	
	tmp_prio = 0;
	status = 0;
	temp = *queue;
	//printf("->%d\t", (*queue)->q_data);
	//return (*queue)->q_data;

	while(temp!=NULL)
	{ temp = temp->q_next_ptr;q_len++;}
	//printf("->%d\t", --q_len);
	q_len;
	while( q_len > 0)
	{
		temp = *queue;
		//printf("%d %d\n", tmp_prio, temp);
		while(temp!=NULL)
		{
			if(temp->q_priority == tmp_prio)
			{
				status = 0x1;
				break;
			}
			else
			{
				temp = temp->q_next_ptr;
			}
		}
		
		if(status)
		{
			if(temp->q_prev_ptr == NULL)
			{
				//printf("%d %d\n", temp->q_data,temp->q_next_ptr);
				*queue = temp->q_next_ptr;
				if(*queue != NULL)
					(*queue)->q_prev_ptr = temp->q_prev_ptr;
				//printf("%d %d\n", *queue,(*queue)->q_next_ptr);
			}
			else
			{
				//printf("%d %d\n", temp->q_prev_ptr->q_data,temp->q_prev_ptr->q_next_ptr);
				temp->q_prev_ptr->q_next_ptr = temp->q_next_ptr;
				if(temp->q_next_ptr != NULL)
				{
					temp->q_next_ptr->q_prev_ptr = temp->q_prev_ptr;
				}
				//printf("%d %d\n", temp->q_prev_ptr->q_data,temp->q_prev_ptr->q_next_ptr);
			}
			q_len--;
			return temp->q_data;
		}
		//temp = *queue;
		tmp_prio++;
		
		
	};
	
	if(status == 0)
	{
		return 0;
	}
	
}

void proc_print_queue(struct queue * queue)
{
	struct queue *temp;
	temp = queue;
	printf("\n\tData\tqueue Address\t+1 queue Address -1 queue Address\n");
	while(temp !=NULL)
	{
		printf("%10d\t%10d\t%10d\t%10d\n", temp->q_data,&temp->q_data,temp->q_next_ptr, temp->q_prev_ptr);
		temp = temp->q_next_ptr;
	}
}

void proc_queue(void)
{
	struct queue *queue;
	
	queue_push(&queue, 10, 01); 
	//proc_print_queue(queue);
	queue_push(&queue, 40, 02);
	//proc_print_queue(queue);
	queue_push(&queue, 60, 00);
	//proc_print_queue(queue);
	queue_push(&queue, 20, 04);
	//proc_print_queue(queue);
	queue_push(&queue, 70, 03);
	
	proc_print_queue(queue);
	printf("Pop the contents based on the priority\n");
	printf("Data popped %d\n", queue_pop(&queue));
	proc_print_queue(queue);
	printf("Data popped %d\n", queue_pop(&queue));
	proc_print_queue(queue);
	printf("Data popped %d\n", queue_pop(&queue));
	queue_push(&queue, 10, 01);
	proc_print_queue(queue);
	printf("Data popped %d\n", queue_pop(&queue));
	queue_push(&queue, 60, 00);
	proc_print_queue(queue);
	printf("Data popped %d\n", queue_pop(&queue));
}