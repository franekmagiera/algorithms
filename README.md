# algorithms

This is a library containing various algorithms written in C. Functions work on arrays and are generic(independent of the array's data type) and they require a comparison function for a given data type. In order for a comparison function to be compatible with algorithms from this repository it should take two pointers to const voids and return an int, more precisely:
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
 
 ## other
  - linear search
  - binary search
  - sum two binary numbers
  - inversion counting
  
## common
Contains functions such as swap and merge.
