#include <iostream>

using namespace std;

void Asc(int &first, int &second) {
	if (first > second) {
		swap(first, second);
	}
}

void Dec(int &first, int &second) {
	if (first < second) {
		swap(first, second);
	}
}

void sort(int *&array, const int &size, void(*pSort)(int &, int &)) {
	for (int i = 0; i < size - 1; i++)
		for (int j = i + 1; j < size; j++)
			pSort(array[i], array[j]);
}

void printf(int *array, const int size) {
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;
}

void main() {
	//adress of function
	cout << main << endl;

	int *i_Array = new int[10];
	int n_Array = 10;
	for (int i = 0; i < n_Array; i++)
		i_Array[i] = i + 1;

	//sort Asc
	sort(i_Array, n_Array, Asc);
	printf(i_Array, n_Array);
	//sort Dec
	sort(i_Array, n_Array, Dec);
	printf(i_Array, n_Array);

	//deletePointer
	delete[] i_Array;
	i_Array = NULL;

	system("pause");
}