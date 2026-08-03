class DSU:
    def __init__(self, n):
        self.p = list(range(n))

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, a, b):
        pa, pb = self.find(a), self.find(b)
        if pa == pb:
            return False
        self.p[pa] = pb
        return True


class Solution:
    def maxStability(self, n, edges, k):

        def check(x):
            dsu = DSU(n)
            used = 0
            upgrades = 0

            # mandatory edges
            for u, v, s, must in edges:
                if must:
                    if s < x:
                        return False
                    if not dsu.union(u, v):
                        return False
                    used += 1

            # optional without upgrade
            for u, v, s, must in edges:
                if not must and s >= x:
                    if dsu.union(u, v):
                        used += 1

            # optional with upgrade
            for u, v, s, must in edges:
                if not must and s < x and 2 * s >= x and upgrades < k:
                    if dsu.union(u, v):
                        upgrades += 1
                        used += 1

            return used == n - 1

        ans = -1
        lo, hi = 1, 200000

        while lo <= hi:
            mid = (lo + hi) // 2
            if check(mid):
                ans = mid
                lo = mid + 1
            else:
                hi = mid - 1

        return ans