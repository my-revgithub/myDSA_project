#ifndef _TYPES_DEF
#define _TYPES_DEF

#include <stdio.h>

typedef unsigned int uint32;
typedef short uint16;
typedef unsigned char uint8;
typedef char int8;
typedef int int32;
typedef unsigned long long uint64 ;

typedef struct
{
	uint16 emp_id;
	int8 name[100];
}emp_info_DB;

typedef struct
{
	uint8 *prev_ptr;
	uint8 *next_ptr;
	uint8 data;
}list;

typedef struct
{
	uint8 data[100];
	uint8 *start_pos;
	uint8 queue_pos;
}queue_type;

struct node
{
	int data;
	struct node *next_ptr;
	struct node *prev_ptr;
};

struct queue
{
	uint8 q_priority;
	uint8 q_data;
	struct queue *q_next_ptr;
};


#endif
