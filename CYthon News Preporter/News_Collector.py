import os
import time
import requests
from dotenv import load_dotenv

load_dotenv()
apiKey = os.getenv("API_Key")
#Fetching your API key from .env file.
main_news_url = f"http://newsapi.org/v2/top-headlines?country=in&category=business&apiKey={apiKey}"

def func(url):

    response = requests.get(url)
    json_news_content = response.json()
    print(json_news_content)
    lists = json_news_content['articles']

    while True:
        for dics in lists:
            for key in dics:
                if key == 'title':
                    title = str(dics[key])
                    print(main_news_url)
                    print(str(dics[key]))
                    file = open("NewsContent.txt", 'a') ###############
                    file.write(f"{title}\n") #Adding the content in file
                    file.close() #############
                    # time.sleep(1)

                if key == 'description':
                    description = str(dics[key])
                    print(dics[key])
                    file = open("NewsContent.txt", 'a') ##############
                    file.write(f"{description}\n") #Adding the description
                    file.close() #############
                    # time.sleep(1)

                if key == 'url':
                    url_of_news = str(dics[key])
                    print(dics[key])
                    file = open("Links.txt", 'a') ##############
                    file.write(f"Link for this news: {url_of_news}\n") #Adding the description
                    file.close() #############
                    # time.sleep(1)



if __name__ == "__main__":

    f = open("NewsContent.txt", "r+")
    fLink = open("Links.txt", "r+")
    # absolute file positioning
    f.seek(0)
    fLink.seek(0)
    # to erase all data
    f.truncate()
    fLink.truncate()

    f.close()
    fLink.close()
    print(main_news_url)
    func(main_news_url)


#End_of_program
