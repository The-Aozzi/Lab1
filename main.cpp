#include <iostream>

std::pair<int, int> byVal(int first_argument, int second_argument){
    int *first_ptr = &first_argument;
    int *second_ptr = &second_argument;

    if (*first_ptr <= *second_ptr)
        *first_ptr *= 2;
    else
        *second_ptr *= 2;

    *first_ptr ^= *second_ptr;
    *second_ptr ^= *first_ptr;
    *first_ptr ^= *second_ptr;

    return std::pair<int, int>(first_argument, second_argument);
}

void byPtr(int *first_ptr_arg, int *second_ptr_arg){

    if (*first_ptr_arg <= *second_ptr_arg)
        *first_ptr_arg *= 2;
    else
        *second_ptr_arg *= 2;

    *first_ptr_arg ^= *second_ptr_arg;
    *second_ptr_arg ^= *first_ptr_arg;
    *first_ptr_arg ^= *second_ptr_arg;
}

void byRef(int& first_ref_arg, int& second_ref_arg){
    int *first_ptr = &first_ref_arg;
    int *second_ptr = &second_ref_arg;

    if (*first_ptr <= *second_ptr)
        *first_ptr *= 2;
    else
        *second_ptr *= 2;

    *first_ptr ^= *second_ptr;
    *second_ptr ^= *first_ptr;
    *first_ptr ^= *second_ptr;
}

int main(int, char**){
    int first_number, second_number;

    std::cin >> first_number >> second_number;
    std::pair<int, int> res = byVal(first_number, second_number);
    std::cout << res.first << ' ' << res.second << std::endl;

    std::cin >> first_number >> second_number;
    byPtr(&first_number, &second_number);
    std::cout << first_number << ' ' << second_number << std::endl;

    std::cin >> first_number >> second_number;
    byRef(first_number, second_number);
    std::cout << first_number << ' ' << second_number << std::endl;
}

