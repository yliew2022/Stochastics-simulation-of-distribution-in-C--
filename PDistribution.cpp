#include <iostream>
#include <random>

int main() {
    int n;
    double S = 0;
    int c = 0;

    std::cout << "Enter a value for n: ";
    std::cin >> n;

    // Define the probabilities
    double probability_X_0_2 = 0.8;
    double probability_X_1_7 = 0.2;

    // Set up random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(0.0, 1.0);

    for (int i = 1; i <= 1000; ++i) {
        for (int j = 1; j <= n; ++j) {
            // Generate X with specified probabilities
            double rand_num = dis(gen);
            double X = (rand_num < probability_X_0_2) ? 0.2 : 1.7;

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
