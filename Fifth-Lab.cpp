#include <iostream>
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

/*9 Вариант*/
/*Дана матрица размером NxM. Упорядочить ее столбцы по возрастанию
их наименьших элементов*/

/*10 Вариант*/
/*Определить, является ли заданная квадратная матрица n-го порядка
симметричной относительно побочной диагонали*/

/*11 Вариант*/
/*Для матрицы размером NxM вывести на экран все седловые точки.
Элемент матрицы называется седловой точкой, если он является наименьшим в
своей строке и одновременно наибольшим в своем столбце или наоборот*/

/*12 Вариант*/
/*В матрице размером NxM переставить строки так, чтобы на главной
диагонали матрицы были расположены элементы, наибольшие по абсолютной
величине*/

/*13 Вариант*/
/*В матрице размером NxM найти максимальный среди элементов,
лежащих ниже побочной диагонали, и минимальный среди элементов, лежащих
выше главной диагонали*/

/*14 Вариант*/
/*В матрице размером NxM поменять местами строку, 
одержащую элемент с наибольшим значением, со строкой,
содержащей элемент с наименьшим значением*/

/*15 Вариант*/
/*Из матрицы размером NxM получить матрицу размером (N–1) x (M–1)
путем удаления из исходной матрицы строки и столбца, 
на пересечении которых расположен элемент с наибольшим по модулю значением*/