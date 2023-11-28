#include <iostream>
#include <fstream>
#include <vector>

double naprejDiferenca(std::vector<std::pair<double, double>>& data, int idx, double dx) {
    return (-3 * data[idx].second + 4 * data[idx + 1].second - data[idx + 2].second) / (2 * dx);
}

double nazajDiferenca(std::vector<std::pair<double, double>>& data, int idx, double dx) {
    return (3 * data[idx].second - 4 * data[idx - 1].second + data[idx - 2].second) / (2 * dx);
}

double centralnaDiferenca(std::vector<std::pair<double, double>>& data, int idx, double dx) {
    return (data[idx + 1].second - data[idx - 1].second) / (2 * dx);
}

int main() {
    std::ifstream vhodnaDatoteka("poly.txt");
    if (!vhodnaDatoteka.is_open()) {
        std::cerr << "Napaka pri odpiranju vhodne datoteke.";
        return 1;
    }

    int steviloVrednosti;
    vhodnaDatoteka >> steviloVrednosti;

    std::vector<std::pair<double, double>> data;
    double x, fx;
    for (int i = 0; i < steviloVrednosti; ++i) {
        vhodnaDatoteka >> x >> fx;
        data.emplace_back(x, fx);
    }

    vhodnaDatoteka.close();

    double dx = 0.0294117647058822; // ∆x
    std::ofstream izhodnaDatoteka("diff_poly.txt");
    if (!izhodnaDatoteka.is_open()) {
        std::cerr << "Napaka pri ustvarjanju izhodne datoteke.";
        return 1;
    }

    
    for (int i = 0; i < steviloVrednosti; ++i) {
        double derivative;
        if (i == 0) {
            derivative = naprejDiferenca(data, i, dx);
        } else if (i == steviloVrednosti - 1) {
            derivative = nazajDiferenca(data, i, dx);
        } else {
            derivative = centralnaDiferenca(data, i, dx);
        }
        izhodnaDatoteka << "Odvod f'(" << data[i].first << ") = " << derivative << std::endl;
    }

   izhodnaDatoteka.close();

    std::cout << "Izračunani odvodi so shranjeni v diff_poly.txt.";

    return 0;
}
