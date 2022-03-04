#include "Simple_window.h"
#include "Graph.h"
#include <string>
#include <iostream>

using namespace Graph_lib;

int main()
try {
    

    // 1. Make an 800x1000 window
    const Point tl {100, 100};
    Simple_window win {tl, 800, 1000, "Chapter 13 Drill"};
    win.wait_for_button();

    // 2.  Put an 8-by-8 grid on the leftmost 800-by-800 part of that window (so that each square is 100 by 100)
    int x_size = 800;
    int y_size = 800;
    int x_grid = 100;
    int y_grid = 100;

    Lines grid;
    for (int x = x_grid; x < x_size; x += x_grid)
        grid.add(Point{x, 0}, Point{x, y_size});    // vertical lines
    for (int y = y_grid; y < y_size; y += y_grid)
        grid.add(Point{0, y}, Point{x_size, y});

    grid.set_color(Color::red);

    win.attach(grid);
    win.wait_for_button();

    // 3. Make the eight squares on the diagonal starting from the top left corner red (use Rectangle).
   Vector_ref<Rectangle> rects;
    for (int i = 0; i < x_size; i += x_grid) {
        rects.push_back(new Rectangle{Point{i,i}, Point{i+x_grid,i+x_grid}});
        rects[rects.size() - 1].set_color(Color::invisible);
        rects[rects.size() - 1].set_fill_color(Color::red);
        win.attach(rects[rects.size() - 1]);
    }

    win.wait_for_button();

    // 4.  Find a 200-by-200-pixel image (JPEG or GIF) and place three copies of it on the grid
    Image cpp1 {Point{0,300}, "cpp.gif"};
    Image cpp2 {Point{300,600}, "cpp.gif"};
    Image cpp3 {Point{500,100}, "cpp.gif"};

    win.attach(cpp1);
    win.attach(cpp2);
    win.attach(cpp3);
    win.wait_for_button();

    // 5. Add a 100-by-100 image. Have it move around from square to square when you click the “Next” button.
    Image pika {Point{0,0}, "kep.gif"};
    win.attach(pika);
    win.wait_for_button();

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            pika.move(100, 0);
            win.wait_for_button();
        }
        pika.move(-700, 100);       
        win.wait_for_button();
    }
}
catch(exception& e) {
    cerr << "exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "error\n";
    return 2;
}
