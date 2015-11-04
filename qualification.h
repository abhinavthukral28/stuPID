#ifndef QUALIFICATION_H
#define QUALIFICATION_H


#include <QString>
class Qualification
{

    QString expectationDisplay;
    QString qualificationDisplay;
    QString title;
    int qualificationRating;
    int expectationRating;
    int qualificationID;
    int displayID;

public:
    Qualification(const int& dispID,const int& ID,const QString& titleParam,const QString& displayExpectationParam,const QString& displayQualificationParam);
    Qualification(const int& dispID,const int& ID,const QString& titleParam,const QString& displayExpectationParam,const QString& displayQualificationParam,const int& qualificationRatingParam,const int& expectationRatingParam);
    QString getQualificationDisplay() const;
    QString getTitle() const;
    QString getExpectationDisplay() const;
    int getQualificationRating() const;
    int getExpectationRating() const;
    int getQualificationID() const;
    int getDisplayID() const;
    int setQualificationRating(const int& rating);
    int setExpectationRating(const int& rating);

};

#endif // QUALIFICATION_H
