
#include <stdio.h>
#include <stdlib.h>
#include "nn_maker.h"
#include "math.h"

using namespace std;

activation::activation(unsigned int type, float funct_slope = 0, float int_threshold = 0.9){
    function_type = type;
    threshold = int_threshold;
    slope = funct_slope;
    last = 0;
}

float activation::sigmoid(float in){
    last = 1/(1 + exp(-in));
    return last;
}

float activation::ReLU(float in){
    if (in > 0){
        last = in;
    }
    else{
        last = 0;
    }
    return last;
}

float activation::leaky_ReLU(float in){
    if (in > 0){
        last = in;
    }
    else{
        last = slope*in;
    }
    return last;
}

float activation::integrate_fire(float in){
    last = last + in;
    int temp = last;
    if (last >= threshold){
        last = 0;
        return temp;
    }
    return 0;
}

float activation::leaky_integrate_fire(float in){
    last = (slope * last) + in;
    int temp = last;
    if (last >= threshold){
        last = 0;
        return temp;
    }
    return 0;
}

float activation::activate(float in){
    switch(function_type){
        case sig:
            return sigmoid(in);
            break;
        case relu:
            return ReLU(in);
            break;
        case int_fire:
            return integrate_fire(in);
            break;
        case lrelu:
            return leaky_ReLU(in);
            break;
        case lif:
            return leaky_integrate_fire(in);
            break;
        default:
            return 0;
            break;
    }
}

