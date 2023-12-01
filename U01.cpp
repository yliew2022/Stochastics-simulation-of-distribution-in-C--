#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    int n;
    double S, X;
    int c = 0;

    std::cout << "Enter a value for n: ";
    std::cin >> n;

    // Seed the random number generator
    std::srand(static_cast<unsigned>(std::time(0)));

    for (int i = 1; i <= 1000; ++i) {
        S = 0.0;

        for (int j = 1; j <= n; ++j) {
            // Generate X ~ U(0, 1)
            X = static_cast<double>(std::rand()) / RAND_MAX;

            S += X;
        }

        // Check the condition
        if (S / n > 0.45 && S / n < 0.55) {
            c++;
        }
    }

    // Print the result
    std::cout << static_cast<double>(c) / 1000.0 << std::endl;

    return 0;
}
