#pragma once
#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <memory>
#ifndef TREE_TRIE_H
#define TREE_TRIE_H

namespace nm
{

    template <class T>
    class Node {

        T data;
        bool mark{};
        std::array<std::shared_ptr<Node<T>>,26> children;

    public:

        Node() = default;
        Node(const Node&) = delete;

        Node& operator = (const Node&) = delete;

        [[nodiscard]] int toIndex(char c) const noexcept { return c - 'a'; }

        void setLeaf(int i) noexcept { children[i] = std::make_shared<Node<T>>(); }
        void setMark(bool b) noexcept { mark = b; }
        void setData(T d) noexcept { data = d; }

        Node* getLeaf(int i) const noexcept { return children[i].get(); }
        [[nodiscard]] bool getMark()  const noexcept { return mark; }
        T getData() const noexcept { return data; }

    };

    template <class T>
    class Trie {

        std::unique_ptr<Node<T>> root;


    public:

        Trie();
        Trie(const T&) = delete;

        Trie& operator=(const Trie&) = delete;

        void insert(const std::string& str, const T& data) noexcept;
        Node<T>* find(const std::string& str) const noexcept;
        void startsWith(const std::string& str,std::vector<std::string>& v) const noexcept;

    };


    template <class T>
    Trie<T>::Trie()
    {
        root = std::make_unique<Node<T>>();
    }

    template <class T>
    void Trie<T>::insert(const std::string& str, const T& data) noexcept
    {
        auto tmp = root.get();

        for (char i : str)
        {
            auto index = tmp->toIndex(i);

            if(!tmp->getLeaf(index)) tmp->setLeaf(index);

            tmp = tmp->getLeaf(index);
        }

        tmp->setMark(true);
        tmp->setData(data);
    }

    template<class T>
    Node<T>* Trie<T>::find(const std::string &str) const noexcept
    {
        auto tmp = root.get();

        for (char i : str)
        {
            auto index = tmp->toIndex(i);

            if(!tmp->getLeaf(index)) return nullptr;

            tmp = tmp->getLeaf(index);
        }

        return tmp;

    }

    template<class T>
    void Trie<T>::startsWith(const std::string& str, std::vector<std::string>& v) const noexcept
    {
        auto tmp = find(str);

        if(!tmp) return;

        std::string res = str;

        if(tmp->getMark()) v.push_back(res);

        for (int i = 0; i < 26; ++i)
        {
            if(tmp->getLeaf(i))
            {
                res += i +'a';
                startsWith(res,v);
                res.pop_back();
            }
        }

    }

}


#endif //TREE_TRIE_H
