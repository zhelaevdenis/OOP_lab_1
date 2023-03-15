#include <iostream>
#include <string>
#include <typeinfo>

int bin2dec(const std::string&  binNumber)
{
    size_t length = binNumber.size();
    int result = 0;
    for (int i = 0; i < length; i++)
    {
        if (binNumber[i] != '0' && binNumber[i] != '1')
        {
            return -1;
        }
        int tempNumber = binNumber[i] - '0';
        result = result +(int)pow(2, (length - 1 - i)) * tempNumber;

    }
    return result;
}

int main(int argc, char* argv[])
{

    if (argc != 2)
    {
        std::cout << "Invalid arguments count" << std::endl;
        std::cout << "Usage: Invert.exe <matrix file name>" << std::endl;
        return 1;
    }

    int decNumber = bin2dec(argv[1]);
    if (decNumber == -1)
    {
        std::cout << "incorrect number" << std::endl;
        return 1;
    }
    else
    {
        std::cout << decNumber << std::endl;
    }

    return 0;
}