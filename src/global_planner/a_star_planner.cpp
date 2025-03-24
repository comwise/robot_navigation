#include "global_planner/a_star_planner.h"
#include <cmath>
#include <algorithm>
#include <queue>

AStarPlanner::AStarPlanner(int width, int height, const std::vector<std::vector<int>>& map)
    : width_(width), height_(height), map_(map) {}

std::vector<Node> AStarPlanner::get_neighbors(Node node) {
    std::vector<Node> neighbors;
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue;
            int nx = node.x + dx;
            int ny = node.y + dy;
            if (nx >= 0 && nx < width_ && ny >= 0 && ny < height_ && map_[ny][nx] == 0) {
                neighbors.emplace_back(nx, ny);
            }
        }
    }
    return neighbors;
}

bool AStarPlanner::is_valid(Node node) {
    return node.x >= 0 && node.x < width_ && node.y >= 0 && node.y < height_ && map_[node.y][node.x] == 0;
}

std::vector<Node> AStarPlanner::plan_path(const Node& start, const Node& goal) {
    std::vector<Node> open_list;
    std::vector<Node> closed_list;

    open_list.push_back(start);

    while (!open_list.empty()) {
        Node current = open_list.front();
        open_list.erase(open_list.begin());

        if (current.x == goal.x && current.y == goal.y) {
            std::vector<Node> path;
            Node* node = &current;
            while (node) {
                path.push_back(*node);
                node = node->parent;
            }
            std::reverse(path.begin(), path.end());
            return path;
        }

        closed_list.push_back(current);

        for (Node& neighbor : get_neighbors(current)) {
            if (std::find(closed_list.begin(), closed_list.end(), neighbor) != closed_list.end()) {
                continue;
            }

            float g_cost = current.g_cost + 1;
            float h_cost = std::abs(neighbor.x - goal.x) + std::abs(neighbor.y - goal.y);
            float f_cost = g_cost + h_cost;

            neighbor.g_cost = g_cost;
            neighbor.h_cost = h_cost;
            neighbor.f_cost = f_cost;
            neighbor.parent = &current;

            open_list.push_back(neighbor);
        }
    }

    return {};
}
