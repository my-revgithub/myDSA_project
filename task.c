#include "task.h"


emp_info_DB company_A[100];
list list_A; 
list *list_ptr;
list *list_var;
static uint8 list_length;


static void add_queue(queue_type *queue_list, uint8 * data);
static void remove_queue(queue_type *queue_list, uint8 * data);
static void init_queue(queue_type *queue_list);
static void proc_add_list(list *list, uint8 data);

void func_data_entry_ini()
{
	unsigned char i = 0;
	for(i=0;i<100;i++)
	{
		company_A[i].emp_id = 0xFFFF;
		//company_B[i].emp_id = 0xFFFF;
	}
		
}

void func_data_entry(void)
{
    unsigned char i = 0, j;
	volatile unsigned int exit = 0;
	printf("Enter the details\n");
	
	while(exit!=1)
	{
		if(printf("\nEmployee ID: "));
			scanf("%d",&company_A[i].emp_id);
		if(printf("\nEmployee Name:"));
			scanf("%s",company_A[i].name);
		i++;
		
		printf("\nPlease press 1 to stop the data entry : ");
		scanf("%d",&exit);
	}
	
	printf("i = %d", i);
	//Print the database
	for(j=0;j<i;j++)
	{
		printf("\nEmployeed ID: %d, Employee Name: %s\n", company_A[j].emp_id, company_A[j].name);
	}
}


void func_sort(void)
{
	uint8 i=0, length =0, flag = 0, tmp;
	uint8 *start_ptr;
	uint8 *end_ptr;
	uint8 *begin_ptr;
	uint8 data_list[50] = {11,4,22,64,27,28,32,98,9,87,34,67,100,1,67,32};
	
	//length of an array
	while(data_list[length] != '\0'){length++;};
	
	begin_ptr = (uint8 *)&data_list;
	end_ptr = &data_list[length-1];
	start_ptr = begin_ptr;
	
	printf("Start = %d, End = %d\n", *start_ptr, *end_ptr);
	
	do
	{
		flag = 0;
		while(start_ptr != end_ptr)
		{
			if(*start_ptr > *(start_ptr+1))
			{
				//swap the pointers
				tmp = *(start_ptr+1);
				*(start_ptr+1) = *start_ptr;
				*start_ptr = tmp;
				flag = 1;
			}
			start_ptr++;
		}
		if(flag)
		{
			start_ptr = begin_ptr;		
		}
	}while(flag);
	
	for(i=0;i<length;i++)
	{
		printf("%d ", data_list[i]);
	}
			
}
	
void func_linked_lists(void)
{
	uint8 i,length;
	//Circular linked list
	uint8 data_list[50] = {11,4,22,64,27,28,32,98,9,87,34,67,100,1,67,32};
	
	//length of an array
	while(data_list[length] != '\0'){length++;};
	
	length--;
	
	list_ptr = (list *)malloc(length*sizeof(list));
	printf("%d\n", sizeof(list_ptr));
	//list_ptr = (list *)list_A;
	
	while(data_list[i] != '\0')
	{
		list_ptr[i].data = data_list[i];

		if(i==0)
		{
			list_ptr[i].prev_ptr = &data_list[length-i];
			list_ptr[i].next_ptr = &data_list[i+1];
		}
		else if(i == length)
		{
			list_ptr[i].prev_ptr = &data_list[i-1];
			list_ptr[i].next_ptr = &data_list[i-length];
		}
		else
		{
			list_ptr[i].prev_ptr = &data_list[i-1];
			list_ptr[i].next_ptr = &data_list[i+1];
		}
			
		i++;
	}

	//prepare the linked list
	for(i=0;i<=length;i++)
	{
		printf("%d ", list_ptr[i].data);
		printf("%d ", *list_ptr[i].next_ptr);
		printf("%d\n ", *list_ptr[i].prev_ptr);
	}
	
	free(list_ptr);
	
}	

void proc_linked_list(void)
{
	volatile uint8 i;
	uint8 data,return_code;
	uint8 j,list_size;
	printf("Dynamic linked list\n");
	
	printf("Enter the size of the list: ");
	scanf("%d", &list_size);
	printf("%d\n", list_size);
	list_var = (list *)malloc(list_size);
	list_length = 0;
	i = 0;
	while(1)
	{
		//if(i > list_size)
		//{ break;}
		
		printf("Enter the input, press Cntrl+Z to stop\n");
		return_code = scanf("%d",&data);
	
		if(return_code == 0xFF)
		{ break;}
	
		proc_add_list(list_var, data);
		printf("%d\n", i);
		i = i+1;
	}

	printf("Display result\n");
	for(j=0;j<list_size;j++)
	{
		printf("%d\t",list_var[j].data);
		printf("%d\t",&list_var[j].data);
		printf("%d\t",list_var[j].prev_ptr);
		printf("%d\n",list_var[j].next_ptr);
	}
	
	free(list_var);
}

void proc_add_list(list *list, uint8 data)
{
	list[list_length].data = data;
	if(list_length < 1)
	{
		list[list_length].prev_ptr = NULL;
		list[list_length].next_ptr = NULL;
	}
	else
	{		
		list[list_length].prev_ptr = &list[list_length-1].data;
		list[list_length-1].next_ptr = &list[list_length].data;
	}
	list_length++;
	printf("%d\t%d\n",list_length,list[list_length-1].data);
}

void func_in_entries(void)
{
	uint8 i = 0, entry_cnt = 0;
	uint8 book[100][100];
	printf("Enter the books. Press Cntrl+Z to finish\n");

	input_entries(&book[0][0], &entry_cnt);
	
	printf("Number of books = %d", entry_cnt);
		
	while(entry_cnt!=0)
	{
		printf("\n%s", book[i++]);
		entry_cnt--;
	}
	
}

void input_entries(uint8 *array_ptr, uint8 *cnt)
{
	uint8 i=0,j=0,x=0;
	while(x != 0xFF)
	{
		x = scanf("%s",&array_ptr[i++]);
	}
	*cnt = i-1;
}


void func_queue(void)
{
	uint8 q_data,input = 0, data, count = 0;
	queue_type queue_list;
	printf("Make the queue entries\n");
	
	queue_list.start_pos = queue_list.data;
	queue_list.queue_pos = 0;
	
	while(input != 0xFF)
	{
		printf("Press 1 to add and 0 to remove, any other key to exit\n");
		input = scanf("%d", &q_data);
		
		if(q_data == 0)
		{
				data = 0xFF;
				remove_queue(&queue_list,&data);
				printf("Datat removed: %d\n", data);
		}
		else if(q_data==1)
		{
				printf("Enter the data\n");
				input = scanf("%d", &data);
				add_queue(&queue_list,&data);
		}
		else
		{
			input = 0xFF;/*do nothing*/}
	
	}
	
	//printf("
	
}

void add_queue(queue_type *queue_list, uint8 * data)
{
	uint8 size_data;
	size_data = sizeof(queue_list->data);

	queue_list->data[queue_list->queue_pos] = *data;
	queue_list->queue_pos++;
}

void remove_queue(queue_type *queue_list, uint8 * data)
{
	if(queue_list->queue_pos !=0)
	{
		*data = *queue_list->start_pos;
		queue_list->start_pos = queue_list->start_pos + 1;
		
		if(queue_list->queue_pos == 0)
		{
			init_queue(queue_list);
		}
		queue_list->queue_pos--;
	}
	
}

void init_queue(queue_type *queue_list)
{
	queue_list->start_pos = &queue_list->data[0];
	queue_list->queue_pos = 0;
}


//End of file