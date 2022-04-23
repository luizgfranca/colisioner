#include <vector>
#include "circle.h"
#include "../../lib/geometry/point.h"
#include <cstdio>

#define UPPER_BOUND_POS 0
#define LOWER_BOUND_POS 1

std::vector<SDL_Point> _calculate_points(Circle* c) {
    unsigned int** limits = c->get_shape_limits();
    unsigned int* h_limits = limits[ORIENTATION_HORIZONTAL];
    unsigned int* v_limits = limits[ORIENTATION_VERTICAL];

    auto point_it = new Point(0,0);
    auto center = c->center;

    std::vector<SDL_Point> pixels;

    //TODO: this could use some parallelization
    for(unsigned int ih = h_limits[UPPER_BOUND_POS]; ih < h_limits[LOWER_BOUND_POS]; ih ++){
        point_it->x = ih;
        for(unsigned int iv = v_limits[UPPER_BOUND_POS]; iv < v_limits[LOWER_BOUND_POS]; iv ++) {
            point_it->y = iv;
            auto distance = center->get_distance_from(*point_it);
            if(distance < c->radius) {
                SDL_Point sdl_point = {(int) ih, (int) iv};
                pixels.push_back(sdl_point);
            }
        }
    }

    return pixels;
}

void draw_circle(SDL_Renderer *renderer, Circle* definition) {
    auto points_list = _calculate_points(definition);
    SDL_RenderDrawPoints(renderer, &points_list[0], points_list.size());
}