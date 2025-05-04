//Function to sort using bubble sort
void bubble(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

//Function to sort using selection sort
void selection(int arr[], int len)
{
    for (int i = 0; i < len - 1; i++) 
    {
        int m = i;
        for (int j = i + 1; j < len; j++) 
        {
            if (arr[j] < arr[m])
                m = j;
        }
        int temp = arr[m];
        arr[m] = arr[i];
        arr[i] = temp;
    }
}

//Function to sort using insertion sort
void insertion(int arr[], int len)
{
    for (int i = 1; i < len; i++) 
    {
        int key = arr[i];
        int j = i - 1;
        while (j >=0 && key < arr[j]) 
        {
            arr[j+1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}
