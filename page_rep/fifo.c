#include<stdio.h>

void main(){
int i,j,k=0;
int n,f,pf=0;
int in[20],out[20];

printf("Enter the number of string elements : ");
scanf("%d",&n);

for(i=0;i<n;i++){
    printf("Enter the %d element : ",i+1);
    scanf("%d",&in[i]);
}
printf("Enter the total no.of frames:");
scanf("%d",&f);
for(i=0;i<f;i++){
    out[i]=-1;
}

for(i=0;i<n;i++){
    for(j=0;j<f;j++){
        if(in[i]==out[j])
            break;
    }
    if(f==j)
    {
        out[k]=in[i];
        k=(k+1)%f;
        pf++;
    }

    for(j=0;j<f;j++){
    printf("%d\t",out[j]);
    }
    printf("Page fault:%d\n",pf);
    }
}