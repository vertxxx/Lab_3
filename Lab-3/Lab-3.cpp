#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
using namespace std;

const int N1 = 6;
const int N2 = 8;
const int N3 = 10;

void actionMenu(int* array, int N);
void menu(int* pArr, int SIZE);

void fillZeroMatrix(int* array, int N)
{
	int* end = array + N * N - 1;
	for (int* i = array; i <= end; i++) {
		*i = 0;
	}
}

void printMatrix(int* array, int N)
{
	int* end = array + N * N - 1;
	for (int* i = array; i <= end; i++) {
		cout << setw(4) << *i;
		if ((i - array + 1) % N == 0) {
			cout << '\n';
		}
	}
}

void createNewMatrix(int* array, int N)
{
	int* end = array + N * N - 1;
	for (int* i = array; i <= end; i++) {
		*i = rand() % (N * N) + 1;
	}
}

void fillSpiralMatrix(int* array, int N)
{
	fillZeroMatrix(array, N);
	printMatrix(array, N);
	for (int i = 0; i < N / 2; i++) {
		int* pTopLeft = array + i * (N + 1);
		int* pTopRight = array + i * (N - 1) + (N - 1);
		int* pBottomRight = array + (N * N - 1) - i * (N + 1);
		int* pBottomLeft = array + (N * N - N) - i * (N - 1);
		for (int* j = pTopLeft; j < pTopRight; j++) {
			*j = rand() % (N * N) + 1;
			system("cls");
			printMatrix(array, N);
			Sleep(50);
		}
		for (int* j = pTopRight; j < pBottomRight; j += N) {
			*j = rand() % (N * N) + 1;
			system("cls");
			printMatrix(array, N);
			Sleep(50);
		}
		for (int* j = pBottomRight; j > pBottomLeft; j--) {
			*j = rand() % (N * N) + 1;
			system("cls");
			printMatrix(array, N);
			Sleep(50);
		}
		for (int* j = pBottomLeft; j > pTopLeft; j -= N) {
			*j = rand() % (N * N) + 1;
			system("cls");
			printMatrix(array, N);
			Sleep(50);
		}
	}
}

void fillSnakeMatrix(int* array, int N)
{
	fillZeroMatrix(array, N);
	printMatrix(array, N);
	for (int i = 0; i < N / 2; i++) {
		int* pUp = array + i * 2;
		int* pBottom = array + (N * N - N) + i * 2;
		int* p3 = array + (N * N - N + 1) + i * 2;
		int* p4 = array + 1 + i * 2;
		for (int* j = pUp; j <= pBottom; j += N) {
			*j = rand() % (N * N) + 1;
			system("cls");
			printMatrix(array, N);
			Sleep(50);
		}
		for (int* j = p3; j >= p4; j -= N) {
			*j = rand() % (N * N) + 1;
			system("cls");
			printMatrix(array, N);
			Sleep(50);
		}
	}
}

void createBlocks(int* array, int N)
{
	int* end = array + N * N - 1;
	int* start = array + N / 2 - 1;
	int* mid = array + (N * N / 2) - 1;
	cout << "\n\n";
	for (int* i = array; i <= end; i++) {
		cout << setw(4) << *i;
		if (((i - array + 1) % (N / 2) == 0) && ((i - array + 1) % N != 0)) {
			cout << "\t";
		}
		if (((i - array + 1) % ((N * N) / 2) == 0) && ((i - array + 1) % (N * N) != 0)) {
			cout << "\n" << " ";
		}
		if ((i - array + 1) % N == 0) {
			cout << '\n';
		}
	}
}

void swapBlocksSequentially(int* array, int N)
{
	for (int i = 0; i < (N * N / 4); i++) {
		int* ptr1 = array + (i / (N / 2)) * N + (i % (N / 2));
		int* ptr2 = ptr1 + (N / 2);
		int* ptr4 = ptr2 + (N / 2) * N;
		int* ptr3 = ptr4 - (N / 2);

		int temp = *ptr2;
		*ptr2 = *ptr1;
		int temp1 = *ptr4;
		*ptr4 = temp;
		temp = *ptr3;
		*ptr3 = temp1;
		*ptr1 = temp;
	}
	createBlocks(array, N);
}

void swapBlocksDiagonally(int* array, int N)
{
	for (int i = 0; i < (N * N / 4); i++) {
		int* ptr1 = array + (i / (N / 2)) * N + (i % (N / 2));
		int* ptr2 = ptr1 + (N / 2);
		int* ptr4 = ptr2 + (N / 2) * N;
		int* ptr3 = ptr4 - (N / 2);
		swap(*ptr1, *ptr4);
		swap(*ptr2, *ptr3);
	}
	createBlocks(array, N);
}

void swapBlocksVertically(int* array, int N)
{
	for (int i = 0; i < (N * N / 4); i++) {
		int* ptr1 = array + (i / (N / 2)) * N + (i % (N / 2));
		int* ptr2 = ptr1 + (N / 2);
		int* ptr4 = ptr2 + (N / 2) * N;
		int* ptr3 = ptr4 - (N / 2);
		swap(*ptr1, *ptr3);
		swap(*ptr2, *ptr4);
	}
	createBlocks(array, N);
}

void swapBlocksHorizontally(int* array, int N)
{
	for (int i = 0; i < (N * N / 4); i++) {
		int* ptr1 = array + (i / (N / 2)) * N + (i % (N / 2));
		int* ptr2 = ptr1 + (N / 2);
		int* ptr4 = ptr2 + (N / 2) * N;
		int* ptr3 = ptr4 - (N / 2);
		swap(*ptr1, *ptr2);
		swap(*ptr3, *ptr4);
	}
	createBlocks(array, N);
}

void sequentialExample()
{
	cout << "\nПоменять местами блоки следующим образом:\n"
		<< "\t --------------\n"
		<< "\t|  1  --->  2  |\n"
		<< "\t|  ^        |  |\n"
		<< "\t|  |        |  |\n"
		<< "\t|  |        v  |\n"
		<< "\t|  3  <---  4  |\n"
		<< "\t --------------";
}

void diagonalExample()
{
	cout << "\nПоменять местами блоки: 1 с 4 и 2 с 3, где:\n"
		<< "\t --------------\n"
		<< "\t|  1        2  |\n"
		<< "\t|              |\n"
		<< "\t|       X      |\n"
		<< "\t|              |\n"
		<< "\t|  3        4  |\n"
		<< "\t --------------";
}

void veticalExample()
{
	cout << "\nПоменять местами блоки: 1 с 3 и 2 с 4, где:\n"
		<< "\t --------------\n"
		<< "\t|  1        2  |\n"
		<< "\t|              |\n"
		<< "\t|  |        |  |\n"
		<< "\t|              |\n"
		<< "\t|  3        4  |\n"
		<< "\t --------------";
}

void horizontalExample()
{
	cout << "\nПоменять местами блоки: 1 со 2 и 3 с 4, где:\n"
		<< "\t --------------\n"
		<< "\t|  1  <-->  2  |\n"
		<< "\t|              |\n"
		<< "\t|              |\n"
		<< "\t|              |\n"
		<< "\t|  3  <-->  4  |\n"
		<< "\t --------------";
}

void sizeOfMAtrix();

void increaseMatrixByNumber(int* array, int N, int value)
{
	int* end = array + N * N - 1;
	for (int* i = array; i <= end; i++) {
		*i += value;
	}
}

void reduceMatrixByNumber(int* array, int N, int value)
{
	int* end = array + N * N - 1;
	for (int* i = array; i <= end; i++) {
		*i -= value;
	}
}

void divMatrix(int* array, int N, int value)
{
	int* end = array + N * N - 1;
	for (int* i = array; i <= end; i++) {
		*i /= value;
	}
}

void multMatrix(int* array, int N, int value)
{

	int* end = array + N * N - 1;
	for (int* i = array; i <= end; i++) {
		*i *= value;
	}
}

void combSort1(int* array, int N)
{
	int* end = array + N * N - 1;
	float k = 1.247;
	int gap = *end;
	while (gap >= 1)
	{
		for (int* i = array; i + gap <= end; i++) {
			if (*i > *(i + gap)) {
				swap(*i, *(i + gap));
			}
		}
		gap /= k;
	}
}

void returnToMenu(int* array, int N) 
{
	int choiceMenu;
	{
		cout << "Продолжить выполнение действий с измененной матрицей?\n"
			<< "1 - Да\t\t2 - Нет\n";
	}
	cin >> choiceMenu;
	switch (choiceMenu)
	{
	case 1:
		system("cls");
		actionMenu(array, N);
		break;
	case 2:
		system("cls");
		menu(array, N);
		break;
	default:
		cout << "\nОшибка!Попробуйте снова\n";
		_getch();
		system("cls");
		returnToMenu(array, N);
		break;
	}
}

void actionMenu(int* array, int N)
{
	int value;
	cout << "Введите число: ";
	cin >> value;
	printMatrix(array, N);
	int chooseAction;
	{
		cout << "\nВыберите действие:\n"
			<< "1 - увеличивает все элементы матрицы на введенное число\n"
			<< "2 - уменьшает все элементы матрицы на введенное число\n"
			<< "3 - умножает все элементы матрицы на введенное число\n"
			<< "4 - делит все элементы матрицы на введенное число\n"
			<< "5 - Вернуться в главное меню\n\n";
	}
	cin >> chooseAction;
	switch (chooseAction)
	{
	case 1:
		increaseMatrixByNumber(array, N, value);
		printMatrix(array, N);
		_getch();
		system("cls");
		returnToMenu(array, N);
		break;
	case 2:
		reduceMatrixByNumber(array, N, value);
		printMatrix(array, N);
		_getch();
		system("cls");
		returnToMenu(array, N);
		break;
	case 3:
		multMatrix(array, N, value);
		printMatrix(array, N);
		_getch();
		system("cls");
		returnToMenu(array, N);
		break;
	case 4:
		divMatrix(array, N, value);
		printMatrix(array, N);
		_getch();
		system("cls");
		returnToMenu(array, N);
		break;
	case 5:
		system("cls");
		menu(array, N);
		break;
	default:
		cout << "\nОшибка!Попробуйте снова\n";
		_getch();
		system("cls");
		actionMenu(array, N);
		break;
	}
}

void createIDZMatrix(int* array, int N)
{
	int* end = array + N * N - 1;
	for (int* i = array; i <= end; i++) {
		*i = rand() % 60 - 30;
	}
}

void findDet(int* array, int N)
{
	createIDZMatrix(array, N);
	printMatrix(array, N);

	int term1 = *array * *(array + 4) * *(array + 8);
	int term2 = *(array + 1) * *(array + 5) * *(array + 6);
	int term3 = *(array + 2) * *(array + 3) * *(array + 7);
	int term4 = *(array + 2) * *(array + 4) * *(array + 6);
	int term5 = *(array + 1) * *(array + 3) * *(array + 8);
	int term6 = *array * *(array + 5) * *(array + 7);
	cout << "\n(" << term1 << ")";
	Sleep(500);
	cout << " + ";
	cout << "(" << term2 << ")";
	Sleep(500);
	cout << " + ";
	cout << "(" << term3 << ")";
	Sleep(500);
	cout << " + ";
	cout << "(" << term4 << ")";
	Sleep(500);
	cout << " + ";
	cout << "(" << term5 << ")";
	Sleep(500);
	cout << " + ";
	cout << "(" << term6 << ")";
	Sleep(500);
	cout << " = ";

	int determinant = term1 + term2 + term3 - term4 - term5 - term6;
	cout << determinant << "\n\nОпределитель = " << determinant << "\n\n";
}

void idz(int* array, int N)
{
	system("cls");
	cout << "ИДЗ: создать матрицу 3х3 и найти ее определитель\n\n";
	createIDZMatrix(array, N);
	printMatrix(array, N);
	findDet(array, N);
	cout << "\n\nЧтобы вернуться к выбору размера матрицы, нажмите любую клавишу...\n";
	_getch();
	system("cls");
	sizeOfMAtrix();
}

void menu(int* pArr, int SIZE)
{
	setlocale(LC_ALL, "RU");
	int mainMenu;
	{
		cout << "Главное меню:\n\nКакой пункт вы хотите выбрать?\n"
			<< "1 - Заполнить матрицу по спирали\n"
			<< "2 - Заполнить матрицу змейкой\n"
			<< "3 - Переставить блоки матрицы последовательно\n"
			<< "4 - Переставить диагональные блоки матрицы\n"
			<< "5 - Переставить вертикальные блоки матрицы\n"
			<< "6 - Переставить горизонтальные блоки матрицы\n"
			<< "7 - Сортировка матрицы\n"
			<< "8 - Арифметические операции с матрицей\n"
			<< "9 - Поменять размер матрицы\n"
			<< "0 - Выход\n";
	}
	cin >> mainMenu;
	switch (mainMenu)
	{
	case 1:
		system("cls");
		fillSpiralMatrix(pArr, SIZE);
		cout << "\nНажмите любую клавишу, чтобы вернуться в меню...\n";
		_getch();
		system("cls");
		menu(pArr, SIZE);
		break;
	case 2:
		system("cls");
		fillSnakeMatrix(pArr, SIZE);
		cout << "\nНажмите любую клавишу, чтобы вернуться в меню...\n";
		_getch();
		system("cls");
		menu(pArr, SIZE);
		break;
	case 3:
		system("cls");
		createNewMatrix(pArr, SIZE);
		createBlocks(pArr, SIZE);
		sequentialExample();
		swapBlocksSequentially(pArr, SIZE);
		cout << "\nНажмите любую клавишу, чтобы вернуться в меню...\n";
		_getch();
		system("cls");
		menu(pArr, SIZE);
		break;
	case 4:
		system("cls");
		createNewMatrix(pArr, SIZE);
		createBlocks(pArr, SIZE);
		diagonalExample();
		swapBlocksDiagonally(pArr, SIZE);
		cout << "\nНажмите любую клавишу, чтобы вернуться в меню...\n";
		_getch();
		system("cls");
		menu(pArr, SIZE);
		break;
	case 5:
		system("cls");
		createNewMatrix(pArr, SIZE);
		createBlocks(pArr, SIZE);
		veticalExample();
		swapBlocksVertically(pArr, SIZE);
		cout << "\nНажмите любую клавишу, чтобы вернуться в меню...\n";
		_getch();
		system("cls");
		menu(pArr, SIZE);
		break;
	case 6:
		system("cls");
		createNewMatrix(pArr, SIZE);
		createBlocks(pArr, SIZE);
		horizontalExample();
		swapBlocksHorizontally(pArr, SIZE);
		cout << "\nНажмите любую клавишу, чтобы вернуться в меню...\n";
		_getch();
		system("cls");
		menu(pArr, SIZE);
		break;
	case 7:
		system("cls");
		createNewMatrix(pArr, SIZE);
		printMatrix(pArr, SIZE);
		combSort1(pArr, SIZE);
		cout << "\nОтсортированная матрица:\n";
		printMatrix(pArr, SIZE);
		cout << "\nНажмите любую клавишу, чтобы вернуться в меню...\n";
		_getch();
		system("cls");
		menu(pArr, SIZE);
		break;
	case 8:
		system("cls");
		cout << "8 пункт\n\n";
		createNewMatrix(pArr, SIZE);
		actionMenu(pArr, SIZE);
		menu(pArr, SIZE);
		break;
	case 9:
		system("cls");
		sizeOfMAtrix();
		break;
	case 0:
		system("cls");
		break;
	default:
		cout << "Ошибка! Попробуйте снова\n";
		_getch();
		system("cls");
		menu(pArr, SIZE);
		break;
	}
}

void sizeOfMAtrix()
{
	srand(time(NULL));
	const int N1 = 6, N2 = 8, N3 = 10, N_IDZ = 3;
	int arr1[N1][N1], arr2[N2][N2], arr3[N3][N3], arr4[N_IDZ][N_IDZ];
	int* pArr6 = *arr1, * pArr8 = *arr2, * pArr10 = *arr3, * pArr3 = *arr4;
	int* pArr1 = *arr1;
	int* pArr2 = *arr1;
	int chooseSize;
	{
		cout << "Выберите размер матрицы для дальнейших операций (6x6, 8x8, 10x10) или 3х3 (для ИДЗ)\n";
	}
	cin >> chooseSize;
	switch (chooseSize)
	{
	case 3:
		system("cls");
		findDet(pArr3, N_IDZ);
		system("pause");
		system("cls");
		sizeOfMAtrix();
		break;
	case 6:
		system("cls");
		menu(pArr6, N1);
		break;
	case 8:
		system("cls");
		menu(pArr8, N2);
		break;
	case 10:
		system("cls");
		menu(pArr10, N3);
		break;
	default:
		cout << "Ошибка! Попробуйте снова\n";
		_getch();
		system("cls");
		sizeOfMAtrix();
		break;
	}
}

void main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	sizeOfMAtrix();
}
