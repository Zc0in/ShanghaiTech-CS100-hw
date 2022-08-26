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
    std::atomic<std::vector<int>> count;
    std::atomic<std::vector<double>> total_x;
    std::atomic<std::vector<double>> total_y;
    std::thread t[4];
    int delta = m_numPoints % 4;
    int step = m_numPoints / 4;
    while (changed && (currIteration < maxIterations))
    {
        changed = false;
        count.load().clear();
        count.load().resize(m_numCenters);
        total_x.load().clear();
        total_x.load().resize(m_numCenters);
        total_y.load().clear();
        total_y.load().resize(m_numCenters);
        for (int a = 0; a < 4; a++)
        {
            t[a] = std::thread([&](int a)
                               {
                                   int limit = (a == 3) ? (a + 1) * step + delta : (a + 1) * step;
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
                                       total_x.load()[min_index] += m_points[i].x;
                                       total_y.load()[min_index] += m_points[i].y;
                                       count.load()[min_index] += 1;
                                   }
                               },
                               a);
        }
        for (int a = 0; a < 4; a++)
        {
            t[a].join();
        }
        // for (int i = 0; i < m_numPoints; i++)
        // {
        //     int min_index = 0;
        //     double min_dist = DBL_MAX;
        //     for (int j = 0; j < m_numCenters; j++)
        //     {
        //         double dist = m_points[i].Distance(m_centers[j]);
        //         if (dist < min_dist)
        //         {
        //             min_index = j;
        //             min_dist = dist;
        //         }
        //     }
        //     if (assignment[i] != min_index)
        //     {
        //         changed = true;
        //     }
        //     assignment[i] = min_index;
        //     total_x[min_index] += m_points[i].x;
        //     total_y[min_index] += m_points[i].y;
        //     count[min_index] += 1;
        // }
        for (int j = 0; j < m_numCenters; j++)
        {
            m_centers[j].x = total_x.load()[j] / count.load()[j];
            m_centers[j].y = total_y.load()[j] / count.load()[j];
        }
        currIteration += 1;
    }

    // YOUR CODE ENDS HERE
    std::cout << "Finished in " << currIteration << " iterations." << std::endl;
    return assignment;
}