#include<stdio.h>
#include<stdlib.h>

void sort(int a[], int size)
{
    int i,j,temp;
    for(i=0;i<size-1;i++)
    {
        for(j=i+1;j<size;j++)
        {
            if(a[i]>a[j])
            {
                temp = a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}

void main()
{
    int head,max;
    int q[20],upper[20],lower[20],usize=0,qsize=0,lsize=0;
    int i,total=0;

    printf("ENTER MAX NO OF CYLINDERS : ");
    scanf("%d",&max);

    printf("HEAD POSITION: ");
    scanf("%d",&head);

    printf("TOTAL WORK QUEUE");
    scanf("%d",&qsize);

    for(i=0;i<qsize;i++)
    {
        printf("ENTER THE WORK QUEUE ELEMENTS : ");
        scanf("%d",&q[i]);    
    }

for(i=0;i<qsize;i++)
{
    if(q[i]<head)
    {
        lower[lsize]=q[i];
        lsize++;
    }
    else
    {
        upper[usize]=q[i];
        usize++;
    }
}

sort(upper,usize);
sort(lower,lsize);

for(i=0;i<usize;i++)
{
    printf("%d--->",upper[i]);
    total += abs(upper[i]-head);
    head = upper[i];
}

if(usize>0 && lsize == 0)
{
printf("%d-->",max-1);
total += abs(max - head);
head = max;
}

if(lsize>0)
{
printf("0-->");
total += head;
head = 0;
}

for(i=0;i<lsize;i++)
{
    printf("%d--->",lower[i]);
    total += abs(lower[i]-head);
    head = lower[i]; 
}
printf("Total head movements : %d", total);
}