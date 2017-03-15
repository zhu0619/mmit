#ifndef MMIT_PIECEWISE_FUNCTION_H
#define MMIT_PIECEWISE_FUNCTION_H

#include <map>
#include <set>

#include "coefficients.h"

enum FunctionType{
    hinge,
    squared_hinge
};

class PiecewiseFunction {

private:
    // Function parameters
    FunctionType function_type;
    double margin;

    // Breakpoint and their coefficients
    std::map<double, Coefficients> breakpoint_coefficients;

    // Minimum solution
    Coefficients min_coefficients;
    std::map<double, Coefficients>::iterator min_ptr = breakpoint_coefficients.end();  // Always on the right of the minimum

    // Minimum pointer functions
    void move_minimum_pointer_left();
    void move_minimum_pointer_right();

    // Utility vars + functions
    double get_breakpoint_position(double y, bool is_upper_bound);
    bool verbose;

public:
    PiecewiseFunction(double margin, FunctionType loss, bool verbose){
        this->margin = margin;
        this->function_type = loss;
        this->verbose = verbose;
    }

    PiecewiseFunction(double margin, FunctionType loss){
        this->margin = margin;
        this->function_type = loss;
        this->verbose = false;
    }

    // Point insertion
    int insert_point(double y, bool is_upper_bound);
    void insert_points();

    // Minimum pointer functions
    double get_minimum_position();
    double get_minimum_value();
};


#endif //MMIT_PIECEWISE_FUNCTION_H
