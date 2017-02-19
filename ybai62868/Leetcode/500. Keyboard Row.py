class Solution(object):
     def findwords(self,words):
          self.words=words
          result=[]
          rows=[set('qwertyuiop'),set('asdfghjkl'),set('zxcvbnm')]
          for row in rows:
               for word in words:
                    if set(word.lower())<=row:
                         result.append(word)

          return result
