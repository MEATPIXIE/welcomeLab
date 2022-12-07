
#include "Dictionary.h"
#include <string>
#include <cmath>
using namespace std;

Dictionary::Dictionary(std::istream& stream){
    string word;
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
    size_t size = points.size();
    float done = 0;
    float average = 0;
    
    for (string word:mWords){
        if (word.length() == size){
            float score = 0;
            for (size_t i = 0; i < word.length(); i++){
                if (islower(word[i])){
                    done = sqrt(pow(points[i].x - QWERTY[word[i] - 'a'].x,2) + pow(points[i].y - QWERTY[word[i] - 'a'].y, 2));
                    score = score + (1/((10 * pow(done,2)) + 1));
                }
            }
            
            average = score/size;
            
            if(average > cutoff){
                if (scores.count() != scores.capacity()){
                    scores.push(word, average);
                }else{
                    if(average > scores.top().score){
                        scores.pushpop(word, average);
                    }
                }
            }
        }
    }
    return scores;
}

