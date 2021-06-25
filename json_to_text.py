'''
Using the json file we have, turn it into a readable txt file with news.
@author Weijie Yu
student number: 251028185
'''
import json


def main():
    #getting the news in the json file
    with open("output.json", "r") as f:
        news = json.load(f)
    try:
    #reading the each articles
      with open('output.txt', 'w') as f:
        for article in news["articles"]:
            try:
                f.write('Author: ' + article["author"] + '\n')
                #writing the author to file
            except:
                f.write('Unable to find the author of this article. \n')
                #if the author couldn't be found
            try:
                f.write('Source: ' + article["source"]["name"] + '\n')
                #writing the source to file
            except:
                f.write('Unable to find the source of this article. \n')
                #if the source couldn't be found
            try:
                f.write(article["title"] + '\n')
                #writing the title to the file
            except:
                f.write('Unable to find the title of this article. \n')
                #if the title couldn't be found
            try:
                f.write(article["description"] + '\n')
                #write the description to file
            except:
                f.write('Unable to find the description of this article. \n')
                #if the description couldn't be found
            try:
                f.write(article["url"] + '\n')
                #write the url to the file
            except:
                f.write('Unable to find the url of this article. \n')
                #if the url couldn't be found
            try:
                f.write(article["urlToImage"] + '\n')
                #write the image url to the file
            except:
                f.write('There is no image in this article. \n')
                #if the image url couldn't be found
            try:
                f.write(article["publishedAt"] + '\n')
                #write the publish time to the file
            except:
                f.write('Unable to find the time of this article. \n')
                #if the publish time couldn't be found
            try:
                f.write(article["content"] + '\n')
                #write the content to the file
            except:
                f.write('Unable to find the content of this article. \n')
                #if the content couldn't be found
            f.write('\n')
            #leave a space

    except TypeError:
        with open("output.txt","w") as f:#if the output txt file couldn't be found
            f.write("No news can be found.")
    if len(news["articles"])==0:
        with open("output.txt","w") as f:#if no news can be found
            f.write("No news can be found.")
    f.close()#close the file


if __name__ == main():
    main()
