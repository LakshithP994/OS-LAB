#include<stdio.h>
int main()
{

    int n,t;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    int wt[n],tat[n],bt[n],p[n];
    float wtavg=0,tatavg=0;
    for(int i=0;i<n;i++)
    {
        printf("\n Enter the burst time for process%d: ",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++)
        {
            if(bt[i]>bt[j]){
                t=bt[j];
                bt[j]=bt[i];
                bt[i]=t;

                t=p[i];
                p[i]=p[j];
                p[j]=t;
            }
        }
    }
    wt[0]=0;
    tat[0]=bt[0];
    for(int i=1;i<n;i++)
    {
        wt[i]=wt[i-1]+bt[i-1];
        tat[i]=tat[i-1]+bt[i];
        wtavg+=wt[i];
        tatavg+=tat[i];
    }
    wtavg=(wt[0]+wtavg)/n;
    tatavg=(tat[0]+tatavg)/n;
     printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n",p[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", wtavg);
    printf("\nAverage Turnaround Time = %.2f", tatavg);

    return 0;
}
