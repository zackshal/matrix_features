#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include "OuterVector.h"
#include "InnerVector.h"
#include "Utils.h"
#define NOMINMAX  // Запрещаем определение макросов min и max в Windows.h
#include <Windows.h>
#include <limits>
using namespace std;

int main() {
    // Настройка кодировки консоли для поддержки русского языка
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int rows, cols;
    cout << "Введите количество строк матрицы: ";
    cin >> rows;
    cout << "Введите количество столбцов матрицы: ";
    cin >> cols;
    cin.ignore();  // очистка символа новой строки

    OuterVector<int> matrix;

    // Ввод матрицы: для каждой строки пользователь вводит строку чисел через пробел
    for (int i = 0; i < rows; i++) {
        while (true) {
            string line;
            cout << "Введите элементы строки " << i << " через пробел (ожидается "
                << cols << " чисел): ";
            getline(cin, line);
            line = trim(line);
            if (line.empty()) {
                cout << "Строка пуста. Повторите ввод." << endl;
                continue;
            }
            istringstream iss(line);
            InnerVector<int> row;
            int number;
            int count = 0;
            while (iss >> number) {
                row.addElement(number);
                count++;
            }
            if (count != cols) {
                cout << "Ошибка: введено " << count
                    << " чисел, ожидается " << cols << ". Повторите ввод." << endl;
                continue;
            }
            matrix.addElement(row);
            break;
        }
    }

    // Вывод исходной матрицы и её элементов с координатами
    cout << "\nИсходная матрица:" << endl;
    printMatrix(matrix);
    cout << "\nЭлементы матрицы с координатами:" << endl;
    printMatrixWithIndices(matrix);

    int choice = -1;
    do {
        cout << "\nВыберите операцию:" << endl;
        cout << "1 - Умножить строку на скаляр" << endl;
        cout << "2 - Сложить две строки" << endl;
        cout << "3 - Вычислить скалярное произведение двух строк" << endl;
        cout << "4 - Вывести матрицу" << endl;
        // Выводим опцию векторного произведения только для матриц 3x3
        if (rows == 3 && cols == 3) {
            cout << "5 - Вычислить векторное произведение двух строк" << endl;
        }
        cout << "0 - Выход" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int idx, scalar;
            cout << "Введите индекс строки для умножения (0 - " << rows - 1 << "): ";
            cin >> idx;
            cout << "Введите скаляр: ";
            cin >> scalar;
            try {
                InnerVector<int> result = matrix.getRow(idx) * scalar;
                cout << "Результат умножения строки " << idx << " на " << scalar << ":\n";
                for (size_t j = 0; j < result.size(); j++) {
                    cout << setw(5) << result[j] << " ";
                }
                cout << endl;
                int upd;
                cout << "Обновить строку " << idx << " полученным результатом? (1 - да, 0 - нет): ";
                cin >> upd;
                if (upd == 1) {
                    matrix.getRow(idx) = result;
                    cout << "Строка " << idx << " обновлена." << endl;
                    printMatrix(matrix);
                }
            }
            catch (const exception& e) {
                cout << "Ошибка: " << e.what() << endl;
            }
            break;
        }
        case 2: {
            int idx1, idx2;
            cout << "Введите индексы двух строк для сложения (0 - " << rows - 1 << "): ";
            cin >> idx1 >> idx2;
            try {
                InnerVector<int> result = matrix.getRow(idx1) + matrix.getRow(idx2);
                cout << "Результат сложения строк " << idx1 << " и " << idx2 << ":\n";
                for (size_t j = 0; j < result.size(); j++) {
                    cout << setw(5) << result[j] << " ";
                }
                cout << endl;
                int upd;
                cout << "Обновить какую строку результатом сложения? (1 - первая, 2 - вторая, 0 - не обновлять): ";
                cin >> upd;
                if (upd == 1) {
                    matrix.getRow(idx1) = result;
                    cout << "Строка " << idx1 << " обновлена." << endl;
                }
                else if (upd == 2) {
                    matrix.getRow(idx2) = result;
                    cout << "Строка " << idx2 << " обновлена." << endl;
                }
                printMatrix(matrix);
            }
            catch (const exception& e) {
                cout << "Ошибка: " << e.what() << endl;
            }
            break;
        }
        case 3: {
            int idx1, idx2;
            cout << "Введите индексы двух строк для скалярного произведения (0 - " << rows - 1 << "): ";
            cin >> idx1 >> idx2;
            try {
                int result = matrix.getRow(idx1).dotProduct(matrix.getRow(idx2));
                cout << "Скалярное произведение строк " << idx1 << " и " << idx2 << ": " << result << endl;
            }
            catch (const exception& e) {
                cout << "Ошибка: " << e.what() << endl;
            }
            break;
        }
        case 4: {
            cout << "\nТекущая матрица:" << endl;
            printMatrix(matrix);
            cout << "\nЭлементы матрицы с координатами:" << endl;
            printMatrixWithIndices(matrix);
            break;
        }
        case 5: {
            // Если матрица не 3x3, данная опция недоступна
            if (rows != 3 || cols != 3) {
                cout << "Опция векторного произведения доступна только для матриц 3x3." << endl;
                break;
            }
            int idx1, idx2;
            cout << "Введите индексы двух строк для векторного произведения (от 0 до " << rows - 1 << ") через пробел: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            string line;
            getline(cin, line);
            istringstream iss(line);
            if (!(iss >> idx1 >> idx2)) {
                cout << "Ошибка: требуется ввести два числа." << endl;
                break;
            }
            try {
                InnerVector<int> result = matrix.getRow(idx1).crossProduct(matrix.getRow(idx2));
                cout << "Векторное произведение строк " << idx1 << " и " << idx2 << ":\n";
                for (size_t j = 0; j < result.size(); j++) {
                    cout << setw(5) << result[j] << " ";
                }
                cout << endl;
                int upd;
                cout << "Обновить строку " << idx1 << " результатом векторного произведения? (1 - да, 0 - нет): ";
                cin >> upd;
                if (upd == 1) {
                    matrix.getRow(idx1) = result;
                    cout << "Строка " << idx1 << " обновлена." << endl;
                    printMatrix(matrix);
                }
            }
            catch (const exception& e) {
                cout << "Ошибка: " << e.what() << endl;
            }
            break;
        }
        case 0:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Неверный выбор. Попробуйте еще раз." << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}
