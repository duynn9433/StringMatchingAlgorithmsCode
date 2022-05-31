#include <bits/stdc++.h>
#include "Brute_Force/brute_force.h"
#include "Karp-Rabin/Karp-Rabin.h"
#include "Morris-Pratt/Morris-Pratt.h"
#include "Knuth-Morris-Pratt/Knuth-Morris-Pratt.h"
#include "Apostolico_Crochemore/Apostolico_Crochemore.h"
#include "StringMatchingOnOrderedAlphabets/StringMatchingOnOrderedAlphabets.h"
#include "ShiftOr/ShiftOr.h"
#include "NotSoNaive/NotSoNaive.h"
#include "Boyer-Moore/Boyer-Moore.h"
#include "Zhu-Takaodo/Zhu-Takaodo.h"
#include "Berry-Ravindran/Berry-Ravindran.h"
#include "Optimal-Mismatch/Optimal-Mismatch.h"
#include "Maximal-Shift/Maximal-Shift.h"
#include "Skip-Search/Skip-Search.h"
#include "KMP-Skip-Search/KMP-Skip-Search.h"
#include "Horspool/Horspool.h"
#include "Quick-Search/Quick-Search.h"
#include "Tuned-Boyer-Moore/Tuned-Boyer-Moore.h"
#include "Smith/Smith.h"
#include "Raita/Raita.h"

using namespace std;

void print(vector<int> res){
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
}

int main(){
//    char x[] = "abcdefghijklmnopqrstuvwxyzjkl132";
//    char y[] = "jkl";
    char x[] = "gcatcgcagagagtatacagtacg";
//    char y[] = "abcddabc";
    char y[] = "gcagagag";
    //left to right
//    BruteForce
//    print(BF(y, strlen(y), x, strlen(x)));
//    KarpRabin
//    print(KR(y, strlen(y), x, strlen(x)));
//    print(MorrisPratt(y, strlen(y), x, strlen(x)));
//    print(KnuthMorrisPratt(y, strlen(y), x, strlen(x)));
//    print(ApostolicoCrochemore(y, strlen(y), x, strlen(x)));
//    print(NotSoNaive(y, strlen(y), x, strlen(x)));
//    print(StringMatchingOnOrderedAlphabets(y, strlen(y), x, strlen(x)));
    print(ShiftOr(y, strlen(y), x, strlen(x)));

    // right to left
//    print(BoyerMoore(y, strlen(y), x, strlen(x)));
//    print(ZhuTakaodo(y, strlen(y), x, strlen(x)));
//    print(BerryRavindran(y, strlen(y), x, strlen(x)));


    //special
//    print(OptimalMismatch(y, strlen(y), x, strlen(x)));
//    print(MaximalShift(y, strlen(y), x, strlen(x)));
//    print(SkipSearch(y, strlen(y), x, strlen(x)));
//    print(KMPSkipSearch(y, strlen(y), x, strlen(x)));

    // random
//    print(Horspool(y, strlen(y), x, strlen(x)));
//    print(QuickSearch(y, strlen(y), x, strlen(x)));
//    print(TunedBoyerMoore(y, strlen(y), x, strlen(x)));
//    print(Smith(y, strlen(y), x, strlen(x)));
//    print(Raita(y, strlen(y), x, strlen(x)));

    return 0;
}
