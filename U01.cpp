#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <random>

double generateRandomNumber() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<double> dis(0.0, 1.0);

    return dis(gen);
}

int main() {
    int n;
    double S = 0;
    int c = 0;

    std::cout << "Enter a value for n: ";
    std::cin >> n;

    for (int i = 1; i <= 1000; ++i) {
        for (int j = 1; j <= n; ++j) {
            // Generate X from U(0, 1)
            double X = generateRandomNumber();

            S = S + X;
        }

        if (S / n > 0.45 && S / n < 0.55) {
            c = c + 1;
        }

        S = 0;
    }

    std::cout << static_cast<double>(c) / 1000 << std::endl;

    return 0;
}