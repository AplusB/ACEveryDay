import re
import urllib

wtf = 'https://movie.douban.com/top250?start=00&filter='
urls = []
scores = []

def calURL():
    step = 0
    while step <= 166:
        tmp = wtf[:38]
        tmp += str(step)
        tmp += wtf[40:]
        urls.append(tmp)
        step += 25

def getHTML(url):
    page = urllib.urlopen(url)
    html = page.read()
    return html
    
def getScore(html):
    score = []
    reg = r'property="v:average">([0-9].[0-9])</span>'
    score = re.findall(re.compile(reg), html)
    return score

def solve():
    calURL()
    for each in urls:
        print each
        scores.append(getScore(getHTML(each)))
    sum = 0
    cnt = 0
    for each in scores:
        if cnt == 166: break
        for i in range(0, len(each)):
            if cnt == 166: break
            cnt += 1
            sum += float(each[i])            
    return sum

print solve()
