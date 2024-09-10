#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include "queue.h"

void queue_push(struct queue *queue, uint8 data, uint8 priority)
{
	struct queue *q;
	q = (struct queue *) malloc(sizeof(struct queue));
	
	q->priority = priority;
	q->data = data;
	
	if(queue == NULL)
	{
		queue = q;
	}
	else
	{
		while(queue->q_next_ptr != NULL)
		{
			*queue = *queue->next;
		}
		*queue->q_next_ptr = q;
	}
}

uint8 queue_pop(struct queue *queue)
{
	
}

void proc_queue(void)
{
	struct queue queue = NULL;
	
	queue_push(&queue, 10, 01); 
	queue_push(&queue, 40, 02);
	queue_push(&queue, 60, 00);
	queue_push(&queue, 20, 04);
	queue_push(&queue, 70, 03);
	
	printf("Pop the contents based on the priority\n");
	printf("%d\n", queue_pop(&queue));
	printf("%d\n", queue_pop(&queue));
	printf("%d\n", queue_pop(&queue));
	printf("%d\n", queue_pop(&queue));
	printf("%d\n", queue_pop(&queue));
}