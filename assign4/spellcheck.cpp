#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(const std::string& source) {
  /* TODO: Implement this method */
  auto it_vec = find_all(source.begin(), source.end(), isspace);
  Corpus tokens;
  auto gen_token = [&source](std::string::const_iterator it1, std::string::const_iterator it2) { 
    Token token(source, it1, it2); 
    return token;
  };
  std::transform(it_vec.begin(), it_vec.end() - 1, it_vec.begin() + 1, std::insert_iterator(tokens, tokens.end()), gen_token);
  auto is_empty = [](Token token) { return token.content.empty(); };
  std::erase_if(tokens, is_empty);
  return tokens;
}

std::set<Mispelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
  /* TODO: Implement this method */
  namespace rv = std::ranges::views;
  auto NotInDict = [&dictionary](Token token) {return !dictionary.contains(token.content);};
  auto Token2Mispelling = [&dictionary](Token token) {
    auto dist1 = [&token] (std::string word) {return (levenshtein(token.content, word) == 1);};
    auto view = dictionary | rv::filter(dist1); 
    std::set<std::string> suggestions(view.begin(), view.end());
    return Mispelling {token, suggestions};
  };
  auto NoSuggestions = [](Mispelling word) {return !word.suggestions.empty();};
  auto v = source | rv::filter(NotInDict) | rv::transform(Token2Mispelling) | rv::filter(NoSuggestions);
  auto view = source 
    | rv::filter(NotInDict)
    | rv::transform(Token2Mispelling)
    | rv::filter(NoSuggestions);
  std::set<Mispelling> ans(view.begin(), view.end());
  return ans;
};

/* Helper methods */

#include "utils.cpp"