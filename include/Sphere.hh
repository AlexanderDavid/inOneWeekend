#ifndef SPHERE_HH
#define SPHERE_HH

#include "Hittable.hh"

#include <Eigen/Dense>

namespace hittable
{

class Sphere : public Hittable
{
  public:
    Sphere() = default;

    Sphere(Eigen::Vector3d center, double radius)
    {
        center_ = std::move(center);
        radius_ = radius;
    }

    [[nodiscard]] auto hit(const ray::Ray& r, double t_min, double t_max) const
        -> hitRecord override;

  private:
    Eigen::Vector3d center_{0, 0, 0};
    double radius_{1};
};

} // namespace hittable

#endif
