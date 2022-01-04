#include <stdlib.h>

using namespace std;

enum activation_type {sig, relu, int_fire, lrelu, lif};

class activation{
    private:
        unsigned int function_type;
        float last, slope, threshold;
        float sigmoid(float in);
        float ReLU(float in);
        float integrate_fire(float in);
        float leaky_ReLU(float in);
        float leaky_integrate_fire(float in);
    public:
        activation(unsigned int type, float funct_slope = 0, float int_threshold = 0.9);
        float activate(float in);
};


