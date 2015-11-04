#include "qualification.h"
#include <QString>
Qualification::Qualification(const int& dispID,const int& ID,const QString& titleParam,const QString& displayExpectationParam,const QString& displayQualificationParam):
                displayID(dispID),qualificationID(ID),title(QString::fromStdString(titleParam.toStdString())),expectationDisplay(QString::fromStdString(displayExpectationParam.toStdString())),qualificationDisplay(QString::fromStdString(displayQualificationParam.toStdString())),qualificationRating(1),expectationRating(1){

}

Qualification::Qualification(const int& dispID,const int&ID,const QString& titleParam,const QString& displayExpectationParam,const QString& displayQualificationParam,const int& qualificationRatingParam,const int& expectationRatingParam):
                 displayID(dispID),qualificationID(ID),title(QString::fromStdString(titleParam.toStdString())),expectationDisplay(QString::fromStdString(displayExpectationParam.toStdString())),qualificationDisplay(QString::fromStdString(displayQualificationParam.toStdString())),qualificationRating(qualificationRatingParam),expectationRating(expectationRatingParam){
}

QString Qualification::getQualificationDisplay() const {
    return qualificationDisplay;
}

QString Qualification::getExpectationDisplay() const {

    return expectationDisplay;
}

int Qualification::getQualificationRating() const {
    return qualificationRating;
}

int Qualification::getExpectationRating() const {
    return expectationRating;
}

int Qualification::getQualificationID() const {
    return qualificationID;
}

int Qualification::getDisplayID() const {
    return displayID;
}

int Qualification::setQualificationRating(const int& rating){
    if (rating < 1 || rating > 5)
        return 0;
    else{
        qualificationRating = rating;
        return 1;
    }
}

int Qualification::setExpectationRating(const int& rating){
    if (rating < 1 || rating > 5)
        return 0;
    else{
        expectationRating = rating;
        return 1;
    }
}

QString Qualification::getTitle() const{
    return title;
}

