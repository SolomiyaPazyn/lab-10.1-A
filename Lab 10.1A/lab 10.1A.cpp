#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <string.h>

using namespace std;


enum Majors { RI = 1, IK, PZ, AI, KN, SA };
enum Subjects { Physics = 1, Math, IT };

#pragma pack(push, 1)  //  оптимізація структури даних у пам'яті
struct Student {

    string return_prizv() {
        return this->prizv;
    }


    unsigned short return_course() {
        return this->course;
    }


    string return_major() {
        switch (this->major) {
        case RI: return "RI";
        case IK: return "IK";
        case PZ: return "PZ";
        case AI: return "AI";
        case KN: return "KN";
        case SA: return "SA";
        }
    }


    unsigned short return_physics() {
        return this->physics;
    }


    unsigned short return_math() {
        return this->math;
    }


    unsigned short return_it() {
        return this->it;
    }


    void fill_class(int i) {
        int temp;
        cout << "Студент №" << i + 1 << endl;
        cout << "Прізвище: "; cin >> this->prizv;
        cout << "Курс: "; cin >> this->course;
        cout << "Спеціальність (RI=1, IK=2, PZ=3, AI=4, KN=5, SA=6): "; cin >> temp;
        this->major = (Majors)temp;
        cout << "Оцінка з фізики: "; cin >> this->physics;
        cout << "Оцінка з математики: "; cin >> this->math;
        cout << "Оцінка з інформатики: "; cin >> this->it;
    }
private:
    string prizv;
    unsigned short course;
    Majors major;
    unsigned short physics;
    unsigned short math;
    unsigned short it;
};
#pragma pack(pop)

// Підрахунок відсотка студентів-відмінників
float calculateExcellentStudentsPercentage(Student* arr, int n) {
    int excellentCount = 0;
    for (int i = 0; i < n; i++) {
        // Якщо студент має всі оцінки 5, то він відмінник
        if (arr[i].return_physics() == 5 &&
            arr[i].return_math() == 5 &&
            arr[i].return_it() == 5) {
            excellentCount++;
        }
    }
    return (float)excellentCount / n * 100;
}

// Виведення прізвищ студентів, які мають оцінку 5 з фізики
void printStudentsWithExcellentPhysics(Student* arr, int n) {
    bool found = false;
    cout << "Студенти, які отримали 5 з фізики:" << endl;
    for (int i = 0; i < n; i++) {
        if (arr[i].return_physics() == 5) {
            cout << i + 1 << ". " << arr[i].return_prizv() << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Таких студентів немає" << endl;
    }
}

// Заповнення масиву студентів
void fill_arr(Student* arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = Student();
        arr[i].fill_class(i);
        cout << endl;
    }
}

// Підрахунок кількості цифр у числі
int calc_n(int n) {
    int res = 0;
    while (n != 0) {
        n /= 10;
        res++;
    }
    return res;
}

// Визначення довжини найдовшого прізвища серед студентів
int lenOfLongestPrizv(Student* arr, int n) {
    int res = -1;
    for (int i = 0; i < n; i++) {
        if (static_cast<int>(arr[i].return_prizv().length()) > res) {
            res = static_cast<int>(arr[i].return_prizv().length());
        }
    }
    return res;
}

// Виведення заголовка таблиці
void printHeader(Student* arr, int n) {
    int width = lenOfLongestPrizv(arr, n);
    (width <= 8) ? (width = 8) : (NULL);  // Мінімальна ширина 8
    int maxDigits = calc_n(n);

    cout << "=======================================================================";
    for (int i = 0; i < (maxDigits - 1) + (width - 8); i++) {
        cout << "=";
    }
    cout << endl;

    cout << "|" << setw(maxDigits) << right << "№";
    cout << "|" << setw(width) << left << "Прізвище" << "| Курс | Спеціальність | Фізика | Математика | Інформатика | " << endl;

    cout << "-----------------------------------------------------------------------";
    for (int i = 0; i < (maxDigits - 1) + (width - 8); i++) {
        cout << "-";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << "|" << setw(maxDigits) << right << i + 1;
        cout << "|" << setw(width) << left << arr[i].return_prizv();
        cout << "|" << setw(6) << left << arr[i].return_course();
        cout << "|" << setw(15) << left << arr[i].return_major();
        cout << "|" << setw(8) << left << arr[i].return_physics();
        cout << "|" << setw(12) << left << arr[i].return_math();
        cout << "|" << setw(13) << left << arr[i].return_it();
        cout << setw(13) << "|" << endl;
    }

    cout << "-----------------------------------------------------------------------";
    for (int i = 0; i < (maxDigits - 1) + (width - 8); i++) {
        cout << "-";
    }
    cout << endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n;
    cout << "Введіть кількість студентів: "; cin >> n;

    Student* arr = new Student[n];  // Виділення пам'яті під масив студентів
    fill_arr(arr, n);
    printHeader(arr, n);


    cout << fixed << setprecision(2);
    cout << "Процент студентів-відмінників: " << calculateExcellentStudentsPercentage(arr, n) << "%" << endl << endl;
    printStudentsWithExcellentPhysics(arr, n);

    delete[] arr;
    return 0;
}
