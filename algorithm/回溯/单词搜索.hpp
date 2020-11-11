/*
题目：给定一个二维网格和一个单词，找出该单词是否存在于网格中。
单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
同一个单元格内的字母不允许被重复使用
解法：深度优先搜索 DFS

我们可以将矩阵看作一个无向图。对于无向图，我们可以采用深度优先搜索和广度优先搜索两种办法进行遍历。
因此对于 word = ABCCEE，我们可以先采用暴力搜索的办法找到目标字符串 word 中的第一个字符 A,找到之后按照深度优先搜索的顺序寻找是否有和 word 匹配的字符串，如果找到直接返回 True；
如果没有，我们继续寻找下一个 A...
对于一轮深度搜索过程中，为了避免重复我们需要将搜索过的字符置为 0
*/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0) return false;
        for (int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if (dfs(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word, int i,int j,int length){
        if(i>=board.size()||j>=board[0].size()||i<0||
            j<0||length>=word.size()||word[length]!=board[i][j]){
            return false;
        }
        if(length==word.size()-1&&word[length]==board[i][j]){
            return true;
        }
        char temp=board[i][j];
        board[i][j]='0';
        bool flag=dfs(board,word,i,j+1,length+1)||dfs(board,word,i,j-1,length+1)||dfs(board,word,i+1,j,length+1)||dfs(board,word,i-1,j,length+1);
        board[i][j]=temp;  // 标记过的点恢复原状，以便进行下一次搜索
        return flag;
    }
};
