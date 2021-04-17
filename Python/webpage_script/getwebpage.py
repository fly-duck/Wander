
###import requests
##response = requests.get('http://hiscore.runescape.com/index_lite.ws?player=zezima')
#response = requests.get('https://www.baidu.com')
#print (response.status_code)
#print (response.content)


import urllib.request
import re

url = 'http://pythonprogramming.net/parse-website-using-regular-expressions-urllib/'

url2 = 'https://www.baidu.com'
req = urllib.request.Request(url2)
resp = urllib.request.urlopen(req)
respData = resp.read()
