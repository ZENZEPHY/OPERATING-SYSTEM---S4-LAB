#include<stdio.h>
#include<stdlib.h>

// creting a structure for the node
struct node{
    int id;
    int burstTime;
    int waitTime;
    int turnAroundTime;
    struct node *next;
}*head, *current,*new;

// function to add a process to the linked list
void addProcess(int i,int bt)
{
    new = (struct node *)malloc(sizeof(struct node));
    new->id = i;
    new->burstTime = bt;
    current->next = new;
    current=new;
    new->next = NULL;
    printf("New Process added:\nProcessId:%d\nBurstTime:%d\n",new->id,new->burstTime);
}

void calculateWaitTime(){
    //| head | -(next)-> | new |
    (head->next)->waitTime = 0;
    (head->next)->turnAroundTime = (head->next)->burstTime;
    current = head->next;

    while((current->next)!=NULL){
        (current->next)->waitTime = (current->waitTime) + (current->burstTime);
        (current->next)->turnAroundTime = (current->next)->waitTime + (current->next)->burstTime;
        current = current->next;
    }
}

void gantt()
{
    int i=0;
    current = head->next;
    printf("PID\tBURST TIME\tARRIVAL TIME\tCOMPLETION TIME\t TURN AROUND TIME\tWAITING TIME\n");
    while(current->next!=NULL)
    {
        printf(" \n%d \t %d \t\t %d \t\t %d \t\t\t %d \t\t %d",current->id,current->burstTime,i,current->burstTime+i,current->turnAroundTime,current->waitTime);
        i=i+(current->burstTime);
        current = current->next;
    }
}

void average()
{
    int i=0,avgWaitTime=0,avgTurnAroundTime=0;

    current = head->next;
    
    while(current->next!=NULL)
    {
        avgWaitTime = avgWaitTime + current->waitTime;
      
        avgTurnAroundTime = avgTurnAroundTime + current->turnAroundTime;
      
        current = current->next;
      
        i++;
    }
    printf("Average Waiting Time:%d\nAverage Turn Around Time:%d\n",avgWaitTime/i,avgTurnAroundTime/i);

}


void main(){

    int i=0, no_of_process, bt;
    head = (struct node *)malloc(sizeof(struct node));
    current = head;
    printf("Enter the number of processes\n");
    scanf("%d",&no_of_process);

    for(i=0;i<no_of_process;i++){
        printf("Enter the burst time for process %d\n",i+1);
        scanf("%d",&bt);
        addProcess(i,bt);
    }
    calculateWaitTime();
    gantt();
}