// sorts.h
#pragma once

//swap
void swap(int A[], int i, int j);

//selectionSort
int findMax(int A[], int n);
void selectionSort(int A[], int n);

//quickSort
int partition(int A[], int p, int r);
void quickSort(int A[], int p, int r);

//insertionSort
void insertionSort(int A[], int n);

//bubbleSort
void bubbleSort(int A[], int n);

//heapSort
void buildHeap(int A[], int n);
void heapify(int A[], int i, int n);
void heapSort(int A[], int n);