#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int inputSize;
    printf("Enter the number of elements (between 10 and 1000): ");
    scanf("%d", &inputSize);

    int *arr = (int *)malloc(inputSize * sizeof(int));

    srand(time(0));
    for (int i = 0; i < inputSize; i++)
    {
        arr[i] = rand();
    }

    clock_t start = clock();
    mergeSort(arr, 0, inputSize - 1);
    clock_t end = clock();
    double averageCaseTime = ((double)(end - start)) / CLOCKS_PER_SEC;

    start = clock();
    mergeSort(arr, 0, inputSize - 1);
    end = clock();
    double bestCaseTime = ((double)(end - start)) / CLOCKS_PER_SEC;

    for (int i = 0, j = inputSize - 1; i < j; i++, j--)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    start = clock();
    mergeSort(arr, 0, inputSize - 1);
    end = clock();
    double worstCaseTime = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Average case time complexity: %f seconds\n", averageCaseTime);
    printf("Best case time complexity: %f seconds\n", bestCaseTime);
    printf("Worst case time complexity: %f seconds\n", worstCaseTime);

    free(arr);

    return 0;
}