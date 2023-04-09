#include <iostream>

void sortMerge(int* arr, int first, int size) {
	int firstInTheRightHalf = first + size / 2;
	if (size > 1) {
		sortMerge(arr, first, size / 2);
		sortMerge(arr, firstInTheRightHalf, size - size / 2);
		int* temp = new int[size];
		int left = first;
		int right = firstInTheRightHalf;
		for (int i = 0; i < size; i++)
			if (left - first >= size / 2)
				temp[i] = arr[right++];
			else if (right - firstInTheRightHalf >= size - size / 2)
				temp[i] = arr[left++];
			else
				temp[i] = arr[left] < arr[right] ? arr[left++] : arr[right++];
		for (int i = 0, j = first; i < size; i++, j++)
			arr[j] = temp[i];
	}
}


int main()
{
	int arr[] = { 38, 27, 43, 3, 9, 82, 10 };
	//int arr[] = { 15, 45, 100, 80, 1 , 0, 1 , 15, 15 };
	int n = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < n; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	sortMerge(arr, 0, n);
	for (int i = 0; i < n; i++)
		std::cout << arr[i] << " ";
}

