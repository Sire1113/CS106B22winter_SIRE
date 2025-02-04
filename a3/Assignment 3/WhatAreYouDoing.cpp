#include "WhatAreYouDoing.h"
#include <cctype>
#include <strlib.h>
using namespace std;

/* TODO: Read the comments in WhatAreYouDoing.h to see what this function needs to do, then
 * delete this comment.
 *
 * Don't forget about the tokenize function defined in WhatAreYouDoing.h; you'll almost
 * certainly want to use it.
 */


Set<string> allEmphasesOfHelper(const string& sentence, Vector<string>& chosen) {
    Vector<string>tokens = tokenize(sentence);
    Set<string> c,c1,c2;
    if (tokens.isEmpty()){
        string s;
        for (string word:chosen){
            s += word;
        }
        c.add(s);
        return c;
    }
    else{
        string first_word,sub_sentence,start;
        int first = 0;
        for (int i = 0;i<tokens.size();i++){
            string token = tokens[i];
            if (isalpha(token[0])){
                first = i;
                first_word = token;
                break;
            }
        }
        for (int i = 0;i<first;i++)
            start += tokens[i];
        for (int i = first + 1;i<tokens.size();i++)
            sub_sentence += tokens[i];
        chosen.add(start+toUpperCase(first_word));
        string s;
        for (string word:chosen){
            s += word;
        }

        c+= allEmphasesOfHelper(sub_sentence,chosen);

        chosen.remove(chosen.size()-1);
        chosen.add(start+toLowerCase(first));
        s = "";
        for (string word:chosen){
            s += word;
        }

        c+= allEmphasesOfHelper(sub_sentence,chosen);
        chosen.remove(chosen.size()-1);
        return c;
    }
}


Set<string> allEmphasesOf(const string& sentence) {
    /* TODO: Delete this line and the next one, then implement this function. */
    // Vector<string> v;
    // return allEmphasesOfHelper(sentence,v);

    //without helper function version
    Vector<string>tokens = tokenize(sentence);
    Set<string> c;
    int num_words =0;
    int start = -1,end;
    string word_mid;
    for (int i=0;i<tokens.size();i++){
        string token = tokens[i];
        if (isalpha(token[0])){
            if (start == -1){
                start = i;}
            end = i+1;
            word_mid = token;
            num_words += 1;
        }
    }
    if (num_words ==0){
        c += sentence;
        return c;
    }
    else if (num_words == 1){
            string end_sentence,start_sentence;
            for (int ii = 0;ii < start;ii++){
                start_sentence += tokens[ii];
            }
            for (int ii = end;ii < tokens.size();ii++){
                end_sentence += tokens[ii];
            }
            c += (start_sentence + toUpperCase(word_mid) + end_sentence);
            c += (start_sentence + toLowerCase(word_mid) + end_sentence);
            return c;
    }
    else {
        bool flag = false;
        string sub_sentence,s0,s_mid;
        int end;
        for (int i=0;i<tokens.size();i++){
            string s = tokens[i];
            if (flag){
                sub_sentence += s;
            }
            else {
                if (isalpha(s[0])){
                    s0 = s;
                    end = i ;
                    flag = true;
                }
            }
        }
        for (int j=0;j<end;j++){
            s_mid += tokens[j];
        }
        Set<string> result = allEmphasesOf(sub_sentence);
        for (string each_s:result){
            c += (s_mid + toUpperCase(s0) + each_s);
            c += (s_mid + toLowerCase(s0) + each_s);
        }
        return c;
    }
}

/* * * * * * Test Cases * * * * * */
#include "GUI/SimpleTest.h"

/* TODO: Add your own tests here. You know the drill - look for edge cases, think about
 * very small and very large cases, etc.
 */














/* * * * * * Test cases from the starter files below this point. * * * * * */

PROVIDED_TEST("Enumerates all options in a simple case.") {
    Set<string> expected = {
        "hello",
        "HELLO",
    };

    EXPECT_EQUAL(allEmphasesOf("Hello"), expected);
}

PROVIDED_TEST("Each option has the right length.") {
    string sentence = "Hello, world!";
    for (string option: allEmphasesOf(sentence)) {
        EXPECT_EQUAL(option.length(), sentence.length());
    }
}

PROVIDED_TEST("Enumerates all options in a more typical case.") {
    Set<string> expected = {
        "you are?",
        "you ARE?",
        "YOU are?",
        "YOU ARE?"
    };

    EXPECT_EQUAL(allEmphasesOf("You Are?"), expected);
}

PROVIDED_TEST("Stress Test: Recursion only branches on words (should take under a second)") {
    /* We're producing a string consisting of fifty copies of the * character. This tokenizes
     * into fifty separate stars. A star is the same whether or not you capitalize it - there
     * is no such thing as an "upper-case" or "lower-case" star. Therefore, your code should
     * not try to form two versions of the sentence, one with the star capitalized and one
     * without, because the two versions will end up being the same and the work to compute
     * both options will dramatically increase the runtime.
     *
     * For reference, if you do try branching the recursion and checking what happens both if
     * you capitalize the star and if you don't, you'll try exploring 2^50 different possible
     * capitalizations. That's 1,125,899,906,842,624 options, and even doing a billion of
     * these a second is going to take over two years to generate them all! And of course,
     * that's all wasted work, since there's only one way to capitalize this sentence, and
     * that's just to leave it as-is.
     *
     * If your code is hanging when this test is running, it likely means that your code is
     * trying to enumerate all of these options. See if you can edit your code so that, if
     * you're given a non-word token, you just leave it as-is and don't change anything.
     */
    string punctuation(50, '*'); // 50 copies of *

    /* The only emphasis is itself. */
    Set<string> expected = {
        punctuation
    };

    EXPECT_EQUAL(allEmphasesOf(punctuation), expected);
}

PROVIDED_TEST("Stress test: Generates each option once (should take at most a few seconds)") {
    /* This sentence has 13 words in it. There are therefore 2^13 = 8192 possible emphases for
     * the words there, which is a big number but not so large that the computer can't handle
     * it if generates each emphasis exactly once.
     *
     * On the other hand, if your code tries to generate the same emphases multiple times,
     * this test may take a very, very long time to complete, and might even appear to freeze
     * up.
     *
     * If your code gets stuck in this test, trace through your code and confirm that you can't
     * produce the same emphasis multiple times. Check to make sure you aren't, for example,
     * looping over every token in the input sentence and deciding which one to capitalize
     * next. The recursion here follows more of an include/exclude type pattern (more like
     * subsets and combinations) than it does a "which is next?" type pattern (more like
     * permutations).
     */
    string yeats = "Turing and turning in a widening gyre / the falcon cannot hear the falconer.";
    EXPECT_EQUAL(allEmphasesOf(yeats).size(), 8192);
}
