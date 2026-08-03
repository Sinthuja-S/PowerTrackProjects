#include "Header.h"

int get_index(char *word)
{
    if(isalpha(word[0]))
        return tolower(word[0]) - 'a';
    else
        return 26;
}

int create_database(Slist *head, HashTable *arr)
{
    char word[50];

    while(head != NULL)
    {
        FILE *fp = fopen(head->fname, "r");

        if(fp == NULL)
        {
            head = head->link;
            continue;
        }

        while(fscanf(fp, "%49s", word) != EOF)
        {
            /* Convert to lowercase */
            for(int i = 0; word[i]; i++)
            {
                word[i] = tolower(word[i]);
            }

            int index = get_index(word);

            MainNode *mtemp = arr[index].link;
            MainNode *prev_main = NULL;

            /* Search Word in Main Node */
            while(mtemp != NULL)
            {
                if(strcmp(mtemp->word, word) == 0)
                    break;

                prev_main = mtemp;
                mtemp = mtemp->main_link;
            }

            /* Word Not Found */
            if(mtemp == NULL)
            {
                MainNode *new_main = malloc(sizeof(MainNode));
                SubNode *new_sub = malloc(sizeof(SubNode));

                if(new_main == NULL || new_sub == NULL)
                    return FAILURE;

                strcpy(new_main->word, word);
                new_main->file_count = 1;
                new_main->main_link = NULL;

                strcpy(new_sub->file_name, head->fname);
                new_sub->word_count = 1;
                new_sub->sub_link = NULL;

                new_main->sub_link = new_sub;

                if(arr[index].link == NULL)
                {
                    arr[index].link = new_main;
                }
                else
                {
                    prev_main->main_link = new_main;
                }
            }
            else
            {
                /* Word Already Exists */

                SubNode *stemp = mtemp->sub_link;
                SubNode *prev_sub = NULL;

                while(stemp != NULL)
                {
                    if(strcmp(stemp->file_name, head->fname) == 0)
                        break;

                    prev_sub = stemp;
                    stemp = stemp->sub_link;
                }

                /* Same File */
                if(stemp != NULL)
                {
                    stemp->word_count++;
                }
                else
                {
                    /* New File */

                    SubNode *new_sub = malloc(sizeof(SubNode));

                    if(new_sub == NULL)
                        return FAILURE;

                    strcpy(new_sub->file_name, head->fname);
                    new_sub->word_count = 1;
                    new_sub->sub_link = NULL;

                    if(prev_sub == NULL)
                        mtemp->sub_link = new_sub;
                    else
                        prev_sub->sub_link = new_sub;

                    mtemp->file_count++;
                }
            }
        }

        fclose(fp);
        head = head->link;
    }

    printf("\nDatabase Created Successfully...\n");

    return SUCCESS;
}