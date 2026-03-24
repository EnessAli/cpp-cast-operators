#ifndef DATA_HPP
# define DATA_HPP

# include <string>

struct Data
{
    int         id;
    std::string name;
    double      value;
    bool        isActive;

    Data(void);
    Data(int id, const std::string& name, double value, bool isActive);
    Data(const Data& src);
    Data& operator=(const Data& src);
    ~Data(void);
    void display(void) const;
};

#endif
