// https://www.cppstories.com/2019/10/lazyinit/

// Create file class. 

#include <iostream>
#include <string_view>

class File
{
public:

    // Constructor, accepting file name, will display with fake 'opening file' output.

    File(std::string_view fileName) {
        std::cout << "Opening file " << fileName << std::endl;
    }

    // Destructor, will display fake 'closing file' output.

    ~File() {
        std::cout << "Closing file" << std::endl;
    }

    // Copy constructor is disallowed with delete.

    File(const File&) = delete;

    // File as rvalue??.
    File(File&&) = default;

    // Assignment operator is disallowed.

    File& operator=(const File&) = delete;

    // File as rvalue??.

    File& operator=(File&&) = default;

    // write method, fake write.

    void write(std::string_view str)
    {
        std::cout << "Writing to file: " << str << std::endl;
    }
};

// Config class.

class Config
{
    
    // Create file class member.

    File file;
public:

    // Constructor will pass file name to construct file instance.

    Config() : file{"config.txt"} {
        std::cout << "Config object created" << std::endl;
    }

    // add option member function.

    void addOption(std::string_view name, std::string_view value)
    {
        file.write(name);
        file.write(" = ");
        file.write(value);
        file.write("\n");
    }
};

int main()
{
    Config c;
    std::cout << "Some operations..." << std::endl;
    c.addOption("dark_mode", "true");
    c.addOption("font", "DejaVu Sans Mono");
}
