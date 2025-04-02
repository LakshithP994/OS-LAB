#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>

#define buffer_size 5

int count=0,x=0;
int buffer[buffer_size];
sem_t full,empty,mutex;
void wait(sem_t *s)
{
    sem_wait(s);
}

void signal_sem(sem_t *s)
{
    sem_post(s);
}

void producer()
{
    if(count==buffer_size)
    {
        printf("Buffer is full");
    }
    wait(&empty);
    wait(&mutex);

    buffer[count]=++x;
    printf("The item produced=%d\n",x);
    count++;

    signal_sem(&mutex);
    signal_sem(&full);
}

void consumer()
{
    if(count==0)
    {
        printf("Buffer is empty\n");
    }
    wait(&full);
    wait(&mutex);

    x=buffer[count-1];
    printf("The item consumed=%d\n",x);
    count--;

    signal_sem(&mutex);
    signal_sem(&empty);
}

int main()
{
    sem_init(&full,0,0);
    sem_init(&empty,0,buffer_size);
    sem_init(mutex,0,1);
    int choice;
    for(;;){
    printf("Enter 1.Produce 2.consume 3.exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        producer();
        break;
    case 2:
        consumer();
        break;
    case 3:
        printf("Exiting....\n");
        sem_destroy(&empty);
        sem_destroy(&full);
        sem_destroy(&mutex);
        return 0;
    }
    }
}
