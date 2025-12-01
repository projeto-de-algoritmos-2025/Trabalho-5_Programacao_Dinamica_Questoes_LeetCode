from typing import List

class Solution:
    def paintWalls(self, cost: List[int], time: List[int]) -> int:
        n = len(cost)

        # dp[t] = custo mínimo para alcançar t unidades de "tempo ocupado"
        # (tempo que habilita o pintor grátis para pintar t paredes)
        INF = 10**18
        dp = [INF] * (n + 1)
        dp[0] = 0

        for c, t in zip(cost, time):
            # Fazemos a varredura de forma decrescente para evitar reuso no mesmo item
            for used_time in range(n, -1, -1):
                new_t = min(n, used_time + t + 1)  # t+1 unidades de tempo do pintor pago
                dp[new_t] = min(dp[new_t], dp[used_time] + c)

        return dp[n]
