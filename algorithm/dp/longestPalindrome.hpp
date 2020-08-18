#include "../head.h"

std::string longestPalindrome(const char* str)
{
    int len = strlen(str);
    if (len < 2)
    {
        return str;
    }
    int maxlen = 1;
    int begin = 0;
    
}