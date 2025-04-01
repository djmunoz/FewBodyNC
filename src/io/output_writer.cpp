// output_writer.cpp
#include "output_writer.hpp"

outputWriter::outputWriter(const std::string& filename)
    : file(filename), header_written(false) {}

outputWriter::~outputWriter() {
    close();
}

void outputWriter::write(const std::vector<BodyState>& bodies) {
    if (!header_written) {
        file << "time,id,x,y,z,vx,vy,vz,mass\n";
        header_written = true;
    }

    for (size_t i = 0; i < bodies.size(); ++i) {
        const auto& b = bodies[i];
        file << b.time << "," << i << ","
             << b.position[0] << "," << b.position[1] << "," << b.position[2] << ","
             << b.velocity[0] << "," << b.velocity[1] << "," << b.velocity[2] << ","
             << b.mass << "\n";
    }
}

void outputWriter::close() {
    if (file.is_open()) file.close();
}
