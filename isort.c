#include <stdio.h>
#define N 50

void shift_element(int *arr, int i);
void insertion_sort(int* arr , int len);
void print_arr(int *arr);
void get_arr(int arr[N]);

void insertion_sort(int* arr , int len)
{
    int i, key, j, shiftCounter;
    int *ptr;
    for (i = 1; i < len; i++) {
        key = *(arr+i);
        j = i - 1;
        
        //measure how many valus to shift 
        while (j >= 0 && *(arr+j) > key){
            j--;
        }
        
        shiftCounter = i-j-1;
        if(shiftCounter) //if shiftCounter == 0 don't shift 
        {
            //call shift_element with starting point of arr[j+1] 
            ptr = (arr + (j+1)); 
            shift_element(ptr, shiftCounter);
            *(arr + (j+1)) = key; 
        }
    }
}
//move element one step right from satrt to satart + i + 1
void shift_element(int *arr, int i)
{   
    for(int j = i; j > 0; j--)
    {   
        *(arr + j) = *(arr + j -1);
    }
}

void print_arr(int *arr)
{
    for(int i = 0; i<N; i++)
    {
        printf((i < N-1) ? "%d," : "%d\n", *(arr+i));
    }
}

void get_arr(int arr[N])//get array from user
{
    for(int i =0; i<N; i++)
    {
        scanf("%d", (arr+i));
    }
}

int main()
{
    int arr[N];
    get_arr(arr); //input from user  
    insertion_sort(arr, N); //sort the array by insertionSort algorithm
    print_arr(arr);
    return 0;
}
