#include "Header.h"

int display_database(HashTable *arr)
{
    int i;

    printf("\n");
    printf("===========================================================================================================\n");
    printf("%-8s %-20s %-12s %-20s %-10s\n",
           "Index",
           "Word",
           "File Count",
           "File Name",
           "Word Count");
    printf("===========================================================================================================\n");

    for(i = 0; i < 27; i++)
    {
        if(arr[i].link == NULL)
            continue;

        MainNode *mtemp = arr[i].link;

        while(mtemp != NULL)
        {
            SubNode *stemp = mtemp->sub_link;
            int first = 1;

            while(stemp != NULL)
            {
                if(first)
                {
                    printf("%-8d %-20s %-12d %-20s %-10d\n",
                           i,
                           mtemp->word,
                           mtemp->file_count,
                           stemp->file_name,
                           stemp->word_count);

                    first = 0;
                }
                else
                {
                    printf("%-8s %-20s %-12s %-20s %-10d\n",
                           "",
                           "",
                           "",
                           stemp->file_name,
                           stemp->word_count);
                }

                stemp = stemp->sub_link;
            }

            mtemp = mtemp->main_link;
        }
    }

    printf("===========================================================================================================\n");

    return SUCCESS;
}