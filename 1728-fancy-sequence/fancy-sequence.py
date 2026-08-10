class Fancy:
    MOD = 10**9 + 7

    def __init__(self):
        self.seq = []
        self.M = 1
        self.A = 0

    def append(self, val: int) -> None:
        inv_M = pow(self.M, self.MOD - 2, self.MOD)
        raw = (val - self.A) * inv_M % self.MOD
        self.seq.append(raw)

    def addAll(self, inc: int) -> None:
        self.A = (self.A + inc) % self.MOD

    def multAll(self, m: int) -> None:
        self.M = self.M * m % self.MOD
        self.A = self.A * m % self.MOD

    def getIndex(self, idx: int) -> int:
        if idx >= len(self.seq):
            return -1
        return (self.seq[idx] * self.M + self.A) % self.MOD