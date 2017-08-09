import requests
import pandas as pd
from bs4 import BeautifulSoup


url = "http://www.akc.org/content/news/articles/most-popular-dog-breeds-full-ranking-list/?button"
r = requests.get(url)
data = r.text
soup = BeautifulSoup(data, 'html5lib')

table = soup.find_all('table')[0]

rows = table.find_all('tr')[1:]

data = {
    'breeds' : [],
    'rank2016' : [],
    'rank2015' : [],
    'rank2014' : [],
    'rank2013' : []
}


for row in rows:
    cols = row.find_all('td')
    data['breeds'].append( cols[0].get_text() )
    data['rank2016'].append( cols[1].get_text() )
    data['rank2015'].append( cols[2].get_text() )
    data['rank2014'].append( cols[3].get_text() )
    data['rank2013'].append( cols[4].get_text() )


dogData = pd.DataFrame(data)


# dogData.to_csv('path.csv', header=True, index=False, encoding='utf-8')

print (dogData)
