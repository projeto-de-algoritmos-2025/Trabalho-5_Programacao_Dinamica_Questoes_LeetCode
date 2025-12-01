class Solution:
    def shortestCommonSupersequence(self, str1: str, str2: str) -> str:
        n, m = len(str1), len(str2)

        # ============================
        # 1. DP da LCS (Longest Common Subsequence)
        # ============================
        dp = [[0] * (m + 1) for _ in range(n + 1)]

        for i in range(1, n + 1):
            for j in range(1, m + 1):
                if str1[i - 1] == str2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + 1
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

        # ============================
        # 2. Reconstruir a SCS
        # ============================
        i, j = n, m
        result = []

        while i > 0 and j > 0:
            # Se o caractere é igual → parte da LCS
            if str1[i - 1] == str2[j - 1]:
                result.append(str1[i - 1])
                i -= 1
                j -= 1
            else:
                # Segue o caminho que mantém a LCS
                if dp[i - 1][j] >= dp[i][j - 1]:
                    result.append(str1[i - 1])
                    i -= 1
                else:
                    result.append(str2[j - 1])
                    j -= 1

        # Se ainda restaram caracteres em str1
        while i > 0:
            result.append(str1[i - 1])
            i -= 1

        # Se ainda restaram caracteres em str2
        while j > 0:
            result.append(str2[j - 1])
            j -= 1

        # Construímos de trás para frente → inverter
        return "".join(reversed(result))
