#ifndef HEADER_H
#define HEADER_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define SUCCESS 0
#define FAILURE -1

/*---------------- File Linked List ----------------*/

typedef struct file_node
{
    char fname[50];
    struct file_node *link;

}Slist;


/*---------------- Sub Node ----------------*/

typedef struct sub_node
{
    char file_name[50];
    int word_count;
    struct sub_node *sub_link;

}SubNode;


/*---------------- Main Node ----------------*/

typedef struct main_node
{
    char word[50];
    int file_count;

    SubNode *sub_link;
    struct main_node *main_link;

}MainNode;


/*---------------- Hash Table ----------------*/

typedef struct hash
{
    int index;
    MainNode *link;

}HashTable;


/*---------------- Function Prototypes ----------------*/

int file_validation_n_file_list(Slist **head, char *argv[]);
int insert_at_last(Slist **head, char *fname);
int duplicate_file(Slist *head, char *fname);

int create_database(Slist *head, HashTable *arr);
int display_database(HashTable *arr);
int search_database(HashTable *arr);

int get_index(char *word);

#endif