#include <iostream>
#include <chrono>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;



void insertionSort(int *arr){
    int temp;
    for(int k=1; k<10000; k++)
    {
        temp = arr[k];
        int j= k-1;
        while(j>=0 && temp <= arr[j])
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = temp;
    }

}


void selectionSort(int *arr){
    int temp, lowest;
    for(int i = 0; i<10000-1; i++){
        temp = arr[i];
        lowest = i;
        for(int j = i+1; j<10000; j++){
            if(temp > arr[j] ){
                temp = arr[j];
                lowest = j;

            }
        }
        arr[lowest] = arr[i];
        arr[i] = temp;
    }
}



void bubbleSort(int *arr){
    int temp, index;

    bool sorted;
    for(int i = 0; i<10000-1; i++){

        sorted = true;

        temp = arr[i];
        index = i;

        for(int j = i+1;j<10000;j++){
            if(temp>arr[j]){
                sorted = false;
                arr[index] = arr[j];
                arr[j] = temp;
                index = j;
                temp = arr[j];

            }
        }

        if(sorted == true){
            break;
        }
    }
}



void merge(int *arr, int p, int q, int r) {

  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

void mergeSort(int *arr, int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}





int partition(int arr[], int start, int end)
{

    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }

    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {

        while (arr[i] <= pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{

    if (start >= end)
        return;

    int p = partition(arr, start, end);

    quickSort(arr, start, p - 1);

    quickSort(arr, p + 1, end);
}





int main()
{

    double insertion[20],selection[20],bubble[20],mergeS[20],quickS[20];
    int arr[10000];
    int arr1[10000];
    int arr2[10000];
    int arr3[10000];
    int arr4[10000];

    int upper = 10000;
    int lower = 1;
    int k = 1;
    int filename = 1;


    while(k!=21){


        for(int i = 0; i<10000;i++){
            arr[i] = (rand() % (upper-lower+1)) + lower;
            arr1[i] = arr[i];
            arr2[i] = arr[i];
            arr3[i] = arr[i];
            arr4[i] = arr[i];
        }

        ofstream MyFile("D:\\Random\\"+to_string(filename)+".txt");

        for(int i = 0; i<10000;i++){
            MyFile << arr[i] << endl;
        }

        MyFile.close();


        auto start = std::chrono::steady_clock::now();

        insertionSort(arr);

        auto  end = std::chrono::steady_clock::now();

        double elapsed = double(std::chrono::duration_cast <std::chrono::nanoseconds> (end-start).count());
        cout<<"\nTime OF Insertion Sort : "<<elapsed/1e9<<endl;

        auto s = std::chrono::steady_clock::now();
        selectionSort(arr1);
        auto  e = std::chrono::steady_clock::now();
        double el = double(std::chrono::duration_cast <std::chrono::nanoseconds> (e-s).count());
        cout<<"\nTime OF Selection Sort : "<<el/1e9<<endl;




        auto st = std::chrono::steady_clock::now();
        bubbleSort(arr2);
        auto  en = std::chrono::steady_clock::now();
        double ela = double(std::chrono::duration_cast <std::chrono::nanoseconds> (en-st).count());
        cout <<"\nTime OF Bubble Sort : "<< ela/1e9<<endl;


        auto stz = std::chrono::steady_clock::now();
        mergeSort(arr3,0,10000-1);
        auto  ena = std::chrono::steady_clock::now();
        double elaz = double(std::chrono::duration_cast <std::chrono::nanoseconds> (ena-stz).count());
        cout <<"\nTime OF Merge Sort : "<< elaz/1e9<<endl;


        auto stzx = std::chrono::steady_clock::now();
        quickSort(arr4,0,10000-1);
        auto  enax = std::chrono::steady_clock::now();
        double elazx = double(std::chrono::duration_cast <std::chrono::nanoseconds> (enax-stzx).count());
        cout <<"\nTime OF Quick Sort : "<< elazx/1e9<<"\n\n\n"<<endl;




        insertion[k-1] = elapsed/1e9;
        selection[k-1] = el/1e9;
        bubble[k-1] = ela/1e9;


        upper += 10000;
        lower += 10000;
        k += 1;
        filename += 1;

    }


    ofstream a1("D:\\Random\\Insertion.txt");
    ofstream a2("D:\\Random\\Selection.txt");
    ofstream a3("D:\\Random\\Bubble.txt");
    ofstream a4("D:\\Random\\Merge.txt");
    ofstream a5("D:\\Random\\Quick.txt");

    for(int i = 0; i<20; i++){
        a1<<insertion[i]<<endl;
        a2<<selection[i]<<endl;
        a3<<bubble[i]<<endl;
        a4<<mergeS[i]<<endl;
        a5<<quickS[i]<<endl;
    }

    return 0;

}

