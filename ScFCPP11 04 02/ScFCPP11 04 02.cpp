// ScFCPP11 04 02.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

void sortMerge(int* arr, int first, int size) {
	//for (int i = first; i < first + size; i++)
	//	std::cout << arr[i] << " ";
	//std::cout << std::endl;
	//int last = first + size - 1;
	int firstRight = first + size / 2;
	if (size > 1) {
		//std::cout << "Left: " << first << " " << size / 2 << std::endl;
		sortMerge(arr, first, size / 2);
		//std::cout << "Right: " << firstRight << " " << size - size / 2 << std::endl;
		sortMerge(arr, firstRight, size - size / 2);
		int* temp = new int[size];
		int left = first;
		int right = firstRight;
		for (int i = 0; i < size; i++)
			if (left - first >= size / 2)
				temp[i] = arr[right++];
			else if (right - firstRight >= size - size / 2)
				temp[i] = arr[left++];
			else
				temp[i] = arr[left] < arr[right] ? arr[left++] : arr[right++];
		for (int i = 0, j = first; i < size; i++, j++) {
			arr[j] = temp[i];
			//std::cout << arr[j] << " ";
		}
		//std::cout << std::endl;
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

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
