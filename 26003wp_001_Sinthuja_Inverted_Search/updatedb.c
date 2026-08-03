#include "header.h"

int update_database(Slist **head, HashTable *arr)
{
    char fname[50];
    FILE *fp;

    printf("\nEnter the file name to update database : ");
    scanf("%s", fname);

    /* Validate extension */
    char *ext = strrchr(fname, '.');

    if(ext == NULL || strcmp(ext, ".txt") != 0)
    {
        printf("Invalid file extension\n");
        return FAILURE;
    }

    /* Check file exists */
    fp = fopen(fname, "r");

    if(fp == NULL)
    {
        printf("File not found\n");
        return FAILURE;
    }

    /* Check empty file */
    fseek(fp, 0, SEEK_END);

    if(ftell(fp) == 0)
    {
        printf("Empty file\n");
        fclose(fp);
        return FAILURE;
    }

    fclose(fp);

    /* Check duplicate */
    if(duplicate_file(*head, fname) == SUCCESS)
    {
        printf("File already exists in database\n");
        return FAILURE;
    }

    /* Insert into linked list */
    insert_at_last(head, fname);

    /* Get last node */
    Slist *temp = *head;

    while(temp->link != NULL)
    {
        temp = temp->link;
    }

    /* Create database only for newly added file */
    create_database(temp, arr);

    printf("\nDatabase Updated Successfully...\n");

    return SUCCESS;
}