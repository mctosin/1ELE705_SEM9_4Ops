#include "gtest/gtest.h"
#include <cstring>
#include "aux_functions.h"
#define _USE_MATH_DEFINES
#include "math.h"

extern "C"
{
    #include <time.h>
    #include <stdlib.h>
}

#define tolerance 0.000001
const char* const cart = "cart";
const char* const pol = "pol";
const char* const add = "add";
const char* const sub = "sub";
const char* const mul = "mul";
const char* const dvs = "dvs";
TEST(TestCaseName, TestName) {
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
    srand((unsigned int) time(NULL));
}

TEST(SomaCartesiana, ZeroInputsCheckReturnValue) {
    Cart x = { 0.0, 0.0 };
    Cart x_expected = { 0.0, 0.0 };
    Cart y = { 0.0, 0.0 };

    unsigned ret = somacartesiana(&x, y);

    ASSERT_EQ(0, ret);
}

TEST(SomaCartesiana, ZeroInputsCheckX) {
    Cart x = { 0.0, 0.0 };
    Cart x_expected = { 0.0, 0.0 };
    Cart y = { 0.0, 0.0 };

    unsigned ret = somacartesiana(&x, y);

    ASSERT_TRUE(CartNear(x_expected, x, tolerance));
}

TEST(SomaCartesiana, xRealPartZeroyRealPartNonZeroCheckX) {
    Cart x = { 0.0, 0.0 };
    Cart y = { 1.1, 0.0 };
    Cart x_expected = { 1.1, 0.0 };

    unsigned ret = somacartesiana(&x, y);
 
    ASSERT_TRUE(CartNear(x_expected, x, tolerance));
}

TEST(SomaCartesiana, xImaginaryPartZeroyImaginaryPartNonZeroCheckX) {
    Cart x = { 0.0, 0.0 };
    Cart y = { 0.0, 1.7 };
    Cart x_expected = { 0.0, 1.7 };

    unsigned ret = somacartesiana(&x, y);

    ASSERT_TRUE(CartNear(x_expected, x, tolerance));
}

TEST(SomaCartesiana, xRandomyRandomCheckX) {
    Cart x = { 0.0001*(double)rand(), 0.0001 * (double)rand() };
    Cart y = { 0.0001 * (double)rand(), 0.0001 * (double)rand() };
    Cart x_expected{ x.a + y.a, x.b + y.b };
    
    unsigned ret = somacartesiana(&x, y);
    
    ASSERT_TRUE(CartNear(x_expected, x, tolerance));
}

TEST(Cartesian2Polar, ZeroInputCheckReturnValue) {
    Cart x = { 0.0, 0.0 };
    Pol w_expected = { 0.0, 0.0 };
    Pol w;

    unsigned ret = cartesian2polar(&w, x);

    ASSERT_EQ(0, ret);
}

TEST(Cartesian2Polar, ZeroInputCheckOutputW) {
    Cart x = { 0.0, 0.0 };
    Pol w_expected = { 0.0, 0.0 };
    Pol w;

    cartesian2polar(&w, x);

    ASSERT_TRUE(PolNear(w_expected, w, tolerance));
}

TEST(Cartesian2Polar, ZeroPiInputCheckOutputW) {
    Cart x = { 2.25, 0.0 };
    Pol w_expected = { 2.25, 0.0 };
    Pol w;

    cartesian2polar(&w, x);

    ASSERT_TRUE(PolNear(w_expected, w, tolerance));
}
TEST(Cartesian2Polar, PiOverTwoInputCheckOutputW) {
    Cart x = { 0.0, 1.5 };
    Pol w_expected = { 1.5, M_PI_2 };
    Pol w;

    cartesian2polar(&w, x);

    ASSERT_TRUE(PolNear(w_expected, w, tolerance));
}

TEST(Cartesian2Polar, PiInputCheckOutputW) {
    Cart x = { -1.33, 0.0 };
    Pol w_expected = { 1.33, M_PI };
    Pol w;

    cartesian2polar(&w, x);

    ASSERT_TRUE(PolNear(w_expected, w, tolerance));
}

TEST(Cartesian2Polar, MinusPiOverTwoInputCheckOutputW) {
    Cart x = { 0, -1.337 };
    Pol w_expected = { 1.337, -M_PI_2 };
    Pol w;

    cartesian2polar(&w, x);

    ASSERT_TRUE(PolNear(w_expected, w, tolerance));
}

TEST(Cartesian2Polar, FirstQuadrantInputCheckOutputW) {
    Cart x = { 1.01324972243, 0.585 };
    Pol w_expected = { 1.17, M_PI/6 };
    Pol w;

    cartesian2polar(&w, x);

    ASSERT_TRUE(PolNear(w_expected, w, tolerance));
}

TEST(Cartesian2Polar, SecondQuadrantInputCheckOutputW) {
    Cart x = { -6.685, 11.5787596486 };
    Pol w_expected = { 13.37, 2*M_PI/3 };
    Pol w;

    cartesian2polar(&w, x);

    ASSERT_TRUE(PolNear(w_expected, w, tolerance));
}

TEST(Cartesian2Polar, ThirdQuadrantInputCheckOutputW) {
    Cart x = { -6.685, -11.5787596486 };
    Pol w_expected = { 13.37, -2 * M_PI / 3 };
    Pol w;

    cartesian2polar(&w, x);

    ASSERT_TRUE(PolNear(w_expected, w, tolerance));
}

TEST(Cartesian2Polar, FourthQuadrantInputCheckOutputW) {
    Cart x = { 1.01324972243, -0.585 };
    Pol w_expected = { 1.17, -M_PI / 6 };
    Pol w;

    cartesian2polar(&w, x);

    ASSERT_TRUE(PolNear(w_expected, w, tolerance));
}

TEST(MultiplyPolar, ZeroInputsCheckReturnValue) {
    Pol x = { 0.0, 0.0 };
    Pol x_expected = { 0.0, 0.0 };
    Pol y = { 0.0, 0.0 };

    multiplypolar(&x, y);

    ASSERT_TRUE(PolNear(x_expected, x, tolerance));
}

TEST(MultiplyPolar, FirstInputZeroCheckOutputX) {
    Pol x = { 0.0, 0.0 };
    Pol x_expected = { 0.0, 0.0 };
    Pol y = { 2.2, M_PI_2 };

    multiplypolar(&x, y);

    ASSERT_TRUE(PolNear(x_expected, x, tolerance));
}

TEST(MultiplyPolar, FirstInputZeroModuleNonZeroAngleCheckOutputX) {
    Pol x = { 0.0, M_PI_4 };
    Pol x_expected = { 0.0, 0.0 };
    Pol y = { 2.2, M_PI_2 };

    multiplypolar(&x, y);

    ASSERT_TRUE(PolNear(x_expected, x, tolerance));
}

TEST(MultiplyPolar, FirstInputModuleHasInfinityCheckOutputX) {
    Pol x = { INFINITY, M_PI_4 };
    Pol y = { 2.2, M_PI_2 };
    Pol x_expected = { INFINITY, 3 * M_PI_4 };

    multiplypolar(&x, y);

    ASSERT_TRUE(PolNear(x_expected, x, tolerance));
}

TEST(MultiplyPolar, FirstInputModuleHasInfinityCheckReturnValue) {
    Pol x = { INFINITY, M_PI_4 };
    Pol y = { 2.2, M_PI_2 };
    Pol x_expected = { INFINITY, 3 * M_PI_4 };

    unsigned ret = multiplypolar(&x, y);

    ASSERT_EQ(2, ret);
}

TEST(MultiplyPolar, SecondInputModuleHasInfinityCheckOutputX) {
    Pol x = { 1.33, M_PI_4 };
    Pol y = { INFINITY, M_PI_4 };
    Pol x_expected = { INFINITY, M_PI_2 };

    multiplypolar(&x, y);

    ASSERT_TRUE(PolNear(x_expected, x, tolerance));
}

TEST(MultiplyPolar, SecondInputModuleHasInfinityCheckReturnValue) {
    Pol x = { 1.33, M_PI_4 };
    Pol y = { INFINITY, M_PI_4 };
    Pol x_expected = { INFINITY, M_PI_2 };

    unsigned ret = multiplypolar(&x, y);

    ASSERT_EQ(2, ret);
}

TEST(MultiplyPolar, FirstInputModuleZeroSecondInputModuleHasInfinityCheckOutputX) {
    Pol x = { 0.0, M_PI_4 };
    Pol y = { INFINITY, M_PI_4 };
    Pol x_expected = { 0.0, 0.0 };

    multiplypolar(&x, y);

    ASSERT_TRUE(PolNear(x_expected, x, tolerance));
}

TEST(MultiplyPolar, FirstInputModuleSecondInputModuleHasInfinityCheckReturnValue) {
    Pol x = { 0.0, M_PI_4 };
    Pol y = { INFINITY, M_PI_4 };
    Pol x_expected = { 0.0, 0.0 };

    unsigned ret = multiplypolar(&x, y);

    ASSERT_EQ(0, ret);
}

TEST(MultiplyPolar, FirstInputModuleHasInfinitySecondInputZeroCheckOutputX) {
    Pol x = { INFINITY, M_PI_4 };
    Pol y = { 0.0, M_PI_2 };
    Pol x_expected = { 0.0, 0.0 };

    multiplypolar(&x, y);

    ASSERT_TRUE(PolNear(x_expected, x, tolerance));
}

TEST(MultiplyPolar, FirstInputModuleHasInfinitySecondInputZeroCheckReturnValue) {
    Pol x = { INFINITY, M_PI_4 };
    Pol y = { 0.0, M_PI_2 };
    Pol x_expected = { 0.0, 0.0 };

    unsigned ret = multiplypolar(&x, y);

    ASSERT_EQ(0, ret);
}

TEST(MultiplyPolar, BothInputsHasInfinityCheckOutputX) {
    Pol x = { INFINITY, M_PI_4 };
    Pol y = { INFINITY, M_PI_2 };
    Pol x_expected = { INFINITY, 3 * M_PI_4 };

    multiplypolar(&x, y);

    ASSERT_TRUE(PolNear(x_expected, x, tolerance));
}

TEST(MultiplyPolar, BothInputsHasInfinityCheckReturnValue) {
    Pol x = { INFINITY, M_PI_4 };
    Pol y = { INFINITY, M_PI_2 };
    Pol x_expected = { INFINITY, 3 * M_PI_4 };

    unsigned ret = multiplypolar(&x, y);

    ASSERT_EQ(2, ret);
}

TEST(MultiplyPolar, BothInputsAreHugeCheckOutputX) {
    Pol x = { _HUGE_ENUF, M_PI_4 };
    Pol y = { _HUGE_ENUF, M_PI_2 };
    Pol x_expected = { INFINITY, 3 * M_PI_4 };

    multiplypolar(&x, y);

    ASSERT_TRUE(PolNear(x_expected, x, tolerance));
}

TEST(MultiplyPolar, BothInputsAreHugeCheckReturnValue) {
    Pol x = { _HUGE_ENUF, M_PI_4 };
    Pol y = { _HUGE_ENUF, M_PI_2 };
    Pol x_expected = { INFINITY, 3 * M_PI_4 };

    unsigned ret = multiplypolar(&x, y);

    ASSERT_EQ(2, ret);
}

TEST(MultiplyPolar, FirstInputModuleHugeCheckOutputX) {
    Pol x = { _HUGE_ENUF, M_PI_4 };
    Pol y = { 2.2, M_PI_2 };
    Pol x_expected = { _HUGE_ENUF*2.2, 3 * M_PI_4 };

    multiplypolar(&x, y);

    ASSERT_TRUE(PolNear(x_expected, x, tolerance));
}

TEST(MultiplyPolar, FirstInputModuleHugeCheckReturnValue) {
    Pol x = { _HUGE_ENUF, M_PI_4 };
    Pol y = { 2.2, M_PI_2 };
    Pol x_expected = { _HUGE_ENUF*2.2, 3 * M_PI_4 };

    unsigned ret = multiplypolar(&x, y);

    ASSERT_EQ(0, ret);
}

TEST(MultiplyPolar, SecondInputModuleHugeCheckOutputX) {
    Pol x = { 13.37, M_PI_2 };
    Pol y = { _HUGE_ENUF, M_PI_2 };
    Pol x_expected = { _HUGE_ENUF * 13.37, M_PI };

    multiplypolar(&x, y);

    ASSERT_TRUE(PolNear(x_expected, x, tolerance));
}

TEST(MultiplyPolar, SecondInputModuleHugeCheckReturnValue) {
    Pol x = { 13.37, M_PI_2 };
    Pol y = { _HUGE_ENUF, M_PI_2 };
    Pol x_expected = { _HUGE_ENUF * 13.37, M_PI };

    unsigned ret = multiplypolar(&x, y);

    ASSERT_EQ(0, ret);
}

TEST(NormalizeAngle, FirstHemisphereAngleCheckOutput) {
    Pol x = { 1.1, 7 * M_PI / 8 };
    Pol x_expected = { 1.1, 7 * M_PI / 8 };

    normalizeangle(&x);

    ASSERT_TRUE(PolNear(x_expected, x, tolerance));
}

TEST(NormalizeAngle, SecondHemisphereAngleCheckOutput) {
    Pol x = { 1.1, 9 * M_PI / 8 };
    Pol x_expected = { 1.1, -7 * M_PI / 8 };

    normalizeangle(&x);

    ASSERT_TRUE(PolNear(x_expected, x, tolerance));
}

TEST(NormalizeAngle, FirstHemisphereNegAngleCheckOutput) {
    Pol x = { 1.1, -9 * M_PI / 8 };
    Pol x_expected = { 1.1, 7 * M_PI / 8 };

    normalizeangle(&x);

    ASSERT_TRUE(PolNear(x_expected, x, tolerance));
}

TEST(NormalizeAngle, SecondHemisphereNegAngleCheckOutput) {
    Pol x = { 1.1, -7 * M_PI / 8 };
    Pol x_expected = { 1.1, -7 * M_PI / 8 };

    normalizeangle(&x);

    ASSERT_TRUE(PolNear(x_expected, x, tolerance));
}

TEST(NormalizeAngle, CincoPI_2InputAngleCheckOutput) {
    Pol x = { 1.1, 5 * M_PI / 2 };
    Pol x_expected = { 1.1, M_PI_2 };

    normalizeangle(&x);

    ASSERT_TRUE(PolNear(x_expected, x, tolerance));
}

TEST(NormalizeAngle, SetePI_2InputAngleCheckOutput) {
    Pol x = { 1.1, 7 * M_PI / 2 };
    Pol x_expected = { 1.1, -M_PI_2 };

    normalizeangle(&x);

    ASSERT_TRUE(PolNear(x_expected, x, tolerance));
}

TEST(NormalizeAngle, PiInputAngleCheckOutput) {
    Pol x = { 1.1, M_PI };
    Pol x_expected = { 1.1, -M_PI };

    normalizeangle(&x);

    ASSERT_TRUE(PolNear(x_expected, x, tolerance));
}

