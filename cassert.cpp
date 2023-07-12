#include <iostream>
#include <cassert>

void mprintf(const char* format)
{
    while (*format)
    {
        if (*format == '%' && *(++format) == '%')
        {
            assert(!"unhandled format specifier");
        }
        std::cout << *format++;
    }
}

template<typename T, typename... Args>
void mprintf(const char* format, T value, Args... args)
{
    while (*format)
    {
        if (*format == '%' && *(++format) != '%')
        {
            std::cout << value;
            return mprintf(++format, args...);
        }
        std::cout << *format++;
    }
    assert(!"extra arguments provided to mprintf");
}

int main()
{
    mprintf("%s, %s!", "Hello", "world");

    return 0;
}