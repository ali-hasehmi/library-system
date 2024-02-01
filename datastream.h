#ifndef DATASTREAM_H
#define DATASTREAM_H

#include <fstream>
#include <string>
#include <cinttypes>

class inputDataStream
{
public:
    inputDataStream(std::ifstream *input_file);

    friend inputDataStream &operator>>(inputDataStream &inputStream, float &i);
    friend inputDataStream &operator>>(inputDataStream &inputStream, double &i);
    friend inputDataStream &operator>>(inputDataStream &inputStream, int16_t &i);
    friend inputDataStream &operator>>(inputDataStream &inputStream, int32_t &i);
    friend inputDataStream &operator>>(inputDataStream &inputStream, int64_t &i);
    friend inputDataStream &operator>>(inputDataStream &inputStream, char &i);
    friend inputDataStream &operator>>(inputDataStream &inputStream, double &i);
    friend inputDataStream &operator>>(inputDataStream &inputStream, uint32_t &i);
    friend inputDataStream &operator>>(inputDataStream &inputStream, uint64_t &i);
    friend inputDataStream &operator>>(inputDataStream &inputStream, uint16_t &i);
    friend inputDataStream &operator>>(inputDataStream &inputStream, uint8_t &i);
    friend inputDataStream &operator>>(inputDataStream &inputStream, bool &i);
    friend inputDataStream &operator>>(inputDataStream &inputStream, std::string &i);

private:
    std::ifstream *mp_input_file;
};

class outputDataStream
{

public:
    outputDataStream(std::ofstream *output_file);

    friend outputDataStream &operator<<(outputDataStream &outputStream, const float &i);
    friend outputDataStream &operator<<(outputDataStream &outputStream, const double &i);
    friend outputDataStream &operator<<(outputDataStream &outputStream, const int16_t &i);
    friend outputDataStream &operator<<(outputDataStream &outputStream, const int32_t &i);
    friend outputDataStream &operator<<(outputDataStream &outputStream, const int64_t &i);
    friend outputDataStream &operator<<(outputDataStream &outputStream, const char &i);
    friend outputDataStream &operator<<(outputDataStream &outputStream, const double &i);
    friend outputDataStream &operator<<(outputDataStream &outputStream, const uint32_t &i);
    friend outputDataStream &operator<<(outputDataStream &outputStream, const uint64_t &i);
    friend outputDataStream &operator<<(outputDataStream &outputStream, const uint16_t &i);
    friend outputDataStream &operator<<(outputDataStream &outputStream, const uint8_t &i);
    friend outputDataStream &operator<<(outputDataStream &outputStream, const bool &i);
    friend outputDataStream &operator<<(outputDataStream &outputStream, const std::string &i);

private:
    std::ofstream *mp_output_file;
};

#endif // DATASTREAM_H