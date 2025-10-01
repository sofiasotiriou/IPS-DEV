#include "../headers/compute.hpp"
//#include <corecrt_math_defines.h>

Compute::Compute() noexcept {
    m = 1.0;
    w = 1.0;
    h = 1.0;
}

double Compute::hermite(int n, double z) {
    if (n < 0) {
        throw std::invalid_argument("n must be non-negative");
    }
    memo = std::vector<double>(n + 1, -1);
    return hermiteRecursive(n, z);
}

double Compute::hermiteRecursive(int n, double z) {
    if (n < 0) {
        throw std::invalid_argument("n must be non-negative");
    }

    if (n == 0) return 1;
    if (n == 1) return 2 * z;
    if (memo[n] != -1) return memo[n];

    memo[n] = 2 * z * hermiteRecursive(n - 1, z) - 2 * (n - 1) * hermiteRecursive(n - 2, z);
    return memo[n];
}

int Compute::factorial(int n) {
    if (n < 0) {
        throw std::invalid_argument("n must be non-negative");
    }

    if (n == 0 || n == 1) return 1;
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

double Compute::psi(int n, double z) {
    if (n < 0) {
        throw std::invalid_argument("n must be non-negative");
    }
    
    // Precompute constants
    double mw_h = (m * w) / h;
    double normalization = 1.0 / std::sqrt(std::pow(2, n) * factorial(n)) * std::pow(mw_h / M_PI, 0.25);

    // Exponential term
    double exp_term = std::exp(-mw_h * z * z / 2);

    // Hermite polynomial term
    double hermite_value = hermite(n, std::sqrt(mw_h) * z);

    // Compute ψ_n(z)
    return normalization * exp_term * hermite_value;
}

double Compute::potential(double z){
    return 0.5*m*w*w*z*z;
}
