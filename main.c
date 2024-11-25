#include "function_for_equation.h"
#include "debug_functions.h"

int main(int argc, char* argv[]) {
    if (argc == 2 && strcmp(argv[1], "-h") == 0) {
        print_instruction();
        return 0;
    }
    #ifdef DEBUG_MOD
        printf("DEBUG POEXALO\n");
        debug_function(); 
    #else
        print_proga();
    #endif //DEBUG_MOD
        
    return 0;
}