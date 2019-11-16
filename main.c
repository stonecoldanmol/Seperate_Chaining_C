#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10
struct node
{
               int data;
               struct node *next;
};
struct node *head[TABLE_SIZE]={NULL},*c;
/*Insertion*/
void insert()
{
    int i,key;
    printf("\nEnter a value to insert into hash table:");
    scanf("%d",&key);
    i=key%TABLE_SIZE;
    struct node * newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=key;
    newnode->next = NULL;
    if(head[i] == NULL)
        head[i] = newnode;
    else
    {
        c=head[i];
        while(c->next != NULL)
        {
           c=c->next;
        }
        c->next=newnode;
    }
}

/*Searching*/
void search()
{
    int key,index;
    printf("\nEnter the element to be searched:");
    scanf("%d",&key);
    index=key%TABLE_SIZE;
    if(head[index] == NULL)
        printf("\n Search element not found\n");
    else
    {
        for(c=head[index];c!=NULL;c=c->next)
        {
            if(c->data == key)
                {
                    printf("Search element found\n");
                    break;
                }
        }
        if(c==NULL)
            printf("\n Search element not found\n");

    }
}
/*Display*/

void display()
{
    int i;
    for(i=0;i<TABLE_SIZE;i++)
          {
           printf("\nEntries at index %d\n",i);
               if(head[i] == NULL)
               {
               printf("No Hash Entry");
               return;
               }
               else
               {
                              for(c=head[i];c!=NULL;c=c->next)
                              printf("%d->",c->data);
               }
          }

}

int main()
{
    int choice;
    while(1)
    {
        printf("\n\tMENU DRIVEN\n");
        printf("\n1.Insertion");
        printf("\n2.Display");
        printf("\n3.Searching");
        printf("\n4.Exit");
        printf("\n\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:exit(0);
            default:
                printf("Invalid Choice!");

        }
    }
    return 0;
}
