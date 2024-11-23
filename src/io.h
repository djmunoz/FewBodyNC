#ifndef IO_H
#define IO_H

#include <vector>
#include <string>  // Correct inclusion of string header
#include "body.h"

struct SolverParams {
  int output_frequency;
  double runtime;
  double timestep;
  std::string integrator;
  double gravitational_constant;
};

void readInitialConditions(const std::string& filename, std::vector<Body>& bodies);
void writeOutput(const std::string& filename, const std::vector<Body>& bodies, double time);
SolverParams readParams(const std::string& filename);

#endif // IO_H

