/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Please write your names here>
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good input") {
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n@-------@\n@-@@@@@-@\n@-@---@-@\n@-@@@@@-@\n@-------@\n@@@@@@@@@"));
	CHECK(nospaces(mat(11, 15, '#', '*')) == nospaces("###########\n#*********#\n#*#######*#\n#*#*****#*#\n#*#*###*#*#\n#*#*#*#*#*#\n#*#*#*#*#*#\n#*#*#*#*#*#\n#*#*#*#*#*#\n#*#*#*#*#*#\n#*#*###*#*#\n#*#*****#*#\n#*#######*#\n#*********#\n###########"));
	CHECK(nospaces(mat(13, 9, 't', 'x')) == nospaces("ttttttttttttt\ntxxxxxxxxxxxt\ntxtttttttttxt\ntxtxxxxxxxtxt\ntxtxtttttxtxt\ntxtxxxxxxxtxt\ntxtttttttttxt\ntxxxxxxxxxxxt\nttttttttttttt"));
	CHECK(nospaces(mat(3, 5, 'e', '^')) == nospaces("eee\ne^e\ne^e\ne^e\neee"));
	CHECK(nospaces(mat(7, 1, '&', '|')) == nospaces("&&&&&&&"));
	CHECK(nospaces(mat(7, 9, 'e', '1')) == nospaces("eeeeeee\ne11111e\ne1eee1e\ne1e1e1e\ne1e1e1e\ne1e1e1e\ne1eee1e\ne11111e\neeeeeee"));
	CHECK(nospaces(mat(15, 7, '3', '4')) == nospaces("333333333333333\n344444444444443\n343333333333343\n343444444444343\n343333333333343\n344444444444443\n333333333333333"));
	CHECK(nospaces(mat(5, 1, 'f', 't')) == nospaces("fffff"));
	CHECK(nospaces(mat(7, 3, 'p', 'q')) == nospaces("ppppppp\npqqqqqp\nppppppp"));
	CHECK(nospaces(mat(1, 1, '6', '9')) == nospaces("6"));
	CHECK(nospaces(mat(7, 11, 'e', '^')) == nospaces("eeeeeee\ne^^^^^e\ne^eee^e\ne^e^e^e\ne^e^e^e\ne^e^e^e\ne^e^e^e\ne^e^e^e\ne^eee^e\ne^^^^^e\neeeeeee"));
	CHECK(nospaces(mat(5, 3, 'o', 'p')) == nospaces("ooooo\nopppo\nooooo"));
	CHECK(nospaces(mat(15, 7, 'x', 't')) == nospaces("xxxxxxxxxxxxxxx\nxtttttttttttttx\nxtxxxxxxxxxxxtx\nxtxtttttttttxtx\nxtxxxxxxxxxxxtx\nxtttttttttttttx\nxxxxxxxxxxxxxxx"));
	CHECK(nospaces(mat(23, 15, 'y', '$')) == nospaces("yyyyyyyyyyyyyyyyyyyyyyy\ny$$$$$$$$$$$$$$$$$$$$$y\ny$yyyyyyyyyyyyyyyyyyy$y\ny$y$$$$$$$$$$$$$$$$$y$y\ny$y$yyyyyyyyyyyyyyy$y$y\ny$y$y$$$$$$$$$$$$$y$y$y\ny$y$y$yyyyyyyyyyy$y$y$y\ny$y$y$y$$$$$$$$$y$y$y$y\ny$y$y$yyyyyyyyyyy$y$y$y\ny$y$y$$$$$$$$$$$$$y$y$y\ny$y$yyyyyyyyyyyyyyy$y$y\ny$y$$$$$$$$$$$$$$$$$y$y\ny$yyyyyyyyyyyyyyyyyyy$y\ny$$$$$$$$$$$$$$$$$$$$$y\nyyyyyyyyyyyyyyyyyyyyyyy"));
	CHECK(nospaces(mat(9, 19, '@', 'a')) == nospaces("@@@@@@@@@\n@aaaaaaa@\n@a@@@@@a@\n@a@aaa@a@\n@a@a@a@a@\n@a@a@a@a@\n@a@a@a@a@\n@a@a@a@a@\n@a@a@a@a@\n@a@a@a@a@\n@a@a@a@a@\n@a@a@a@a@\n@a@a@a@a@\n@a@a@a@a@\n@a@a@a@a@\n@a@aaa@a@\n@a@@@@@a@\n@aaaaaaa@\n@@@@@@@@@"));
	CHECK(nospaces(mat(5, 1, '&', '!')) == nospaces("&&&&&"));
	CHECK(nospaces(mat(9, 7, 'a', 'z')) == nospaces("aaaaaaaaa\nazzzzzzza\nazaaaaaza\nazazzzaza\nazaaaaaza\nazzzzzzza\naaaaaaaaa"));
	CHECK(nospaces(mat(7, 7, '5', 'x')) == nospaces("5555555\n5xxxxx5\n5x555x5\n5x5x5x5\n5x555x5\n5xxxxx5\n5555555"));
	CHECK(nospaces(mat(7, 3, 'a', 'b')) == nospaces("aaaaaaa\nabbbbba\naaaaaaa"));
	CHECK(nospaces(mat(5, 13, '!', 'x')) == nospaces("!!!!!\n!xxx!\n!x!x!\n!x!x!\n!x!x!\n!x!x!\n!x!x!\n!x!x!\n!x!x!\n!x!x!\n!x!x!\n!xxx!\n!!!!!"));
	CHECK(nospaces(mat(15, 5, '1', '0')) == nospaces("111111111111111\n100000000000001\n101111111111101\n100000000000001\n111111111111111"));
	CHECK(nospaces(mat(21, 13, 'l', 's')) == nospaces("lllllllllllllllllllll\nlsssssssssssssssssssl\nlslllllllllllllllllsl\nlslssssssssssssssslsl\nlslslllllllllllllslsl\nlslslssssssssssslslsl\nlslslslllllllllslslsl\nlslslssssssssssslslsl\nlslslllllllllllllslsl\nlslssssssssssssssslsl\nlslllllllllllllllllsl\nlsssssssssssssssssssl\nlllllllllllllllllllll"));
	CHECK(nospaces(mat(3, 9, 'e', '^')) == nospaces("eee\ne^e\ne^e\ne^e\ne^e\ne^e\ne^e\ne^e\neee"));
	CHECK(nospaces(mat(1, 15, 'd', 'b')) == nospaces("d\nd\nd\nd\nd\nd\nd\nd\nd\nd\nd\nd\nd\nd\nd"));
}

TEST_CASE("Bad input") {
    CHECK_THROWS(mat(10, 5, '$', '%'));
    /* Add more test here */
	CHECK_THROWS(mat(21, 10, '@', '-'));
	CHECK_THROWS(mat(6, 7, '#', '!'));
	CHECK_THROWS(mat(1, 2, '^', '!'));
	CHECK_THROWS(mat(16, 16, 'u', 'x'));
	CHECK_THROWS(mat(2, 1, 'p', '3'));
	CHECK_THROWS(mat(5, 4, '?', 'y'));
	CHECK_THROWS(mat(9, 0, '1', '0'));
	CHECK_THROWS(mat(-1, 3, '@', 'r'));
	CHECK_THROWS(mat(20, -5, 'f', 'w'));
	CHECK_THROWS(mat(3, 6, 'a', 'b'));
	CHECK_THROWS(mat(16, 17, '?', '!'));
	CHECK_THROWS(mat(7, 16, '!', '?'));
	CHECK_THROWS(mat(32, 14, 'w', 'q'));
	CHECK_THROWS(mat(2, 8, '5', '6'));
	CHECK_THROWS(mat(12, 30, '>', '<'));
	CHECK_THROWS(mat(32, 19, 'p', 'q'));
	CHECK_THROWS(mat(26, 24, ',', ':'));
	CHECK_THROWS(mat(10, 11, 'b', 'c'));
	CHECK_THROWS(mat(6, 1, 'c', 'x'));
	CHECK_THROWS(mat(-9, -7, 'w', 'm'));
	CHECK_THROWS(mat(4, 11, 'y', 'z'));
	CHECK_THROWS(mat(8, 7, '*', '@'));
}


/* Add more test cases here */
