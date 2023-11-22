#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

//ocena arctan(x) z uporabo Taylorjeve vrste
double arctan(double x, double n) {
    double ocena = 0;

    for (int i = 0; i < n; i++) {
        ocena += pow(-1, i) * pow(x, 2 * i + 1) / (2 * i + 1);
    }

    return ocena;
}

int main() {

    //meje integrala
    double a = 0;
    double b = M_PI / 4;

    //razdelitev koordinatne osi x na 1000 točk
    int tocke = 1000;
    std::vector<double> xi(tocke);

    for (int i = 0; i < tocke; i++) {
        xi[i] = static_cast<double>(i) * M_PI / (4 * (tocke - 1));
    }

    //vsota posameznih območij
    double vsota = 0;
    for (int i = 1; i < tocke - 1; i++) {
        vsota += exp(3 * xi[i]) * arctan(xi[i] / 2, 10);
    }

    //izračun integrala
    double integral = (b - a) / (2 * tocke) * (2 * vsota + exp(3 * a) * arctan(a / 2, 10) + exp(3 * b) * arctan(b / 2, 10));


    std::cout << "Ocena vrednosti integrala je " << integral << std::endl;

    return 0;
}