#include<stdio.h>

void merge(int arr[], int low, int mid, int high) {
    int l = low, r = mid + 1;
    int a = high - low + 1;
    int temp[a];
    int i = 0;
    
    while (l <= mid && r <= high) {
        if (arr[l] <= arr[r])
            temp[i++] = arr[l++];
        else
            temp[i++] = arr[r++];
    }
    
    while (l <= mid)
        temp[i++] = arr[l++];
    while (r <= high)
        temp[i++] = arr[r++];
    
    for (int j = 0; j < a; j++)
        arr[low + j] = temp[j];
}
void meso(int arr[], int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2;
    meso(arr, low, mid);
    meso(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void mergesort(int arr[], int n) {
    meso(arr, 0, n - 1);
}
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    mergesort(arr, n);
    
    printf("Sorted elements: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    return 0;
}
