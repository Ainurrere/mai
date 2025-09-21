#include <iostream>
using namespace std;

int main() {
    const int WORKERS = 4;
    const int MONTHS = 3; // вместо 12 месяцев для тестирования
    
    // Массивы для хранения данных
    double rates[WORKERS]; // почасовые ставки каждого работника
    double hours[WORKERS][MONTHS]; // отработанные часы (работник x месяц)
    double results[WORKERS][MONTHS][2]; // зарплата и налог (работник x месяц x [зарплата, налог])
    
    // Ввод данных
    cout << "Введите почасовые ставки для " << WORKERS << " работников:" << endl;
    for (int i = 0; i < WORKERS; i++) {
        cout << "Работник " << i+1 << ": ";
        cin >> rates[i];
    }
    
    cout << "\nВведите отработанные часы за " << MONTHS << " месяцев:" << endl;
    for (int i = 0; i < WORKERS; i++) {
        cout << "Работник " << i+1 << ":" << endl;
        for (int j = 0; j < MONTHS; j++) {
            cout << "Месяц " << j+1 << ": ";
            cin >> hours[i][j];
        }
    }
    
    // Расчет зарплат и налогов
    for (int i = 0; i < WORKERS; i++) {
        for (int j = 0; j < MONTHS; j++) {
            double salary = hours[i][j] * rates[i];
            double tax = salary * 0.13; // НДФЛ 13%
            results[i][j][0] = salary;  // зарплата
            results[i][j][1] = tax;     // налог
        }
    }
    
    // Вывод результатов
    cout << "\n=== РЕЗУЛЬТАТЫ ===" << endl;
    
    // 1. Сумма первого работника во втором месяце
    cout << "1. Первый работник во втором месяце: " 
         << results[0][1][0] << " руб. (на руки)" << endl;
    
    // 2. Общий налог третьего работника за весь год
    double totalTax3 = 0;
    for (int j = 0; j < MONTHS; j++) {
        totalTax3 += results[2][j][1];
    }
    cout << "2. Налог третьего работника за год: " << totalTax3 << " руб." << endl;
    
    // 3. Номер работника с максимальной зарплатой в третьем месяце
    int maxWorker = 0;
    double maxSalary = results[0][2][0];
    for (int i = 1; i < WORKERS; i++) {
        if (results[i][2][0] > maxSalary) {
            maxSalary = results[i][2][0];
            maxWorker = i;
        }
    }
    cout << "3. Больше всех в третьем месяце заработал работник №" << maxWorker+1 << endl;
    
    // 4. Общая сумма за год всей бригадой
    double totalYear = 0;
    for (int i = 0; i < WORKERS; i++) {
        for (int j = 0; j < MONTHS; j++) {
            totalYear += results[i][j][0];
        }
    }
    cout << "4. Общая сумма за год: " << totalYear << " руб." << endl;
    
    return 0;
}