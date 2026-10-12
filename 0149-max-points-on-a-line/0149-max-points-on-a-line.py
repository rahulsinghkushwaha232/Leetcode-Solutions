from collections import defaultdict

class Solution:
    def maxPoints(self, points):
        n = len(points)
        if n <= 2:
            return n
            
        max_points = 0
        
        def gcd(a, b):
            while b:
                a, b = b, a % b
            return a
        
        for i in range(n):
            slopes = defaultdict(int)
            duplicates = 1
            current_max = 0
            
            for j in range(i + 1, n):
                x1, y1 = points[i]
                x2, y2 = points[j]
                
                if x1 == x2 and y1 == y2:
                    duplicates += 1
                    continue
                    
                dx = x2 - x1
                dy = y2 - y1
                g = gcd(dx, dy)
                
                dx //= g
                dy //= g
                
                if dx < 0 or (dx == 0 and dy < 0):
                    dx = -dx
                    dy = -dy
                    
                slopes[(dx, dy)] += 1
                current_max = max(current_max, slopes[(dx, dy)])
                
            max_points = max(max_points, current_max + duplicates)
            
        return max_points