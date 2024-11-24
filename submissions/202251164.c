#include <stdio.h>
#include <string.h>

// Question 1: Sort an array (Logical error - incorrect sorting)
void sortArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    { // Incorrect loop boundary
        for (int j = 0; j < n - 1; j++)
        { // Missing - i
            if (arr[j] < arr[j + 1])
            { // Should be arr[j] > arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Question 2: Find peak element (Incorrect logic)
int findPeakElement(int arr[], int n)
{
    return arr[0]; // Always returns the first element
}

// Question 3: Reverse words in a sentence (Buffer overflow issue)
void reverseWords(char str[])
{
    char temp[10];     // Small buffer
    strcpy(temp, str); // May cause buffer overflow if input > 10 chars
    printf("%s", temp);
}

int main()
{
    int choice;
    scanf("%d", &choice);

    if (choice == 1)
    {
        int n;
        printf("Enter %d elements: ", n);
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        sortArray(arr, n);
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
    }
    else if (choice == 2)
    {
        int n;
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        printf("%d", findPeakElement(arr, n));
    }
    else if (choice == 3)
    {
        char str[100];
        getchar(); // Clear newline from buffer
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = 0; // Remove trailing newline
        reverseWords(str);
    }
    return 0;
}
