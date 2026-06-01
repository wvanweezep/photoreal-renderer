#pragma once

#include <concepts>
#include <ostream>
#include <cmath>

template<typename T>
concept Arithmetic = std::integral<T> || std::floating_point<T>;

template <Arithmetic T>
struct Vec2 {
    T x{};
    T y{};

    constexpr explicit Vec2(T v): x(v), y(v) {}
    constexpr Vec2(T x, T y) : x(x), y(y) {}
    constexpr Vec2() : x(0), y(0) {}

    template <Arithmetic U>
    requires (!std::same_as<T, U>)
    constexpr explicit Vec2(const Vec2<U>& other) :
        x(static_cast<T>(other.x)),
        y(static_cast<T>(other.y)) {}

    constexpr bool operator==(const Vec2 &) const = default;

    constexpr Vec2 operator+() const {
        return *this;
    }

    constexpr Vec2 operator-() const {
        return {-x, -y};
    }

    constexpr Vec2& operator+=(const Vec2& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    constexpr Vec2& operator-=(const Vec2& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    constexpr Vec2& operator*=(T scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    constexpr Vec2& operator/=(T scalar) {
        x /= scalar;
        y /= scalar;
        return *this;
    }

    [[nodiscard]]
    constexpr T dot(const Vec2& other) const {
        return x * other.x + y * other.y;
    }

    [[nodiscard]]
    constexpr auto length() const {
        return std::sqrt(x * x + y * y);
    }

    [[nodiscard]]
    constexpr T lengthSquared() const {
        return x * x + y * y;
    }

    [[nodiscard]]
    constexpr Vec2 normalized() const requires std::floating_point<T> {
        const T len = static_cast<T>(length());
        return Vec2(x / len, y / len);
    }
};


template <Arithmetic T>
constexpr Vec2<T> operator+(Vec2<T> lhs, const Vec2<T>& rhs) {
    lhs += rhs;
    return lhs;
}

template <Arithmetic T>
constexpr Vec2<T> operator-(Vec2<T> lhs, const Vec2<T>& rhs) {
    lhs -= rhs;
    return lhs;
}

template <Arithmetic T>
constexpr Vec2<T> operator*(Vec2<T> vec, T scalar) {
    vec *= scalar;
    return vec;
}

template <Arithmetic T>
constexpr Vec2<T> operator*(T scalar, Vec2<T> vec) {
    vec *= scalar;
    return vec;
}

template <Arithmetic T>
constexpr Vec2<T> operator/(Vec2<T> vec, T scalar) {
    vec /= scalar;
    return vec;
}

template <Arithmetic T>
std::ostream& operator<<(std::ostream& os, const Vec2<T>& v) {
    return os << "Vec2(" << v.x << ", " << v.y << ")";
}


using Vec2i = Vec2<int>;
using Vec2f = Vec2<float>;
