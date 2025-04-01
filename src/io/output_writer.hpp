// output_writer.hpp
#pragma once
#include "output_writer.hpp"
#include <fstream>

class CSVOutputWriter : public OutputWriter {
public:
    CSVOutputWriter(const std::string& filename);
    ~CSVOutputWriter() override;
    void write(const std::vector<BodyState>& bodies) override;
    void close() override;

private:
    std::ofstream file;
    bool header_written;
};
