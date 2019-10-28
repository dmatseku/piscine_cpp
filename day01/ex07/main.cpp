#include <iostream>
#include <fstream>
#include <string>

static void with_endl(std::ifstream& input_file, std::ofstream& output_file, std::string& buffer, std::string str, std::string rstr)
{
    while (std::getline(input_file, buffer))
    {
        while (buffer.find(str) != std::string::npos)
        {
            buffer.replace(buffer.find(str), str.length(), rstr);
        }
        output_file << buffer;
        if (!input_file.eof())
            output_file << std::endl;
    }
}

static bool check_strings(std::string str1, std::string str2)
{
    return (str1 != str2 && str2.find(str1) == std::string::npos);
}

int main(int ac, char** av)
{
    if (ac < 4)
    {
        std::cout << "Arguments error" << std::endl;
    }
    else if (!check_strings(av[2], av[3]))
    {
        std::cout << "Input strings error" << std::endl;
        exit(0);
    }
    else
    {
        std::string     buffer;
        std::string     p_str = av[2];
        std::string     str = av[3];
        std::string     name_tmp = ".replace";
        name_tmp.insert(0, av[1]);
        std::ifstream   input_file(av[1]);
        if (input_file.fail())
        {
            std::cout << "File error" << std::endl;
            exit(0);
        }
        std::ofstream   output_file(name_tmp);
        if (output_file.fail())
        {
            std::cout << "File error" << std::endl;
            exit(0);
        }
        
        with_endl(input_file, output_file, buffer, av[2], av[3]);
        
        input_file.close();
        output_file.close();
    }
    return (0);
}