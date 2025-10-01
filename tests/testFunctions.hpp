#ifndef TEST_HPP
#define TEST_HPP

#include <cxxtest/TestSuite.h>
#include "../headers/compute.hpp"
#include "../headers/checkOrthonormality.hpp"

class Test : public CxxTest::TestSuite {
public:

    /**
    * @brief Test the contructor of Compute
    */
    void testConstructor() {
        Compute compute;
        TS_ASSERT_EQUALS(compute.m, 1.0);
        TS_ASSERT_EQUALS(compute.w, 1.0);
        TS_ASSERT_EQUALS(compute.h, 1.0);
    }

    /**
    * @brief Test the Hermite function with valid arguments
    */
    void testHermite() {
        Compute compute;
        TS_ASSERT_DELTA(compute.hermite(0, 1.0), 1.0, 1e-6);
        TS_ASSERT_DELTA(compute.hermite(1, 1.0), 2.0, 1e-6);
        TS_ASSERT_DELTA(compute.hermite(2, 1.0), 2.0, 1e-6);

        TS_ASSERT_DELTA(compute.hermite(4, 3.0), 876.0, 1e-6);
    }

    /**
    * @brief Test the Hermite function with invalid arguments
    */
    void testHermiteNegative() {
        Compute compute;
        TS_ASSERT_THROWS(compute.hermite(-1, 1.0), std::invalid_argument&);
    }

    /**
    * @brief Test the Factorial function with valid argument
    */ 
    void testFactorial() {
        Compute compute;
        TS_ASSERT_EQUALS(compute.factorial(0), 1);
        TS_ASSERT_EQUALS(compute.factorial(1), 1);
        TS_ASSERT_EQUALS(compute.factorial(5), 120);
    }

    /**
    * @brief Test the Factorial function with invalid argument
    */
    void testFactorialNegative() {
        Compute compute;
        TS_ASSERT_THROWS(compute.factorial(-1), std::invalid_argument&);
    }

    /**
    * @brief Test the Psi function with valid argument
    */
    void testPsi() {
        Compute compute;
        TS_ASSERT_DELTA(compute.psi(1, 1.0), 0.644288, 1e-6);
        TS_ASSERT_DELTA(compute.psi(2, 1.0), 0.322144, 1e-6);
        TS_ASSERT_DELTA(compute.psi(3, 1.0), -0.26303, 1e-6);
        TS_ASSERT_DELTA(compute.psi(3, 3.0), 0.21679, 1e-6);
    }

    /**
    * @brief Test the Psi function with invalid argument
    */
    void testPsiNegative() {
        Compute compute;
        TS_ASSERT_THROWS(compute.psi(-1, 1.0), std::invalid_argument&);
    }

    /**
    * @brief Test the handling of the parameters of the Integral function
    */
    void testIntegral() {
        Compute compute;
        CheckOrthonormality check;
        check.hermiteCoeff("../ressources/hermiteCoeff.csv");
        TS_ASSERT_DELTA(check.integral(1, 1, compute), 1.0, 1e-6);
        TS_ASSERT_DELTA(check.integral(1, 0, compute), 0.0, 1e-6);
        TS_ASSERT_DELTA(check.integral(5, 5, compute), 1.0, 1e-6);
        TS_ASSERT_DELTA(check.integral(3, 4, compute), 0.0, 1e-6);
    }
};

#endif // TEST_HPP