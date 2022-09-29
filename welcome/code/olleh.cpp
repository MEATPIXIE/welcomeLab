#include <iostream>
#include <string>
using namespace std;


void reverseLetters(string& str){
    int len = str.length();
    int first = 0;
    int last = len - 1;
    while(first <= last){
        swap(str[first],str[last]);
        last = last - 1;
        first = first + 1;
  }
}

string reverseWords(string& str)
{
    int i = str.length() - 1;
    int start, end = i + 1;
    string result = "";
 
    while (i >= 0) {
        if (str[i] == ' ') {
            start = i + 1;
            while (start != end)
                result += str[start++];
            result += ' ';
            end = i;
        }
        if (str[i] == '$'){
            start = i + 1;
            while (start != end)
                result += str[start++];
            result += '$';
            end = i;
        }
        if (str[i] == '.'){
            start = i + 1;
            while (start != end)
                result += str[start++];
            result += '.';
            end = i;
        }
        if (str[i] == ','){
            start = i + 1;
            while (start != end)
                result += str[start++];
            result += ',';
            end = i;
        }
        i--;
    }
    
    start = 0;
    while (start != end){
        result += str[start++];
    }
 
    return result;
}



int main()
{
    string str;
    getline(cin, str);
    
    reverseLetters(str);
    cout << reverseWords(str) << endl;
    
	return 0;
}
