class Solution:
    def simplifyPath(self, path: str) -> str:
        words = path.split('/')
        results = []
        for w in words:
            if w == '.' or w == '':
                continue
            elif w == '..':
                # /home/allen/docs/../yolo
                if len(results) > 0:
                    results.pop()
            else:
                results.append(w)
        result = ''
        for w in results:
            result += '/' + w

        if result == '':
            result = '/'
        return result

