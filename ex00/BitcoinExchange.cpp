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

void removeSpaces(std::string &str)
{
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
}

std::ifstream openFile(std::string filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cout << "Error: could not open file." << std::endl;
        exit(1);
    }
    return file;
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
    std::ifstream file;

    file = openFile(filename);
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
		if (it->first > key)
		{
			std::cout << "Error: no data found "<< std::endl;
			return;
		}
		it = data.upper_bound(key);
			--it;
		if (it != data.end())
			std::cout << key <<" => " << val <<" = "<< it->second *  val << std::endl;
    }
    
}
void format_input(std::string input, std::map<std::string, float> &data)
{
    std::string key;
    std::string value;
    std::ifstream file;
    std::string line;

    file = openFile(input);
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