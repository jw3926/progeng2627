#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> transpose_grid(const std::vector<std::string>& in){ //transpose the grid
    std::string tmp_str;
    std::vector<std::string> out;
    for (int i = 0; i < in.at(0).size(); i++){
        for (int j = 0; j < in.size(); j++){
            tmp_str += in.at(j).at(i);
        }
        out.push_back(tmp_str);
        tmp_str.clear();
    }
    return out;
}

std::vector<std::string> word_slicer(const std::string& in, const int& word_len){//slice the input string into strings with the lengths of the input word length
    std::vector<std::string> sliced;
    std::string tmp;
    for (int i = 0; i < in.size() - word_len + 1; i++){//choose the starting char
        for (int j = 0; j < word_len; j++){//slice the string
            tmp += in.at(j + i);
        }
        sliced.push_back(tmp);
        tmp.clear();
    }
    return sliced;
}

void pop_word(std::vector<std::string>& word_bank, std::string& word){
    bool word_found = false;
    for (int i = 0; i < word_bank.size() - 1; i++){
        if (word_bank.at(i) == word){
            word_found = true;
        }
        if (word_found){
            word_bank.at(i) = word_bank.at(i + 1);
        }
    }
    word_bank.pop_back();
}

std::string hashtag_unmatched(const std::string& in, std::vector<std::vector<int>>& match_pos){// it replaces all the non-match chars with a hashtag
    std::string hashtag;
    for (int i = 0; i < in.size(); i++){
        hashtag += "#";
    }
    for (int i = 0; i < match_pos.size(); i++){
        for (int j = match_pos.at(i).at(0); j < match_pos.at(i).at(1) + 1; j++){
            hashtag.at(j) = in.at(j);
        }
    }
    return hashtag;
}

void string_match(const std::string& in_str, std::vector<std::string>& word_bank_tmp, std::vector<std::string>& word_bank, std::vector<std::vector<int>>& match_pos, int n){//find the matches and record its coordinates
    std::vector<int> coordinate; //the coordinate (a,b)
    std::vector<std::string> sliced;
    std::string word = word_bank.at(n);
    int word_length;
    if (in_str.size() >= word.size()){
        sliced = word_slicer(in_str, word.size()); //slice the input string into lengths of the word
        for (int i = 0; i < sliced.size(); i++){
            if (sliced.at(i) == word){
                coordinate.clear();
                word_length = word.size();
                coordinate = {i, i + word_length - 1};
                pop_word(word_bank_tmp, word);
                match_pos.push_back(coordinate);
            }
        }
    }
}

std::vector<std::string> word_combine(const std::vector<std::string>& in1, const std::vector<std::string>& in2){//combine the two word matrixes produced by word matcher
    std::vector<std::string> out;
    std::string tmp;
    for (int i = 0; i < in1.size(); i++){
        for (int j = 0; j < in1.at(i).size(); j++){
            if (in1.at(i).at(j) == '#'){
                tmp += in2.at(i).at(j);
            }else{
                tmp += in1.at(i).at(j);
            }
        }
        out.push_back(tmp);
        tmp.clear();
    }
    return out;
}

std::string str_combine(std::vector<std::string>& in){//combine the strings, when there is a letter, use letter, otherwise use hashtag
    std::string out;
    char tmp;
    for (int i = 0; i < in.at(0).size(); i++){
        tmp = '#';
        for (int j = 0; j < in.size(); j++){
            if (tmp != in.at(j).at(i) && tmp == '#'){
                tmp = in.at(j).at(i);
            }
        }
        out += tmp;
    }
    return out;
}

void word_match(const std::vector<std::string>& in_str, const std::vector<std::string>& words, std::vector<std::string>& solution, std::vector<std::string>& not_found){ //match the input vector string with the words
    std::vector<std::vector<int>> match_pos; //((a, b), (a, b)) a is the start of the match while b is the end
    std::vector<std::string> tmp;
    std::vector<std::string> word_bank_tmp;
    std::vector<std::string> word_bank = words;
    for (int i = 0; i < in_str.size(); i++){//choose a string from the input vector
        if (word_bank.size() == 0){
            std::string hashtag;
            for (int j = 0; j < in_str.at(0).size(); j++){
                hashtag += "#";
            }
            solution.push_back(hashtag);
        }else{
            tmp.clear();
            word_bank_tmp = word_bank;
            for (int j = 0; j < word_bank.size(); j++){
                string_match(in_str.at(i), word_bank_tmp, word_bank, match_pos, j);
                tmp.push_back(hashtag_unmatched(in_str.at(i), match_pos));
                match_pos.clear();
            }
            word_bank = word_bank_tmp;
            solution.push_back(str_combine(tmp));
        }
        not_found = word_bank;
    }
}

void find_words(const std::vector<std::string>& grid, const std::vector<std::string>& words, std::vector<std::string>& solution, std::vector<std::string>& not_found){//the program that process the grid and synthesize the answer
    std::vector<std::string> solution_row;
    std::vector<std::string> not_found_row;
    std::vector<std::string> solution_col;
    std::vector<std::string> not_found_col;

    word_match(grid, words, solution_row, not_found_row);

    word_match(transpose_grid(grid), not_found_row, solution_col, not_found_col);

    solution = word_combine(solution_row, transpose_grid(solution_col));
    not_found = not_found_col;
}

int main(){

    std::vector<std::string> grid = {
        "xappleg",
        "dzeazkg",
        "zwazzbx",
        "dxnqzoy",
        "qyueytp",
        "pythtyg"
    };

    std::vector<std::string> words = {"peanut", "bot", "mango", "apple", "cinnamon"};
    std::vector<std::string> solution;
    std::vector<std::string> not_found;

    find_words(grid, words, solution, not_found); 

    std::vector<std::string> expected_solution = {
        "#apple#",
        "##e####",
        "##a##b#",
        "##n##o#",
        "##u##t#",
        "##t####"
    };

    std::vector<std::string> expected_not_found = {"mango", "cinnamon"};

    if( (solution == expected_solution) && (not_found == expected_not_found) ){
        std::cout << "test passed" << std::endl;
    }
    else{
        std::cout << "test failed" << std::endl;
    }

    std::cout << "solution:" << std::endl;
    for(int i = 0; i < solution.size(); i++){
        std::cout << solution[i] << std::endl;
    }

    std::cout << "not found:" << std::endl;
    for(int i = 0; i < not_found.size(); i++){
        std::cout << not_found[i] << std::endl;
    }

}