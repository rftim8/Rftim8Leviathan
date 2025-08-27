#include "rft_leetcode.hh"

int main()
{
    speedup();
    std::system("cls");

    rft_leetcode_csv lc_csv;
    lc_csv.competition_name = "LeetCode_Warm_Up_Contest";
    lc_csv.rank = 0;
    lc_csv.rating = 0;
    lc_csv.problem_number = "lc_00000386";
    lc_csv.problem_title = "LexicographicalNumbers";
    lc_csv.problem_description = R"(
Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.
You must write an algorithm that runs in O(n) time and uses O(1) extra space. 

Example 1:

Input: n = 13
Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
Example 2:

Input: n = 2
Output: [1,2]

Constraints:

1 <= n <= 5 * 10^4)";
    lc_csv.problem_input = R"(2
2
13
[1,10,11,12,13,2,3,4,5,6,7,8,9]
2
[1,2])";
    lc_csv.difficulty = 1000;
    lc_csv.algorithms = {"dfs", "trie"};
    insertPGLeetCodeFullProblem(lc_csv);

    lc_csv.competition_name = "LeetCode_Warm_Up_Contest";
    lc_csv.rank = 0;
    lc_csv.rating = 0;
    lc_csv.problem_number = "lc_00000387";
    lc_csv.problem_title = "FirstUniqueCharacterInAString";
    lc_csv.problem_description = R"(
Given a string s, find the first non-repeating character in it and return its index. 
If it does not exist, return -1.

Example 1:
Input: s = "leetcode"
Output: 0

Explanation:
The character 'l' at index 0 is the first character that does not occur at any other index.

Example 2:
Input: s = "loveleetcode"
Output: 2

Example 3:
Input: s = "aabb"
Output: -1

Constraints:

1 <= s.length <= 10^5
s consists of only lowercase English letters.)";
    lc_csv.problem_input = R"(3
2
"leetcode"
0
"loveleetcode"
2
"aabb"
-1)";
    lc_csv.difficulty = 0;
    lc_csv.algorithms = {"hash table", "string", "queue", "counting"};
    insertPGLeetCodeFullProblem(lc_csv);

    lc_csv.competition_name = "LeetCode_Warm_Up_Contest";
    lc_csv.rank = 0;
    lc_csv.rating = 0;
    lc_csv.problem_number = "lc_00000388";
    lc_csv.problem_title = "LongestAbsoluteFilePath";
    lc_csv.problem_description = R"(
Suppose we have a file system that stores both files and directories. An example of one system is represented in the following picture:
Here, we have dir as the only directory in the root. dir contains two subdirectories, subdir1 and subdir2. 
subdir1 contains a file file1.ext and subdirectory subsubdir1. subdir2 contains a subdirectory subsubdir2, which contains a file file2.ext.

In text form, it looks like this (with ⟶ representing the tab character):

dir
⟶ subdir1
⟶ ⟶ file1.ext
⟶ ⟶ subsubdir1
⟶ subdir2
⟶ ⟶ subsubdir2
⟶ ⟶ ⟶ file2.ext
If we were to write this representation in code, it will look like this: 
"dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext". 
Note that the '\n' and '\t' are the new-line and tab characters.

Every file and directory has a unique absolute path in the file system, 
which is the order of directories that must be opened to reach the file/directory itself, all concatenated by '/'s. 
Using the above example, the absolute path to file2.ext is "dir/subdir2/subsubdir2/file2.ext". 
Each directory name consists of letters, digits, and/or spaces. 
Each file name is of the form name.extension, where name and extension consist of letters, digits, and/or spaces.

Given a string input representing the file system in the explained format, return the length of the longest absolute path 
to a file in the abstracted file system. 
If there is no file in the system, return 0.

Note that the testcases are generated such that the file system is valid and no file or directory name has length 0.

Example 1:
Input: input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"
Output: 20
Explanation: We have only one file, and the absolute path is "dir/subdir2/file.ext" of length 20.

Example 2:
Input: input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"
Output: 32
Explanation: We have two files:
"dir/subdir1/file1.ext" of length 21
"dir/subdir2/subsubdir2/file2.ext" of length 32.
We return 32 since it is the longest absolute path to a file.

Example 3:
Input: input = "a"
Output: 0
Explanation: We do not have any files, just a single directory named "a".
 
Constraints:

1 <= input.length <= 104
input may contain lowercase or uppercase English letters, 
a new line character '\n', a tab character '\t', a dot '.', a space ' ', and digits.
All file and directory names have positive length.)";
    lc_csv.problem_input = R"(3
2
"dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"
0
"dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"
0
"a"
0)";
    lc_csv.difficulty = 1000;
    lc_csv.algorithms = {"dfs", "string", "stack"};
    insertPGLeetCodeFullProblem(lc_csv);

    closeIOStreams();

    return 0;
}
