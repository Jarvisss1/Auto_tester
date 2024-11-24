#include <stdio.h>
#include <string.h>

// Question 1: Sort an array (Accesses memory out of bounds)
void sortArray(int arr[], int n)
{
    for (int i = 0; i <= n; i++)
    { // Accesses arr[n], out of bounds
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Question 2: Find peak element (Causes segmentation fault)
int findPeakElement(int arr[], int n)
{
    return arr[n]; // Accesses out-of-bounds index
}

// Question 3: Reverse words in a sentence (Incorrect fgets handling)
void reverseWords(char str[])
{
    fgets(str, 50, stdin); // Assumes input will always be less than 50 chars, but doesn't clear buffer
    for (int i = strlen(str) - 1; i >= 0; i--)
    {
        printf("%c", str[i]); // Reverses the string character-wise, not word-wise
    }
}

int main()
{
    int choice;
    scanf("%d", &choice);

    if (choice == 1)
    {
        int n;
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
        str[strcspn(str, "\n")] = 0;
        reverseWords(str);
    }
    return 0;
}
