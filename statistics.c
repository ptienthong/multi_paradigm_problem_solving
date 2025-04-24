#include <stdio.h>
#include <stdlib.h>

// Function to calculate mean
double calculate_mean(int *arr, int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (double)sum / size;
}

// Swap for sorting
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Simple bubble sort for median
void bubble_sort(int *arr, int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Function to calculate median
double calculate_median(int *arr, int size) {
    bubble_sort(arr, size);
    if(size % 2 == 1) {
        return arr[size / 2];
    } else {
        return (arr[(size - 1) / 2] + arr[size / 2]) / 2.0;
    }
}

// Function to calculate mode (returns number of modes and fills in the mode array)
int calculate_mode(int *arr, int size, int *modes) {
    int *counts = (int *)calloc(size, sizeof(int));
    int max_count = 0;
    int num_modes = 0;

    for(int i = 0; i < size; i++) {
        counts[i] = 1;
        for(int j = i + 1; j < size; j++) {
            if(arr[i] == arr[j]) {
                counts[i]++;
            }
        }
        if(counts[i] > max_count) {
            max_count = counts[i];
        }
    }

    for(int i = 0; i < size; i++) {
        int is_unique = 1;
        for(int j = 0; j < i; j++) {
            if(arr[i] == arr[j]) {
                is_unique = 0;
                break;
            }
        }
        if(counts[i] == max_count && is_unique) {
            modes[num_modes++] = arr[i];
        }
    }

    free(counts);
    return num_modes;
}

int main() {
    int numbers[] = {4, 2, 1, 3, 4, 2, 4, 2, 2, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    // Copy array for median so original remains unsorted
    int *temp = (int *)malloc(size * sizeof(int));
    for(int i = 0; i < size; i++) temp[i] = numbers[i];

    double mean = calculate_mean(numbers, size);
    double median = calculate_median(temp, size);

    int *modes = (int *)malloc(size * sizeof(int));
    int num_modes = calculate_mode(numbers, size, modes);

    printf("Mean: %.2f\n", mean);
    printf("Median: %.2f\n", median);
    printf("Mode: ");
    for(int i = 0; i < num_modes; i++) {
        printf("%d ", modes[i]);
    }
    printf("\n");

    free(temp);
    free(modes);
    return 0;
}
