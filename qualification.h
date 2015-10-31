#ifndef QUALIFICATION_H
#define QUALIFICATION_H


class QString;
class Qualification
{

QString& partnerDisplay;
QString& personalDisplay;

int* partnerRating;
int* personalRating;

public:
    Qualification(QString& displayPartner,QString& displayPersonal);
    int setPartnerRating(int * rating);
};

#endif // QUALIFICATION_H
