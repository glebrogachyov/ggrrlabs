#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

void Merge_Sort(int *, int, int);
void Merge(int *, int, int, int);
const unsigned int N=100;

int main() {
    srand(time(0));
    int test0[N];
    int test1[N];
    for (int i=0; i<N; i++) {
        test0[i]=rand()%10000;
    }
    for (int i=0; i<N; i++) {
        test1[i]=N-i;
    }
    printf("Start test 0: \n");   //1 test
    for (int i = 0; i<N; i++)
        printf(" %d,", test0[i]);
    printf("\n\n");
    Merge_Sort(test0, 0, N-1);
    printf("Finish test 0: \n");
    for (int i = 0; i<N; i++)
        printf(" %d,", test0[i]);
    printf("\n\n");
    printf("Start test 1: \n");  //2 test
    for (int i = 0; i<N; i++)
        printf(" %d,", test1[i]);
    printf("\n\n");
    Merge_Sort(test1, 0, N-1);
    printf("Finish test 1: \n");
    for (int i = 0; i<N; i++)
        printf(" %d,", test1[i]);
    printf("\n\n");
    printf("Start test 2: \n");  //3 test
    for (int i = 0; i<N; i++)
        printf(" %d,", test1[i]);
    printf("\n\n");
    Merge_Sort(test1, 0, N-1);
    printf("Finish test 2: \n");
    for (int i = 0; i<N; i++)
        printf(" %d,", test1[i]);
    printf("\n");
}

void Merge_Sort(int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        Merge_Sort(a,low,mid);
        Merge_Sort(a,mid+1,high);
        Merge(a,low,high,mid);
    }
    return;
}

void Merge(int *a, int low, int high, int mid) {
    int i, j, k, c[N];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else
        {
            c[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        a[i] = c[i];
    }
}
