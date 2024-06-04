#include <iostream>
using namespace std;

const int MAX_NUMBERS = 100;  // Batas maksimal angka yang dapat dioperasikan

// Fungsi untuk menjumlahkan sejumlah angka
double addNumbers(double numbers[], int count) {
    double sum = numbers[0];
    for (int i = 1; i < count; ++i) {
        sum += numbers[i];
    }
    return sum;
}

// Fungsi untuk mengurangkan sejumlah angka
double subtractNumbers(double numbers[], int count) {
    double result = numbers[0];
    for (int i = 1; i < count; ++i) {
        result -= numbers[i];
    }
    return result;
}

// Fungsi untuk mengalikan sejumlah angka
double multiplyNumbers(double numbers[], int count) {
    double result = numbers[0];
    for (int i = 1; i < count; ++i) {
        result *= numbers[i];
    }
    return result;
}

// Fungsi untuk membagi sejumlah angka
double divideNumbers(double numbers[], int count) {
    double result = numbers[0];
    for (int i = 1; i < count; ++i) {
        if (numbers[i] != 0) {
            result /= numbers[i];
        } else {
            cout << "Error: Pembagian oleh nol tidak diizinkan." << endl;
            return 0; // Mengembalikan 0 untuk menunjukkan kesalahan
        }
    }
    return result;
}

int main() {
    double numbers[MAX_NUMBERS];
    int count = 0;

    // Input dari pengguna
    cout << "Masukkan angka-angka dan operasi yang akan dijalankan (akhiri dengan 0):" << endl;

    // Menggunakan loop untuk terus-menerus menerima input pengguna
    while (true) {
        double input;
        cout << "Angka/Operasi ke-" << (count + 1) << ": ";
        cin >> input;

        // Jika pengguna memasukkan 0, hentikan input
        if (input == 0) {
            break;
        }

        numbers[count++] = input;

        // Validasi agar tidak melebihi batas maksimal angka
        if (count == MAX_NUMBERS) {
            cout << "Batas maksimal angka telah dicapai. Menghentikan input." << endl;
            break;
        }
    }

    // Menjalankan operasi yang dimasukkan pengguna
    char operation;
    cout << "Masukkan operasi matematika (+, -, *, /): ";
    cin >> operation;

    double result = 0;

    switch (operation) {
        case '+':
            result = addNumbers(numbers, count);
            break;
        case '-':
            result = subtractNumbers(numbers, count);
            break;
        case '*':
            result = multiplyNumbers(numbers, count);
            break;
        case '/':
            result = divideNumbers(numbers, count);
            break;
        default:
            cout << "Operasi tidak valid." << endl;
            return 1;
    }

    // Menampilkan hasil perhitungan
    cout << "Hasil: " << result << endl;

    return 0;
}
