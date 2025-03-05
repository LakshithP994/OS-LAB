#include<stdio.h>
void sumrow(int arr[3][4],int n,int m)
{
    int sumrow=0;
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=0;j<m;j++)
        {
            sum+=arr[i][j];
        }
        printf("\n sum of row %d=%d",i,sum);
        sumrow+=sum;
    }
    printf("\n the sum of the rows=%d",sumrow);
}
void sumcol(int arr[3][4],int n,int m)
{
    int sumcol=0;
    for(int i=0;i<m;i++)
    {
        int sum=0;
        for(int j=0;j<n;j++)
        {
            sum+=arr[j][i];
        }
        printf("\n sum of column %d=%d",i,sum);
        sumcol+=sum;
    }
    printf("\n the sum of the columns=%d",sumcol);
}
int main()
{
    int arr[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int n=3;
    int m=4;
    sumrow(arr,n,m);
    sumcol(arr,n,m);
}
