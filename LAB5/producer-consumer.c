#include<stdio.h>
#include<stdlib.h>
#define buffer_size 5

int buffer[buffer_size],x=0,count=0;
int full=0;
int empty=buffer_size;
int mutex=1;

void wait(int *s){
    if(*s>0){
        (*s)--;
    }
}

void sem_signal(int *s){
    (*s)++;
}

void producer(){

    if(empty==0){
        printf("\nBuffer is full.\n");
        return;
    }
    wait(&empty);
    wait(&mutex);

    buffer[count]=++x;
    printf("item produced=%d\n",x);
    count++;

    sem_signal(&mutex);
    sem_signal(&full);
}

void consumer(){
    if(full==0){
        printf("\nBuffer is empty.\n");
        return;
    }
    wait(&full);
    wait(&mutex);

    x=buffer[count-1];
    printf("item consumed=%d\n",x);
    count--;

    sem_signal(&mutex);
    sem_signal(&empty);
}

int main(){
    int c;
    while(1){
        printf("Enter\n1.produce\n2.consume\n3.exit\n");
        scanf("%d",&c);
        switch(c){
        case 1:
            producer();
            break;
        case 2:
            consumer();
            break;
        case 3:
            printf("Exiting.\n");
            exit(0);
        default:
            printf("Invalid entry.\n");
            break;
        }
    }
    return 0;
}
