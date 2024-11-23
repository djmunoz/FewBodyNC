#include "io.h"
#include "globals.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void readInitialConditions(const std::string& filename, std::vector<Body>& bodies) {
    std::ifstream infile(filename);
    std::string line;

    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        double mass;
        std::vector<double> position(3), velocity(3);

        if (!(iss >> mass >> position[0] >> position[1] >> position[2] 
                   >> velocity[0] >> velocity[1] >> velocity[2])) { break; }
        
        bodies.emplace_back(mass, position, velocity);
    }
    std::cout << "Number of bodies read: " << bodies.size() << std::endl;
}

void writeOutput(const std::string& filename, const std::vector<Body>& bodies, double time) {
    std::ofstream outfile(filename, std::ios_base::app);  // Append to the file

    outfile << time;  // Start with the current time

    for (const auto& body : bodies) {
        outfile << " " << body.mass;
        for (const auto& pos : body.position) outfile << " " << pos;
        for (const auto& vel : body.velocity) outfile << " " << vel;
    }
    outfile << "\n";  // Newline at the end of each timestep
}

SolverParams readParams(const std::string& filename) {
    std::ifstream infile(filename);
    std::string line, param;
    SolverParams params = {100, 10.0, 0.01, "leapfrog", 6.67430e-11};  // Default values


    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        if (iss >> param) {
            if (param == "output_frequency") {
                iss >> params.output_frequency;
            } else if (param == "runtime") {
                iss >> params.runtime;
            } else if (param == "timestep") {
                iss >> params.timestep;
            } else if (param == "integrator") {
                iss >> params.integrator;
            } else if (param == "gravitational_constant") {
	      iss >> params.gravitational_constant;
	    }
        }
    }

    return params;
}
