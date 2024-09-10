#ifndef _TASK_H
#define _TASK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "typedef.h"

extern void func_data_entry(void);
extern void func_sort(void);
extern void func_linked_lists(void);
extern void func_in_entries(void);
extern void input_entries(uint8 *array_ptr, uint8 *cnt);
extern void func_queue(void);
extern void proc_linked_list(void);
extern void thread_proc(void);
extern void proc_linked(void);
extern void proc_queue(void);
extern void proc_print_list(struct node * node);
#endif