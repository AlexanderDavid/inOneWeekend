#ifndef HITTABLE_HH
#define HITTABLE_HH

#include <Eigen/Dense>

#include "ray.hh"

namespace hittable
{

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
    virtual ~Hittable();

    [[nodiscard]] virtual auto
    hit(const ray::Ray& r, double t_min = 0,
        double t_max = std::numeric_limits<double>::infinity()) const
        -> hitRecord = 0;
};

} // namespace hittable

#endif // HITTABLE_HH
