#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <cmath>
#include <functional>

#include "node.hpp"

// MacCormack finite difference sceme for the kinemetic wave
// double mac_cormack(
//         Node& node, 
//         double alpha, 
//         double m, 
//         double t,
//         double dt,
//         std::function<double(double, double, double)> i)
// {
//     auto q = [&](double h) { return alpha * std::pow(h, m); };
// 
//     auto distance = [&](double x_other, double y_other) 
//     { 
//         return std::sqrt(std::pow(node.x - x_other, 2) + 
//                          std::pow(node.y - y_other, 2)); 
//     };
// 
//     auto predictor = [&](
//             double h_next, 
//             double h_current, 
//             double dx,
//             double rainfall) 
//     {
//         return h_current 
//                - dt / dx * (q(h_next) - q(h_current))
//                + dt * rainfall;
//     };
// 
//     const double x = node.x;
//     const double y = node.y;
//     const double h_current_node = node.h;
//     const double h_next_node = (node.next != nullptr)? node.next->h : 0;
//     const double d_next = (node.next != nullptr)? 
//                           distance(node.next->x, node.next->y) : 0;
// 
//     double h_prev_pred = 0;
//     const double h_current_pred = predictor(h_next_node, 
//                                             h_current_node, 
//                                             d_next, 
//                                             i(x, y, t));
//     for (Node *prev : node.prev)
//     {
//         h_prev_pred += predictor(h_current_node,
//                                  prev->h,
//                                  distance(prev->x, prev->y),
//                                  i(prev->x, prev->y, t));
//     }
//     return 0.5 * (h_current_node + h_current_pred) 
//            - 0.5 * (dt/d_next * (q(h_current_pred) - q(h_prev_pred)) 
//                    + i(x, y, t) * dt);
// }
// 
#endif // UTILS_HPP_
