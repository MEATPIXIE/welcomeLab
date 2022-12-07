
#include "Dictionary.h"
#include <string>


Dictionary::Dictionary(std::istream& stream){
    std::string word;
    while(getline(stream, word)){
        for (size_t i = 0; i < word.length(); i++){
            if(isupper(word[i])){
                continue;
            }
        }
        mWords.push_back(word);
    }
    return;
}

Heap Dictionary::correct(const std::vector<Point>& points, size_t maxcount, float cutoff) const{
    Heap scores = Heap(maxcount); 
    return 0;
}
