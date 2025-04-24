from typing import List
from collections import Counter

class StatisticsCalculator:
    def __init__(self, data: List[int]):
        self.data = data

    def mean(self) -> float:
        return sum(self.data) / len(self.data)

    def median(self) -> float:
        sorted_data = sorted(self.data)
        n = len(sorted_data)
        mid = n // 2
        if n % 2 == 1:
            return float(sorted_data[mid])
        else:
            return (sorted_data[mid - 1] + sorted_data[mid]) / 2.0

    def mode(self) -> List[int]:
        frequency = Counter(self.data)
        max_count = max(frequency.values())
        return [num for num, count in frequency.items() if count == max_count]

    def print_statistics(self):
        print(f"Mean: {self.mean():.2f}")
        print(f"Median: {self.median():.2f}")
        print(f"Mode: {' '.join(map(str, self.mode()))}")

# Example usage
if __name__ == "__main__":
    data = [4, 2, 1, 3, 4, 2, 4, 2, 2, 5]
    stats_calc = StatisticsCalculator(data)
    stats_calc.print_statistics()
