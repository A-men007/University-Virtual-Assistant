# -*- coding: utf-8 -*-




'''
Get the news with api then write it to a json file
@author Weijie Yu
Student number:251028185
'''
from newsapi import NewsApiClient
import json


def main():
    ''' API key'''
    api_key = "28d1246fd41b4019ba0850d8cf53c296"
    newsapi = NewsApiClient(api_key)
    ''' What we are searching for'''
    query = "London Ontario"
    '''use the news api to get news'''
    top_headlines = newsapi.get_everything(
        q=query,sort_by='relevancy',language='en')
    ''' writes the output to a JSON file. '''
    with open('output.json', 'w') as output:
        json.dump(top_headlines, output)

if __name__ == main():
    main()
