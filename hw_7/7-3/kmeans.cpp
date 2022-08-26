#include "kmeans.hpp"

double Point::Distance(Point &other)
{
    // YOUR CODE HERE
    return (x - other.x) * (x - other.x) + (y - other.y) * (y - other.y);
}

std::istream &operator>>(std::istream &is, Point &pt)
{
    // YOUR CODE HERE
    is >> pt.x >> pt.y;
    return is;
}

std::ostream &operator<<(std::ostream &os, Point &pt)
{
    // YOUR CODE HERE
    os << pt.x << " " << pt.y;
    return os;
}

Kmeans::Kmeans(const std::vector<Point> &points, const std::vector<Point> &initialCenters)
{
    // YOUR CODE HERE
    m_points = points;
    m_centers = initialCenters;
    m_numPoints = m_points.size();
    m_numCenters = m_centers.size();
}

std::vector<index_t> Kmeans::Run(int maxIterations)
{
    // DO NOT MODIFY THESE CODE
    std::vector<index_t> assignment(m_numPoints, 0); // the return vector
    int currIteration = 0;
    std::cout << "Running kmeans with num points = " << m_numPoints
              << ", num centers = " << m_numCenters
              << ", max iterations = " << maxIterations << "...\n";

    // YOUR CODE HERE
    bool changed = true;
    std::vector<std::vector<int>> count;
    std::vector<std::vector<double>> total_x;
    std::vector<std::vector<double>> total_y;
    count.resize(32);
    total_x.resize(32);
    total_y.resize(32);
    std::thread t[32];
    int delta = m_numPoints % 32;
    int step = m_numPoints / 32;
    while (changed && (currIteration < maxIterations))
    {
        changed = false;
        for (int i = 0; i < 32; i++)
        {
            count[i].clear();
            count[i].resize(m_numCenters);
            total_x[i].clear();
            total_x[i].resize(m_numCenters);
            total_y[i].clear();
            total_y[i].resize(m_numCenters);
        }
        for (int a = 0; a < 32; a++)
        {
            t[a] = std::thread([&](int a)
                               {
                                   int limit = (a == 31) ? (a + 1) * step + delta : (a + 1) * step;
                                   for (int i = a * step; i < limit; i++)
                                   {
                                       int min_index = 0;
                                       double min_dist = DBL_MAX;
                                       for (int j = 0; j < m_numCenters; j++)
                                       {
                                           double dist = m_points[i].Distance(m_centers[j]);
                                           if (dist < min_dist)
                                           {
                                               min_index = j;
                                               min_dist = dist;
                                           }
                                       }
                                       if (assignment[i] != min_index)
                                       {
                                           changed = true;
                                       }
                                       assignment[i] = min_index;
                                       total_x[a][min_index] += m_points[i].x;
                                       total_y[a][min_index] += m_points[i].y;
                                       count[a][min_index] += 1;
                                   }
                               },
                               a);
        }
        for (int a = 0; a < 32; a++)
        {
            t[a].join();
        }
        for (int j = 0; j < m_numCenters; j++)
        {
            double x = 0, y = 0;
            int c = 0;
            for (int i = 0; i < 32; i++)
            {
                x += total_x[i][j];
                y += total_y[i][j];
                c += count[i][j];
            }
            // m_centers[j].x = (total_x[0][j] + total_x[1][j] + total_x[2][j] + total_x[3][j]) / (count[0][j] + count[1][j] + count[2][j] + count[3][j]);
            // m_centers[j].y = (total_y[0][j] + total_y[1][j] + total_y[2][j] + total_y[3][j]) / (count[0][j] + count[1][j] + count[2][j] + count[3][j]);
            m_centers[j].x = x / c;
            m_centers[j].y = y / c;
        }
        currIteration += 1;
    }

    // YOUR CODE ENDS HERE
    std::cout << "Finished in " << currIteration << " iterations." << std::endl;
    return assignment;
}