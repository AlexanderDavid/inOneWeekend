#ifndef COLOR_HH
#define COLOR_HH

#include <Eigen/Dense>
#include <iostream>

namespace color {

using Color = Eigen::Vector3d;

/**
 * @brief Writes a color into some stream in PPM format
 *
 * @param out Stream to write to
 * @param color Color to write
 */
void write_color(std::ostream& out, Color color);

} // namespace color

#endif // COLOR_HH
