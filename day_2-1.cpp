#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string helper2(int idx, string line) {
    string num = "";
    num.push_back(line[idx]);

    for (int j = idx + 1; j < line.length(); j++) {
        char ch = line[j];
        
        if (isdigit(ch)) {
            num.push_back(ch);
        } else {
            break;
        }
    }

    return num;
    //return as int instead?
}

int helper(string line) {
    bool past_header = false;
    for (int i = 0; i < line.length(); i++) {
        char ch = line[i];

        if (ch == ':') {
            past_header = true;
            continue;
        }

        if (past_header) {
            if (isdigit(ch)) {
                //start writing all ch that isdigit to a new string
                //(or vector, just appending them)
                //alt. - log starting idx, end idx, substring it and convert to int
                helper2(i, line);
                //w/o logging the idx helper 2 ends on, for digits > 1 char in length, this logic will run again on subsequent characters
                //need to either keep track of this idx, and ignore all logic in this loop while iterating through idxs between i and helper2 ending j
                //or, preferably, set some sort of flag that terminates when idx j from helper 2 is reached
            }
        }
    }
}

int main() {
    ifstream input;
    input.open("day_2.txt");

    string line;
    while (getline(input, line)) {
        helper(line);
    }

    input.close();
    return 0;
}