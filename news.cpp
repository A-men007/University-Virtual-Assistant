#include "news.h"
#include <iostream>
#include "news.h"
using namespace std;

news::news(string author="", string source="", string title="", string description="", string url="", string imageurl="", string time="", string content=""){
    this->author = author;
    this->source = source;
    this->title = title;
    this->descrip = description;
    this->url = url;
    this->image = imageurl;
    this->time = time;
    this->content = content;
}

string news::getAuthor(){
        return this->author;
    }
string news::getSource(){
        return this->source;
}
string news::getTitle(){
        return this->title;
}
string news::getUrl(){
        return this->url;
}
string news::getImage(){
        return this->image;
}
string news::getTime(){
        return this->time;
}
string news::getContent(){
        return this->content;
}
string news::getDescription(){
        return this->descrip;
}


