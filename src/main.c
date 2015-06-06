#include "lib/setup.c"

int main()
{
    setup();
    while ( 1 ) loop();
}

void loop()
{
    lcd_box(
            rand() % 130,
            rand() % 130,
            rand() % 130,
            rand() % 130,
            rand() % 256
        );
}
