#ifndef RAY_HH
#define RAY_HH

#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <optional>

#include "Hittable.hh"
#include "color.hh"

namespace ray
{

using Ray = Eigen::ParametrizedLine<double, 3>;

/**
 * @brief Calculate the color of a given ray
 *
 * @param ray Ray to calculate color of
 * @returns Color of the ray
 */
auto ray_color(const Ray& ray, const hittable::Hittable& world) -> color::Color;

/**
 * @brief Determine if given ray intersects with given sphere
 *
 * @param center Center of sphere
 * @param radius Radius of sphere
 * @param ray Ray to use to check intersection
 * @returns value of t when ray intersects with sphere or nullopt
 */
auto hit_sphere(const Eigen::Vector3d& center, double radius, const Ray& ray)
    -> std::optional<double>;

} // namespace ray

#endif // RAY_HH
