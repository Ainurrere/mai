#include <iostream>
using namespace std;

// Функции для работы с массивами (пункт 9)
int findMinElement(double arr[], int size) {
    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

void findMaxElement(double arr[], int size, double &maxValue, int &maxIndex) {
    maxValue = arr[0];
    maxIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
            maxIndex = i;
        }
    }
}

int countGreaterThan(double arr[], int size, double value) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > value) {
            count++;
        }
    }
    return count;
}

double sumArray(double arr[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// Функция для ввода данных о работнике (пункт 3)
void inputWorkerData() {
    double data[3]; // массив для хранения данных: [часы, ставка, премия%]
    
    cout << "Введите количество отработанных часов: ";
    cin >> data[0];
    cout << "Введите ставку почасовой оплаты (руб./час): ";
    cin >> data[1];
    cout << "Введите процент премии: ";
    cin >> data[2];
    
    // Расчеты с использованием функций для массивов
    double salary = data[0] * data[1];
    double bonusAmount = salary * data[2] / 100;
    double total = salary + bonusAmount;
    
    // Создаем массив с результатами расчетов
    double results[3] = {salary, bonusAmount, total};
    
    // Вывод результатов с использованием функций для массивов
    cout << "\nРезультаты расчета:" << endl;
    cout << "Основная зарплата: " << results[0] << " руб." << endl;
    cout << "Премия: " << results[1] << " руб." << endl;
    cout << "Итого к выплате: " << results[2] << " руб." << endl;
    
    // Демонстрация использования функций для массивов
    cout << "\nАнализ данных с использованием функций:" << endl;
    
    // 1. Номер минимального элемента в исходных данных
    int minIndex = findMinIndex(data, 3);
    cout << "Минимальное значение в исходных данных: " << data[minIndex] << " (позиция " << minIndex << ")" << endl;
    
    // 2. Максимальный элемент и его номер в результатах
    double maxValue;
    int maxIndex;
    findMaxElement(results, 3, maxValue, maxIndex);
    cout << "Максимальная сумма: " << maxValue << " руб. (позиция " << maxIndex << ")" << endl;
    
    // 3. Количество элементов больше 50000 в результатах
    int count = countGreaterThan(results, 3, 50000);
    cout << "Количество сумм больше 1000 руб.: " << count << endl;
    
    // 4. Сумма всех результатов
    double totalSum = sumArray(results, 3);
    cout << "Общая сумма всех компонентов: " << totalSum << " руб." << endl;
}

int main() {
    cout << "=== Расчет зарплаты работника ===" << endl;
    inputWorkerData();
    return 0;
}