#include "Ratings.h"

void Ratings::leaveRating(double rating)
{
    totalRatings += rating;
    numberOfRatings++;

    overallRating = totalRatings / numberOfRatings;
}