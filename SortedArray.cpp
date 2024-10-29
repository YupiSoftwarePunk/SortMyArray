#include <iostream>
#include <Windows.h>

// Функции для сортировки быстрым методом
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);


void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	// Сортировка массива выбором
	int arr[]{10, 5, 2, 7, 1, 3, 6, 9, 4, 0};
	int size = 10;
	int minIndex = 0;

	std::cout << "--------------------------------------------------------------------------\n";
	std::cout << "Несортированный массив: \n";

	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << "\t";
	}


	std::cout << "\n\n--------------------------------------------------------------------------\n";
	std::cout << "\nСортировка выбором" << "\n\n";
	std::cout << "\n--------------------------------------------------------------------------\n";
	std::cout << "Отсортированный массив выбором: \n";


	for (int i = 0; i < size; i++)
	{
		int minIdx = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[minIdx])
			{
				minIdx = j;
			}
		}
		std::swap(arr[minIdx], arr[i]);
	}

	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << "\t";
	}


	std::cout << "\n\n\n";




	// Сортировка вставками


	int arr2[]{ 100, 300, 9, 0, 1, 888, 4, 7,  32, 28 };
	int size2 = 10;

	std::cout << "\n\n--------------------------------------------------------------------------\n";
	std::cout << "Несортированный массив: \n";

	for (int i = 0; i < size2; i++)
	{
		std::cout << arr2[i] << "\t";
	}

	std::cout << "\n\n--------------------------------------------------------------------------\n";
	std::cout << "\nСортировка вставками" << "\n\n";
	std::cout << "\n--------------------------------------------------------------------------\n";
	std::cout << "Отсортированный массив вставками: \n";


	for (int i = 1; i < size2; i++)
	{
		int key = arr2[i];
		int j = i - 1;
		while (j >= 0 && arr2[j] > key)
		{
			arr2[j + 1] = arr2[j];
			j--;
		}
		arr2[j + 1] = key;
	}

	for (int i = 0; i < size2; i++)
	{
		std::cout << arr2[i] << "\t";
	}



	std::cout << "\n\n\n";



	// Сортировка быстрым методом

	int arr3[]{ 99, 0, 88, 11, -100, 5, 8, 7, 2, 10 };
	int size3 = 10;


	std::cout << "\n\n--------------------------------------------------------------------------\n";
	std::cout << "Несортированный массив: \n";

	for (int i = 0; i < size3; i++)
	{
		std::cout << arr3[i] << "\t";
	}


	std::cout << "\n--------------------------------------------------------------------------\n";
	std::cout << "\nСортировка быстрым методом" << "\n\n";
	std::cout << "\n--------------------------------------------------------------------------\n";
	std::cout << "Отсортированный массив быстрым методом: \n";


	quickSort(arr3, 0, size3 - 1);

	for (int i = 0; i < size3; i++)
	{
		std::cout << arr3[i] << "\t";
	}
	std::cout << "\n";
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);
	for (int j = low; j < high; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			std::swap(arr[i], arr[j]);
		}
	}
	std::swap(arr[i + 1], arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}