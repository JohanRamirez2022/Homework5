#include <iostream>
#include <cstdlib>
#include <chrono>
#include <array>
#include <vector>
#include <ctime>
#include <fstream>

using namespace std;
using namespace chrono;

void appendDataFromRand(vector<int>& array, int const& size);
void selectionSort(vector<int>& array);
void insertionSort(vector<int>& array);
void bubbleSort(vector<int>& array);
void mergeSort(vector<int>& array);
void saveListToFile(const vector<int>& lst, const string& filename);


void appendDataFromRand(vector<int>& array, int const& size)
{
    
    int randomNumber;

    srand(time(0));
    for (int i = 0; i < size; i++)
    {   
        randomNumber = (rand() % size) + 1;
        array.push_back(randomNumber);
    }
}

void selectionSort(vector<int> array)
{   
    int comparisons = 0;
    int swaps = 0;

    for (int i = 0; i < array.size()-1; i++)
    {
        int minIndex = i;
        for (int j = i+1; j < array.size(); j++)
        {   
            comparisons++;
            if (array[j] < array[minIndex])
            {
                swaps++;
                minIndex = j;
            }
        int temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
        }
    }
    cout << "Total number of comparisons: " << comparisons << endl;
    cout << "Total number of swaps: " << swaps << endl;
}

void insertionSort(vector<int>& array)
{
    int comparisons = 0;
    int swaps = 0;
    for (int i = 1; i < array.size(); i++)
    {
        int curr = i;
        while ((curr >= 0) && (array[curr] < array[curr-1]))
        {
            int temp = array[curr];
            array[curr] = array[curr-1];
            array[curr-1] = temp;
            curr--;
            swaps++;
            
        }
    }
}

void bubbleSort(vector<int>& array)
{   
    int comparisons = 0;
    int swaps = 0;

    bool sorted = false;
    while (!sorted)
    {
        sorted = true;
        for (int i = 0; i < (array.size() - 1); i++)
        {   
            comparisons++;

            if (array[i] > array[i+1])
            {
                swaps++;

                sorted = false;
                int temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
            }
        }
        
    }
    cout << "Total number of comparisons: " << comparisons << endl;
    cout << "Total number of swaps: " << swaps << endl;
}



int main()
{
    
    vector<int> thousand;
    vector<int> tenK;
    vector<int> hundredK;
    
    int comparisons = 0;
    int swaps = 0;

    appendDataFromRand(thousand, 1000);
    
    auto start = high_resolution_clock::now();

    bubbleSort(thousand);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
 
    cout << "Algorithm ran in " << duration.count() << " microseconds \n";
    
    return 0;
}