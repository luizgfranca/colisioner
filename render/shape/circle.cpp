#include <vector>
#include "circle.h"
#include "../../lib/geometry/point.h"

#define UPPER_BOUND_POS 0
#define LOWER_BOUND_POS 1

std::vector<SDL_Point> _calculate_points(Circle c) {
    unsigned int h_limits[] = {c.center_x - c.radius, c.center_x + c.radius};
    unsigned int v_limits[] = {c.center_y - c.radius, c.center_y + c.radius};

    auto point_it = new Point(0,0);
    auto center = new Point(c.center_x, c.center_y);

    std::vector<SDL_Point> pixels;

    //TODO: this could use some parallelization
    for(unsigned int ih = h_limits[UPPER_BOUND_POS]; ih < h_limits[LOWER_BOUND_POS]; ih ++){
        point_it->x = ih;
        for(unsigned int iv = v_limits[UPPER_BOUND_POS]; iv < v_limits[LOWER_BOUND_POS]; iv ++) {
            point_it->y = iv;
            auto distance = center->get_distance_from(*point_it);
            if(distance < c.radius) {
                SDL_Point sdl_point = {(int) ih, (int) iv};
                pixels.push_back(sdl_point);
            }
        }
    }

    return pixels;
}

void draw_circle(SDL_Renderer *renderer, Circle definition) {
    auto points_list = _calculate_points(definition);
    SDL_RenderDrawPoints(renderer, &points_list[0], points_list.size());
}