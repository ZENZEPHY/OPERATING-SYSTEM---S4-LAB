#include<stdio.h>
#include<stdlib.h>

int q[20];
int front=-1,rear=-1;

struct pros{
    int id;
    int burst;
    int tat;
    int wait;
    int remTime;
}a[10];

void insert(int i)
{
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        q[rear] = i;
    }
    else
    {
        rear = rear + 1;
        q[rear] = i;
    }
}

int delete()
{
    int i;
    i=q[front];
    front++;
    return i;
}
void main()
{
    int no,i,j,qt,p,t=0;
    float avgwt=0,avgtat=0;

    printf("Enter the no of Processess: ");
    scanf("%d",&no);
    for(i=1;i<=no;i++)
    {
        printf("Enter the burst time of Process: %d ",i);
        scanf("%d",&a[i].burst);
        a[i].id=i;
        a[i].remTime=a[i].burst;
        a[i].tat=0;
        insert(i);
    }

    printf("Enter time quantum : ");
    scanf("%d",&qt);
    printf("GANTT CHART\n");

    while(front<=rear)
    {
        j = delete();
        printf("%d\t",j);
        
        if(a[j].remTime<=qt)
        {
            a[j].tat = t + a[j].remTime;
            t = t + a[j].remTime;
            a[j].remTime = 0;
        }
        else
        {
            a[j].remTime = a[j].remTime-qt;
            t = t + qt;
        }

        if(a[j].remTime > 0)
        {
            insert(j);
        }
    }

    printf("\nPROCESS\tBURST TIME\tTAT\tWAITING TIME\n");
    for(i=1;i<=no;i++)
    {
        a[i].wait = a[i].tat - a[i].burst;
        printf("%d\t%d\t\t%d\t%d \n",a[i].id,a[i].burst,a[i].tat,a[i].wait);
        avgwt = avgwt + a[i].wait;
        avgtat = avgtat + a[i].tat;
    }
    printf("Average wait time : %f",avgwt/no);
    printf("Average Tat time : %f",avgtat/no);
}



































// void main()
// {
//     int n,i,qt,count=0,temp,sq=0,bt[10],wt[10],tat[10],rem_bt[10];
//     float awt=0,att=0;
//     print("Enter number of Process : ");
//     scanf("%d",&n);
//     printf("Enter the burst time of the process : ");
//     for(i=0;i<n;i++)
//     {
//         scanf("%d",&bt[i]);
//         rem_bt[i]=bt[i];
//     }
//     printf("Enter the quantum time : ");
//     scanf("%d",&qt);


//     while(1)
//     {
//         for(i=0,count=0;i<n;i++)
//         {
//             temp = qt;
//             if(rem_bt[i]=0)
//             {
//                 count++;
//                 continue;
//             }
//         }
//     }
// }
