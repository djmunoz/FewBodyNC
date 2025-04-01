#include <iostream>
#include <vector>    // Correct inclusion of vector header
#include <string>    // Correct inclusion of string header
#include "body.h"
#include "solver.h"
#include "io/io.h"
#include "globals.h"
#include "io/output_writer.hpp"

int main() {
    std::vector<Body> bodies;
    readInitialConditions("data/initial_conditions.txt", bodies);

    outputfilename="output.csv";
    outputWriter output(outputfilename);
    output.writeToFile(bodies); // write out initial state
    
    Solver sim(bodies);
    SolverParams params = readParams("data/param.txt");
    int steps = static_cast<int>(params.runtime / params.timestep);
    sim.run(steps, params.timestep);  // Use runtime and timestep from params

    output.close();
    
    
    
    return 0;
}
