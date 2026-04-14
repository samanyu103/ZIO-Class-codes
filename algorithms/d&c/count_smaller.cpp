#include <iostream>
#include <array>
using namespace std;

void merge(array<int,2> a[], int l, int mid, int r, int ans[]) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    array<int,2> L[n1], R[n2];

    for(int i = 0; i < n1; i++) L[i] = a[l + i];
    for(int j = 0; j < n2; j++) R[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = l;

    while(i < n1 && j < n2) {
        if(R[j][0] < L[i][0]) {
            // L[i..n1-1] are strictly > R[j].
            a[k++] = R[j++];
        } 
        else {
            // L[i] =< R[j] then R[0..j-1] are strictly smaller than L[i] and to the right of it.
            ans[L[i][1]] += j;
            a[k++] = L[i++];
        }
    }

    while(i < n1) {
        // all j element are to the right and smaller than L[i]
        ans[L[i][1]] += j;
        a[k++] = L[i++];
    }

    while(j < n2) {
        a[k++] = R[j++];
    }
}

void mergeSort(array<int,2> a[], int l, int r, int ans[]) {
    if(l >= r) return;

    int mid = (l + r) / 2;

    mergeSort(a, l, mid, ans);
    mergeSort(a, mid + 1, r, ans);
    merge(a, l, mid, r, ans);
}

int main() {
    int nums[] = {7,3,9,5};
    int n = sizeof(nums) / sizeof(nums[0]);

    array<int,2> a[n];
    int ans[n] = {0};

    for(int i = 0; i < n; i++) {
        a[i] = {nums[i], i};
    }

    mergeSort(a, 0, n-1, ans);

    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";
}