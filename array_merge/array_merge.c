#include "array_merge.h"
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include "../mergesort/mergesort.h"
#include "../mergesort/mergesort.c"

//num_arrays is the number of arrays that are in values
//sizes is an array that has the sizes of the corresponding array in values
//values is an array of arrays with the number of arrays and size each array determined by num_arrays and sizes
//essentially, putting all the elements into a big array, using mergesort, counting the unique number of characters and putting that final result into an array

int* array_merge(int num_arrays, int* sizes, int** values) {
  
  int fullSize = 0; //variable for all the elements in values put together
  int* fullArray;
  for (int i = 0; i < num_arrays; ++i){ //the number of all the values in the values array with repeats
	fullSize = fullSize + sizes[i]; //adding the sizes array to determine how many total values there are
  }
  fullArray = (int*) calloc(fullSize, sizeof(int)); //an array of all the values in values
  int fullArrayIndex = 0; 
  for (int i = 0; i < num_arrays; ++i) { //looping through the elements of sizes
	for (int j = 0; j < sizes[i]; ++j){ //looping through the values in the sizes elements
		fullArray[fullArrayIndex] = values[i][j]; //adding the values of values into the array
		fullArrayIndex++;
	}
  }
  mergesort(fullSize, fullArray); //use mergesort on the fullArray
  int uniqueNum;
  if (num_arrays !=0) {
	uniqueNum = 1;
  }
  else {
  	uniqueNum = 0;
  }
  for (int i = 1; i < fullSize; i++){
	if (fullArray[i] != fullArray[i-1]){ //checking to see if there are any duplicate numbers
		++uniqueNum;
	}
  }
  fullArrayIndex = 2;
  int* result = (int*) calloc(uniqueNum+1, sizeof(int));
  result[0] = uniqueNum; //how many unique elements there will be
  if (uniqueNum != 0) {
	result[1] = fullArray[0];
  }
  for (int i = 1; i < fullSize; ++i){
	if (fullArray[i] != fullArray[i-1]){ //if it's not a duplicate number
		result[fullArrayIndex] = fullArray[i]; //add it to the result array
		++fullArrayIndex;
	}	
  }
  free(fullArray);
  return result;

}
