#ifndef NEWS_H
#define NEWS_H

#include <string>
//namespace
using namespace std;


class news{
    private:
    string author;
    string source;
        string title;
        string descrip;
        string url;
        string image;
        string time;
        string content;

    public:
    news(string, string, string, string, string, string, string, string);
    string getAuthor();
    string getSource();
        string getTitle();
    string getUrl();
        string getImage();
        string getTime();
        string getContent();
        string getDescription();

};

#endif
