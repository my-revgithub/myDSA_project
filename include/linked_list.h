#ifndef _LINKED_LIST_
#define _LINKED_LIST_

extern struct node * proc_insert_node(uint8 data);
extern void proc_insert_node_pos(struct node **node, uint8 data, uint8 pos);
extern struct node * proc_reverse_list(struct node *node);
extern void proc_search_list_method2(struct node *node, uint8 data);
extern void proc_search_list_method1(struct node *node, uint8 data);
extern void proc_search_list_method1(struct node *node, uint8 data);
extern struct node * proc_insert_node2(struct node **node, uint8 data);
#endif