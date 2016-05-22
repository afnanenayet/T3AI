#!/bin/bash
g++ -std=gnu++14 ../*.cpp -o T3AI_debug;
valgrind --leak-check=yes ./T3AI_debug > mem_check_results.txt;
