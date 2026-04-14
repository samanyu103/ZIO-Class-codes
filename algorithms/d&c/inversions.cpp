#include <iostream>
using namespace std;

int merge(int a[], int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int L[n1], R[n2];

    for(int i=0;i<n1;i++) L[i] = a[l+i];
    for(int j=0;j<n2;j++) R[j] = a[mid+1+j];

    int i=0, j=0, k=l;
    int inv = 0;

    while(i<n1 && j<n2) {
        if(L[i] <= R[j]) {
            a[k++] = L[i++];
        }
        else {
            // L[i]>R[j] then L[i ... n1-1], R[j] form inversion  pair.
            a[k++] = R[j++];
            inv += (n1 - i);   // count inversions
        }
    }

    while(i<n1) a[k++] = L[i++];
    while(j<n2) a[k++] = R[j++];

    return inv;
}

int mergeSort(int a[], int l, int r) {
    int inv = 0;

    if(l < r) {
        int mid = (l+r)/2;

        inv += mergeSort(a,l,mid);
        inv += mergeSort(a,mid+1,r);
        inv += merge(a,l,mid,r);
    }

    return inv;
}

int main() {
    int a[] = {2,4,1,3,5};
    int n = 5;

    cout << mergeSort(a,0,n-1) << endl;
}