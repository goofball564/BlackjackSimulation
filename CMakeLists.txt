cmake_minimum_required(VERSION 4.0)
project(BlackjackSimulation C)

set(CMAKE_C_STANDARD 11)

add_executable(BlackjackSimulation main.c
        hand.h
        card.h
        hand.c
        shoe.c
        shoe.h
        card.c
        count.c
        count.h
        strategy.c
        strategy.h)
