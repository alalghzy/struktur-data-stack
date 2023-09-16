#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

const int maxstack = 5;

struct Stack {
    int top;
    float data[maxstack];
};

float dta;
struct Stack stackbaru;

bool isFull() {
    return stackbaru.top == maxstack;
}

bool isEmpty() {
    return stackbaru.top == -1;
}

void push(float dta) {
    if (isFull()) {
        std::cout << "Maaf, stack penuh" << std::endl;
    } else {
        stackbaru.top++;
        stackbaru.data[stackbaru.top] = dta;
    }
}

void pop() {
    if (isEmpty()) {
        std::cout << "Data kosong!" << std::endl;
    } else {
        std::cout << "Data yang terambil: " << stackbaru.data[stackbaru.top] << std::endl;
        stackbaru.top--;
    }
}

void print() {
    std::cout << "\nData dalam stack:\n";
    std::cout << "-------------------\n";
    for (int i = 0; i <= stackbaru.top; i++) {
        std::cout << stackbaru.data[i] << "    ";
    }
    std::cout << std::endl;
}

void clear() {
    stackbaru.top = -1;
    std::cout << "\nStack sekarang kosong" << std::endl;
}

int main() {
    stackbaru.top = -1;

    char menu;
    char ulang;

    do {
        system("cls"); // Menghapus tampilan konsol (Windows) untuk tampilan yang lebih bersih.
        std::cout << "\t PROGRAM STACK\n";
        std::cout << "\t===============\n";
        std::cout << "Menu:\n";
        std::cout << "1. Pop stack\n";
        std::cout << "2. Push stack\n";
        std::cout << "3. Cetak\n";
        std::cout << "4. Bersihkan stack\n";
        std::cout << "5. Exit\n";

        std::cout << "Menu pilihan Anda: ";
        std::cin >> menu;

        if (menu == '1') {
            pop();
            ulang = 'y';
        } else if (menu == '2') {
            std::cout << "\nTambah Data";
            std::cout << "\n-----------";
            std::cout << "\nData yang akan disimpan di stack: ";
            std::cin >> dta;
            push(dta);
            ulang = 'y';
        } else if (menu == '3') {
            print();
            std::cout << "\n\nUlang? (y/t)";
            std::cin >> ulang;
        } else if (menu == '4') {
            clear();
            std::cout << "\n\nUlang? (y/t)";
            std::cin >> ulang;
        } else if (menu == '5') {
            exit(0);
        }
    } while (ulang == 'Y' || ulang == 'y');

    return 0;
}
