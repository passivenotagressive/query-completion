

#pragma once

#include <string>
#include <vector>
#include <map>
#include <codecvt>
#include <locale>
#include <memory>

const size_t TOP_SUGGEST = 5;

class Suggestion {
public:
    std::string word_;
    std::u16string word16_;
    size_t population_;

    Suggestion(std::string word, std::u16string word16, size_t population) :
            word_(std::move(word)), word16_(std::move(word16)), population_(population) {}

    Suggestion() = default;

    ~Suggestion() = default;

    bool operator<(const Suggestion &other) const;
};

class Tree {
public:
    std::map<char16_t, std::shared_ptr<Tree>> next_vertex_;
    std::vector<size_t> ids_;
    int population_;

    void add(const std::u16string &word16, size_t id);

    Tree *find(const std::u16string &prefix);
};

class Lvn {
    std::vector<std::vector<int>> levenshtein_;
    std::u16string current_;
    size_t DEPTH_;

public:

    Lvn(size_t DEPTH);

    void increase(size_t size);

    void update(const std::u16string &str);

    std::tuple<int, int, std::u16string>  correct(const std::u16string &str, Tree *ptr, char16_t prev = '\0');
};

std::vector<size_t> search(Tree *ptr, std::vector<Suggestion> &query);


std::vector<size_t> intersect(std::vector<std::vector<size_t>*> &attempt);
