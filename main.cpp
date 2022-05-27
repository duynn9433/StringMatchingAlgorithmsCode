#include <bits/stdc++.h>
#include "Brute_Force/brute_force.h"
#include "Karp-Rabin/Karp-Rabin.h"
#include "Morris-Pratt/Morris-Pratt.h"
#include "Knuth-Morris-Pratt/Knuth-Morris-Pratt.h"
#include "Apostolico_Crochemore/Apostolico_Crochemore.h"
using namespace std;

void print(vector<int> res){
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
}
void callBruteForce(char* x, char* y);
void callKarpRabin(char* x, char* y);
void callMorrisPratt(char* x, char* y);
void callKnuthMorrisPratt(char* x, char* y);

int main(){
//    char x[] = "abcdefghijklmnopqrstuvwxyzjkl132";
//    char y[] = "jkl";
    char x[] = "gcatcgcagagagtatacagtacg";
//    char y[] = "abcddabc";
    char y[] = "gcagagag";
//    callBruteForce(x,y);
//    callKarpRabin(x,y);
//    callMorrisPratt(x,y);
//    print(KnuthMorrisPratt(y, strlen(y), x, strlen(x)));
    print(ApostolicoCrochemore(y, strlen(y), x, strlen(x)));
    return 0;
}

void callBruteForce(char* x, char* y){
    vector<int> res = BF(y, strlen(y), x, strlen(x));
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
}
void callKarpRabin(char* x, char* y){
    vector<int> res = KR(y, strlen(y), x, strlen(x));
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
}
void callMorrisPratt(char* x, char* y){
    vector<int> res = MorrisPratt(y, strlen(y), x, strlen(x));
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
}
void callKnuthMorrisPratt(char* x, char* y){
    vector<int> res = KnuthMorrisPratt(y, strlen(y), x, strlen(x));
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
}