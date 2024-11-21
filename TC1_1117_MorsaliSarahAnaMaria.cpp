// Morsali Sarah Ana Maria
// TC 1
// 1117 - ID - AN 3

#include <iostream>
#include <cstring>
using namespace std;

class Autobuz {
private:
    static int nrTotalAutobuze;
    const int idAutobuz;
    int capacitate;
    int ocupare;
    char* marca;

public:
    Autobuz() : idAutobuz(++nrTotalAutobuze) {
        // valori initiale
        this->capacitate = 40;
        this->ocupare = 0;
        this->marca = new char[10];
        strcpy(this->marca, "nerecunoscut");
    }

    Autobuz(int cap, int pers, const char* prod) : idAutobuz(++nrTotalAutobuze) {
        // validari + atribuiri ale valorilor
        this->capacitate = cap ? cap : 50;
        this->ocupare = pers <= this->capacitate ? pers : this->capacitate;

        this->marca = new char[strlen(prod) + 1];
        strcpy(this->marca, prod);
    }

    Autobuz(const Autobuz& a) : idAutobuz(++nrTotalAutobuze) {
        this->capacitate = a.capacitate;
        this->ocupare = a.ocupare;
        this->marca = new char[strlen(a.marca) + 1];
        strcpy(this->marca, a.marca);
    }

    // destructor
    ~Autobuz() {
        delete[] this->marca;
    }

    Autobuz& operator=(const Autobuz& a) {
        if (this != &a) {
            this->capacitate = a.capacitate;
            this->ocupare = a.ocupare;

            delete[] this->marca;

            this->marca = new char[strlen(a.marca) + 1];
            strcpy(this->marca, a.marca);
        }
        return *this;
    }

    // getter
    int getCapacitate() {
        return this->capacitate;
    }

    // setter
    void setCapacitate(int cap) {
        if (cap) {
            this->capacitate = cap;
        };
    }

    int getNumarLocuriLibere() {
        return this->capacitate - this->ocupare;
    }

    operator int() const {
        return this->ocupare;
    }

    bool operator>(const Autobuz& a) const {
        return this->capacitate > a.capacitate;
    }

    friend ostream& operator<<(ostream& os, const Autobuz& a);
};

ostream& operator<<(ostream& os, const Autobuz& a) {
    os << a.idAutobuz << "; " << a.capacitate
        << "; " << a.ocupare << "; " << a.marca;
    return os;
}

int Autobuz::nrTotalAutobuze = 0;

int main() {
    char prod1[] = "opel";

    Autobuz a1(60, 30, prod1);
    Autobuz a2(a1);
    Autobuz a3;

    a3 = a1;

    cout << "detalii autobuze:\n";
    cout << "a1: " << a1 << endl;
    cout << "a2: " << a2 << endl;
    cout << "a3: " << a3 << endl;

    a1.setCapacitate(50);

    cout << "locuri libere a1: " << a1.getNumarLocuriLibere() << endl;

    int ocupare = a1;
    cout << "grad ocupare a1: " << ocupare << endl;

    char prod2[] = "mercedes";
    Autobuz a4(70, 40, prod2);

    string comparatie = a1 > a4 ? "a1 este mai ocupat decat a4" : "a1 NU este mai ocupat decat a4";
    cout << "a1 > a4: " << comparatie << endl;

    return 0;
}