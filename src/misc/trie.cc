//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

#include <cctype>
#include <istream>
#include "nauths/mcl/color.hh"
#include "misc/trie.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

namespace mcl
{

  namespace il
  {


    // constructors

    template <typename T>
    Trie<T>::Trie()
    {
    }

    template <typename T>
    Trie<T>::~Trie()
    {
      for (const auto& p : children_)
        delete p.second;
    }



    // getters

    template <typename T>
    T
    Trie<T>::get(std::istream& istr) const
    {
      const Trie* current = this;
      std::string key;

      while (true)
      {
        auto letr = istr.peek();
        auto next = current->children_.find(tolower(letr));

        key += letr;
        if (next == current->children_.end())
          break;

        istr.get();
        current = next->second;
      }

      if (not current->action_)
        fail(key);

      return current->action_(istr);
    }



    // modifiers

    template <typename T>
    void
    Trie<T>::add(const std::string& key, const Action& a)
    {
      Trie* current = this;

      for (char c : key)
      {
        auto next = current->children_[tolower(c)];
        if (next == nullptr)
          current->children_[tolower(c)] = (next = new Trie());
        current = next;
      }

      current->action_ = a;
    }



    // internal

    template <>
    void
    Trie<Color>::fail(const std::string& key) const
    {
      throw std::runtime_error("read<Color>: failed to find a match starting with \"" + key + "\"");
    }

    template <>
    void
    Trie<SpaceType>::fail(const std::string& key) const
    {
      throw std::runtime_error("read<ColorSpace>: failed to find a match starting with \"" + key + "\"");
    }


  }

}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Instantiation

namespace mcl
{

  namespace il
  {


    template class Trie<Color>;
    template class Trie<SpaceType>;


  }

}
