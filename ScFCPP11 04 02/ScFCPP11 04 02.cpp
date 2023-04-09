#include <iostream>

void sortMerge(int* arr, int first, int size) {
	// divide the range in half and find the first element in the right half
	int firstInTheRightHalf = first + size / 2;
	if (size > 1) {
		// sort the left half
		sortMerge(arr, first, size / 2);
		// sort the right half
		sortMerge(arr, firstInTheRightHalf, size - size / 2);
		// an array for temporary storage of sorted values
		int* temp = new int[size];
		// left half counter
		int left = first;
		// right half counter
		int right = firstInTheRightHalf;
		for (int i = 0; i < size; i++)
			// if the values on the left side are over, fill in the rest from the right side
			if (left - first >= size / 2)
				temp[i] = arr[right++];
		// if the values on the right side are over, fill in the rest from the left side
			else if (right - firstInTheRightHalf >= size - size / 2)
				temp[i] = arr[left++];
		// if there are value on both sides, choose the smallest one of the remaining 
			else
				temp[i] = arr[left] < arr[right] ? arr[left++] : arr[right++];
		// fill current range with sorted values
		for (int i = 0, j = first; i < size; i++, j++)
			arr[j] = temp[i];
	}
}


int main()
{
	int arr[] = { 38, 27, 43, 3, 9, 82, 10 };
	int n = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < n; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	sortMerge(arr, 0, n);
	for (int i = 0; i < n; i++)
		std::cout << arr[i] << " ";
}

