#include "Header.h"

/* Check Duplicate File */

int duplicate_file(Slist *head, char *fname)
{
    while(head != NULL)
    {
        if(strcmp(head->fname, fname) == 0)
            return SUCCESS;

        head = head->link;
    }

    return FAILURE;
}

/* Insert File Name at Last */

int insert_at_last(Slist **head, char *fname)
{
    Slist *new = malloc(sizeof(Slist));

    if(new == NULL)
        return FAILURE;

    strcpy(new->fname, fname);
    new->link = NULL;

    if(*head == NULL)
    {
        *head = new;
        return SUCCESS;
    }

    Slist *temp = *head;

    while(temp->link != NULL)
    {
        temp = temp->link;
    }

    temp->link = new;

    return SUCCESS;
}

/* Validate Files and Create SLL */

int file_validation_n_file_list(Slist **head, char *argv[])
{
    FILE *fp;
    int i = 1;

    while(argv[i] != NULL)
    {
        /* Check Extension */

        char *ext = strrchr(argv[i], '.');

        if(ext == NULL || strcmp(ext, ".txt") != 0)
        {
            printf("%s --> Invalid File Extension\n", argv[i]);
            i++;
            continue;
        }

        /* Check File Exists */

        fp = fopen(argv[i], "r");

        if(fp == NULL)
        {
            printf("%s --> File Not Found\n", argv[i]);
            i++;
            continue;
        }

        /* Check Empty File */

        fseek(fp, 0, SEEK_END);

        if(ftell(fp) == 0)
        {
            printf("%s --> Empty File\n", argv[i]);
            fclose(fp);
            i++;
            continue;
        }

        rewind(fp);
        fclose(fp);

        /* Check Duplicate */

        if(duplicate_file(*head, argv[i]) == SUCCESS)
        {
            printf("%s --> Duplicate File\n", argv[i]);
            i++;
            continue;
        }

        /* Insert into SLL */

        insert_at_last(head, argv[i]);

        printf("%s --> Successfully Added\n", argv[i]);

        i++;
    }

    return SUCCESS;
}