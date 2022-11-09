#include <iostream>
#include <regex>
#include <string>
#include <cmath>
using namespace std;

int binary_to_decimal(int binary)
{
    int result = 0;
    for(int n=0; binary != 0; ++n)
    {
        result += binary%10 * pow(2, n);
        binary /= 10;
    }
    return result;
}

bool is_required_str(string str)//is string containing a binary number multiple of 3
{
    int number, binary_number, digits_sum = 0;
    string processed_str = str;
    smatch result;
    regex reg("\\b[0,1]{1,100}\\b");
    while(regex_search(processed_str, result, reg) == 1)
    {
        binary_number = stoi(result.str(0));
        number = binary_to_decimal(binary_number);
        while(number != 0)
        {
            digits_sum += number%10;
            number /= 10;
        }
        //cout << "num = " << number << endl << "sum of digits = " << digits_sum << endl;
        if(digits_sum % 3 == 0)
            return true;
        processed_str.replace(result.position(0), result.length(0), "");
        digits_sum = 0;
    }
    return false;
}


int main()
{
    string s;
    cout << "Enter string: ";
    cin >> s;
    cout << is_required_str(s) << endl;
}
