// Code designed on 18th Februaray, 2021 ~ Thursday_3testd on 21st February ~ Sunday_3.
// Check out the tracing part and the code designing part in the "Data Structures" notes of GPT-MSB.
#include <iostream>
using namespace std;

// Global function Declarations..
void swap(int array[], int pos1, int pos2);
void quicksort(int array[], int left, int right);
int partition(int array[], int lowerb, int upperb);

int main()
{
    int size=0;
    cout << "Enter the size of the list to be sorted: ";
    cin >> size;
    int *list = new int[size];
    
    cout << "Enter " << size << " elements.." << endl;
    for (int i=0; i<size; i++)
    {
        cout << "Element-" << i+1<<": ";
        cin >> list[i];
    }
    
    cout << "Sorting.." << endl;
    quicksort(list, 0, size-1);
    
    cout << "After sorting the elements in the list: ";
    for (int i=0; i<size; i++)
        cout << list [i] << " ";

    cout << endl << "-- Done  --" << endl;
}


void quicksort(int array[], int left, int right)
{
    int finalPivotIdx = partition (array, left, right);     // Get the pivot Idx to split the array..
    if(left < right && finalPivotIdx != left)
    {
        quicksort (array, left, finalPivotIdx-1);
        quicksort (array, finalPivotIdx+1, right);
    }
}


int partition(int array[], int lowerb, int upperb)
{
    int pivotIdx = lowerb;       // Considering the left element as the pivot element..
    int leftIdx = lowerb+1;     // The next successive element of the pivot as the left-element..
    int rightIdx = upperb;
    
    while(rightIdx >= leftIdx)  // Base-condition.. i.e., runs till the pivotIdx finds its appropriate position to get seated..
    {
        // Move the leftIdx pointer to appropriate position -- i.e., till the position, where the element is > pivot-element..
        while (array[leftIdx] <= array[pivotIdx] && leftIdx < upperb)
            leftIdx++;
        // Move the rightIdx pointer to approriate position -- i.e., till the position, where the element is < pivot..
        while (array[rightIdx] >= array[pivotIdx] && rightIdx > lowerb)
            rightIdx--;
        
        if(leftIdx < rightIdx)            
            swap(array, leftIdx, rightIdx); // By these swaps, the get arranged as, towards left of pivot->lesser and right of pivot - greater... 
    }
    swap(array, pivotIdx, rightIdx);           // By this, swap, all the elements towards the left of the pivot will be left, and towards right - greater than pivot.... NOTE, its left->lesser and right->greater, that's it, it doesn't mean that, they are SORTED..-- only pivot got sorted..
    return (pivotIdx = rightIdx);       // After swap with the pivot and right, pivotIdx will now be as of the rightIdx right..??
}


void swap(int array[], int pos1, int pos2)
{
    if(pos1 != pos2)
    {
        int temp = array[pos1];
        array[pos1] = array[pos2];
        array[pos2] = temp;
    }
}
