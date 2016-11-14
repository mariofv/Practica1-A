#ifndef MINHASHSIGNATURES_H
#define MINHASHSIGNATURES_H

#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include "kshingle.h"
#include "kshinglemap.h"
#include <unordered_set>
#include <fstream>
#include <list>
#include "reader.h"
using namespace std;

enum PermutationMode {
    Hash,
    Hash32,
    HashWithPrime,
    Random
};

typedef unsigned int uint;
typedef vector<vector<uint>> matrix;

class MinHashSignatures {

    matrix signatures;
    uint medida;
    uint medidaFinal;


    void randomPermutations(const KShingleMap& map, bool tiempo);
public:
    MinHashSignatures(uint t, uint k, const vector<string>& texts, PermutationMode mode, bool tiempo);
    static uint nextPrime(uint number);
    double jaccard(uint a, uint b);
    void permutations32(const vector<string>& texts, uint t, uint k, bool tiempo);
    uint size();
    uint finalSize();
    matrix getSignatures() const;

};

#endif // MINHASHSIGNATURES_H
