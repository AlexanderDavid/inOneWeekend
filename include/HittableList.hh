#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include <memory>
#include <vector>

#include "Hittable.hh"
#include "ray.hh"

namespace hittable
{

class HittableList : public Hittable
{
  public:
    HittableList() = default;
    explicit HittableList(const std::shared_ptr<Hittable>& object)
    {
        add(object);
    };

    void clear()
    {
        objects_.clear();
    }

    void add(const std::shared_ptr<Hittable>& object)
    {
        objects_.push_back(object);
    }

    [[nodiscard]] auto
    hit(const ray::Ray& r, double t_min = 0,
        double t_max = std::numeric_limits<double>::infinity()) const
        -> hitRecord override;

  private:
    std::vector<std::shared_ptr<Hittable>> objects_;
};

} // namespace hittable

#endif
