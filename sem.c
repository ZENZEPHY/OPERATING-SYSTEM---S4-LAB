#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>

void main()
{
    int *p,val,val1;
    int sid;
    key_t key = ftok("sem.c",'1');
    sid=semget(key,50,1,IPC CREAT|0777);

    if(sid<0)
    {
        printf("error in creating semaphore\n");
    }
    else
    {
        printf("semaphore created successfully\n");
        printf("Semaphore id : %d\n",sid);
    }

    if(semctl(sid,0,SETVAL,1)==0)
    {
        printf("semaphore value set as 1 successfully\n");
    }
    if(semctl(sid,0,GETVAL)==1)
    {
        printf("semaphore value is 1\n");
    }
  
    if(semop(sid,0,-1)==0)
    {
        printf("semaphore locked successfully\n");
    }
    if(semctl(sid,0,GETVAL)==0)
    {
        printf("semaphore value is 0\n");
    }
    s[0].sem_op=1;
    semop(sid,&s[0],1);
    printf("semaphore unlocked successfully\n");
    if(semctl(sid,0,GETVAL)==1)
    {
        printf("semaphore value is 1 after unlocking\n");
    }

    ifsemctl(sid,0,IPC_RMID)==0)
    {
        printf("semaphore removed successfully\n");
    }
    else
    {
        printf("error in removing semaphore\n");
    }
    

}