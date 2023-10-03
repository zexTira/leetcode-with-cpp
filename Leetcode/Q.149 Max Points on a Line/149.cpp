/*//
//  First we implement a class Point as a representation of the coordinate of a point.
//  Next we need to check if three points are on one line by comparing the gradient of two pairs of points, with the pair can be chosen from any two points.
//  Then to the judging stage, if the number of points is smaller than two, return the size directly, otherwise we construct those coordinates as a Point object, and we need to go throughout any three points
      among all points, if they are on a line, add 1 to the count. 
//  Finally we need to pay attention that we need to reset the count when we choose 2 new points because the line these 2 points lying on is probably not the same, and after a loop we need to add 2 to the count, 
     indicating two initial points, and compare previous count and current count, choose a bigger one as the result till the end.
//*/

class Point {
public:
    double x;
    double y;

    Point(double x, double y) :x(x), y(y) {}
};

class Solution {
public:
    bool isCollinear(Point a, Point b, Point c) {
        double m1 = (b.y - a.y) / (b.x - a.x);
        double m2 = (c.y - b.y) / (c.x - b.x);
        return m1 == m2;
    }

    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2)
        {
            return n;
        }

        vector<Point> coordinates;
        for (auto& i : points)
        {
            Point k = Point((double)i[0], (double)i[1]);
            coordinates.push_back(k);
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int count = 0;
                for (int k = 0; k < n; k++)
                {
                    if (i != j && j != k && i != k)
                    {
                        if (isCollinear(coordinates[i], coordinates[j], coordinates[k]))
                        {
                            count++;
                        }
                    }
                }
                ans = max(count + 2, ans);
            }
        }
        return ans;   
    }
};