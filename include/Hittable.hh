#ifndef HITTABLE_HH
#define HITTABLE_HH

#include <Eigen/Dense>

#include "ray.hh"

namespace hittable {

struct hitRecord
{
    bool didHit{false};
    double t{0};
    Eigen::Vector3d p;
    Eigen::Vector3d norm;
    bool frontFace{false};

    inline void setFaceNormal(const ray::Ray& ray,
                              const Eigen::Vector3d& outwardNormal)
    {
        frontFace = ray.direction().dot(outwardNormal) < 0;
        norm = frontFace ? outwardNormal : -outwardNormal;
    }
};

class Hittable
{
  public:
    virtual ~Hittable() = 0;

    [[nodiscard]] virtual auto hit(const ray::Ray& r, double t_min,
                                   double t_max) const -> hitRecord = 0;
};

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
    
}

#endif // HITTABLE_HH
