#include <iostream>
#include <vector>

using namespace std;
void merge(int arr[], int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid) // this if all the right subarray is filled into temp and left subarray has some elements.So to insert those elements we created this loop.
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high) // this if all the left subarray is filled into temp and right subarray has some elements.So to insert those elements we created this loop.
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (auto i = low; i <= high; i++) // equal to because high is already as n-1
    {
        arr[i] = temp[i - low];
    }
}

void divide(int arr[], int low, int high) // array ke jaga vector<int>&arr ye bhi likh sakte h function definiton mai
{
    if (low == high)
        return;
    int mid = (low + high) / 2;
    divide(arr, low, mid);
    divide(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void mergesort(int arr[], int n)
{
    divide(arr, 0, n - 1);
}
void display(int arr[], int n)
{
    for (auto i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int partition(int arr[], int low, int high)
{
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot&&i<=high-1){
            i++;
        }
        while(arr[j]>=pivot&&j>=low+1){
            j--;
        }
        if(i<j)
        swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}

void qs(int arr[],int low,int high){
    if(low>=high)
    return;
    int partitionindex=partition(arr,low,high);
    qs(arr,low,partitionindex-1);
    qs(arr,partitionindex+1,high);
}

void quicksort(int arr[],int n){
    qs(arr,0,n-1);
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quicksort(arr,n);
    display(arr,n);
}
