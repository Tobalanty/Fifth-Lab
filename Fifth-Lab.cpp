﻿#include <iostream>
#include "cinClear.h" //Для проверки ввода с клавиатуры

/*1 Вариант*/
/*Задана матрица размером NxM. Получить массив B, присвоив его k-му
элементу значение 0, если все элементы k-го столбца матрицы нулевые,
и значение 1 − в противном случае*/
/*int main()
{
	int n;								//Ввод количества строк			
	while (true) {
		std::cout << "Input N: ";
		std::cin >> n;
		if (cinClear()) {				//Проверка ввода
			break;
		}
	}

	int m;								//Ввод количества столбцов
	while (true) {
		std::cout << "Input M: ";
		std::cin >> m;
		if (cinClear()) {
			break;
		}
	}

	int **array = new int*[n];			//Объявление двумерного динамического массива

	for (int i = 0; i < n; ++i) {
		array[i] = new int[m];
	}

	int* arrayB = new int[m] {};	//Объявление массива, хранящего результат проверки матрицы

	std::cout << "fill the array with integers.\n";	
	
	for (int i = 0;i < n; ++i) {				//Заполнение матрицы с клавиатуры
		for (int j = 0; j < m; ++j) {
			while (true) {
				std::cin >> array[i][j];
				if (cinClear()) {
					break;
				}
			}
		}
	}

	for (int i = 0; i < n; ++i) {					//Вывод матрицы в понятном виде
		for (int j = 0; j < m; ++j) {
			std::cout << array[i][j] << " ";
		}
		std::cout << std::endl;
	}


	for (int j = 0; j < n; ++j) {				//Проверка матрицы соглсано условию
		for (int i = 0; i < m; ++i) {
			if (array[i][j] != 0) {
				arrayB[j] = 1;
				break;
			}
		}
	}

	std::cout << "arrayB now:\n";				//Вывод массива-результата
	for (int j = 0; j < m; ++j) {
		std::cout << arrayB[j] << "\n";
	}

	for(int i = 0; i < n; ++i){				//Освобождение памяти
	delete []array[i];
	}
	delete []array;
	delete []arrayB;

	system("pause");
	return 0;
}*/
/*2 Вариант*/
/*Задана матрица размером NxM. Получить массив B, присвоив его k-му
элементу значение 1, если элементы k-й строки матрицы упорядочены по убыванию, 
и значение 0 − в противном случае*/
/*int main() {

	int n;								//Ввод количества строк			
	while (true) {
		std::cout << "Input N: ";
		std::cin >> n;
		if (cinClear()) {				//Проверка ввода
			break;
		}
	}

	int m;								//Ввод количества столбцов
	while (true) {
		std::cout << "Input M: ";
		std::cin >> m;
		if (cinClear()) {
			break;
		}
	}

	int** array = new int* [n];				//Объявление думмерного динамического массива (матрицы)

	for (int i = 0; i < n; ++i) {
		array[i] = new int[m];
	}

	int *arrayB = new int[n] {};			//Массив, хранящий результат проверки на упорядоченность строк

	std::cout << "fill the array with integers.\n";		//Заполнение матрицы с клавиатуры

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			while (true) {
				std::cin >> array[i][j];
				if (cinClear()) {
					break;
				}
			}
		}
	}

	for (int i = 0; i < n; ++i) {					//Проверка на упорядоченность

		bool k{true};

		for (int j = 0; j < m-1; ++j) {
			if (array[i][j] < array[i][j + 1]) {
				k = false;
				break;
			}
		}
		if (k) {
			arrayB[i] = 1;
		}
	}

	std::cout << "arrayB now:\n";					//Вывод массива-результата
	for (int i = 0; i < n; ++i) {
		std::cout << arrayB[i] << "\n";
	}

	for(int i = 0; i < n; ++i){				//Освобождение памяти
	delete []array[i];
	}
	delete []array;
	delete []arrayB;

	system("pause");
	return 0;
}*/
/*3 Вариант*/
/*Задана матрица размером NxM. Получить массив B, присвоив его k-му
элементу значение 1, если k-я строка матрицы симметрична, и значение 0 − в
противном случае*/
/*int main() {

	int n;								//Ввод количества строк			
	while (true) {
		std::cout << "Input N: ";
		std::cin >> n;
		if (cinClear()) {				//Проверка ввода
			break;
		}
	}

	int m;								//Ввод количества столбцов
	while (true) {
		std::cout << "Input M: ";
		std::cin >> m;
		if (cinClear()) {
			break;
		}
	}

	int **array = new int*[n];			//Объявление двумерного динамического массива (матрицы)
	for (int i = 0; i < n; ++i) {
		array[i] = new int[m];
	}

	std::cout << "Fill the array with integer: ";		

	for (int i = 0; i < n; ++i) {		//Заполнение матрицы пользователем
		for (int j = 0; j < m; ++j) {
			while (true) {
				std::cin >> array[i][j];
				if (cinClear()) {
					break;
				}
			}
		}
	}

	std::cout << "Your array: \n";				//Вывод матрицы в понятном виде

	for (int i = 0; i < n; ++i) {				
		for (int j = 0; j < m; ++j) {
			std::cout << array[i][j] << " ";
		}
		std::cout << "\n";
	}

	bool* arrayB = new bool[n]{};			//Обявление одномерного динамического массива, хранящего результат проверки на симметрию строк матрицы array

	for (int i = 0; i < n; ++i) {

		bool k = true;

		for (int j = 0; j < m/2; ++j) {					//Сама проверка
			if (array[i][m - j - 1] != array[i][j]) {
				k = false;
				break;
			}
		}
		if (k) {
			arrayB[i] = true;
		}
	}
	
	std::cout << "arrayB now:\n";				//Вывод массива-результата проверки на симметричность
	for (int i = 0; i < n; ++i) {
		std::cout << arrayB[i] << " ";
	}

	for (int i = 0; i < n; ++i) {			//Освобождение памяти
		delete[]array[i];
	}
	delete[]array;
	delete[]arrayB;

	system("pause");
	return 0;
}*/
/*4 Вариант*/
/* Задана матрица размером NxM. Определить количество «особых» элементов матрицы, 
считая элемент «особым», если он больше суммы остальных
элементов своего столбца*/
/*int main() {

	int n;								//Ввод количества строк			
	while (true) {
		std::cout << "Input N: ";
		std::cin >> n;
		if (cinClear()) {				//Проверка ввода
			break;
		}
	}

	int m;								//Ввод количества столбцов
	while (true) {
		std::cout << "Input M: ";
		std::cin >> m;
		if (cinClear()) {
			break;
		}
	}

	int **array = new int *[n];			//Объявление двумерного динамического массива 
	for (int i = 0; i < n; ++i) {
		array[i] = new int[m];
	}

	std::cout << "Fill the matrix with integers: \n";	//Заполнение полученной матрицы значениями введёнными пользователем
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			while (true) {
				std::cin >> array[i][j];
				if (cinClear()) {
					break;
				}
			}
		}
	}

	int *sum = new int[m]{};				//Одномерный массив для хранения суммы каждого столбца матрицы

	for (int j = 0; j < m; ++j) {			//Запись суммы каждого столбца матрицы в элемент под соответствующим номером массива sum
		for (int i = 0; i < n; ++i) {
			sum[j] += array[i][j];
		}
	}

	int k{ 0 };								//Переменная, хранящая количество "особых" элементов

	for (int j = 0; j < m; ++j) {						//Поиск "особых" элементов и увеличение счётчика k на 1 при нахождении такого
		for (int i = 0; i < n; ++i) {
			if (array[i][j] > (sum[j] - array[i][j])) {	
				k++;
			}
		}
	}

	std::cout << "Your matrix is: \n";				//Вывод исходной матрицы в понятном виде
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cout << array[i][j] << " ";
		}
		std::cout << std::endl;
	}

	delete []sum;							//Освобождение памяти
	for (int i = 0; i < n; ++i) {
		delete []array[i];
	}
	delete []array;

	std::cout << "There are " << k << " 'special' elements in this matrix.\n";

	system("pause");
	return 0;
}*/
/*5 Вариант*/
/* Задана матрица размером NxM. Определить количество «особых» элементов матрицы, 
считая элемент «особым», если в строке слева от него находятся элементы, меньшие его, 
а справа – большие*/
/*int main() {

	int n;								//Ввод количества строк			
	while (true) {
		std::cout << "Input N: ";
		std::cin >> n;
		if (cinClear()) {				//Проверка ввода
			break;
		}
	}

	int m;								//Ввод количества столбцов
	while (true) {
		std::cout << "Input M: ";
		std::cin >> m;
		if (cinClear()) {
			break;
		}
	}

	int** array = new int* [n];			//Объявление двумерного динамического массива 
	for (int i = 0; i < n; ++i) {
		array[i] = new int[m];
	}

	std::cout << "Fill the matrix with integers: \n";	//Заполнение полученной матрицы значениями введёнными пользователем
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			while (true) {
				std::cin >> array[i][j];
				if (cinClear()) {
					break;
				}
			}
		}
	}

	std::cout << "Your matrix is: \n";				//Вывод исходной матрицы в понятном виде
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cout << array[i][j] << " ";
		}
		std::cout << std::endl;
	}

	bool leftside, rightside;
	int k{ 0 };

	for (int i = 0; i < n; ++i) {								//Циклы для итераций по массиву(проходимся по всем строкам, не затрагивая крайние элементы)
		for (int j = 1; j < (m - 1); ++j) {

			for (int left = 0; left < j; ++left) {				//Проверяем элементы слева от текущего
				if (array[i][j] <= array[i][left]) {
					leftside = false;
					break;
				}
				leftside = true;
			}

			for (int right = j+1; right < m; ++right) {			//Проверяем элементы справа от текущего
				if (array[i][j] >= array[i][right]) {
					rightside = false;
					break;
				}
				rightside = true;
			}

			if (leftside & rightside) {						//Если результат обеих проверок положительный, то увеличиваем счётчик на 1
				++k;
			}
		}
	}
	
	std::cout << "There are " << k << " 'special' elements in your matrix.\n";

	for (int i = 0; i < n; ++i) {			//Освобождение памяти
		delete[]array[i];
	}
	delete[]array;

	system("pause");
	return 0;
}*/
/*6 Вариант*/
/*Задана символьная матрица размером NxM.
Определить количество различных элементов матрицы (т.е. повторяющиеся элементы считать один раз)*/
/*int main() {


	int n;								//Ввод количества строк			
	while (true) {
		std::cout << "Input N: ";
		std::cin >> n;
		if (cinClear()) {				//Проверка ввода
			break;
		}
	}

	int m;								//Ввод количества столбцов
	while (true) {
		std::cout << "Input M: ";
		std::cin >> m;
		if (cinClear()) {
			break;
		}
	}

	char** array = new char* [n];			//Объявление двумерного динамического массива 
	for (int i = 0; i < n; ++i) {
		array[i] = new char[m];
	}

	std::cout << "Fill the matrix with integers: \n";	//Заполнение полученной матрицы значениями введёнными пользователем
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			while (true) {
				std::cin >> array[i][j];
				if (cinClear()) {
					break;
				}
			}
		}
	}

	std::cout << "Your matrix is: \n";				//Вывод исходной матрицы в понятном виде
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cout << array[i][j] << " ";
		}
		std::cout << std::endl;
	}

	int specialQuantity{ 0 };					//Хранит количество различных элементов

	for (int i = 0; i < n; ++i) {				//Для итерации по матрице
		for (int j = 0; j < m; ++j) {
		
			short k{ 0 };									//Переменная для хранения количества повторений 
			bool notSpecial{false};						//Переменная для проверки на "особенность"

			for (int ii = 0; ii < n; ++ii) {			//Для сравнения с каждым элементом матрицы
				for (int jj = 0; jj < m; ++jj) {

					if (array[i][j] == array[ii][jj]) {				//Сравниваем текущий элемент со всеми элементами матрицы (включая себя)
						++k;
					}
					if ((k >= 2) & (ii <= i) & (jj <= j)) {			//Если такой же элемент найден до текущего, не считаем его
						notSpecial = true;
						break;
					}
					else if (k >= 2) {								//Если такой же элемент найден после текущего, считаем его
						++specialQuantity;
						notSpecial = true;
						break;
					}
				}
				if (notSpecial) {									//Если был найден такой же элемент, переходим к следующему элементу
					break;
				}
			}
			if (!notSpecial) {										//Если такой же элемент не найден, увеличиваем счётчик
				++specialQuantity;
			}
		}
	}

	for (int i = 0; i < n; ++i) {			//Освобождение памяти
		delete[]array[i];
	}
	delete[]array;

	std::cout << "There are " << specialQuantity << " 'special' elements in your matrix.\n";

	system("pause");
	return 0;
}*/
/*7 Вариант*/
/*Дана матрица размером NxM. Упорядочить ее строки по возрастанию их
первых элементов*/
/*int main() {

	int n;								//Ввод количества строк			
	while (true) {
		std::cout << "Input N: ";
		std::cin >> n;
		if (cinClear()) {				//Проверка ввода
			break;
		}
	}

	int m;								//Ввод количества столбцов
	while (true) {
		std::cout << "Input M: ";
		std::cin >> m;
		if (cinClear()) {
			break;
		}
	}

	int** array = new int* [n];			//Объявление двумерного динамического массива 
	for (int i = 0; i < n; ++i) {
		array[i] = new int[m];
	}

	std::cout << "Fill the matrix with integers: \n";	//Заполнение полученной матрицы значениями введёнными пользователем
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			while (true) {
				std::cin >> array[i][j];
				if (cinClear()) {
					break;
				}
			}
		}
	}

	std::cout << "Your matrix is: \n";				//Вывод исходной матрицы в понятном виде
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cout << array[i][j] << " ";
		}
		std::cout << std::endl;
	}

	//Использую сортировку пузырьком
	for (int k = 0; k < n; ++k) {

		bool earlyComplete{ true };					//Переменная, для выхода из цикла, при преждевременном завершении сортировки

		for (int i{ 0 }; i < (n - 1); ++i) {
			if (array[i + 1][0] < array[i][0]) {

				earlyComplete = false;

				int temp;
				for (int j = 0; j < m; ++j) {	

					temp = array[i][j];
					array[i][j] = array[i+1][j];
					array[i + 1][j] = temp;

				}

			}

		}
		if (earlyComplete) {
			break;
		}
	}
	

	std::cout << "Matrix ordered according to the condition: \n";			//Вывод отсортированной согласно условию матрицы
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cout << array[i][j] << " ";
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < n; ++i) {			//Освобождение памяти
		delete[]array[i];
	}
	delete[]array;

	system("pause");
	return 0;
}*/
/*8 Вариант*/
/*Дана матрица размером NxM. Упорядочить ее строки по возрастанию
суммы их элементов*/
/*int main() {

	int n;								//Ввод количества строк
	while (true) {
		std::cout << "Input N: ";
		std::cin >> n;
		if (cinClear()) {	//Проверка ввода
			break;
		}
	}

	int m;								//Ввод количества столбцов
	while (true) {
		std::cout << "Input M: ";
		std::cin >> m;
		if (cinClear()) {
			break;
		}
	}

	int** array = new int* [n];		//Объявление двумерного динамического массива
	for (int i = 0; i < n; ++i) {
		array[i] = new int[m];
	}

	std::cout << "Fill the matrix with integers: ";		//Заполнение матрицы с клавиатуры
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			while (true) {
				std::cin >> array[i][j];
				if (cinClear()) {
					break;
				}
			}
		}
	}

	std::cout << "Your matrix is: ";			//Вывод матрицы в понятном виде
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cout << array[i][j] << " ";
		}
		std::cout << std::endl;
	}

	int* sum = new int[n]{};			//Объявление динамического массива, содержащего суммы строк матрицы

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			sum[i] += array[i][j];
		}
	}

	//сортировка пузырьком
	int temp;
	for (int k = 0; k < n; ++k) {

		bool earlyComplete{ true };					//Переменная, для проверки на преждевременное завершение сортировки

		for (int i = 0; i < (n - 1); ++i) {

			if (sum[i] > sum[i + 1]) {

				temp = sum[i];
				sum[i] = sum[i + 1];
				sum[i + 1] = temp;

				for (int j = 0; j < m; ++j) {
					temp = array[i][j];
					array[i][j] = array[i + 1][j];
					array[i + 1][j] = temp;
					earlyComplete = false;
				}
			}
		}
		if (earlyComplete) {
			break;
		}
	}

	std::cout << "Matrix ordered according to the condition: \n";			//Вывод отсортированной согласно условию матрицы
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cout << array[i][j] << " ";
		}
		std::cout<<std::endl;
	}

	for (int i = 0; i < n; ++i) {		//Освобождение памяти
		delete[]array[i];
	}
	delete[]array;
	delete[]sum;
	

	system("pause");
	return 0;
}*/
/*9 Вариант*/
/*Дана матрица размером NxM. Упорядочить ее столбцы по возрастанию
их наименьших элементов*/
/*int main() {

	int n;								//Ввод количества строк
	while (true) {
		std::cout << "Input N: ";
		std::cin >> n;
		if (cinClear()) {	//Проверка ввода
			break;
		}
	}

	int m;								//Ввод количества столбцов
	while (true) {
		std::cout << "Input M: ";
		std::cin >> m;
		if (cinClear()) {
			break;
		}
	}

	int** array = new int* [n];		//Объявление двумерного динамического массива
	for (int i = 0; i < n; ++i) {
		array[i] = new int[m];
	}

	std::cout << "Fill the matrix with integers: ";		//Заполнение матрицы с клавиатуры
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			while (true) {
				std::cin >> array[i][j];
				if (cinClear()) {
					break;
				}
			}
		}
	}

	std::cout << "Your matrix is: ";			//Вывод матрицы в понятном виде
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cout << array[i][j] << " ";
		}
		std::cout << std::endl;
	}

	int* smallestElements = new int[m];				//Динамический массив, который будет содержать мминимальные элементы каждого столбца матрицы

	for (int j = 0; j < m; ++j) {					//Записываем первые элементы каждого столбца матрицы в этот массив
		smallestElements[j] = array[0][j];
	}

	for (int j = 0; j < m; ++j) {					//Находим наименьшие элементы в каждом столбце и перезаписываем массив smallestElements при необходимости
		for (int i = 0; i < n; ++i) {
			if (array[i][j] < smallestElements[j]) {
				smallestElements[j] = array[i][j];
			}
		}
	}

	//сортировка пузырьком
	int temp;								//Временная переменная для свапа
	for (int k = 0; k < m; ++k) {

		bool earlyComplete{ true };						//Переменная для выхода из цикла при преждевременном окончании сортировки
		for (int j = 0; j < (m - 1); ++j) {

			if (smallestElements[j] > smallestElements[j + 1]) {
			
				temp = smallestElements[j];							//сортируем smalestElements
				smallestElements[j] = smallestElements[j + 1];
				smallestElements[j + 1] = temp;

				for (int i = 0; i < n; ++i) {						//и матрицы array соответственно
					temp = array[i][j];
					array[i][j] = array[i][j + 1];
					array[i][j + 1] = temp;
					earlyComplete = false;
				}
			}
		}
		if (earlyComplete) {									//Завершаем цикл, если попалась "холостая" итерация
			break;
		}
	}

	std::cout << "Matrix ordered according to the condition: \n";			//Вывод отсортированной согласно условию матрицы
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cout << array[i][j] << " ";
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < n; ++i) {		//Освобождение памяти
		delete[]array[i];
	}
	delete[]array;
	delete[]smallestElements;
	

	system("pause");
	return 0;
}*/
/*10 Вариант*/
/*Определить, является ли заданная квадратная матрица n-го порядка
симметричной относительно побочной диагонали*/
/*int main() {

	int n;								//Ввод размерности матрицы
	while (true) {
		std::cout << "Input N: ";
		std::cin >> n;
		if (cinClear()) {	//Проверка ввода
			break;
		}
	}

	int** array = new int* [n];		//Объявление двумерного динамического массива
	for (int i = 0; i < n; ++i) {
		array[i] = new int[n];
	}

	std::cout << "Fill the matrix with integers: ";		//Заполнение матрицы с клавиатуры
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			while (true) {
				std::cin >> array[i][j];
				if (cinClear()) {
					break;
				}
			}
		}
	}

	std::cout << "Your matrix is: \n";			//Вывод матрицы в понятном виде
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			std::cout << array[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
	bool symmetric{ true };										//Переменная для выхода из циклов, если будут найдены не симметричные элементы
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (array[i][j] != array[n - 1 - i][n - 1 - j]) {			//Проверка на симметричность
				symmetric = false;
				break;
			}
		}
		if (!symmetric) {
			break;
		}
	}

	if (symmetric) {
		std::cout << "Your matrix is symmetric with respect to the side diagonal.\n";
	}
	else
		std::cout << "Your matrix is NOT symmetric with respect to the side diagonal.\n";

	system("pause");
	return 0;
}*/
/*11 Вариант*/
/*Для матрицы размером NxM вывести на экран все седловые точки.
Элемент матрицы называется седловой точкой, если он является наименьшим в
своей строке и одновременно наибольшим в своем столбце или наоборот*/
/*int main() {
	
	int n;										//Ввод количества строк
	while (true) {
		std::cout << "Input N: ";
		std::cin >> n;
		if (cinClear()) {
			break;
		}
	}

	int m;
	while (true) {							//Ввод количества столбцов
		std::cout << "Input M: ";
		std::cin >> m;
		if (cinClear()) {
			break;
		}
	}

	int** array = new int* [n];				//Объявление двумерного ддинамического массива
	for (int i = 0; i < n; ++i) {
		array[i] = new int[m];
	}

	std::cout << "Fill the matrix with integer: \n";						//Заполнение матрицы с клавиатуры
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			while (true) {
				std::cout << "Element " << "[" << i + 1 << ", " << j + 1 << "]: ";
				std::cin >> array[i][j];
				if (cinClear()) {
					break;
				}
			}
		}
	}

	for (int i = 0; i < n; ++i) {					//Вывод матрицы в понятном виде
		for (int j = 0; j < m; ++j) {
			std::cout << array[i][j] << "  ";
		}
		std::cout << std::endl;
	}

	int count{ 0 };

	for (int i = 0; i < n; ++i) {								//Поиск седдловых точек (min в строке/max в столбце)

		int temp{ array[i][0] };
		bool* temp_j = new bool[m] {};
		int tempJ{ 0 };

		for (int j = 1; j < m; ++j) {					//Находим минимальный элемент в строке
			if (array[i][j] < temp) {
				temp = array[i][j];
				tempJ = j;								//Записываем координату j этого элемента во временную переменную
			}
		}

		for (int j = tempJ; j < m; ++j) {				//Ищем в строке такие же элементы
			if (temp == array[i][j]) {						
				temp_j[j] = 1;							//Запоминаем координаты минимальных элементов этой строки 
			}											//(записываю true в соответствующие элементы временного массива)
		}

		for (int j = 0; j < m; ++j) {
			
			bool notSaddle{ false };				//Переменная для выхода из цикла, если не соблюдается условие седловой точки
			if (temp_j[j] != 0) {					//Идём по тем столбцам, координаты которых находятся в temp_j
				for (int ii = 0; ii < n; ++ii) {
					if (temp < array[ii][j]) {
						notSaddle = true;
						break;
					}
				}
				if (!notSaddle) {					//Если в столбце не был найден элемент, больший текущего, то выводим его на экран
					std::cout << "Element [" << i + 1 << ", " << j + 1 << "] = "
							  << temp << " is saddle point.\n";
					++count;						//Увеличиваем счётчик, хранящий количество седловых точек
				}
			}
		}

		delete[]temp_j;				//Освобождение памяти

	}

	for (int j = 0; j < m; ++j) {								//Поиск седдловых точек (max в строке/min в столбце)

		int temp{ array[0][j] };
		bool* temp_i = new bool[n] {};
		int tempI{ 0 };

		for (int i = 1; i < n; ++i) {		//Находим минимальный элемент в столбце
			if (array[i][j] < temp) {
				temp = array[i][j];
				tempI = i;					//Записываем координату i этого элемента во временную переменную
			}
		}

		for (int i = tempI; i < n; ++i) {	//Находим такие же элементы в столбце
			if (temp == array[i][j]) {
				temp_i[i] = 1;				//Запоминаем координаты минимальных элементов этого столбца
			}
		}

			for (int i = 0; i < n; ++i) {		//Чтобы седловая точка, находящаяся на пересечении строки и столбца с одинаковыми элементамм,
				if (!temp_i[i]) {					//не считалась программой второй раз, удаляем её из списка обрабатываемых точек
					break;
				}
			}
			for (int i = 0; i < n; ++i) {

				bool same_same{ true };
				for (int jj = 0; jj < m - 1; ++jj) {
					if (array[i][jj]!=array[i][jj+1]) {
						same_same = false;					
						break;
					}
				}
				if (same_same) {
					temp_i[i] = 0;
				}
			}
		

		for (int i = 0; i < n; ++i) {

			bool notSaddle{ false };			//Переменная для выхода из цикла, если не соблюдается условие седловой точки
			if (temp_i[i] != 0) {				//Идём по строкам, координаты которых записаеы в temp_i
				for (int jj = 0; jj < m; ++jj) {
					if (temp < array[i][jj]) {
						notSaddle = true;
						break;
					}
				}
				if (!notSaddle) {		//Если в строке не был найден элемент, больший текущего, то выводим его на экран
					std::cout << "Element [" << i + 1 << ", " << j + 1 << "] = "
						<< temp << " is saddle point.\n";
					++count;			//Увеличиваем счётчик, хранящий количество седловых точек
				}
			}
		}
		delete[]temp_i;			//Освобождение памяти
	}

	for (int i = 0; i < n; ++i) {	//Освобождение памяти
		delete[]array[i];
	}
	delete[]array;

	std::cout << "There are " << count << " saddle point's in this matrix.\n";

	system("pause");
	return 0;
}*/
/*12 Вариант*/
/*В матрице размером NxM переставить строки так, чтобы на главной
диагонали матрицы были расположены элементы, наибольшие по абсолютной
величине*/
/*int main() {

	int n;								//Ввод количества строк
	while (true) {
		std::cout << "Input N: ";
		std::cin >> n;
		if (cinClear()) {
			break;
		}
	}

	int m;							//Ввод количества столбцов
	while (true) {
		std::cout << "Input M: ";
		std::cin >> m;
		if (cinClear()) {
			break;
		}
	}

	int** array = new int* [n];			//Объявление двумерного динамического массива
	for (int i = 0; i < n; ++i) {
		array[i] = new int[m];
	}

	std::cout << "Fill the matrix wight integer: \n";			//Заполнение массива с клавиатуры
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {

			while (true) {
				std::cout << "Element [" << i + 1 << ", " << j + 1 << "]: ";
				std::cin >> array[i][j];
				if (cinClear()) {
					break;
				}

			}
		}
	}

	for (int i = 0; i < n; ++i) {				//Вывод исходного массива
		for (int j = 0; j < m; ++j) {
			std::cout << array[i][j] << "   ";
		}
		std::cout << std::endl;
	}

	for (int k = 0; k < n; ++k) {						//Сортируем строки

		bool complete{ true };		//Для выхода, если сортировка закончилась до прогона n раз
		for (int i = 0; i < n; ++i) {

			int max = array[i][0], temp_j = 0, temp;
			for (int j = 1; j < m; ++j) {				//Ищу максимальный по модулю элемент в строке
				if (abs(max) < abs(array[i][j])) {
					max = array[i][j];
					temp_j = j;
				}
			}

			if (temp_j != i) {						//Перемещаю строку с этим элементом на ту строку, номер которой равен номеру столбца этого элемента
				for (int j = 0; j < m; ++j) {
					temp = array[i][j];
					array[i][j] = array[temp_j][j];
					array[temp_j][j] = temp;
					complete = false;
				}
			}
		}
		if (complete) {			//Если за n итераций никакие строки не поменялись, то выходим из сортировки
			break;
		}
	}

	std::cout << "New matrix: \n";					//Вывод отсортированной матрицы
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cout << array[i][j] << "   ";
		}
		std::cout << std::endl;
	}
	
	for (int i = 0; i < n; ++i) {	//Освобождение памяти
		delete[]array[i];
	}
	delete[]array;

	system("pause");
	return 0;
}*/
/*13 Вариант*/
/*В матрице размером NxM найти максимальный среди элементов,
лежащих ниже побочной диагонали, и минимальный среди элементов, лежащих
выше главной диагонали*/
/*int main() {
	
	int n;								//Ввод количества строк
	while (true) {
		std::cout << "Input N: ";
		std::cin >> n;
		if (cinClear()) {
			break;
		}
	}

	int m;								//Ввод количества столбцов
	while (true) {
		std::cout << "Input M: ";
		std::cin >> m;
		if (cinClear()) {
			break;
		}
	}

	int** array = new int* [n];				//Объявление двумерного динамического массива (матрицы)
	for (int i = 0; i < n; ++i) {
		array[i] = new int[m];
	}

	std::cout << "Fill the matrix with integer: \n";						//Заполнение матрицы с клавиатуры
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cout << "Element [" << i + 1 << ", " << j + 1 << "]: ";
			while (true) {
				std::cin >> array[i][j];
				if (cinClear()) {
					break;
				}
			}
		}
	}

	std::cout << "Your matrix: \n";					//Вывод матрицы в понятном виде
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cout << array[i][j] << "  ";
		}
		std::cout << std::endl;
	}
	
	int k = 1;
	int temp{ array[0][1] };
	for (int i = 0; i < n; ++i) {					//Поиск минимального среди элементов выше главной диагонали

		for (int j = k; j < m; ++j) {
			if (array[i][j] < temp) {
				temp = array[i][j];
			}
		}
		++k;
		if (k >= m) {
			break;
		}
	}
	std::cout << "Minimum element among elements above the main diagonal: " << temp << std::endl;
	
	k = m - 1;
	temp = array[1][m - 1];
	for (int i = 1; i < n; ++i) {						//Поиск максимального среди элементов ниже побочной диагонали
		for (int j = k; j < m; ++j) {
			if (array[i][j] > temp) {
				temp = array[i][j];
			}
		}
		if (k > 0) {
			--k;
		}
	}
	std::cout << "Maximum element among elements below the secondary diagonal: " << temp << std::endl;
	
	for (int i = 0; i < n; ++i) {		//Освобождение памяти
		delete[]array[i];
	}
	delete[]array;

	system("pause");
	return 0;
}*/
/*14 Вариант*/
/*В матрице размером NxM поменять местами строку, 
cодержащую элемент с наибольшим значением, со строкой,
содержащей элемент с наименьшим значением*/
/*int main() {

	int n;								//Ввод количества строк
	while (true) {
		std::cout << "Input N: ";
		std::cin >> n;
		if (cinClear()) {
			break;
		}
	}

	int m;								//Ввод количества столбцов
	while (true) {
		std::cout << "Input M: ";
		std::cin >> m;
		if (cinClear()) {
			break;
		}
	}

	int** array = new int* [n];				//Объявление двумерного динамического массива (матрицы)
	for (int i = 0; i < n; ++i) {
		array[i] = new int[m];
	}

	std::cout << "Fill the matrix with integer: \n";						//Заполнение матрицы с клавиатуры
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cout << "Element [" << i + 1 << ", " << j + 1 << "]: ";
			while (true) {
				std::cin >> array[i][j];
				if (cinClear()) {
					break;
				}
			}
		}
	}

	std::cout << "Your matrix: \n";					//Вывод матрицы в понятном виде
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cout << array[i][j] << "  ";
		}
		std::cout << std::endl;
	}

	int min_i = 0, max_i = 0;
	int temp_min = array[0][0], temp_max = array[0][0];
	for (int i = 0; i < n; ++i) {					//Поиск максимального и минимального элементов и запоминание их строк
		for (int j = 0; j < m; ++j) {
			if (array[i][j] > temp_max) {
				temp_max = array[i][j];
				max_i = i;
			}

			if (array[i][j] < temp_min) {
				temp_min = array[i][j];
				min_i = i;
			}
		}
	}

	for (int j = 0; j < m; ++j) {			//Меняем строки местами
		int temp{ array[min_i][j] };
		array[min_i][j] = array[max_i][j];
		array[max_i][j] = temp;
	}

	std::cout << "New matrix: \n";					//Вывод новой матрицы в понятном виде
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cout << array[i][j] << "  ";
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < n; ++i) {		//Освобождение памяти
		delete[]array[i];
	}
	delete[]array;

	system("pause");
	return 0;
}*/
/*15 Вариант*/
/*Из матрицы размером NxM получить матрицу размером (N–1) x (M–1)
путем удаления из исходной матрицы строки и столбца, 
на пересечении которых расположен элемент с наибольшим по модулю значением*/
/*int main() {

	int n;								//Ввод количества строк
	while (true) {
		std::cout << "Input N: ";
		std::cin >> n;
		if (cinClear()) {
			break;
		}
	}

	int m;								//Ввод количества столбцов
	while (true) {
		std::cout << "Input M: ";
		std::cin >> m;
		if (cinClear()) {
			break;
		}
	}

	int** array = new int* [n];				//Объявление двумерного динамического массива (матрицы)
	for (int i = 0; i < n; ++i) {
		array[i] = new int[m];
	}

	std::cout << "Fill the matrix with integer: \n";						//Заполнение матрицы с клавиатуры
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cout << "Element [" << i + 1 << ", " << j + 1 << "]: ";
			while (true) {
				std::cin >> array[i][j];
				if (cinClear()) {
					break;
				}
			}
		}
	}

	std::cout << "Your matrix: \n";					//Вывод матрицы в понятном виде
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cout << array[i][j] << "  ";
		}
		std::cout << std::endl;
	}

	int max{ array[0][0] }, temp_i = 0, temp_j = 0;		//Поиск максимального по мудлю значения
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (abs(array[i][j]) > abs(max)) {
				max = array[i][j];
				temp_i = i;
				temp_j = j;
			}
		}
	}

	for (int i = temp_i; i < n - 1; ++i) {			//Смещение строк
		for (int j = 0; j < m; ++j) {
			array[i][j] = array[i + 1][j];
		}
	}

	for (int i = 0; i < n; ++i) {					//Смещение столбцов
		for (int j = temp_j; j < m-1; ++j) {
			array[i][j] = array[i][j + 1];
		}
	}

	std::cout << "New matrix: \n";					//Вывод новой матрицы
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < m - 1; ++j) {
			std::cout << array[i][j] << "  ";
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < n; ++i) {		//Освобождение памяти
		delete[]array[i];
	}
	delete[]array;

	system("pause");
	return 0;
}*/