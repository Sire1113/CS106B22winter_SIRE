#include "Plotter.h"
#include "strlib.h"
#include "vector.h"
using namespace std;

void move_abs(Vector<string> command, PenStyle style, bool is_pen_down, Vector<double>& position){
    double x1 = stringToReal(command[1]);
    double y1 = stringToReal(command[2]);
    if(is_pen_down){
        drawLine(position[0], position[1], x1, y1, style);
    }
    position[0] = x1;
    position[1] = y1;
}

void move_rel(Vector<string> command, PenStyle style, bool is_pen_down, Vector<double>& position){
    double x1 = stringToReal(command[1]);
    double y1 = stringToReal(command[2]);
    if(is_pen_down){
        drawLine(position[0], position[1], position[0]+x1, position[1]+y1, style);
    }
    position[0] += x1;
    position[1] += y1;
}

void runPlotterScript(istream& input) {
    /* TODO: Delete this line and the one after it, then implement this function. */
    PenStyle style = { 1, "black" };
    Vector<double> position = {0,0};
    bool is_pen_down = false;
    for (string line; getline(input, line); ) {
        line = toLowerCase(line);
        Vector<string> s = stringSplit(line, " ");
        if(startsWith(line,"moveabs")){
            move_abs(s, style, is_pen_down, position);
        }
        else if(startsWith(line,"moverel")){
            move_rel(s, style, is_pen_down, position);
        }
        else if(startsWith(line,"pendown")){
            is_pen_down = true;
        }
        else if(startsWith(line,"penup")){
            is_pen_down = false;
        }
        else if(startsWith(line,"pencolor")){
            style.color = s[1];
        }
        else if(startsWith(line,"penwidth")){
            style.width = stringToReal(s[1]);
        }
        else{
            error("input error");
        }
    }

}
