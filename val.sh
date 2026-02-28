#!/bin/bash
valgrind --leak-check=full	--show-leak-kinds=all --suppressions=MacroLibX/valgrind.supp ./so_long $1
