//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef MCL_TRIE_HH_
# define MCL_TRIE_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include <unordered_map>
# include <functional>



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

namespace mcl
{

  namespace il
  {

    template <typename T>
    class Trie
    {
      public:
        // types

        typedef std::unordered_map<char, Trie*> Tries;
        typedef std::function<T(std::istream&)> Action;


        // ctors

        Trie();
        ~Trie();


        // getters

        T get(std::istream&) const;


        // modifiers

        void add(const std::string&, const Action&);


      private:
        // internal

        void fail(const std::string&) const;


        // data

        Tries children_;
        Action action_;
    };

  }

}



#endif /* !MCL_TRIE_HH_ */
