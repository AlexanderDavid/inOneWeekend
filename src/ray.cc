#include <fmt/core.h>
#include <fmt/ostream.h>
#include <iostream>
#include <limits>

#include "Hittable.hh"
#include "ray.hh"

namespace ray
{

auto ray_color(const Ray& ray, const hittable::Hittable& world) -> color::Color
{
    auto hitRecord = world.hit(ray);
    if (hitRecord.didHit)
    {
        return 0.5 * (hitRecord.norm + color::Color{1, 1, 1});
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
