#include "Header.h"

int search_database(HashTable *arr)
{
    char word[50];

    printf("\nEnter the word to search : ");
    scanf("%49s", word);

    /* Convert search word to lowercase */
    for(int i = 0; word[i] != '\0'; i++)
    {
        word[i] = tolower(word[i]);
    }

    int index = get_index(word);

    /* Check whether hash index is empty */
    if(arr[index].link == NULL)
    {
        printf("\nWord \"%s\" not found in database.\n", word);
        return FAILURE;
    }

    MainNode *mtemp = arr[index].link;

    /* Search Main Node */
    while(mtemp != NULL)
    {
        if(strcmp(mtemp->word, word) == 0)
        {
            printf("\n=====================================================\n");
            printf("Word Found Successfully\n");
            printf("=====================================================\n");
            printf("Word       : %s\n", mtemp->word);
            printf("File Count : %d\n", mtemp->file_count);

            printf("\n-----------------------------------------\n");
            printf("%-20s %-10s\n", "File Name", "Word Count");
            printf("-----------------------------------------\n");

            SubNode *stemp = mtemp->sub_link;

            while(stemp != NULL)
            {
                printf("%-20s %-10d\n",
                       stemp->file_name,
                       stemp->word_count);

                stemp = stemp->sub_link;
            }

            printf("-----------------------------------------\n");

            return SUCCESS;
        }

        mtemp = mtemp->main_link;
    }

    printf("\nWord \"%s\" not found in database.\n", word);

    return FAILURE;
}