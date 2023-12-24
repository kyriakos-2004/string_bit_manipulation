#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void 
LPSProcessing(const std::string& pattern, std::vector<int>& lps)
{
    int len = 0;
    lps[0] = 0;
    int i = 1;

    while (i < pattern.length())
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[static_cast<std::vector<int, std::allocator<int>>::size_type>(len) - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void 
KMPSearch(const std::string& text, const std::string& pattern)
{
    std::size_t n = text.length();
    std::size_t m = pattern.length();
    std::vector<int> lps(m);
    LPSProcessing(pattern, lps);
    
    int i = 0;
    int j = 0;

    while (i < n)
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }

        if (j == m)
        {
            int line_number = 1;
            for (int k = 0; k < i - j; k++)
            {
                if (text[k] == '\n')
                {
                    line_number++;
                }
            }

            std::cout << "Pattern was found at index " << (i - j) 
                      << " on line number " << line_number << std::endl;
            j = lps[j - 1];
        }
        else if (i < n && text[i] != pattern[j])
        {
            if (j != 0)
            {
                j = lps[static_cast<std::vector<int, std::allocator<int>>::size_type>(j) - 1];
            }
            else
            {
                i++;
            }
        }
    }
}

int main()
{
    std::ifstream file("lorem_ipsum.txt");
    if (!file.is_open())
    {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }

    auto text = std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    std::cout << "Enter the pattern you wish to search for: ";
    std::string pattern;
    std::cin >> pattern;

    KMPSearch(text, pattern);

    return 0;
}