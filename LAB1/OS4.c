#include<stdio.h>
void countduplicates(int arr[],int n)
{
    int duplicates;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]==arr[j])
            {
                duplicates++;
                break;
            }
        }
    }
    printf("The number of duplicates=%d",duplicates);
}
int main()
{
    int n;
    printf("Enter the size of array=");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        int val;
        printf("enter the value:");
        scanf("%d",&val);
        arr[i]=val;
    }
    countduplicates(arr,n);
}
