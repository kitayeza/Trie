#include <iostream>
#include "Trie.h"
#include "gtest/gtest.h"

namespace testing
{
    static const std::vector<std::string> vec = {
            "condemnation","gutter","enzyme","cocktail","respondent","tracker","exchange","contingent",
            "intermission","darling","interrogator","landing","chart","stockpile","commander","program",
            "fillet","dud","mink","snowstorm","sandwich","sole","cleanser","tubing","pineapple","discrimination",
            "traffic","tic","bulimia","presence","place","setup","streetlight","drift","championship","atbat",
            "wrench","asterisk","profiling","meatball","aviator","storm","doubling","pastime","mysticism","crowd",
            "pc","whiff","throwback","version","vacancy","mustard","daughter","diving","conspiracy","upside","designer",
            "doctor","transfusion","restitution","stool","angler","preface","quality","bowler","afternoon","sweat","end",
            "trek","lilac","emphasis","jockey","brain","fence","looter","binoculars","nutrient","juniper","merchant",
            "federalism","stretcher","ethics","periodical","knot","repellent","critter","model","biosolids","section",
            "colonizer","newsman","quiver","liquidity","urgency","hormone","graveyard","filipino","applause","forest","dietitian"
    };
}

TEST(testcase,insert)
{
    nm::Trie<int> trie;
    EXPECT_TRUE(trie.search("hello") == std::nullopt);
    trie.insert("hello",1);
    EXPECT_TRUE(trie.search("hello") == 1);
    trie.insert("hello",2);
    EXPECT_TRUE(trie.search("hello") == 2);
    trie.insert("hell",3);
    EXPECT_TRUE(trie.search("hell") == 3);

    std::vector<std::string> v;
    trie.startsWith("h",v);
    ASSERT_TRUE(v.size() == 2);
}

TEST(testcase, find)
{
    nm::Trie<int> trie;

    int i = 0;

    for (const auto& str : testing::vec)
    {
        i++;
        trie.insert(str, i);
    }

    i = 0;

    for (const auto& str : testing::vec)
    {
        i++;
        EXPECT_EQ(i, trie.search(str));
    }
}

TEST(testcase,starts_with)
{
    nm::Trie<int> trie;

    int i = 0;

    char val = 'c';

    for (const auto& str : testing::vec)
    {
        if(str[0] == val)
        {
            i++;
            trie.insert(str, i);
        }
    }

    std::vector<std::string> v;
    trie.startsWith("c",v);
    ASSERT_TRUE(v.size() == i);

}

int main(){

    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}