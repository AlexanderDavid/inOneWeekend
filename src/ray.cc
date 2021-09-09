#include <fmt/core.h>
#include <fmt/ostream.h>
#include <iostream>

#include "ray.hh"

namespace ray
{

auto ray_color(const Ray& ray) -> color::Color
{
    Eigen::Vector3d center{0, 0, -1};
    auto hit = hit_sphere(center, 0.5, ray);
    if (hit.has_value())
    {
        auto norm = (ray.pointAt(hit.value()) - center).normalized();
        return 0.5 * color::Color{norm.x() + 1, norm.y() + 1, norm.z() + 1};
    }

    auto unit = ray.direction().normalized();
    auto t = 0.5 * (unit.y() + 1.0);
    return (1.0 - t) * color::Color{1, 1, 1} + t * color::Color{0.5, 0.7, 1.0};
}

auto hit_sphere(const Eigen::Vector3d& center, double radius, const Ray& ray)
    -> std::optional<double>
{
    auto offset = ray.origin() - center;
    auto a = ray.direction().squaredNorm();
    auto half_b = offset.dot(ray.direction());
    auto c = offset.squaredNorm() - radius * radius;
    auto disc = half_b * half_b - a * c;

    if (disc < 0)
    {
        return std::nullopt;
    }
    else
    {
        return (-half_b - std::sqrt(disc)) / a;
    }
}

} // namespace ray
