/* This is the main class for setting up the GUI.
 *    @author Kaustav Sharma
 *      Student number: 250953518
 *    @author Hamzhayen Suventhiran
 *      Student number: 250965255
 *
 */


#include "widget.h"
#include "ui_widget.h"
#include "alarm.h"
#include<QTextStream>
#include<QMessageBox>
#include<QFile>
#include<QDebug>
#include<QTimer>
#include <QSpinBox>
#include <QDateTime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "news.h"


using namespace std;
string a="";
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    //news variables
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    QString newsText;

    //weather global variables
    int tempGUI=0;
    int humidGUI=0;
    int presGUI=0;
    QString weatherText;

    //timer variables
    timer= new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(clock()));
    timer->start(1000);
    // cout<< system("/home/pi/UVA/location.sh");
}

Widget::~Widget()
{
    delete ui;
}

/* Method that prints out the time in the home screen.
 *    @author Kaustav Sharma
 *    Student number: 250953518
 */
void Widget::clock()
{
    QTime time =QTime::currentTime();
    QString time_txt=time.toString("hh : mm : ss");
    ui->label_7->setText(time_txt);
}


/* This is the main page indexing
 *    @author Kaustav Sharma
 *    Student number: 250953518
 */
void Widget::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
//when Home News button is clicked
void Widget::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
//when Home Alarm button is clicked
void Widget::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}
//when Home Bus button is clicked
void Widget::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}
//Button indexing from HomePage
void Widget::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
void Widget::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
void Widget::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
void Widget::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}



/**
    Button refresh to show news, class
    @author Weijie Yu
    Student number: 251028185
*/
void Widget::on_pushButton_9_clicked()
{
        system("/home/pi/UVA/news.sh");//execute the bash
        ifstream myFile("/home/pi/UVA/output.txt"); //open output.txt
        string line, first;//string variables
        int articles = 0;//article numbers
        string author, source, title, description, url, imageurl, time, content;//variables for articles
        vector<news> allNews;//vector that contains all the articles
        if(myFile.is_open()){//if the file is open
           getline(myFile,first);//check first line
           if(first.compare("No news can be found.") != 0){//if there is news found then
                author = first; //get author of first article
                getline(myFile,source);//get source of first article
                getline(myFile,title);//get title of first article
                getline(myFile,description);//get description of first article
                getline(myFile,url);//get url of first article
                getline(myFile,imageurl);//get image url of first article
                getline(myFile,time);//get the time of first article
                getline(myFile,content);//get the content of first article
                getline(myFile,line); //skip the empty line
                news a(author,source,title,description,url,imageurl,time,content);//create news with variables we read
                allNews.push_back(a);//push it into our vector
                articles =+ 1;//total number of articles +1
                while(myFile.good()){//while we haven't reach the end of the file
                   getline(myFile,author);//get author
                   getline(myFile,source);//get source
                   getline(myFile,title);//get title
                   getline(myFile,description);//get description
                   getline(myFile,url);//get url
                   getline(myFile,imageurl);//get image url
                   getline(myFile,time);//get time
                   getline(myFile,content);//get content
                   getline(myFile,line); //skip the empty line
                   news aa(author,source,title,description,url,imageurl,time,content);//create a news with variables we have
                   allNews.push_back(aa);//push it into news vector
                   articles =+ 1;//total articles +1
             }}
          else{
             cout<<"No news can be found."<<endl;//if there is no articile found then
          }
        }
        else{
           cout<<"Error. News file cannot be found."<<endl;//the output file couldn't be found
        }
        for(int i=0; i < allNews.size(); i++){
          a = a + allNews[i].getTitle()+'\n';
          a = a + allNews[i].getSource()+'\n';
          a = a + allNews[i].getAuthor()+'\n';
          a = a + allNews[i].getUrl()+'\n';
          a = a+'\n';
        }
        ui->textBrowser->setText(QString::fromStdString(a));
}





/**
    Refresh button for weather
    @author Amanpreet Gill
    Student number: 250964445
*/
void Widget::on_pushButton_10_clicked()
{
    system("/home/pi/UVA/weather.bash");
    ifstream file("/home/pi/UVA/woutput.txt");
    string line;
    int pressure, temp, humidity;
    string descrip;
    if(file.is_open()){
        getline(file,line);
        temp = stoi(line);
        getline(file,line);
        pressure = stoi(line);
        getline(file,line);
        humidity = stoi(line);
        getline(file,descrip);

        tempGUI=temp;
        humidGUI=humidity;
        presGUI=pressure;
        QString weatherText;
        humidGUI=humidity;
        presGUI=pressure;


        ui->label_9->setNum(tempGUI);
        ui->label_10->setNum(humidGUI);
        ui->label_11->setNum(presGUI);
        ui->textBrowser_2->setText(QString::fromStdString(descrip));
    }
    else{
        cout<<"File cannot be find."<<endl;
    }
}
/*
/*
    Main for news class
    @author Luka Banjanin
    Student number: 250968309
*/
void Widget::on_pushButton_11_clicked()
{
    int hours;
    int mins;
    int sec;
    hours= ui->spinBox->value();
    mins=ui->spinBox_2->value();
    sec=ui->spinBox_3->value();

    alarm:(hours, mins, sec);


}

