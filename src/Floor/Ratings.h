/**
 * @class Ratings
 * @brief This class represents the ratings a customer leaves the restaurant when they leave.
 */

#ifndef RATINGS_H
#define RATINGS_H

class Ratings {
private:
    double overallRating = 0;
    int numberOfRatings = 0;
    double totalRatings = 0;
public:
    void leaveRating(double rating);
};

#endif