#ifndef WC_COMMAND_H_INCLUDED
#define WC_COMMAND_H_INCLUDED

typedef struct node{
    char chr;
    struct node *next;
}node;
typedef struct node1{
    int data;
    struct node *next;
}node1;
typedef node* list;
typedef node1* list1;
void init(list *head);
void init_(list1 *head);
void insert_char_in_list(list *head, char ch);
void insert_int_in_list(list1 *head, int data);
void display_file_content(list head);
int count_lines_in_file(list head);
int count_char(list head);
void destroy_LL(list *head);
int count_word(list head);
int longest_len(list head, list1 *head1);
void count_difftype_char(list head);
int countt(list head);
#endif // WC_COMMAND_H_INCLUDED
