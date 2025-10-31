#include <stdio.h>

// 1. Swap ফাংশন: দুটি উপাদানের মান বিনিময় করার জন্য
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// 2. Partition ফাংশন: এটি অ্যারেটিকে Pivot-এর সাপেক্ষে বিভক্ত করে
int partition(int arr[], int low, int high) {
    // শেষ উপাদানকে Pivot হিসেবে নির্বাচন
    int pivot = arr[high];
    
    // i হলো ছোট উপাদানের সূচক
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++) {
        // যদি বর্তমান উপাদানটি Pivot-এর চেয়ে ছোট হয়
        if (arr[j] < pivot) {
            i++; 
            // ছোট উপাদানটিকে বাম দিকে আনার জন্য Swap
            swap(&arr[i], &arr[j]);
        }
    }
    // Pivot-কে তার সঠিক সর্টেড অবস্থানে (i+1-এ) বসানো
    swap(&arr[i + 1], &arr[high]);
    return (i + 1); // Pivot-এর নতুন সূচক রিটার্ন
}

// 3. Quick Sort ফাংশন: রিকার্সনের মাধ্যমে সর্টিং প্রক্রিয়া পরিচালনা করে
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Pivot-এর সঠিক অবস্থান বের করা
        int pi = partition(arr, low, high);

        // Pivot-এর বাম অংশের জন্য রিকার্সিভ কল
        quickSort(arr, low, pi - 1);

        // Pivot-এর ডান অংশের জন্য রিকার্সিভ কল
        quickSort(arr, pi + 1, high);
    }
}

// অ্যারে প্রিন্ট করার ফাংশন
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main ফাংশন
int main() {
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original Array (অসর্টেড তালিকা):\n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);
    
    printf("\nSorted Array (সর্টেড তালিকা):\n");
    printArray(arr, n);
    
    return 0;
}