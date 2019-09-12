#include "String.h"

int main(int argc, char const *argv[])
{
    StringPtr palabra = new_String("Hola");
    Str_toUpper(palabra);
    printf("%s\n", Str_get(palabra));

    
    return 0;
}
