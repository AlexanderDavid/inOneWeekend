#include "Hittable.hh"

namespace hittable
{

auto Sphere::hit(const ray::Ray& ray, double t_min, double t_max) const
    -> hitRecord
{
    auto offset = ray.origin() - center_;
    auto a = ray.direction().squaredNorm();
    auto half_b = offset.dot(ray.direction());
    auto c = offset.squaredNorm() - radius_ * radius_;
    auto disc = half_b * half_b - a * c;

    if (disc < 0)
    {
        // If the disc is zero then no hit occured, return default struct
        return {};
    }

    // Find the nearest root in the range
    auto sqrtd = std::sqrt(disc);
    auto root = (-half_b - sqrtd) / a;
    if (root < t_min || t_max < root)
    {
        root = (-half_b + sqrtd) / a;
        if (root < t_min || t_max < root)
        {
            // Root is outside the range. No hit
            return {};
        }
    }

    hitRecord rec{true, root, ray.pointAt(root), ray.pointAt(root), false};
    rec.setFaceNormal(ray, (rec.p - center_) / radius_);

    return rec;
}

} // namespace hittable
