#include "sprite_generator.hpp"

namespace tools
{
    core::sprite_geometry SpriteGenerator::create(const math::rect& rect)
    {
        return
        {
            {
               { { rect.min.x, rect.max.y }, { 0.0f, 0.0f } },
               { { rect.max.x, rect.max.y }, { 1.0f, 0.0f } },
               { { rect.max.x, rect.min.y }, { 1.0f, 1.0f } },
               { { rect.min.x, rect.min.y }, { 0.0f, 1.0f } }
            },
            {
                { 0, 1, 2 },
                { 2, 3, 0 }
            }
        };
    }
}