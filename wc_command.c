#include"wc_command.h"
#include<stdio.h>
#include<stdlib.h>
//initilizing linked list
void init(list *head) {
    *head = NULL;
    return;
}
void init_(list1 *head) {
    *head = NULL;
    return;
}
//inserting char upto EOF
void insert_char_in_list(list *head, char ch) {
    node* nn = (node*) malloc(sizeof(node));
    if(nn) {
        nn->chr = ch;
        nn->next = NULL;
    }
    else
        return;
    if(*head == NULL)
        *head = nn;
    else {
        node* p = *head;
        while(p->next)
            p = p->next;
        p->next = nn;
    }
    return;
}
//insert in LL
void insert_int_in_list(list1 *head, int data) {
    node1* nn = (node1*) malloc(sizeof(node1));
    if(nn) {
        nn->data = data;
        nn->next = NULL;
    }
    else
        return;
    if(*head == NULL) {
        *head = nn;
        return;
    }
    else {
        node1* p;
        p = *head;
        while(p->next) {
            p = p->next;
        }
        p->next = nn;
    return;
    }
}
//displaying file  content
void display_file_content(list head) {
    if(head == NULL)
        printf("file is empty,nothing to show!\n");
    else {
        node* p = head;
        while(p) {
            printf("%c",  p->chr);
            p = p->next;
        }
    }
    printf("\n");
    return;
}

//counting number of lines in file
int count_lines_in_file(list head) {
    int line = 0;
    if(head == NULL)
        return line;
    else {
        node* p = head;
        while(p) {
            if(p->chr == '\n' || p->chr == '\0')
                line++;
        p = p->next;
        }
    }
    return line;
}
//counting char in file
int count_char(list head) {
    if(head == NULL)
        printf("Empty file\nNumber of char = 0");
    else {
        int charws1 = 0 , charws2 = 0;
        node* p = head;
        while(p) {
            charws1++;
            if(p->chr == '\0' || p->chr == '\n') {
                charws1++;
                charws2++;
            }
            if(p->chr != ' ')
                charws2++;
        p = p->next;
        }
        printf("Number of char without space = %d\n", charws2);
        return charws1;
    }
    return;
}
//destroys LL
void destroy_LL(list *head) {
    node * curr = *head;
    node* next = NULL;
    if(*head == NULL) {
        free(*head);
        return;
    }
    else {
        while(curr != NULL) {
            next = curr->next;
            free(curr);
            curr = next;
        }
        free(*head);
        free(next);
    }
    return;
}
//get longest length
int longest_len(list head, list1 *head1) {
    if(head == NULL)
        return 0;
    else {
        int min = 0, max = 0;
        node* p = head;
        while(p) {
                min++;
            if(p->chr == '\0' || p->chr == '\n' || p->next == NULL) {
                if(p->next != NULL)
                    insert_int_in_list(head1, --min);
                else
                    insert_int_in_list(head1, min);
                min = 0;
            }
            p = p->next;
        }

        max = get_max(*head1);
        return max;
    }
    return 0;
}
//counting different symbols/char
void count_difftype_char(list head) {
    if(head == NULL)
        printf("Empty\n");
    else {
        node* p = head;
        int alpha = 0, digi = 0, special = 0;
        while(p) {
            if(p->chr >= 'a' && p->chr <= 'z' || p->chr >= 'A' && p->chr <= 'Z')
                alpha++;
            else if(p->chr >= '0' && p->chr <= '9')
                digi++;
            else
                special++;
            p = p->next;
        }
        printf("Number of alphabets = %d\n", alpha);
        printf("Number of digits = %d\n", digi);
        printf("Number of special char = %d\n", special);

    }
    return;
}
//count words
int count_word(list head) {
    int wdd = 0, wd = 0;
    node* p = head;
    if(head == NULL)
        return 0;
    else {
        if(p->chr ==' ') {
            while(p) {
                if(p->chr == ' ')
                    p = p->next;
                else
                    break;
            }
        }
        while(p) {
            if(p->chr == ' ' && (p->next->chr != '\n' && p->next->chr != ' '))
                wdd++;
            else if(p->chr == '\n' && (p->next != NULL && p->next->chr != '\n' && p->next->chr != ' '))
                wdd++;
            else if(p->chr == ' ' && p->next->next == NULL)
                break;
            p = p->next;
        }
        printf("Number of char with space = %d\n", ++wdd);
        return wdd;
    }
    return 0;
}
//count no. of nodes in list
int countt(list head) {
    int cou = 0;
    if(head == NULL)
        return 0;
    else {
        node* p = head;
        while(p) {
            cou++;
            p = p->next;
        }
        return cou;
    }
    return 0;
}
//return max from int list
int get_max(list1 head) {
    if(head == NULL)
        return 0;
    else{
        if(head->next == NULL)
            return head->data;
        else {
            int max = head->data;
            node1* p = head;
            while(p) {
                if(max < p->data)
                    max = p->data;
            p = p->next;
            }
            return max;
        }
    }
    return 0;
}
//counting char for total
int count_charr(list head) {
    if(head == NULL)
        return 0;
    else {
        int charws1 = 0;
        node* p = head;
        while(p) {
            charws1++;
            if(p->chr == '\0' || p->chr == '\n')
                charws1++;
        p = p->next;
        }
        return charws1;
    }
    return;
}
