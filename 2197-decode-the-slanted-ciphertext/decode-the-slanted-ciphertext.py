class Solution:
    def decodeCiphertext(self, encodedText, rows):
        if rows == 1:
            return encodedText

        n = len(encodedText)
        cols = n // rows
        ans = []

        for start in range(cols):
            r = 0
            c = start

            while r < rows and c < cols:
                ans.append(encodedText[r * cols + c])
                r += 1
                c += 1

        return ''.join(ans).rstrip()