#include<stdio.h>
#include<stdlib.h>


/*  1) take total no of cylinders.
    2) take the total no of work queue
    3) now take the total elements in the for loop
    4) take the head position
    5) one by one add the absolute value obtained by adding the individual distances between the diff disk queue
    6) print the total seek movements

*/    
void main()
{
    int c,h,w,mov,temp_distance=0,perm_distance=0;
    int i,q[10];
    printf("ENTER MAX NO OF CYLINDERS : ");
    scanf("%d",&c);
    printf("\nEnter current head pos: ");
    scanf("%d",&h);
    printf("\nEnter the max no.of Work queue : ");
    scanf("%d",&w);

    for(i=1;i<=w;i++)
    {
        printf("\nEnter the DISK ELEMENTS TO BE ACCESSED: ");
        scanf("%d",&q[i]);
    }
    q[0]=h;

    for(i=0;i<w;i++)
    {
        temp_distance = abs(q[i]-q[i+1]);
        printf("From %d to %d ---> %d \n", q[i],q[i+1],temp_distance);
        perm_distance += temp_distance; 
    }
    printf("\n\nTHE TOTAL HEAD MOVEMENTS : %d ",perm_distance);
}