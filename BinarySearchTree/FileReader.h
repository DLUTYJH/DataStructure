//
// Created by answer on 17-10-13.
//

#ifndef BINARYSEARCHTREE_FILEREADER_H
#define BINARYSEARCHTREE_FILEREADER_H

/**
 * 读取文件，将文件内容放到content中，
 *
 * 分词，将单词从content中提取出来，放到vector中
 *
 */
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

using namespace std ;

namespace FileReader{

   /**
    * 将单词转化为小写
    * @param word
    * @return
    */
    string toLower(const string & word){

        string tmp = "";
        for (int i = 0; i < word.length(); ++i) {
            tmp += tolower(word[i]);
        }
        return tmp ;
    }

    /**
     * 在字符串中，从start位置开始，查找第一个为字母的下标,否则返回字符串长度,表示该字符串中没有字母存在
     * @param str
     * @param start
     * @return
     */
    int firstCharacterIndex(const string& str ,int start){
        for (int i = start; i < str.length(); ++i) {
            if (isalpha(str[i]))
                return i ;
        }

        return str.length() ;
    }


   /**
    * 读取文件，然后抽取出文件中的单词转化为小写后存入到vector中
    * @param filename
    * @param words
    * @return
    */
    bool readFile(const string& filename ,vector<string >& words ){

        string content ="";
        string line ;

        //读取文件，将文件内容全部读取到content中
        ifstream file(filename);
        //file.open(filename,ios::in);
        if (file.is_open()){
            while (getline(file,line)){
                content += (line+"\n");
            }
            file.close();
        } else{
            cout<<"打开文件失败"<<endl ;
            return  false ;
        }

        //分词，将抽取的单词放入到vector
       int start = firstCharacterIndex(content , 0);
       for (int i = start+1; i < content.length(); ) {

           //抽取单词

           //字符串结束，或者遇到不是字母的
           if (i == content.length() || !isalpha(content[i])){
               words.push_back(toLower(content.substr(start,i-start)));
               start = firstCharacterIndex(content,i);
               i = start+1 ;
           }
           //如果是字母，则i++
           else i++ ;
       }

        return true ;
    }

}//fileReader

#endif //BINARYSEARCHTREE_FILEREADER_H
