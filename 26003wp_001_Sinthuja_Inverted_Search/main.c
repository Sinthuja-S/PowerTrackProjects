#include "Header.h"

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("Usage: ./a.out file1.txt file2.txt ...\n");
        return FAILURE;
    }

    Slist *head = NULL;

    /* Validate files and create SLL */
    file_validation_n_file_list(&head, argv);

    if(head == NULL)
    {
        printf("\nNo valid files found.\n");
        return FAILURE;
    }

    printf("\nValid File List:\n");

    Slist *temp = head;
    while(temp)
    {
        printf("%s\n", temp->fname);
        temp = temp->link;
    }

    /* Initialize Hash Table */
    HashTable arr[27];

    for(int i = 0; i < 27; i++)
    {
        arr[i].index = i;
        arr[i].link = NULL;
    }

    printf("\nHash Table Initialized Successfully\n");

    int choice;

    while(1)
    {
        printf("\n");
        printf("------------ MENU ------------\n");
        printf("1. Create Database\n");
        printf("2. Display Database\n");
        printf("3. Search Database\n");
        printf("4. Update Database\n");
        printf("5. Save Database\n");
        printf("6. Exit\n");
        printf("------------------------------\n");

        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                create_database(head, arr);
                break;

            case 2:
                display_database(arr);
                break;

            case 3:
                search_database(arr);
                break;

            case 4:
                 update_database(&head, arr);
                break;

            case 5:
               save_database(arr);
                break;

            case 6:
                printf("\nThank You...\n");
                return SUCCESS;

            default:
                printf("\nInvalid Choice\n");
        }
    }

    return SUCCESS;
}