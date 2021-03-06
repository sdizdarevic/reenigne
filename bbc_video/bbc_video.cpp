#include "alfe/main.h"

class Program : public ProgramBase
{
public:
    void p(int n)
    {
        if (n < 10)
            printf("%i",n);
        else
            printf("%c",n + 'A' - 10);
        d[c++] = n;
    }
    void run()
    {
        for (int i = 0; i < 256; ++i) {
            printf("0x%02x: ",i);

            c = 0;

            p( (((i&0x80) != 0) ? 8 : 0) |
               (((i&0x20) != 0) ? 4 : 0) |
               (((i&0x08) != 0) ? 2 : 0) |
               (((i&0x02) != 0) ? 1 : 0) );

            p( (((i&0x40) != 0) ? 8 : 0) |
               (((i&0x10) != 0) ? 4 : 0) |
               (((i&0x04) != 0) ? 2 : 0) |
               (((i&0x01) != 0) ? 1 : 0) );

            p( (((i&0x20) != 0) ? 8 : 0) |
               (((i&0x08) != 0) ? 4 : 0) |
               (((i&0x02) != 0) ? 2 : 0) |
               (((1&0x01) != 0) ? 1 : 0) );

            p( (((i&0x10) != 0) ? 8 : 0) |
               (((i&0x04) != 0) ? 4 : 0) |
               (((i&0x01) != 0) ? 2 : 0) |
               (((1&0x01) != 0) ? 1 : 0) );

            p( (((i&0x08) != 0) ? 8 : 0) |
               (((i&0x02) != 0) ? 4 : 0) |
               (((1&0x01) != 0) ? 2 : 0) |
               (((1&0x01) != 0) ? 1 : 0) );

            p( (((i&0x04) != 0) ? 8 : 0) |
               (((i&0x01) != 0) ? 4 : 0) |
               (((1&0x01) != 0) ? 2 : 0) |
               (((1&0x01) != 0) ? 1 : 0) );

            p( (((i&0x02) != 0) ? 8 : 0) |
               (((1&0x01) != 0) ? 4 : 0) |
               (((1&0x01) != 0) ? 2 : 0) |
               (((1&0x01) != 0) ? 1 : 0) );

            p( (((i&0x01) != 0) ? 8 : 0) |
               (((1&0x01) != 0) ? 4 : 0) |
               (((1&0x01) != 0) ? 2 : 0) |
               (((1&0x01) != 0) ? 1 : 0) );

            int u = 0;
            for (int x = 0; x < 8; ++x) {
                int y = 0;
                int dd = d[x];
                for (; y < x; ++y)
                    if (d[y] == dd)
                        break;
                if (y == x)
                    ++u;
            }
            printf(" %i",u);


            printf("\n");


        }
    }
    int c;
    int d[8];
};