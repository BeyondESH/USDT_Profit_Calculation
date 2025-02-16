#include "userinfo.h"

userInfo::userInfo() {}

QString userInfo::currencyKinds() const
{
    return _currencyKinds;
}

void userInfo::setCurrencyKinds(const QString &newCurrencyKinds)
{
    _currencyKinds = newCurrencyKinds;
}

QString userInfo::unit() const
{
    return _unit;
}

void userInfo::setUnit(const QString &newUnit)
{
    _unit = newUnit;
}

double userInfo::numbers() const
{
    return _numbers;
}

void userInfo::setNumbers(double newNumbers)
{
    _numbers = newNumbers;
}

double userInfo::serviceChargeRate() const
{
    return _serviceChargeRate;
}

void userInfo::setServiceChargeRate(double newServiceChargeRate)
{
    _serviceChargeRate = newServiceChargeRate;
}

double userInfo::serviceCharge() const
{
    return _serviceCharge;
}

void userInfo::setServiceCharge(double newServiceCharge)
{
    _serviceCharge = newServiceCharge;
}

double userInfo::cost() const
{
    return _cost;
}

void userInfo::setCost(double newCost)
{
    _cost = newCost;
}

double userInfo::marketPrice() const
{
    return _marketPrice;
}

void userInfo::setMarketPrice(double newMarketPrice)
{
    _marketPrice = newMarketPrice;
}

double userInfo::minProfit() const
{
    return _minProfit;
}

void userInfo::setMinProfit(double newMinProfit)
{
    _minProfit = newMinProfit;
}

double userInfo::profitRate() const
{
    return _profitRate;
}

void userInfo::setProfitRate(double newProfitRate)
{
    _profitRate = newProfitRate;
}

double userInfo::profit() const
{
    return _profit;
}

void userInfo::setProfit(double newProfit)
{
    _profit = newProfit;
}

double userInfo::grossProfitRate() const
{
    return _grossProfitRate;
}

void userInfo::setGrossProfitRate(double newGrossProfitRate)
{
    _grossProfitRate = newGrossProfitRate;
}
