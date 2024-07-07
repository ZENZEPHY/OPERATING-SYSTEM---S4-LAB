#include <stdlib.h>
#include <stdio.h>

struct node
{
    int id;
    int burst;
    int tat;
    int wait;
    struct node *next;
} *head, *current, *new;



// ! Adding the process 

void addprocess(int i, int bt)
{
 new = (struct node *)malloc(sizeof(struct node));
 new->id = i;
 new->burst = bt;
 new->next=NULL;
 current->next=new;
 current = new;
  printf("\nNew Process added: \nProcessId : %d\nburst : %d\n\n",new->id,new->burst);
}

// ! Sort Fnction for Sorting the burst time

void sort()
{
    struct node *first,*second;
    int temp;

    for(first=head->next;first->next!=NULL;first=first->next)
    {
        for(second=(first->next);second!=NULL;second=second->next)
        {
            if(first->burst>second->burst)
            {
                //!swap
                temp = first->burst;
                first->burst  = second->burst;
                second->burst = temp; 

                temp = first->id;
                first->id  = second->id;
                second->id = temp; 
            }
        }
    }

}

void gantt()
{
    int i=0;
    current = head->next;
    printf("PID\tBURST TIME\tStarting TIME\tCOMPLETION TIME\t TURN AROUND TIME\tWAITING TIME\n");
    while(current!=NULL)
    {
        printf(" \n%d \t %d \t\t %d \t\t %d \t\t\t %d \t\t %d",current->id,current->burst,i,current->burst+i,current->tat,current->wait);
        i=i+(current->burst);
        current = current->next;
    }
}

void calculateWaitTime()
{
    current = head->next;
    current->tat = current ->burst;
    current->wait = 0;

    while(current->next!=NULL){
        (current->next)->wait = current->burst+current->wait;
        (current->next)->tat = (current->next)->burst+(current->next)->wait;
        current = current ->next;
    }
}

void main()
{
    int i=1, bt, p;
    head =(struct node *)malloc(sizeof(struct node)); 
    current = head;
    printf("Enter the total no.of processess\n");
    scanf("%d", &p);

    while(p!=0){
       printf("Enter the burst time of process %d : ",i);
       scanf("%d",&bt);
       addprocess(i,bt);
       p--;
       i++; 
    }
    sort();
    calculateWaitTime();
    gantt();
}