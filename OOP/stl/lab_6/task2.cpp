//2.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
    int x, y;
} Point;

typedef struct {
    int vertex_num;
    vector<Point> vertexes;
} Shape;


int main() {
    vector<Shape> shapes;

   
    shapes.push_back({3, {{1, 8}, {1, 0}, {0, 1}}});    
    shapes.push_back({4, {{2, 9}, {1, 0}, {1, 1}, {0, 1}}});    
    shapes.push_back({4, {{2, 2}, {2, 0}, {2, 1}, {0, 1}}});    
    shapes.push_back({5, {{0, 0}, {1, 0}, {1, 1}, {0, 2}, {0, 1}}}); 
    shapes.push_back({5, {{1, 1}, {2, 1}, {2, 2}, {1, 2}, {0, 1}}});
    shapes.push_back({3, {{0, 0}, {2, 0}, {1, 1}}}); 
    shapes.push_back({3, {{-1, 0}, {0, 2}, {1, 0}}}); 

   
    int total_vertices = 0;
    for (const auto &shape: shapes) {
        total_vertices += shape.vertex_num;
    }
    cout << "Total vertices: " << total_vertices << endl;

   
    int triangles = 0, squares = 0, rectangles = 0;
    for (const auto &shape: shapes) {
        if (shape.vertex_num == 3) {
            ++triangles;
        } else if (shape.vertex_num == 4) {
            if (shape.vertexes[0].x == shape.vertexes[1].x || shape.vertexes[0].y == shape.vertexes[1].y) {
                ++squares;
            } else {
                ++rectangles;
            }
        }
    }
    cout << "Triangles: " << triangles << endl;
    cout << "Squares: " << squares << endl;
    cout << "Rectangles: " << rectangles << endl;

    
    for (int i = 0; i < shapes.size(); i++) {
        if (shapes[i].vertex_num == 5) {
            shapes.erase(shapes.begin() + i);
            i--; 
        }
    }

  
    vector<Point> vertices;
    for (const auto &shape: shapes) {
        vertices.push_back(shape.vertexes[0]);
    }

   
    sort(shapes.begin(), shapes.end(), [](const Shape &s1, const Shape &s2) {
        if (s1.vertex_num < s2.vertex_num) {
            return true;
        } else if (s1.vertex_num == s2.vertex_num) {
            if (s1.vertex_num == 3) {
                return true;
            } else if (s1.vertex_num == 4) {
                if (s1.vertexes[0].x == s1.vertexes[1].x || s1.vertexes[0].y == s1.vertexes[1].y) {
                    return true;
                }
            }
        }
        return false;
    });

    cout << "Shapes:" << endl;
    for (const auto &shape: shapes) {
        cout << "Shape with " << shape.vertex_num << " vertices: ";
        for (const auto &vertex: shape.vertexes) {
            cout << "(" << vertex.x << ", " << vertex.y << ") ";
        }
        cout << endl;
    }
    cout << "Vertices:" << endl;
    for (const auto &vertex: vertices) {
        cout << "(" << vertex.x << ", " << vertex.y << ") ";
    }
    cout << endl;
    return 0;
}







