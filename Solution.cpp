#include<iostream>
#include<cmath>

bool set_initial_values(const int& n, const int& d, std::string& input_str,
char init_char,char& char_to_replace, int& count_to_replace) noexcept
{

    // Check if enough characters are available to form a possible string.
    if (ceil(n/3.0) - 1 > d)
    {
        return false;
    }

    // Set string with a single character (X or O) by total number.
    input_str = std::string(n + d,init_char);

    if(init_char == 'X')
        char_to_replace = 'O';
    else
        char_to_replace = 'X';
        
    count_to_replace = d;

    return true;
}


std::string calculate_xo_string(const int& countX, const int& countY) noexcept
{
    // Return if input is a negative number
    if (countX < 0 || countY < 0)
    {
        return std::string("Arguments cannot be negative");
    }

    // Output string to be populated with correct X and O combination.
    std::string count_str;  
    
    char char_to_replace;
    int count_to_replace = 0;
    bool is_set = false;

    // Fill string with eiter 'X' or 'O' with total count of X and O
    if (countX > countY)
        is_set = set_initial_values(countX,countY,count_str,'X',char_to_replace,count_to_replace);
    else
        is_set = set_initial_values(countY,countX,count_str,'O',char_to_replace,count_to_replace);
    

    if(!is_set)
    {
        return std::string("Error : Not enough characters available to build possible combination!");
    }

    // Start replacing the character at position 4. i.e (XXXO, OOOX)
    int step_size = 4;

    // Index to be replaced by character  
    int curr_pos = step_size - 1;  

    // Track if all characters have been replaced  
    int count = 0;


    while(count < count_to_replace)
    {
        int forward_iterator = curr_pos;

        // Iterate and replace till we reach to count
        while ((forward_iterator) < (int)count_str.length() && count < count_to_replace)
        {
            // Jump to index and change the character on that position.
            count_str[forward_iterator] = char_to_replace;

            // Move the iterator to next position.
            forward_iterator += step_size;

            count++;

            //std::cout << count_str << std::endl;

        }

        // Move iterator to one position back in case the characters are available to replace.
        curr_pos--;
    }

    return count_str;
}

int main(int argc, char* argv[])
{
    const int countX = 15;
    const int countY = 4;

    std::cout << calculate_xo_string(countX,countY) << std::endl;


    /* ---------------- Count Verification ----------------

        std::string res = calculate_xo_string(countX,countY);

        int count_x = 0;
        int count_y = 0;

        for(const char& c :  res)
        {
            if(c == 'X')
                count_x++;
            else
                count_y++;
        }
        
        std:: cout << "X:" << count_x << ", Y:" << count_y << std::endl;
    -------------------------------------------------*/

    return 0;
}