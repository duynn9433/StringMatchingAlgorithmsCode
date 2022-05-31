cmake_minimum_required(VERSION 3.21)
project(StringMatchingAlgorithms)

set(CMAKE_CXX_STANDARD 14)

add_executable(StringMatchingAlgorithms main.cpp
        Brute_Force/brute_force.cpp Brute_Force/brute_force.h
        graph/graph.cpp graph/graph.h
        Deterministic_Finite_Automaton/deterministic_finite_automaton.cpp Deterministic_Finite_Automaton/deterministic_finite_automaton.h
        Karp-Rabin/Karp-Rabin.cpp Karp-Rabin/Karp-Rabin.h
        Morris-Pratt/Morris-Pratt.cpp Morris-Pratt/Morris-Pratt.h
        Knuth-Morris-Pratt/Knuth-Morris-Pratt.cpp Knuth-Morris-Pratt/Knuth-Morris-Pratt.h
        Apostolico_Crochemore/Apostolico_Crochemore.cpp Apostolico_Crochemore/Apostolico_Crochemore.h
        NotSoNaive/NotSoNaive.cpp NotSoNaive/NotSoNaive.h
        Boyer-Moore/Boyer-Moore.cpp Boyer-Moore/Boyer-Moore.h
        Horspool/Horspool.cpp Horspool/Horspool.h
        Quick-Search/Quick-Search.cpp Quick-Search/Quick-Search.h
        Tuned-Boyer-Moore/Tuned-Boyer-Moore.cpp Tuned-Boyer-Moore/Tuned-Boyer-Moore.h
        Smith/Smith.cpp Smith/Smith.h
        Raita/Raita.cpp Raita/Raita.h Zhu-Takaodo/Zhu-Takaodo.cpp Zhu-Takaodo/Zhu-Takaodo.h Berry-Ravindran/Berry-Ravindran.cpp Berry-Ravindran/Berry-Ravindran.h Optimal-Mismatch/Optimal-Mismatch.cpp Optimal-Mismatch/Optimal-Mismatch.h Maximal-Shift/Maximal-Shift.cpp Maximal-Shift/Maximal-Shift.h Skip-Search/Skip-Search.cpp Skip-Search/Skip-Search.h KMP-Skip-Search/KMP-Skip-Search.cpp KMP-Skip-Search/KMP-Skip-Search.h Alpha-Skip-Search/Alpha-Skip-Search.cpp Alpha-Skip-Search/Alpha-Skip-Search.h StringMatchingOnOrderedAlphabets/StringMatchingOnOrderedAlphabets.cpp StringMatchingOnOrderedAlphabets/StringMatchingOnOrderedAlphabets.h ShiftOr/ShiftOr.cpp ShiftOr/ShiftOr.h)

