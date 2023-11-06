/**
 * @File Ratings.h
 * @brief Declaration of the Ratings class
*/

/**
 * @class Ratings
 * @brief This class represents the ratings a customer leaves the restaurant when they leave.
 */

#ifndef RATINGS_H
#define RATINGS_H

class Ratings {
private:
    double overallRating = 0; ///< The overall rating based on user ratings.
    int numberOfRatings = 0; ///< The total number of ratings received.
    double totalRatings = 0; ///< The sum of all user ratings.
public:
    /**
     * @brief Leave a rating for the entity.
     * @param rating The rating to be left by the user.
     * This function allows a user to leave a rating for an entity. The overall
     * rating and other statistics are updated based on the provided rating.
     */
    void leaveRating(double rating);
};

#endif