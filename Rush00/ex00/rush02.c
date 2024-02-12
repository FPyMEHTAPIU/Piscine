#include <unistd.h>

void    ft_putchar(char c);

void    write_line(int width, char l, char m, char r)
{
    int pos;
    
    pos = 1;
    if (width == 1)
    {
        ft_putchar(l);
        ft_putchar('\n');
    }
    else
    {
        ft_putchar(l);
        pos++;
        while (pos > 1 && pos < width)
        {
            ft_putchar(m);
            pos++;
        }
        ft_putchar(r);
        ft_putchar('\n');
    }
}

void    rush(int x, int y)
{
    if (x <= 0 || y <= 0)
    {
        write(1, "Invalid Input!\n", 15);
        return ;
    }
    int line;
    
    line = 1;
    write_line(x, 'A', 'B', 'A');
    line++;
    while (line > 1 && line < y)
    {
        write_line(x, 'B', ' ', 'B');
        line++;
    }
    if (line > 1 && line == y)
    {
        write_line(x, 'C', 'B', 'C');
    }
}