#include <stdio.h>
int isFinish(int burst[],int n);
int isFinish(int burst[],int n){
    
    int i=0;
    for(i=0;i<n;i++){
        if(burst[i]>0){
            return 0;
        }
    }
    return 1;
}


int main(){
    int i=0,j=0,time=0,n=6,b=0;
    int g=0;
    int arrival[6]={0,1,2,3,4,6},burst[6]={4,5,2,1,6,3},wait[20];
    int temp[200][2];
    int queue[30],front=-1,rear=-1;
    int qw[20];
    int q=2;
    float sum=0.0,avg=0.0,turn=0.0;

int pop(){
    int item=0;
    if(front==-1){
        printf("Queue is empty");
        return -1;
    }else{
        item=queue[front];
        if(front==rear){
            front=-1;
            rear=-1;
        }else{
            front=front+1;
        }
        return item;
        printf("%d ",item);
    }

}
int push(int item){
    
    if(rear==30){
        printf("Full");
            return -1;
    }else{
        if(front==-1 && rear==-1){
            front=0;
        }
        rear=rear+1;
        queue[rear]=item;
    }
}

   
    j=0;
    time=0;
    push(0);

   // printf("%d      f  ",front);
    //pop();
    //printf("%d   %d   f  ",,front);
     //printf("%d      a  ",front);
      i=0;
     while(front!=-1){
        g=pop();
       i=0;
        //printf("%d     =g ",g);
        if(time<arrival[n-1]){
        while(i<n){
            if(arrival[i]>time && arrival[i]<=(time+q)&& i!=g){
            push(i);
           printf("%d    i    \n",i);
            }
            
            i++;
        }
        }
        
        temp[j][0]=g;
        if(burst[g]>q){
            temp[j][1]=q;
            time=time+q;
            burst[g]=burst[g]-q; 
            j=j+1; 
            push(g);  
        }else if(burst[g]>0 && burst[g]<=q){
            temp[j][1]=burst[g];
            time=time+burst[g];
            burst[g]=0; 
            
            j=j+1;
        }
        
       
        
     
    }
     printf("\n");
    b=j;
    for(i=0;i<b;i++){
        printf("%d %d \n",temp[i][0],temp[i][1]);

    }
    for(i=0;i<b;i++){
        printf("%d ",queue[i]);

    }
    printf("\n");
    for(i=0;i<n;i++){
        wait[i]=0-arrival[i];
        qw[i]=0;

    }
    time=0;
    for(i=0;i<b;i++){
       wait[temp[i][0]]=wait[temp[i][0]]+time-qw[temp[i][0]];
       time=temp[i][1]+time;
       qw[temp[i][0]]=time;
    }
    
    for(i=0;i<n;i++){
        sum=sum+wait[i];
        printf("\n %d %d",wait[i],qw[i]);
        turn=turn+qw[i]-arrival[i];
    }
    printf("\n %f %f",sum,turn);
    avg=sum/n;
    turn=turn/n;
    printf("\n %f %f",avg,turn);
    
    
     
    return 0;
}






