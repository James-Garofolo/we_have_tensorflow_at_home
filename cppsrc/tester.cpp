#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "nn_maker.h"
#include "math.h"

using namespace std;

int main(){
    activation one(sig), two(relu), three(int_fire), four(lrelu, 0.001), five(lif, 0.5, 0.99);
    double timeone, timetwo, timethree;

    cout << "sigmoid at zero:\t" << one.activate(0) << "\nsigmoid at a lot:\t" << one.activate(100) << "\n\n";

    cout << "relu positive:\t" << two.activate(2) << "\nrelu negative:\t" << two.activate(-2) << "\n\n";

    timeone = three.activate(0.5);
    timetwo = three.activate(0);
    timethree = three.activate(0.5);

    cout << "non-leaky integrate fire one:\t" << timeone << "two:\t" << timetwo << "three:\t" << timethree << "\n\n";

    cout << "lrelu positive:\t" << four.activate(2) << "\nlrelu negative:\t" << four.activate(-2) << "\n\n";

    timeone = five.activate(0.5);
    timetwo = five.activate(0);
    timethree = five.activate(1.8);

    cout << "leaky integrate fire one:\t " << timeone << "two:\t " << timetwo << "three:\t " << timethree << "\n\n";

    while (true)

    return 0;
}