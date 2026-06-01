#include "math/vec2.h"

#include <doctest/doctest.h>

#define VEC2_ALL_TYPES int, float
#define VEC2_INTEGRAL_TYPES int
#define VEC2_FLOATING_TYPES float

TEST_SUITE_BEGIN("Vec2");

TEST_CASE_TEMPLATE("single parameter constructor", T, VEC2_ALL_TYPES) {
    Vec2<T> v{1};
    CHECK_EQ(v.x, 1);
    CHECK_EQ(v.y, 1);
}

TEST_CASE_TEMPLATE("two parameter constructor", T, VEC2_ALL_TYPES) {
    Vec2<T> v{1, 2};
    CHECK_EQ(v.x, 1);
    CHECK_EQ(v.y, 2);
}

TEST_CASE_TEMPLATE("empty constructor gives zero vector", T, VEC2_ALL_TYPES) {
    Vec2<T> v{};
    CHECK_EQ(v.x, 0);
    CHECK_EQ(v.y, 0);
}

TEST_CASE_TEMPLATE("copy constructor", T, VEC2_ALL_TYPES) {
    Vec2<T> v1{1, 2};
    Vec2<T> v2{v1};

    SUBCASE("equality") {
        CHECK_EQ(v1, v2);
    }

    SUBCASE("separation") {
        v2.x = 2;
        CHECK(v1 != v2);
    }
}

TEST_CASE("floating copy conversion constructor") {
    Vec2<int> vi{1, 2};
    Vec2<float> vf{vi};

    SUBCASE("equality") {
        CHECK_EQ(vf.x, 1);
        CHECK_EQ(vf.y, 2);
    }

    SUBCASE("separation") {
        vi.x = 2;
        CHECK(vf.x != vi.x);
    }
}

TEST_CASE("integral copy conversion constructor") {
    Vec2<float> vf{1.1f, 2.3f};
    Vec2<int> vi{vf};

    SUBCASE("equality") {
        CHECK_EQ(vi.x, 1);
        CHECK_EQ(vi.y, 2);
    }

    SUBCASE("separation") {
        vf.x = 2;
        CHECK(vi.x != vf.x);
    }
}

TEST_CASE_TEMPLATE("dot product", T, VEC2_ALL_TYPES) {
    T x1 = static_cast<T>(1.1f);
    T y1 = static_cast<T>(2.3f);
    T x2 = static_cast<T>(2.1f);
    T y2 = static_cast<T>(0.3f);
    Vec2<T> v1{x1, y1};
    Vec2<T> v2{x2, y2};

    CHECK_EQ(v1.dot(v2), v2.dot(v1));
    CHECK_EQ(v1.dot(v2), x1*x2 + y1*y2);

}

TEST_CASE_TEMPLATE("vector length", T, VEC2_ALL_TYPES) {
    T x = static_cast<T>(1.1f);
    T y = static_cast<T>(2.3f);
    Vec2<T> v{x, y};

    SUBCASE("normal") {
        CHECK_EQ(v.length(), sqrt(x*x + y*y));
    }

    SUBCASE("squared") {
        CHECK_EQ(v.lengthSquared(), x*x + y*y);
    }
}

TEST_CASE_TEMPLATE("normalized vectors", T, VEC2_FLOATING_TYPES) {
    T x = static_cast<T>(1.1f);
    T y = static_cast<T>(2.3f);
    Vec2<T> v{x, y};
    CHECK_EQ(v.normalized(), Vec2<T>(x / v.length(), y / v.length()));
    CHECK_EQ(v, Vec2<T>(x, y));
}

TEST_SUITE_END();
