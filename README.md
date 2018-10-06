# algorithms

This is a library containing various algorithms written in C. Functions work on arrays. Some of them are generic(independent of the array's data type) and they require a comparison function for a given data type. In order for a comparison function to be compatible with algorithms from this repository it should take two pointers to const voids and return an int, more precisely:
 - 1, if the first argument is larger than the second one
 - 0, if both arguments are the same
 - -1, if the first argument is smaller than the second one
(it is the same convention as for strcmp() function from string.h; it is easy to remember because '>' kind of looks like '1' rotated 90 degrees clockwise) 

## sorting
 - selection sort
 - insertion sort
 - bubble sort
 - merge sort
 - improved merge sort (newMergeSort()) that uses insertion sort for arrays of size smaller than 18. I came up with number 18 after playing around with insertionVsMerge program for a while. newMergeSort() is faster then old mergeSort(). For the array of size one million the difference is a couple of hundeths of a second.
 - heap sort (in heap.h)
 - quicksort
 - randomized quicksort (the partitioning element is choosen randomly from a given subarray)
 - counting sort

## other
 - linear search
 - binary search
 - sum two binary numbers
 - inversion counting
 - finding maximal subarray (three different algorithms - a brute force one of
complexity O(n^2), a "divide and conquer" recursive one of complexity O(nlogn) and a linear one)
 - randomized select that looks for an *i* smallest element of an array (it also
   modifies the order of the elements in the array, so one has to be cautious
   when the order of the elements is important for some reason and should call this
   function using a copy of the original array)

## heap
 - max heapify
 - build max heap
 - heap sort

## common
 - swap
 - merge
 - minimum
 - maximum
 - minmax functions that finds both minimum and maximum of an array using no
   more than 3n/2 comparisons (unlike running minimum function first and then maximum function that
   would together require 2n-2 comparisions)
 - partition and randomized partition
