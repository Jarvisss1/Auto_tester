#include <stdio.h>
#include <string.h>

// Question 1: Sort an array
void sortArray(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
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

// Question 2: Find peak element
int findPeakElement(int arr[], int n)
{
    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1])
        {
            return arr[i];
        }
    }
    return arr[0]; // Return first element if no peak found
}

// Question 3: Reverse words in a sentence
void reverseWords(char str[])
{
    int len = strlen(str);
    int start = len - 1, end = len - 1;

    while (start >= 0)
    {
        if (str[start] == ' ' || start == 0)
        {
            if (start == 0)
                printf("%.*s ", end - start + 1, &str[start]);
            else
                printf("%.*s ", end - start, &str[start + 1]);
            end = start - 1;
        }
        start--;
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
        str[strcspn(str, "\n")] = 0; // Remove trailing newline
        reverseWords(str);
    }
    return 0;
}
