#include <iostream>
#include <random>

int main() {
    int n;
    double S = 0;
    int c = 0;

    std::cout << "Enter a value for n: ";
    std::cin >> n;

    // Set up random number generation with an exponential distribution
    std::random_device rd;
    std::mt19937 gen(rd());
    std::exponential_distribution<double> dist(1.0 / 2.0); // Mean = 2

    for (int i = 1; i <= 1000; ++i) {
        for (int j = 1; j <= n; ++j) {
            // Generate X from exponential distribution
            double X = dist(gen);

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
