#include<iostream>
using namespace std;
void swapp(int &a, int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
void BubbleSort(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-1-i; j++)
        {
            if(arr[j]>arr[j+1])
            swapp(arr[j], arr[j+1]);
        }
    }
}
void InsertionSort(int arr[], int n)
{
    for(int i=1; i<n; i++)
    {
        int key=arr[i];
        int j=i-1;
        while(j>=0 &&arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
void SelectionSort(int arr[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        int minIndex=i;
        for(int j=i+1; j<n; j++)
        {
            if(arr[j]<arr[minIndex])
            minIndex=j;
        }
        swapp(arr[i], arr[minIndex]);
    }
}
int partitioned(int arr[], int low, int high)
{
    int pivot=arr[high];
    int i=low-1;
    for(int j=low; j<high; j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swapp(arr[i], arr[j]);
        }
    }
    swapp(arr[i+1], arr[high]);
    return i+1;
}
void QuickSort(int arr[], int low, int high)
{
    if(low<high)
    {
        int pi=partitioned(arr, low, high);
        QuickSort(arr, low, pi-1);
        QuickSort(arr,pi+1, high);
    }
}
void Merge(int arr[], int low, int mid, int high)
{
    int n1=mid-low+1;
    int n2=high-mid;
    int left[n1], right[n2];
    for(int i=0; i<n1; i++)
        left[i]=arr[low+i];
    for(int j=0; j<n2; j++)
        right[j]=arr[mid+1+j];
    int i=0, j=0, k=low;
    while(i<n1 && j<n2)
    {
        if(left[i]<=right[j])
            arr[k++]=left[i++];
        else
            arr[k++]=right[j++];
    }
    while(i<n1)
    {
        arr[k++]=left[i++];
    }
    while(i<n2)
    {
        arr[k++]=right[j++];
    }
}
void MergeSort(int arr[], int low, int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid+1, high);
        Merge(arr, low, mid, high);
    }
}
void disp(int arr[], int n)
{
    for(int i=0; i<n; i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}
int main()
{
    int n=5;
    int arr1[n]={5,1,3,2,4};
    int arr2[n]={6,2,9,5,3};
    int arr3[n]={29,65,4,33,22};
    int arr4[n]={99,66,33,55,22};
    int arr5[n]={1,3,99,25,55};
    BubbleSort(arr1, n);
    cout<<" Bubble Sort:  ";
    disp(arr1, n);
    InsertionSort(arr2, n);
    cout<<" Insertion Sort:  ";
    disp(arr2, n);
    SelectionSort(arr3,n);
    cout<<" Selection Sort:  ";
    disp(arr3, n);
    QuickSort(arr4,0,n-1);
    cout<<" Quick Sort:  ";
    disp(arr4,n);
    MergeSort(arr5,0,n-1);
    cout<<" Merge Sort:  ";
    disp(arr5,n);
}
