#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBERS 40000

typedef struct {
	int curr_index;
	int product[MAX_NUMBERS];
} ProductOfNumbers;


ProductOfNumbers* productOfNumbersCreate() {
    ProductOfNumbers *nums = calloc(1, sizeof(ProductOfNumbers));
	nums->product[nums->curr_index] = 1;
	return nums;
}

void productOfNumbersAdd(ProductOfNumbers* obj, int num) {
	if (num == 0) {
		obj->curr_index = 0;
		return;
	}
	obj->curr_index = obj->curr_index  + 1;
	obj->product[obj->curr_index] = obj->product[obj->curr_index - 1] * num;
}

int productOfNumbersGetProduct(ProductOfNumbers* obj, int k) {
	if (obj->curr_index < k) {
		return 0;
	}
	return (obj->product[obj->curr_index] / obj->product[obj->curr_index - k]);
}

void productOfNumbersFree(ProductOfNumbers* obj) {
    free(obj);
}

/**
 * Your ProductOfNumbers struct will be instantiated and called as such:
 * ProductOfNumbers* obj = productOfNumbersCreate();
 * productOfNumbersAdd(obj, num);
 
 * int param_2 = productOfNumbersGetProduct(obj, k);
 
 * productOfNumbersFree(obj);
*/
