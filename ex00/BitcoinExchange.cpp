# include "BitcoinExchange.hpp"

int hasInteger(std::string str)
{
    int i = 0;
    while (str[i])
    {
        if (isdigit(str[i]))
            return (1);
        i++;
    }
    return (0);
}


int isNumber(std::string str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

void removeSpaces(std::string &str)
{
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
}

void checkMap(std::map<std::string, float> &map)
{
    if (map.empty())
    {
        std::cout << "Error: could not parse file." << std::endl;
        exit(1);
    }
}

void get_row(std::string &line, std::string &key, std::string &value, char delim)
{
    std::stringstream ss(line);
    std::getline(ss, key, delim);
    std::getline(ss, value, delim);
    removeSpaces(key);
    removeSpaces(value);
}

int isHeader(std::string str, char delim)
{
    std::string key;
    std::string value;

    if (hasInteger(str))
        return (0);
    get_row(str, key, value, delim);
    if (key.empty() || value.empty())
        return (0);
    return (1);
}

void init_data(std::string filename, std::map<std::string, float> &map)
{
    std::string line;
    std::string key;
    std::string value;
    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cout << "Error: could not open file." << std::endl;
        exit(1);
    }
    std::getline(file, line);
    if (isHeader(line, ','))
    {
        line.clear();
        std::getline(file, line);
    }
    while (!line.empty())
    {
        get_row(line, key, value, ',');
        if (key != "" && value != "")
            map[key] = strtod(value.c_str(), NULL); 
        line.clear();
        std::getline(file, line);
    }
    checkMap(map);
}
int check_date(std::string date)
{
    std::string day;
    std::string month;
    std::string year;
    std::string tmp;
    std::stringstream ss(date);
    std::getline(ss, year, '-');
    std::getline(ss, month, '-');
    std::getline(ss, day, ' ');
    std::getline(ss, tmp, ' ');

    if (!tmp.empty())
        return (0);
    if (day.empty() || month.empty() || year.empty())
        return (0);
    if (isNumber(day) == 0 || isNumber(month) == 0 || isNumber(year) == 0)
        return (0 );
    if (day.size() != 2 || month.size() != 2 || year.size() != 4)
        return (0);
    if (day[0] < '0' || day[0] > '3' || day[1] < '0' || day[1] > '9')
        return (0);
    else if (day[0] == '3' && day[1] > '1')
        return (0);
    if (month[0] < '0' || month[0] > '1' || month[1] < '0' || month[1] > '9')
        return (0);
    else if (month[0] == '1' && month[1] > '2')
        return (0);
    return (1);
    
}

void format(std::string &key, std::string &value, std::map<std::string, float> &data)
{
    if (value.empty())
    {
        std::cout << "Error: bad input => " << key << std::endl;
        return ;
    }
    else if (key.empty())
    {
        std::cout << "Error: bad input => " << value << std::endl;
        return ;
    }
    else if (check_date(key) == 0)
    {
        std::cout << "Error: bad date => " << key << std::endl;
        return ;
    }
    double val = strtod(value.c_str(), NULL);
    if (val < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return ;
    }
    else if (val > 1000)
    {
        std::cout << "Error: too large a number.." << std::endl;
        return ;
    }
    else 
    {
        std::map<std::string, float>::iterator it = data.begin();
        if (it->first < key)
        {
            it = data.upper_bound(key);
                --it;
            if (it != data.end())
                std::cout << key <<" => " << val <<" = "<< it->second *  val << std::endl;
        }
        else 
            std::cout << "Error: no data found "<< std::endl;
    }
    
}
void format_input(std::string input, std::map<std::string, float> &data)
{
    std::string key;
    std::string value;
    std::ifstream file(input);
    std::string line;

    if (!file.is_open())
    {
        std::cout << "Error: could not open file." << std::endl;
        exit(1);
    }
    std::getline(file, line);
    get_row(line, key, value, '|');
    if (isHeader(line , '|'))
    {
        line.clear();
        std::getline(file, line);
    }
    while (!line.empty())
    {
        get_row(line, key, value, '|');
        format(key, value, data);
        line.clear();
        std::getline(file, line);
        key.clear();
        value.clear();
    }
}