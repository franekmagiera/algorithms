# algorithms

This is a library containing various algorithms written in C.

In order for a comparison function to be compatible with sorting functions it should take two pointers to const voids as arguments and return an int. To sort in ascending order, the function should return:
 - a negative value, if the first argument is smaller than the second one,
 - zero, if both arguments are the same,
 - a positive value, if the first argument is bigger than the second one.
 
 To sort in descending order, the function should return:
 - a negative value, if the first argument is bigger than the second one,
 - zero, if both arguments are the same,
 - a positive value, if the first argument is smaller than the second one.
