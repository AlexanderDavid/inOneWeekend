#include "HittableList.hh"

auto HittableList::hit(const ray::Ray& ray, double t_min, double t_max) const
    -> hitRecord
{
    hitRecord closest;

    for (const auto& object : objects_)
    {
        auto rec = object->hit(ray, t_min, t_max);
        if (rec.didHit)
        {
            if (!closest.didHit || closest.t > rec.t)
            {
                closest = std::move(rec);
            }
        }
    }

    return closest;
}
