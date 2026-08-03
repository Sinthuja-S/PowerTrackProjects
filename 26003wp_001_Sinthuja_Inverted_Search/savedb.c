#include "header.h"

int save_database(HashTable *arr)
{
    char fname[50];
    FILE *fp;

    printf("\nEnter the file name to save : ");
    scanf("%s", fname);

    /* Validate extension */
    char *ext = strrchr(fname, '.');

    if(ext == NULL || strcmp(ext, ".txt") != 0)
    {
        printf("Invalid file extension!\n");
        return FAILURE;
    }

    /* Check if file already exists */
    fp = fopen(fname, "r");

    if(fp != NULL)
    {
        fclose(fp);

        int choice;

        printf("\nFile already exists.\n");
        printf("1. Overwrite\n");
        printf("2. Enter New File Name\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        if(choice == 2)
        {
            printf("Enter new file name : ");
            scanf("%s", fname);
        }
    }

    /* Open in write mode */
    fp = fopen(fname, "w");

    if(fp == NULL)
    {
        printf("Unable to create file\n");
        return FAILURE;
    }

    /* Write Database */

    for(int i = 0; i < 27; i++)
    {
        if(arr[i].link == NULL)
            continue;

        MainNode *mtemp = arr[i].link;

        while(mtemp)
        {
            fprintf(fp, "#%d;%s;%d;",
                    i,
                    mtemp->word,
                    mtemp->file_count);

            SubNode *stemp = mtemp->sub_link;

            while(stemp)
            {
                fprintf(fp, "%s;%d;",
                        stemp->file_name,
                        stemp->word_count);

                stemp = stemp->sub_link;
            }

            fprintf(fp, "#\n");

            mtemp = mtemp->main_link;
        }
    }

    fclose(fp);

    printf("\nDatabase Saved Successfully...\n");

    return SUCCESS;
}