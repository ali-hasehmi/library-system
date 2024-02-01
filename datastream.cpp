#include "datastream.h"

#include <iostream>

inputDataStream::inputDataStream(std::ifstream *input_file)
    : mp_input_file(input_file)
{
}



inputDataStream &operator>>(inputDataStream &inputStream, float &i)
{
    inputStream.mp_input_file->read((char *)&i, sizeof(float));
    return inputStream;
}

inputDataStream &operator>>(inputDataStream &inputStream, double &i)
{
    inputStream.mp_input_file->read((char *)&i, sizeof(double));
    return inputStream;
}

inputDataStream &operator>>(inputDataStream &inputStream, uint32_t &i)
{
    inputStream.mp_input_file->read((char *)&i, sizeof(uint32_t));
    return inputStream;
}

inputDataStream &operator>>(inputDataStream &inputStream, uint64_t &i)
{
    inputStream.mp_input_file->read((char *)&i, sizeof(uint64_t));
    return inputStream;
}

inputDataStream &operator>>(inputDataStream &inputStream, uint16_t &i)
{
    inputStream.mp_input_file->read((char *)&i, sizeof(uint16_t));
    return inputStream;
}

inputDataStream &operator>>(inputDataStream &inputStream, uint8_t &i)
{
    inputStream.mp_input_file->read((char *)&i, sizeof(uint8_t));
    return inputStream;
}

inputDataStream &operator>>(inputDataStream &inputStream, bool &i)
{
    inputStream.mp_input_file->read((char *)&i, sizeof(bool));
    return inputStream;
}

inputDataStream &operator>>(inputDataStream &inputStream, std::string &i)
{
    size_t string_size;
    inputStream>>string_size;
    std::cout << "string size " << string_size << std::endl;
    char* str_buff = new char[(string_size+1)*sizeof(char)];
    inputStream.mp_input_file->read(str_buff,string_size*sizeof(char));
    str_buff[string_size] = '\0';
    std::string tmp(str_buff,string_size);
    i = tmp;
    delete str_buff; 
    return inputStream;
}

inputDataStream &operator>>(inputDataStream &inputStream, int16_t &i)
{
    inputStream.mp_input_file->read((char *)&i, sizeof(int16_t));
    return inputStream;
}

inputDataStream &operator>>(inputDataStream &inputStream, int32_t &i)
{
    inputStream.mp_input_file->read((char *)&i, sizeof(int32_t));
    return inputStream;
}

inputDataStream &operator>>(inputDataStream &inputStream, int64_t &i)
{
    inputStream.mp_input_file->read((char *)&i, sizeof(int64_t));
    return inputStream;
}

inputDataStream &operator>>(inputDataStream &inputStream, char &i)
{
    inputStream.mp_input_file->read((char *)&i, sizeof(char));
    return inputStream;
}

/*===============================================================================================================
==============================================================================
\==============================================================================================
------------------------------*/

outputDataStream::outputDataStream(std::ofstream *output_file)
    : mp_output_file(output_file)
{
}




outputDataStream &operator<<(outputDataStream &outputStream, const float &i)
{
    outputStream.mp_output_file->write((char *)&i, sizeof(i));
    return outputStream;
}

outputDataStream &operator<<(outputDataStream &outputStream, const double &i)
{
    outputStream.mp_output_file->write((char *)&i, sizeof(i));
    return outputStream;
}

outputDataStream &operator<<(outputDataStream &outputStream, const uint32_t &i)
{
    outputStream.mp_output_file->write((char *)&i, sizeof(i));
    return outputStream;
}

outputDataStream &operator<<(outputDataStream &outputStream, const uint64_t &i)
{
    outputStream.mp_output_file->write((char *)&i, sizeof(i));
    return outputStream;
}

outputDataStream &operator<<(outputDataStream &outputStream, const uint16_t &i)
{
    outputStream.mp_output_file->write((char *)&i, sizeof(i));
    return outputStream;
}

outputDataStream &operator<<(outputDataStream &outputStream, const uint8_t &i)
{
    outputStream.mp_output_file->write((char *)&i, sizeof(i));
    return outputStream;
}

outputDataStream &operator<<(outputDataStream &outputStream, const bool &i)
{
    outputStream.mp_output_file->write((char *)&i, sizeof(bool));
    return outputStream;
}

outputDataStream &operator<<(outputDataStream &outputStream, const std::string &i)
{
    size_t string_size = i.size();
    outputStream<<string_size;
    outputStream.mp_output_file->write(i.data(),string_size*sizeof(char));
    return outputStream;
}

outputDataStream &operator<<(outputDataStream &outputStream, const int16_t &i)
{
    outputStream.mp_output_file->write((char *)&i, sizeof(i));
    return outputStream;
}

outputDataStream &operator<<(outputDataStream &outputStream, const int32_t &i)
{
    outputStream.mp_output_file->write((char *)&i, sizeof(i));
    return outputStream;
}

outputDataStream &operator<<(outputDataStream &outputStream, const int64_t &i)
{
    outputStream.mp_output_file->write((char *)&i, sizeof(i));
    return outputStream;
}

outputDataStream &operator<<(outputDataStream &outputStream, const char &i)
{
    outputStream.mp_output_file->write((char *)&i, sizeof(i));
    return outputStream;
}
