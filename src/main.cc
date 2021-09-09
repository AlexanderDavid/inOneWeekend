#include <Eigen/Dense>
#include <fmt/core.h>
#include <fmt/ostream.h>
#include <iostream>

#include "HittableList.hh"
#include "Sphere.hh"
#include "color.hh"
#include "ray.hh"

auto main(int /*argc*/, char** /*argv*/) -> int
{
    // Image
    constexpr auto aspect_ratio = 16.0 / 9.0;
    constexpr int image_width = 400;
    constexpr int image_height = static_cast<int>(image_width / aspect_ratio);

    // Camera
    constexpr auto viewport_height = 2.0;
    constexpr auto viewport_width = aspect_ratio * viewport_height;
    constexpr auto focal_length = 1.0;

    Eigen::Vector3d origin{0, 0, 0};
    Eigen::Vector3d horizontal{viewport_width, 0, 0};
    Eigen::Vector3d vertical{0, viewport_height, 0};
    Eigen::Vector3d lower_left_corner = origin - horizontal / 2 - vertical / 2 -
                                        Eigen::Vector3d{0, 0, focal_length};

    // World
    hittable::HittableList world;
    world.add(
        std::make_shared<hittable::Sphere>(Eigen::Vector3d{0, 0, -1}, 0.5));
    world.add(std::make_shared<hittable::Sphere>(Eigen::Vector3d{0, -100.5, -1},
                                                 100));

    fmt::print("P3{} {}\n255\n", image_width, image_height);

    for (int j = image_height - 1; j >= 0; j--)
    {
        fmt::print(std::cerr, "\rScanlines remaining: {} ", j);
        for (int i = 0; i < image_width; i++)
        {
            auto u = double(i) / (image_width - 1);
            auto v = double(j) / (image_height - 1);
            ray::Ray r{origin, lower_left_corner + u * horizontal +
                                   v * vertical - origin};
            color::Color pixColor = ray::ray_color(r, world);
            color::write_color(std::cout, ray::ray_color(r));
        }
    }

    return 0;
}
