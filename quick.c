#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

double quickSort(int arr[], int low, int high)
{
    clock_t start = clock();

    if (low < high)
    {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);

        int pivotIndex = i + 1;

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }

    clock_t end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC;
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

    double averageCaseTime = quickSort(arr, 0, inputSize - 1);

    double bestCaseTime = quickSort(arr, 0, inputSize - 1);

    for (int i = 0, j = inputSize - 1; i < j; i++, j--)
    {
        swap(&arr[i], &arr[j]);
    }

    double worstCaseTime = quickSort(arr, 0, inputSize - 1);

    // Print the sorted array (optional)
    printf("Sorted array: ");
    printArray(arr, inputSize);

    printf("Average case time complexity: %f seconds\n", averageCaseTime);
    printf("Best case time complexity: %f seconds\n", bestCaseTime);
    printf("Worst case time complexity: %f seconds\n", worstCaseTime);

    free(arr);

    return 0;
}
