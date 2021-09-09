#include "color.hh"

namespace color {

void write_color(std::ostream& out, Color color)
{
  // Write the color translated from [0-1] to [0-255]
  out << static_cast<int>(255.999 * color.x()) << " "
      << static_cast<int>(255.999 * color.y()) << " "
      << static_cast<int>(255.999 * color.z()) << "\n";
}

} // namespace color
