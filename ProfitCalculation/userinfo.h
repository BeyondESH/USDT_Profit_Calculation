#ifndef USERINFO_H
#define USERINFO_H

#include <QObject>
#include "singleton.hpp"
#include <QString>

class userInfo : public Singleton<userInfo>
{
    Q_OBJECT
    friend class Singleton<userInfo>;
public:
    userInfo();
    QString currencyKinds() const;
    void setCurrencyKinds(const QString &newCurrencyKinds);
    QString unit() const;
    void setUnit(const QString &newUnit);
    double numbers() const;
    void setNumbers(double newNumbers);
    double serviceChargeRate() const;
    void setServiceChargeRate(double newServiceChargeRate);
    double serviceCharge() const;
    void setServiceCharge(double newServiceCharge);
    double cost() const;
    void setCost(double newCost);
    double marketPrice() const;
    void setMarketPrice(double newMarketPrice);
    double minProfit() const;
    void setMinProfit(double newMinProfit);
    double profitRate() const;
    void setProfitRate(double newProfitRate);
    double profit() const;
    void setProfit(double newProfit);
    double grossProfitRate() const;
    void setGrossProfitRate(double newGrossProfitRate);

private:
    QString _currencyKinds;
    QString _unit;
    double _numbers;
    double _serviceChargeRate;
    double _serviceCharge;
    double _cost;
    double _marketPrice;
    double _minProfit;
    double _profitRate;
    double _profit;
    double _grossProfitRate;
};

#endif // USERINFO_H
