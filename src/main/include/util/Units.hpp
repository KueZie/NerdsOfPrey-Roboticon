// #include <exception>

// struct Unit
// {
//     double value;
//     virtual void Unit(double value, double ratioToMeter) = 0;
//     Unit(Unit&& other) : value(std::move(other.value)), ratioToMeter(std::move(other.ratioToMeter)) {}
//     ~Unit();
//     double GetMeterRatio() { return ratioToMeter; };
//     double Add(const Unit& other) { (this->value * this->ratioToMeter) + (other.value * other.ratioToMeter) };
//     double Sub(const Unit& other) { (this->value * this->ratioToMeter) - (other.value * other.ratioToMeter) };
//     double Mult(const Unit& other) { (this->value * this->ratioToMeter) * (other.value * other.ratioToMeter) };
//     double Div(const Unit& other)  { (this->value * this->ratioToMeter) / (other.value * other.ratioToMeter) };
//     bool operator==(const Unit& other) const
//     {
//         return (this->value * this->ratioToMeter) == (other.value * other.ratioToMeter);
//     }
//     bool operator!=(const Unit& other) const
//     {
//         return (this->value * this->ratioToMeter) != (other.value * other.ratioToMeter);
//     }
//     Unit& operator=(const Unit& other) const
//     {
//         if (this != &other)
//         {
//             if (this->ratioToMeter != other.GetMeterRatio())
//                 throw std::exception("Cannot convert units implicity.");
//             else
//                 return Unit(other.value, other.GetMeterRatio());
//         }
//         return *this;
//     }
//     Unit& operator+(const Unit& other) { return this->Add(&other); }
//     Unit& operator-(const Unit& other) { return this->Sub(&other); }
//     Unit& operator*(const Unit& other) { return this->Mult(&other); }
//     Unit& operator/(const Unit& other) { return this->Div(&other); }
// private:
//     double ratioToMeter;
// };

// struct Meter : public Unit
// {
//     Meter(double value) : Unit(value, 1.0f) {}
// };