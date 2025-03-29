#include "Utils.h"
#include <sstream>
#include <iomanip>
using namespace std;
string trim(const string& str) {
    const string whitespace = " \t\n\r";
    size_t start = str.find_first_not_of(whitespace);
    if (start == string::npos)
        return "";
    size_t end = str.find_last_not_of(whitespace);
    return str.substr(start, end - start + 1);
}

void printMatrix(const OuterVector<int>& matrix) {
    cout << "ћатрица:" << endl;
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix.getRow(i).size(); j++) {
            cout << setw(5) << matrix.getRow(i)[j] << " ";
        }
        cout << endl;
    }
}

void printMatrixWithIndices(const OuterVector<int>& matrix) {
    cout << "Ёлементы матрицы с координатами:" << endl;
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix.getRow(i).size(); j++) {
            cout << "Ёлемент [" << i << "][" << j << "] - "
                << matrix.getRow(i)[j] << endl;
        }
    }
}
