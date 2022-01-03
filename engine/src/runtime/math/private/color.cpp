#include "math.hpp"

using namespace openworld;

const color color::transparent_black = color(static_cast<uint8_t>(0), static_cast<uint8_t>(0), static_cast<uint8_t>(0), static_cast<uint8_t>(0));
const color color::black = color(static_cast<uint8_t>(0), static_cast<uint8_t>(0), static_cast<uint8_t>(0), static_cast<uint8_t>(255));
const color color::white = color(static_cast<uint8_t>(255), static_cast<uint8_t>(255), static_cast<uint8_t>(255), static_cast<uint8_t>(255));
const color color::red = color(static_cast<uint8_t>(255), static_cast<uint8_t>(0), static_cast<uint8_t>(0), static_cast<uint8_t>(255));
const color color::green = color(static_cast<uint8_t>(0), static_cast<uint8_t>(255), static_cast<uint8_t>(0), static_cast<uint8_t>(255));
const color color::blue = color(static_cast<uint8_t>(0), static_cast<uint8_t>(0), static_cast<uint8_t>(255), static_cast<uint8_t>(255));